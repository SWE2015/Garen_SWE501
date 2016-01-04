#include <iostream>
#include <cstdlib>
#include "BST.h"
using namespace std;
//BST.cpp
BST::BST() {
	root = NULL;
};

BST::node* BST::CreateLeaf(int key) {
	node* tempNode = new node;
	tempNode->key = key;
	tempNode->left = NULL;
	tempNode->right = NULL;
	return tempNode;
}

void BST::AddLeaf(int key) {
	AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* Ptr) {
	if (root == NULL) {
		root = CreateLeaf(key);
	}
	else if (key < Ptr->key) {
		if (Ptr->left != NULL) {
			AddLeafPrivate(key, Ptr->left);
		}
		else {
			Ptr->left = CreateLeaf(key);
		}
	}
	else if (key > Ptr->key) {
		if (Ptr->right != NULL) {
			AddLeafPrivate(key, Ptr->right);
		}
		else {
			Ptr->right = CreateLeaf(key);
		}
	}
	else {
		cout << "The key " << key << " is already available on the tree\n";
	}
}

void BST::PrintInOrder() {
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr) {
	if (root != NULL) {
		if (Ptr->left != NULL) {
			PrintInOrderPrivate(Ptr->left);
		}
		cout << Ptr->key << " ";
		if (Ptr->right != NULL) {
			PrintInOrderPrivate(Ptr->right);
		}
	}
	else {
		cout << "Tree is empty\n";
	}
}

BST::node* BST::ReturnNode(int key) {
	return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr) {
	if (Ptr != NULL) {
		if (Ptr->key == key) {
			return Ptr;
		}
		else {
			if (key < Ptr->key) {
				return ReturnNodePrivate(key, Ptr->left);
			}
			else {
				return ReturnNodePrivate(key, Ptr->right);
			}
		}
	}
	else {
		return NULL;
	}
}

void BST::RemoveRootMatch() {
	if (root != NULL) {
		node* delPtr = root;
		int rootKey = root->key;
		int smallestInRightSubtree;
		if (root->left == NULL && root->right == NULL) {
			root = NULL;
			delete delPtr;
		}
		else if (root->left == NULL && root->right != NULL) {
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			cout << "The root node " << rootKey << " removed\n";
		}
		else if (root->left != NULL && root->right == NULL) {
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			cout << "The root node " << rootKey << " removed\n";
		}
		else {
			smallestInRightSubtree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree, root);
			root->key = smallestInRightSubtree;
			cout << "The root node " << rootKey << " overwritten with " << root->key << endl;
		}
	}
	else {
		cout << "Tree is empty\n";
	}
}

int BST::FindSmallestPrivate(node* Ptr) {
	if (root == NULL) {
		cout << "Tree is empty\n";
		return -1;
	}
	else {
		if (Ptr->left != NULL) {
			return FindSmallestPrivate(Ptr->left);
		}
		else {
			return Ptr->key;
		}
	}
}

int BST::FindSmallest() {
	return FindSmallestPrivate(root);
}

void BST::RemoveNode(int key) {
	RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent) {
	if (root != NULL) {
		if (root->key == key) {
			RemoveRootMatch();
		}
		else {
			if (key < parent->key && parent->left != NULL) {
				parent->left->key == key ? RemoveMatch(parent, parent->left, true) : RemoveNodePrivate(key, parent->left);
			}
			else if (key > parent->key && parent->right != NULL) {
				parent->left->key == key ? RemoveMatch(parent, parent->right, false) : RemoveNodePrivate(key, parent->right);
			}
			else {
				cout << "Key " << key << " is not in the tree\n";
			}
		}
	}
	else {
		cout << "Tree is empty\n";
	}
}

void BST::RemoveMatch(node* parent, node* match, bool isLeftChild) {
	if (root != NULL) {
		node* delPtr;
		int matchKey = match->key;
		int smallestInRightSubtree;

		if (match->left == NULL && match->right == NULL) {
			delPtr = match;
			isLeftChild == true ? parent->left = NULL : parent->right == NULL;
			delete delPtr;
			cout << "The node containing key " << matchKey << " was renmoved\n";
		}
		else if (match->left == NULL && match->right != NULL) {
			isLeftChild == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
		}
		else if (match->left != NULL && match->right == NULL) {
			isLeftChild == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
		}
		else {
			smallestInRightSubtree = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree, match);
			match->key = smallestInRightSubtree;
		}
	}
	else {
		cout << "Can't remove match. Tree is already empty\n";
	}
}
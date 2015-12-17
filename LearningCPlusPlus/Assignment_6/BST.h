#pragma once

class BST {
private:
	struct node {
		int key;
		node* left;
		node* right;
	};
	node* root;
	node* CreateLeaf(int key);
	node* ReturnNode(int key);

	void AddLeafPrivate(int key, node* Ptr);
	void PrintInOrderPrivate(node* Ptr);
	node* ReturnNodePrivate(int key, node* Ptr);
	void RemoveMatch(node* parent, node* match, bool isLeftChild);
	int FindSmallestPrivate(node* Ptr);
	void RemoveNodePrivate(int key, node* parent);
	void RemoveRootMatch();

public:
	BST();
	void AddLeaf(int key);
	void PrintInOrder();
	int FindSmallest();
	void RemoveNode(int key);
};
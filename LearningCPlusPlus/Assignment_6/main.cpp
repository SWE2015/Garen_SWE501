#include <iostream>
#include <cstdlib>
#include "BST.cpp"
using namespace std;

int main() {

	int TreeKeys[11] = { 13,15,47,14,58,23,95,11,86,69,2 };
	BST myTree;
	cout << "Printing the tree in order\nBefore adding numbers\n";
	myTree.PrintInOrder();
	for (size_t i = 0; i < 11; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}
	cout << "Printing the tree in order\nAfter adding numbers\n";
	myTree.PrintInOrder();
	return 0;
}
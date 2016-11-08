#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode; // Insert the node.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode); // Search the left branch.
	else
		insert(nodePtr->right, newNode); // Search the right branch.
}

void IntBinaryTree::insertNode(int num)
{
	TreeNode *newNode = nullptr; // Pointer to a new node.

	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;
	
	insert(root, newNode);
}

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

bool IntBinaryTree::searchNode(int num)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == num)
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

void IntBinaryTree::remove(int num)
{
	deleteNode(num, root);
}

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
	if (num < nodePtr->value)
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->value)
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{

	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; // Reattach the left child.
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right; // Reattach the right child.
		delete tempNodePtr;
	}
	// If the node has two children.
	else
	{
	// Move one node to the right.
	tempNodePtr = nodePtr->right;
	// Go to the end left node.
	while (tempNodePtr->left)
		tempNodePtr = tempNodePtr->left;
	// Reattach the left subtree.
	tempNodePtr->left = nodePtr->left;
	tempNodePtr = nodePtr;
	// Reattach the right subtree.
	nodePtr = nodePtr->right;
	delete tempNodePtr;
	}
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
		}
}



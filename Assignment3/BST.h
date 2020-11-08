#pragma once


#include <iostream>
#include <stack>
#include <iomanip>

class binarySearchTree
{
	public:
		struct node
		{
			double key;
			node* leftChild;
			node* rightChild;
		};
		node* root;

		binarySearchTree();

		// Finds a specified key value in the tree and returns the node containing that key
		node* findKey(double);

		// Finds the parent node of a node with a specified key and returns the parent node
		node* findParent(double);

		// Inserts a node into the binary search tree with a specified key if it does not already exist in the tree
		void insertNode(double);

		// Deletes a node with a specified key if it exists in the tree
		void deleteNode(double);

		// Displays the tree structure horizontally with the root node being the leftmost entry
		void displayTree(int, node*);

		// Prints the contents of the tree from highest to lowest
		void printTree();

		// Finds a node with a specified key and prints out the path to that key while summing the keys along the path. 
		void expensivePath(double);
};
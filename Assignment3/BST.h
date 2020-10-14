#pragma once


#include <iostream>
#include <stack>

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
		node* findKey(double);
		void insertNode(double);
		void deleteNode(double);
		void displayTree();
		void printTree();
		void expensivePath(double);

};
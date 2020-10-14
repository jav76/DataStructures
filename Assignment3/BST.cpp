#include "BST.h"


binarySearchTree::binarySearchTree()
{
	root = nullptr;
}

binarySearchTree::node* binarySearchTree::findKey(double val)
{
	node* current = root;
	while (current != nullptr)
	{
		if (current->key == val)
		{
			return current;
		}
		if (current->key > val)
		{
			current = current->leftChild;
		}
		else
		{
			current = current->rightChild;
		}
	}
	return nullptr;
}

void binarySearchTree::insertNode(double val)
{
	node* newNode = new node;
	newNode->key = val;
	newNode->rightChild = nullptr;
	newNode->leftChild = nullptr;
	node* current = root;
	node* last = root;

	if (current == nullptr)
	{
		root = newNode;
		return;
	}
	while (current != nullptr)
	{
		if (current->key == val)
		{
			std::cout << val << " already exists in this BST.\n";
			break;
		}
		if (current->key > val)
		{
			last = current;
			current = current->leftChild;
		}
		else
		{
			last = current;
			current = current->rightChild;
		}
	}
	if (val < last->key)
	{
		last->leftChild = newNode;
	}
	else
	{
		last->rightChild = newNode;
	}
}

void binarySearchTree::deleteNode(double val)
{
	node* toDelete = this->findKey(val);
	if (toDelete != nullptr)
	{
		if (toDelete->leftChild == nullptr && toDelete->rightChild == nullptr)
		{
			delete toDelete;
		}
		else
		{
			if (toDelete->leftChild == nullptr && toDelete->rightChild != nullptr)
			{
				toDelete = toDelete->rightChild;
			}
			else if (toDelete->leftChild != nullptr && toDelete->rightChild == nullptr)
			{
				toDelete = toDelete->leftChild;
			}
			else
			{
				// we gotta do some fucky shit here
			}
		}
	}
}

void binarySearchTree::displayTree()
{
	node* current = root;
	int height = 0;
	while (current != nullptr)
	{
		
	}
}

void binarySearchTree::printTree()
{
	std::cout << "Current contents of this tree in order:\n";
	node* current = root;
	std::stack<node*> stack;
	while (true)
	{
		if (current != nullptr)
		{
			stack.push(current);
			current = current->leftChild;
		}
		else
		{
			if (stack.empty())
			{
				std::cout << std::endl;
				return;
			}
			current = stack.top();
			stack.pop();
			std::cout << current->key << "  ";
			current = current->rightChild;
		}
	}
}

void binarySearchTree::expensivePath(double val)
{
	node* current = root;
	double cost = 0;
	node* endNode = this->findKey(val);
	if (endNode == nullptr)
	{
		std::cout << val << " does not exist in this tree\n";
	}
	std::cout << std::endl << "path: ";
	while (current != nullptr)
	{
		cost = cost + current->key;
		std::cout << current->key;
		if (current == endNode)
		{
			std::cout << "\nThe cost from root to " << val << " is " << cost << std::endl;
			break;
		}
		std::cout << " -> ";
		if (current->key > val)
		{
			current = current->leftChild;
		}
		else
		{
			current = current->rightChild;
		}
	}
}
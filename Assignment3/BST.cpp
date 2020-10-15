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

binarySearchTree::node* binarySearchTree::findParent(double val)
{
	node* prev = root;
	node* current = root;
	while (current != nullptr)
	{
		if (current->key == val)
		{
			return prev;
		}
		if (current->key > val)
		{
			prev = current;
			current = current->leftChild;
		}
		else
		{
			prev = current;
			current = current->rightChild;
		}
	}
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
		if (toDelete->leftChild == nullptr && toDelete->rightChild == nullptr) // Node to be deleted is a leaf node
		{
			if (toDelete == root)
			{
				root = nullptr;
			}
			std::cout << "Deleted " << toDelete->key << std::endl;
			node* parent = this->findParent(val);
			if (parent->rightChild == toDelete)
			{
				parent->rightChild = nullptr;
			}
			else
			{
				parent->leftChild = nullptr;
			}
		}
		else
		{
			if (toDelete->leftChild == nullptr && toDelete->rightChild != nullptr) // Node to be deleted has one right child
			{
				node* parent = this->findParent(val);
				if (parent->rightChild == toDelete)
				{
					parent->rightChild = toDelete->rightChild;
				}
				else
				{
					parent->leftChild = toDelete->rightChild;
				}
				std::cout << "Deleted1 " << toDelete->key << std::endl;
				delete toDelete;
			}
			else if (toDelete->leftChild != nullptr && toDelete->rightChild == nullptr) // Node to be deleted has one left child
			{
				node* parent = this->findParent(val);
				if (parent->rightChild == toDelete)
				{
					parent->rightChild = toDelete->leftChild;
				}
				else
				{
					parent->leftChild = toDelete->leftChild;
				}
				std::cout << "Deleted2 " << toDelete->key << std::endl;
				delete toDelete;
			}
			else // Node to be deleted has 2 children
			{
				node* parent = nullptr;
				node* temp;
				node* current = root;

				temp = current->rightChild;
				while (temp->leftChild != nullptr)
				{
					parent = temp;
					temp = temp->leftChild;
				}
				if (parent != nullptr)
					parent->leftChild = temp->rightChild;
				else
				{
					current->rightChild = temp->rightChild;
				}
				current->key = temp->key;
				std::cout << "Deleted3 " << temp->key << std::endl;
				delete temp;
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
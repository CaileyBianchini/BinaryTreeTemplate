#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"

BinaryTree::~BinaryTree()
{
}

void BinaryTree::insert(int value)
{
	//If the tree is empty, set the root to be a new node with the given value.
	if (isEmpty())
	{
		m_root = new TreeNode(value);
		return;
	}

	//Create a TreeNode pointer that will act as an iterator pointing to the current node and set it to the root.
	TreeNode* iterator = m_root;
	//Create a TreeNode pointer that will act as an iterator pointing to the parent of the current node and set it to the root.
	TreeNode* iterator2 = m_root;

	//Loop until the the current node iterator reaches a nullptr.
	while (iterator != nullptr)
	{
		//Check if the value we want to add to the tree is less than the value at the current node.
		if (value < iterator->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			iterator2 = iterator;
			//Change the current node to be the child to its left and continue.
			iterator = iterator->getLeft();
		}

		//Check if the value we want to add to the tree is greater than the value at the current node.
		else if (value > iterator->getData())
		{
			//Set the parent node to be the current node before the current node moves positions.
			iterator2 = iterator;
			//Change the current node to be the child to its right and continue.
			iterator = iterator->getRight();
		}

		//If the value is the same as a value already in the list return 
		else if (value == iterator->getData())
		{
			return;
		}
	}

	//If the value we want to add is less than the value of the parent node, insert the value to the left.
	//Otherwise, insert the value to the right.
	if (value < iterator2->getData())
	{
		iterator2->setLeft(new TreeNode(value));
	}
	else
	{
		iterator2->setRight(new TreeNode(value));
	}
}

void BinaryTree::remove(int value)
{
	//Create two TreeNode pointers: one to hold a reference to the node we want to remove
	//and another to hold a reference to its parent.
	TreeNode* refRemove = m_root;
	TreeNode* refParent= m_root;

	//Try to find the node that matches the value given and its parent in the tree.
	findNode(value, refRemove, refParent);
	//If the node cannot be found return.
	if (!find(value))
		return;


	//Check to see if the node has a right
	if (refRemove->hasRight())
	{
		//Initialize two iterators to find the node whose data will be copied and its parent.
		TreeNode* iter = new TreeNode();
		TreeNode* iter2 = new TreeNode();
		//Set the first iterator to point to the right child of the node we want to remove.
		refRemove->setRight(iter);

		//Loop while the first iterator has a value to its left
		while (iter->hasLeft())
		{
			//Set the second iterator to be the value of the first iterator.
			iter2->setData(iter->getData());
			//Set the first iterator to be the value to the left of it
			iter = iter->getLeft();

			//end loop
		}

		//Once the smallest value has been found, copy the data in first iterator to the node we want to remove.
		refRemove->setData(iter->getData());

		//Check if the second iterator has a left child.
		if (iter2->hasLeft())
		{
			//Check if the left child stores the same data as the node we wanted to remove.
			if (iter2->getRight()->getData() == refRemove->getData())
			{
				//Set the second iterators left child to be the first iterators right child.
				iter2->setLeft(iter->getRight());
			}
		}
		//Check if the second iterator has a right child.
		if (iter2->hasRight())
		{
			//Check if the right child contains the same data as the node we want to remove.
			if (iter2->getLeft()->getData() == refRemove->getData())
			{
				//Set the right child of the second iterator to be the right child of the first iterator.
				iter2->setRight(iter->getLeft());
			}
		}

		//Delete the first iterator
		delete(iter);
	}
	//Otherwise, if the node doesn't have a right child
	else
	{
		//check if the parent of the node to remove has a left child.
		if (refParent->hasLeft())
		{
			//Check if the data that the left child holds is the same as the data the node to remove holds.
			if (refParent->getLeft()->getData() == refRemove->getData())
			{
				//Set the left child of the parent node to be the left child of the node to remove.
				refParent->setLeft(refRemove->getLeft());
			}
		}

		//Check if the parent of the node to remove has a right child.
		if (refParent->hasRight())
		{
			//Check if the data the right child holds is the same as the data the node to remove holds.
			if (refParent->getRight()->getData() == refRemove->getData())
			{
				//Set the right child of the parent node to be the left child of the node to remove.
				refParent->setRight(refRemove->getLeft());
			}
		}
		//Check if the node we want to remove is the root.
		if (refRemove == m_root)
		{
			//Set the root to be its(?*) left child. <----- meant setting root at its roots left
			m_root = m_root->getLeft();
		}

		//Delete the pointer that points to the node to remove.
		delete(refRemove);
	}
}

TreeNode* BinaryTree::find(int value)
{
	//Initialize an iterator starting at the root.
	TreeNode* iter = m_root;

	//Loop through the tree while the iterator isn't nullptr.
	while (iter != nullptr)
	{
		//Check if the node has the data we want
		if (iter->getData() == value)
		{
			//Return the iterator
			return iter;
		}
		//If the node doesn't have the data we want, check to see if it's higher in value.
		else if (iter->getData() != value && value > iter->getData())
		{
			//Set the iterator to be its current right child.
			iter = iter->getRight();
			
		}
		//If the node doesn't have the data we want, check to see if it's lower in value.
		else if (iter->getData() != value && value < iter->getData())
		{
			//Set the iterator to be its current left child.
			iter = iter->getLeft();
		}
	}

	return nullptr;
}

void BinaryTree::draw(TreeNode* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

bool BinaryTree::findNode(int searchValue, TreeNode*& nodeFound, TreeNode*& nodeParent)
{
	//Create two iterators: one that will point to the current node to compare the search value to,
	//and the other to hold a reference to the parent.
	TreeNode* iter = m_root;
	TreeNode* iter2 = nodeParent;

	//Loop while the current node iterator isn't nullptr/
	while (iter)
	{
		//Check if the search value is the same as the current nodes data.
		if (searchValue == iter->getData())
		{
			//Set the node found argument to be the current node and the parent node to be the parent node iterator. 
			//In the parameters for that function, there's nodeParent, and the second line of comments says "and the other to hold a reference to the parent"
			nodeFound = iter;
			nodeParent = iter2;
			return true;
		}
		//Check if the search value is greater than the value at the current node.
		if (searchValue > iter->getData())
		{
			//Set the parent node to be the current node.
			iter2 = iter;
			//Set the current node to be the child to the right of the current node.
			iter = iter->getRight();
		}
		//Check if the search value is less than the value at the current node.
		if (searchValue < iter->getData())
		{
			//Set the parent node to be the current node.
			iter2 = iter;
			//Set the current node to be its left child.
			iter = iter->getLeft();
		}
	}

	//Return false.
	return false;
}

void BinaryTree::draw(TreeNode* currentNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	//Decrease the horizontal space as the nodes draw
	horizontalSpacing /= 2;

	//draws the left child if this node has one
	if (currentNode)
	{
		if (currentNode->hasLeft())
		{
			//Draws a line between the left child and the current
			DrawLine(x, y, -horizontalSpacing, y + 80, RED);
			//Draws the left child
			draw(currentNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		//Draws the right child if this node has one
		if (currentNode->hasRight())
		{
			//Draws a line between this child and the current node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			//Draws the right child
			draw(currentNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		//draws the current node
		currentNode->draw(x, y, (selected == currentNode));
	}

}

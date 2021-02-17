#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#pragma once

class TreeNode;

class BinaryTree
{
public:

	BinaryTree() { m_root = nullptr; };
	~BinaryTree();

	///<summary>
	///Returns true if the root is set to nullptr.
	///<summary>
	bool isEmpty() const { return m_root == nullptr; };

	///<summary>
	///
	///<summary>
	void insert(int value);

	///<summary>
	///
	///<summary>
	void remove(int value);

	///<summary>
	///
	///<summary>
	TreeNode* find(int value);

	///<summary>
	///
	///<summary>
	void draw(TreeNode* selected = nullptr);

private:
	///<summary>
	///
	///<summary>
	bool findNode(int searchValue, TreeNode*& nodeFound, TreeNode*& nodeParent);

	///<summary>
	///
	///<summary>
	void draw(TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

	TreeNode* m_root;
};

#endif
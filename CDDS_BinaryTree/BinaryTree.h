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
	void insert(int value);
	void remove(int value);
	TreeNode* find(int value);

	///<summary>
	///Draws the Tree and marks the given Node as its left child
	///<summary>
	/// <param name="selected"></param>
	void draw(TreeNode* selected = nullptr);

private:
	///<summary>
	/// Finds the node with the given value and its parent
	///<summary>
	/// <param name="searchValue">The value to be looked for</param>
	/// <param name="nodeFound">The variable that will be changed to the Node being looked for if found</param>
	/// <param name="nodeParent">The parent of the Node being looked for if found</param>
	/// <returns>Whether or not the Node was found</returns>
	bool findNode(int searchValue, TreeNode*& nodeFound, TreeNode*& nodeParent);

	///<summary>
	/// Calls draw for every Node in the Tree
	///<summary>
	/// <param name="">The Node being drawn</param>
	/// <param name="x">X position of the Node being drawn</param>
	/// <param name="y">Y position of the Node being drawn</param>
	/// <param name="horizontalSpacing"></param>
	/// <param name="selected"></param>
	void draw(TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

	TreeNode* m_root = nullptr;
};

#endif
#include "TreeNode.h"
#include <iostream>
#include "raylib.h"

TreeNode::TreeNode(int value)
{
	m_value = value;
}

void TreeNode::draw(int x, int y, bool selected)
{
    //creates an array to store the converted value to a string.
	static char buffer[10];

	//converts int to string
	sprintf(buffer, "%d", m_value);

	//Draws the outer circle of the node
	DrawCircle(x, y, 30, YELLOW);

	//If the mnode is selected, make it green if not its black
	if (selected)
		DrawCircle(x, y, 28, GREEN);
	else
		DrawCircle(x, y, 28, BLACK);

	//draws the text in the center of the node
	DrawText(buffer, x - 12, y - 12, 12, WHITE);
}
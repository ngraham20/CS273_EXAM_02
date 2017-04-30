#include <iostream>
#include "TreeNode.h"
#include "WordNode.h"

int main()
{
	TreeNode* root = new TreeNode(); // creates the root node

	root->push("hike");
	root->push("hill");
	root->push("trail");
	root->push("the");

	root->push("%"); // should not show up on the register
	root->push("&hello"); // should not show up on the register

	return 0;
}
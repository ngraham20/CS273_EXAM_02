#include "TreeNode.h"



TreeNode::TreeNode()
{
}

std::string TreeNode::search(TreeNode * node, std::string word, int depth)
{
	const int number = 26;
	for (int i = 0; i < number; i++)
	{
		if (letters.at(i) == word)
		{
			TreeNode* newNode = children.at(i);
			return search(newNode, word);
		}
	}
}

std::string TreeNode::search(TreeNode * node, std::string word)
{
	return search(node, word, 0); // calls the search function with a default depth of 0
}

std::string TreeNode::getLetter() { return letter; }

std::vector<TreeNode*> TreeNode::getChildren()
{
	return children;
}

std::vector<std::string> TreeNode::getLetters()
{
	return letters;
}


TreeNode::~TreeNode()
{
}

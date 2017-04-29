#pragma once
#include <vector>
#include <string>

class TreeNode
{
public:

	TreeNode();
	std::string search(TreeNode* node, std::string word, int depth);
	std::string search(TreeNode* node, std::string word);

	std::string getLetter();
	std::vector<TreeNode*> getChildren();
	std::vector<std::string> getLetters();

	~TreeNode();

private:
	std::vector<TreeNode*> children; // a vector of all the children this node has
	std::vector<std::string> letters; // a vector of the letters of the children this node has

	std::string letter; // this is the letter contained by this node
};


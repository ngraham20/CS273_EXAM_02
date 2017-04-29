#pragma once
#include <vector>
#include <string>
#include <iostream>

class TreeNode
{
public:

	TreeNode();
	TreeNode(char); // creates a TreeNode with a default letter
	std::string search(TreeNode* node, std::string word);

	char getLetter();
	std::vector<TreeNode*> getChildren();
	std::vector<char> getLetters();

	bool push(std::string word);





	~TreeNode();

private:

	bool push(std::string word, int depth);
	std::string search(TreeNode* node, std::string word, int depth);

	std::vector<TreeNode*> children; // a vector of all the children this node has
	std::vector<char> letters; // a vector of the letters of the children this node has

	char letter; // this is the letter contained by this node

	enum exceptions
	{
		WordNotFound
	};
};


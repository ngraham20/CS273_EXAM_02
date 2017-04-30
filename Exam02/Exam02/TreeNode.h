#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class TreeNode
{
public:

	TreeNode();

	char getLetter();
	std::vector<TreeNode*> getChildren();
	std::vector<char> getLetters();

	bool push(std::string word);

	bool readFile(std::string file);

	std::vector<std::string> find(std::string substring);

	~TreeNode();

private:

	TreeNode(char); // creates a TreeNode with a default letter

	bool push(std::string word, int depth);

	std::string search(TreeNode* node, std::string word, int depth);

	std::string search(TreeNode* node, std::string substring); // this will only be used internally

	// std::vector<std::string> find(std::string substring);

	std::vector<TreeNode*> children; // a vector of all the children this node has
	std::vector<char> letters; // a vector of the letters of the children this node has

	char letter; // this is the letter contained by this node

	enum exceptions
	{
		WordNotFound
	};
};


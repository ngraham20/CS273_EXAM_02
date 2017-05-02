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
	std::vector<std::string> findAll();

	~TreeNode();

private:

	static int wordCount;

	void find(std::vector<std::string> &vec, std::string substring);

	TreeNode(char); // creates a TreeNode with a default letter

	bool push(std::string word, int depth);

	TreeNode* search(std::string word); // searches from the root

	TreeNode* search(TreeNode* node, std::string word, int depth);

	TreeNode* search(TreeNode* node, std::string substring); // this will only be used internally

	// std::vector<std::string> find(std::string substring);

	std::vector<TreeNode*> children; // a vector of all the children this node has
	std::vector<char> letters; // a vector of the letters of the children this node has

	char letter; // this is the letter contained by this node

	bool isWordEnd;

	enum exceptions
	{
		WordNotFound
	};
};


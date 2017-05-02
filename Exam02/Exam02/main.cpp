#include <iostream>
#include <vector>
#include <string>
#include "TreeNode.h"
#include "WordNode.h"

int main()
{
	TreeNode* root = new TreeNode(); // creates the root node

	//root->push("hike");
	//root->push("hill");
	//root->push("trail");
	//root->push("the");

	//root->push("%"); // should not show up on the register
	//root->push("&hello"); // should not show up on the register

	std::string filename = ".\\word.txt";
	root->readFile(filename.c_str());

	std::cout << "All words have been added!" << std::endl;
	std::cout << "(1): Search for a subword" << std::endl;
	std::cout << "(2): Quit" << std::endl;
	std::cout << ">>";

	std::string input;
	std::cin >> input;

	std::vector<std::string> wordList;

	if (input != "2")
	{
		std::cout << "Type the subword (without capital letters) that you would like to search for, or type 'all' to print all words." << std::endl;
		std::cin >> input;

		if (input != "all")
		{
			wordList = root->find(input);
		}

		else if (input == "all")
		{
			wordList = root->findAll();
		}
	}
		std::cout << "------------------------------------" << std::endl;
		for (int i = 0; i < wordList.size(); i++)
		{
			std::cout << wordList.at(i) << std::endl;
		}
		std::cout << "------------------------------------" << std::endl;
	return 0;
}
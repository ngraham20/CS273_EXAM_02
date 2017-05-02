#include <iostream>
#include <vector>
#include <string>
#include "TreeNode.h"
#include "WordNode.h"

int main()
{
	TreeNode* root = new TreeNode(); // creates the root node

	std::vector<std::string> wordList;

	std::string input;

	do
	{
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "Welcome to the word processing program!" << std::endl;
		std::cout << "(1): Add words to system" << std::endl;
		std::cout << "(2): Search for a subword" << std::endl;
		std::cout << "(3): Quit" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << ">>";
		std::cin >> input;

		if (input == "1")
		{
			std::cout << "Type the name of the file you would like to import" << std::endl;
			std::cout << ">>";
			std::cin >> input;

			std::string filename = ".\\" + input;
			root->readFile(filename.c_str());
		}
		if (input == "2")
		{
			std::cout << "Type the subword you would like to search or type 'all' to return all words." << std::endl;
			std::cout << ">>";
			std::cin >> input;
			std::cout << "------------------------------------" << std::endl;

			if (input == "all")
			{
				wordList = root->findAll();
			}
			else
				wordList = root->find(input);

			std::cout << "------------------------------------" << std::endl;
			for (int i = 0; i < wordList.size(); i++)
			{
				std::cout << wordList.at(i) << std::endl;
			}
			std::cout << "------------------------------------" << std::endl;
		}
	} while (input != "3");
	return 0;
}
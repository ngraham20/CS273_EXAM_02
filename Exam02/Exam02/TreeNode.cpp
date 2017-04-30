#include "TreeNode.h"



TreeNode::TreeNode() // creates the root
{
}

TreeNode::TreeNode(char letter)
{
	this->letter = letter;
}

std::string TreeNode::search(TreeNode * node, std::string word, int depth) // TODO fix this to comply with PDF
{
		if (depth == word.length()) // base case, if this node is the last in the word
		{
			return std::to_string(letter); // return this letter through to the recursion
		}

		for (int i = 0; i < letters.size(); i++) // loops through the vector of assigned letters
		{
			if (letters.at(i) == word[depth]) // if the letter exists
			{
				TreeNode* newNode = children.at(i); // search the node at the same index
				return letter + search(newNode, word, depth + 1); // returns the letter of the current node,
																  // plus that of the next node
			}
		}
}

std::string TreeNode::search(TreeNode * node, std::string word)
{
	return search(node, word, 0); // calls the search function with a default depth of 0
}

char TreeNode::getLetter() { return letter; }

std::vector<TreeNode*> TreeNode::getChildren() { return children; }

std::vector<char> TreeNode::getLetters() { return letters; }

bool TreeNode::push(std::string word)
{
	return push(word, 0); // begins pushing from the root node if it can
}

bool TreeNode::readFile(std::string file)
{
	std::ifstream input;

	input.open(file.c_str()); // opens word.txt

	if (!input.fail())
	{
		while (!input.eof()) // loops through all words
		{
			std::string word = "";
			input >> word;
			push(word);
			std::cout << word << std::endl;
		}
		input.close();
		return true;
	}
	else
	{
		std::cout << "Failed to open file. . .\n";
		return false;
	}

}

// pushes an entire word onto the tree, starting from the current parent
bool TreeNode::push(std::string word, int depth)
{
	// makes sure that all letters are valid letters
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] < 'a' || word[i] > 'z') // makes sure all letters in the array are valid lowercase letters
		{
			return false; // if this loop finds a non lowercase letter or a symbol, it returns out
		}
	}

	for (int i = 0; i < letters.size(); i++) // loop through all letters in the current node
	{
		if (letters.at(i) == word[depth]) // if the letter is found, search to the end of it
		{
			return children.at(i)->push(word, depth + 1);
		}
	}

	// if the letter is not found in the vector, then create it
	letters.push_back(word[depth]);

	TreeNode* newNode = new TreeNode(word[depth]);
	children.push_back(newNode); // pushes a new child onto the current node's vector

	if (depth == word.length() - 1)
	{
		return true; // base case, we have found the word
	}

	return newNode->push(word, depth + 1); // pushes the rest of the word onto the next node to continue building
	
}


TreeNode::~TreeNode()
{
}

#include "TreeNode.h"


int TreeNode::wordCount = 0;

TreeNode::TreeNode() // creates the root
{
	isWordEnd = false;
}

TreeNode::TreeNode(char letter)
{
	this->letter = letter;
	this->isWordEnd = false;
}

TreeNode* TreeNode::search(TreeNode * node, std::string word, int depth) // returns a specific word
{
	if (depth == word.length()) // base case, if this node is the last in the word
		{
			return node; // return the node
		}

		for (int i = 0; i < node->letters.size(); i++) // loops through the vector of assigned letters to find the 
		{										 // desired letter

			if (node->letters.at(i) == word[depth]) // if the letter exists
			{
				return search(node->children.at(i), word, depth + 1); // returns the letter of the current node,
																  // plus that of the next node
			}
		}
		return nullptr;
}

TreeNode* TreeNode::search(TreeNode * node, std::string word)
{
	return search(node, word, 0); // calls the search function from the current "root"
}

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
			std::string word;
			input >> word;
			push(word);

			wordCount++;
			std::cout << "[" << std::to_string(wordCount) << "] Added: " << word << std::endl;
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

std::vector<std::string> TreeNode::find(std::string substring)
{
	TreeNode* node = search(substring); // finds the node for the last letter in the substring

	std::vector<std::string> vec;

	node->find(vec, substring.substr(0,substring.size()-1)); // begining from node, find ALL words, putting them into a vector

	return vec;
}

std::vector<std::string> TreeNode::findAll()
{
	std::vector<std::string> vec;

	for (int i = 0; i < letters.size(); i++) // loop through all letters
	{
		children.at(i)->find(vec, "");
	}

	return vec;
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

	// checks the base case before continuing, in case the word already exists in the tree
	if (depth == word.length())
	{
		// base case, we have found the word
		this->isWordEnd = true;
		return true;
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

	return newNode->push(word, depth + 1); // pushes the rest of the word onto the next node to continue building
	
}

TreeNode * TreeNode::search(std::string word)
{
	for (int i = 0; i < letters.size(); i++)
	{
		if (letters.at(i) == word[0]) // if the root contains the first letter in the target word
		{
			return search(children.at(i), word, 1); // begin the search for the target word, begining with the next letter
		}
	}
	return nullptr;
}

void TreeNode::find(std::vector<std::string> &vec, std::string substring)
{
	if (isWordEnd) // found a word, push it on
	{
		vec.push_back(substring + letter);
	}

	for (int i = 0; i < letters.size(); i++) // loop through all children
	{
		children.at(i)->find(vec, substring + letter); // find the children
	}
}

char TreeNode::getLetter() { return letter; }

std::vector<TreeNode*> TreeNode::getChildren() { return children; }

std::vector<char> TreeNode::getLetters() { return letters; }


TreeNode::~TreeNode()
{
}

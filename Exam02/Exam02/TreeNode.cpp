#include "TreeNode.h"



TreeNode::TreeNode() // creates the root
{
}

TreeNode::TreeNode(char letter)
{
	this->letter = letter;
}

std::string TreeNode::search(TreeNode * node, std::string word, int depth)
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
		// if neither of the cases above return a value, it must not exist,
		// therefore we will push the rest of the word onto the tree and then return

		push(word.substr(depth, word.length()), depth); // pushes the rest of the word onto the tree,
												 // starting from the current node
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

// pushes an entire word onto the tree, starting from the current parent
bool TreeNode::push(std::string word, int depth)
{

	for (int i = 0; i < letters.size(); i++) // loop through all letters in the current node
	{
		if (letters.at(i) == word[depth]) // if the letter is found, search to the end of it
		{
			search(children.at(i), word, depth + 1);
		}
	}

	// if the letter is not found in the vector, then create it
	letters.push_back(word[depth]);

	TreeNode* newNode = new TreeNode(word[depth]);
	children.push_back(newNode); // pushes a new child onto the current node's vector

	if (depth == word.length() - 1)
	{
		return true;
	}

	return newNode->push(word, depth+1); // pushes the rest of the word onto the next node to continue building
}


TreeNode::~TreeNode()
{
}

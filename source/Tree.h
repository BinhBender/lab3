#include <string>
#include <cmath>
#pragma once

//Node for the trees that only has two pointers
class HuffManTree;
struct Node{
	char data = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

class HuffManTree{
public:

	HuffManTree();
	//Makes a tree with a node
	HuffManTree(Node*);
	
	//creates a tree given the height
	HuffManTree(int);

	~HuffManTree();

	//returns the height of the class @
	int Height();
	
	//Boolean of if the current size is equal to the max size or not.
	bool IsFull();
	
	//Returns a pointer to a leaf node
	//input will be read from its binary code
	//from the first digit to the last
	//Length of travel will be the height
	Node* GetLeaf(int);
	
	void append(char);
	

	
	
private:

	int height;
	int size;
	int leaf_nodes_filled_up;
	Node* root;
	
	//takes in a height and will make tree
	void deleteTree(Node*);
	Node* generatetree(int);
};

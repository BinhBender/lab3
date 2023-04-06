#include <string>
#include <cctype>
#include "queue.h"
#include <iostream>
#pragma once

//Node for the trees that only has two pointers
struct BTNode{
	char data = 0;
	BTNode* left = nullptr;
	BTNode* right = nullptr;
};

/*
This tree uses strings of 1 & 0s to determine its path
The characters of the path is read of left to right

*/
class BinaryTree{
public:

	BinaryTree();
	//Makes a tree with a node
	BinaryTree(BTNode*);
	
	//creates a tree given the height
	//BinaryTree(int);

	~BinaryTree();

	//returns the height of the class @
	int Height();
	

	int GetSize();
	//Returns a pointer to a leaf node
	//input will be read from its binary code
	//from the first digit to the last
	//Length of travel will be the height
	BTNode* Traverse(std::string);
	
	void append(char, std::string);
	int max_size_of_height();
	void print();
	std::string find_next();
	
private:

	int height;
	int size;
	//int leaf_nodes_filled_up;
	BTNode* root;
	
	void print(BTNode* parent);
	std::string findnextposition(BTNode* parent);
	//takes in a height and will make tree
	void deleteTree(BTNode*);
	BTNode* generatetree(int);
};

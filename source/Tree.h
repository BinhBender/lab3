#include <string>
#pragma once

//Node for the trees that only has two pointers
class HuffManTree;
struct Node{
	std::string data;
	Node* left;
	Node* right;
};

//This is a huffman tree class template

//Ttravel is for the pathing
//TData is for the 

//This class will return relevant data such as its 
//height, size, max capacity size and if it has reached max size

class HuffManTree{
public:
	//returns the height of the class @
	int Height();
	
	//Returns the max size
	int MaxSizeUntilNextHeight();
	
	//Returns the amount of nodes in the tree
	int CurrentSize();
	
	//Boolean of if the current size is equal to the max size or not.
	bool IsFull();
	
	//Returns a pointer to a leaf node
	//input will be read from its binary code
	//from the first digit to the last
	//Length of travel will be from height
	Node* GetLeaf(int);
	
	void append(Tdata);
	
	//empty constructor
	HuffManTree();
	
	//Makes a tree with a node
	HuffManTree(Node*);
	
	//creates a tree with all the leafs but with no data.
	HuffManTree(int);
	
	
private:
	int height;
	int size;
	int leaf_nodes_filled_up;
	Node* root;
	
	
};

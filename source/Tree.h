#include <string>
#pragma once

//Node for the trees that only has two pointers
class HuffManTree;
class Node{

private:
	std::string data;
	Node* left;
	Node* right;
	
public:
	Node();
	~Node();
friend class HuffManTree;
};

//This is a huffman tree class template

//Ttravel is for the pathing
//TData is for the 

//This class will return relevant data such as its 
//height, size, max capacity size and if it has reached max size

template<typename Ttravel, typename Tdata>
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
	
	//takes in an array
	Tdata Data(Ttravel*);
	
	void append(Tdata);
	
	//empty constructor
	HuffManTree();
	
	//Makes a tree with a node
	HuffManTree(Node*);
	
	//creates a tree with all the leafs but with no data.
	HuffManTree(int);
	
	
private:
	
	Node* root;
	
	
};

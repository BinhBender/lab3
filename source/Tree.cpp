#include "Tree.h"

//empty constructor
HuffManTree::HuffManTree(){
	root = nullptr;
	height = 0;
	size = 0;
}
	
//Makes a tree with a node
HuffManTree::HuffManTree(Node* input){
	root = input;
	//find the height of the subtree
	Node* trav = root;
	int count = 0;
	//We have to get to a leaf
	//count up by 12 every time
	while(trav == nullptr){
		trav = trav->left;
		count++;
	}
	
	height = count;
}
	
//creates a tree with all the leafs but with no data.
HuffManTree::HuffManTree(int initheight){
	
	
}
/*
 * This traverses via the binary code in an integer
 * ie 010101001
 * 0 will be the "left" and 1 will be "right"
 * given the binary, we will check the first bit
 * and bitshift right until we get reach the height.
 * */
Node* HuffManTree::GetLeaf(int input){
	Node* trav = root;
	for(int i = 0; i < height; i++){
		
		if((input & 1) == true){
			
		}
	}
}
//returns the height of the class @
int HuffManTree::Height(){
	return height;
}

//Returns the max size
int HuffManTree::MaxSizeUntilNextHeight(){
	
}

//Traverses through the tree
int size_finder(Node* n){
	if(n == nullptr) return 0;
	return size_finder(n.left) + size_finder(n.right) + 1;
}
//Returns the amount of nodes in the tree
int HuffManTree::CurrentSize(){
	return size_finder(root);
}
	
//Boolean of if the current size is equal to the max size or not.
bool HuffManTree::IsFull(){
	return CurrentSize() >= MaxSizeUntilNextHeight();
}
	
	
void HuffManTree::append(Tdata){
	
}
	

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
	leaf_nodes_filled_up = 0;
	
	//find the height of the subtree
	Node* trav = root;
	int newheight = 0;
	
	
	//Traverses until it reaches a 
	while(trav->data == ' '){
		
		trav = trav->left;
		
		newheight++;
	}
	
	height = newheight;
}

//creates a tree with all the leafs but with no data.
HuffManTree::HuffManTree(int initheight){
	root = nullptr;
	size = 0;
	height = initheight;
	leaf_nodes_filled_up = 0;
	
	root = generatetree(height);
}

HuffManTree::~HuffManTree(){
	deleteTree(root);
}

void HuffManTree::deleteTree(Node* input){
	
	if(input == nullptr) return;
	
	
	deleteTree(input->left);
	deleteTree(input->right);
	
	
	delete input;
}


Node* HuffManTree::generatetree(int Height){
	
	//Base case, a 0 node tree
	if(Height == 0) return nullptr;
	

	Node* newnode = new Node();
	
	newnode->left = generatetree(Height -1);
	newnode->right = generatetree(Height - 1);
	
	return newnode;
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
			trav = trav->right;
		}else{
			trav = trav->left;
		}
	}
	
	return trav;
}
//returns the height of the class @
int HuffManTree::Height(){
	return height;
}


//Traverses through the tree
int size_finder(Node* n){
	if(n == nullptr) return 0;
	return size_finder(n->left) + size_finder(n->right) + 1;
}
	
//Boolean of if the current size is equal to the max size or not.
bool HuffManTree::IsFull(){
	
	//In a binary tree where we only care about its leaf nodes
	//The # of leafs are counted as 2^n with n = height - 1 
 	return pow(2, height-1) > leaf_nodes_filled_up;

}	
	
//finds the first open spot
void HuffManTree::append(char c){
	
	//These trees are meant to have static height.
	if(IsFull()) return;
	
	Node* trav = root;
	int path = leaf_nodes_filled_up;
	for(int i = 0; i < height - 1; i++){
		if( (path & 0) == 0) // go left
		{
			trav = trav->left;
		}
		else if( (path & 1)  == 1)// go right
		{
			trav = trav->right;
		}
		
		path = path >> 1;
	}
	leaf_nodes_filled_up++;
	trav->data = c;
	
}
	

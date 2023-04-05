#include "Tree.h"

//empty constructor
BinaryTree::BinaryTree(){
	root = new BTNode;
	height = 0;
	size = 0;
}
	
//Makes a tree with a node
BinaryTree::BinaryTree(BTNode* input){

	
	root = input;
	
	//find the height of the subtree
	BTNode* trav = root;
	int newheight = 0;
	
	
	//Traverses until it reaches a 
	while(trav->data == ' '){
		
		trav = trav->left;
		
		newheight++;
	}
	
	height = newheight;
}
/*
//creates a tree with all the leafs but with no data.
BinaryTree::BinaryTree(int initheight){
	root = nullptr;
	size = 0;
	height = initheight;
	
	root = generatetree(height);
}*/

BinaryTree::~BinaryTree(){
	deleteTree(root);
}

//
void BinaryTree::deleteTree(BTNode* input){
	
	//if the pointer is empty, do nothing
	if(input == nullptr) return;
	
	
	deleteTree(input->left);
	deleteTree(input->right);
	
	
	delete input;
}


BTNode* BinaryTree::generatetree(int Height){
	
	//Base case, a 0 node tree 
	if(Height == 0) return nullptr;
	

	BTNode* newnode = new BTNode;
	
	newnode->left = generatetree(Height -1);
	newnode->right = generatetree(Height - 1);
	
	return newnode;
}



BTNode* BinaryTree::Traverse(std::string path){
	BTNode* trav = root;
	
	for(unsigned int i = 0; i < path.size(); i++){
		BTNode* dummy = trav;
		if(path[i] == '0'){
			//move left
			trav = trav->left;
			
			//if there is an empty node to the left, make new node
			if(trav == nullptr){
				trav = new BTNode;
				dummy->left = trav;
			}
			
		}else if(path[i] == '1'){
			//move right
			trav = trav->right;
			
			//If the node trav went to is empty, create a new node
			if(trav == nullptr){
				trav = new BTNode;
				dummy->right = trav;
			}
		}
		
	}
	
	return trav;
}

//inspired from zybook
int findheight(BTNode* n) {
	if(n == nullptr) return 0;
	
	else { 
		int left = findheight(n->left);
		int right = findheight(n->right);
		
		return 1 + (left > right ? left : right);
	}
}
//returns the height of the class @
int BinaryTree::Height(){
	return findheight(root);
}


//Traverses through the tree
int size_finder(BTNode* n){
	
	if(n == nullptr) return 0;
	
	return size_finder(n->left) + size_finder(n->right) + 1;
}
int BinaryTree::GetSize(){
	
 	return size_finder(root);

}	
	
//finds the first open spot
void BinaryTree::append(char value,std::string path){
	for(unsigned int i = 0; i < path.size(); i++){
		if(isalpha(path[i])) return;
	}
	
	size++;
	BTNode* foundnode = Traverse(path);

	foundnode->data = value;
}
	

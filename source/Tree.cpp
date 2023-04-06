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

//Unused
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
		//std::cout << "Checking alpha" << std::endl;
		if(isalpha(path[i])) return;
	}
	
	size++;
	BTNode* foundnode = Traverse(path);

	foundnode->data = value;
}

void BinaryTree::print(BTNode* parent){
	if(parent == nullptr) return;
	
	print(parent->left);
	
	std::cout << parent->data << " ";
	
	print(parent->right);
	
}
//taken from zybook
void BinaryTree::print(){
	print(root);
	std::cout << std::endl;
}	

int twonplus1(int i){
	if(i == 1) return 1;
	
	return (2 * twonplus1(i-1)) + 1;
	
}

//Finds the next SHORTEST path in the tree with a left path bias
std::string BinaryTree::findnextposition(BTNode* parent){
	if(parent == nullptr) return "";
	
	std::string left = "0" + findnextposition(parent->left);
	std::string right="1" + findnextposition(parent->right) ;
	
	
	//I am the best
	if(left.size() > right.size()){
		return right;
	}
	return left;
	
}

std::string BinaryTree::find_next(){
	return findnextposition(root);
}
int BinaryTree::max_size_of_height(){
	int max = twonplus1(height);
	
	return max;
	
}

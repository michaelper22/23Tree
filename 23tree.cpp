#include <iostream>
#include <fstream>
using namespace std;

class Node{
	public:
	
	Node* parent;
	int key1;
	int key2;
	Node* child1;
	Node* child2;
	Node* child3;
	
	// Constructor for internal node
	Node(Node* newParent, int newKey1, int newKey2, Node* newChild1, Node* newChild2, Node* newChild3){
		parent = newParent;
		key1 = newKey1;
		key2 = newKey2;
		child1 = newChild1;
		child2 = newChild2;
		child3 = newChild3;
	} //Node()
	
	// Constructor for leaf node
	Node(Node* newParent, int data){
		parent = newParent;
		key1 = -1;
		key2 = data;
	}//Node()
	
	void printNode(){
	
	}//printNode()
};//Node class

class Tree{
	public:
	
	Node* root;
	
	Tree(Node* newRoot){
		root = newRoot;
	}//Tree()
	
	void insert(int data){
		Node* spot = findSpot(root, data);
		
		
		// Case 0: Spot has 0 children
		if(spot->child1 == NULL && spot->child2 == NULL && spot->child3 == NULL)
			spot->child1 = new Node(spot, data);
			
		// Case 1: Spot has 1 child
		if(spot->child1 != NULL && spot->child2 == NULL && spot->child3 == NULL){
			if(spot->child1->key2 <= data)
				spot->child2 = new Node(spot, data);
			else {
				spot->child2 = spot->child1;
				spot->child1 = new Node(spot, data);
			}
		}
			
	}//insert()
	
	void printTree(Node* nodeToPrint){
		
	}
	
	private:
	Node* findSpot(Node* currentNode, int data){
		if(currentNode->child1->key1 == -1)
			return currentNode;
		
		else if(data < currentNode->key1)
			return findSpot(currentNode->child1, data);
		
		else if((data >= currentNode->key1 && data > currentNode->key2) || currentNode->key2 == -1)
			return findSpot(currentNode->child2, data);
		
		else if(data >= currentNode->key2 && currentNode->key2 == -1)
			return findSpot(currentNode->child3, data);
	}//findSpot()
};//Tree class


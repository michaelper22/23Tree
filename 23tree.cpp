#include <iostream>
#include <fstream>
using namespace std;

class Node{
	public:
	
	Node* parent;
	Node* key1;
	Node* key2;
	Node* child1;
	Node* child2;
	Node* child3;
	
	Node(Node* newParent, Node* newKey1, Node* newKey2, Node* newChild1, Node* newChild2, Node* newChild3){
		parent = newParent;
		key1 = newKey1;
		key2 = newKey2;
		child1 = newChild1;
		child2 = newChild2;
		child3 = newChild3;
	} //Node()
	
	void printNode(){
	
	}//printNode()
};//Node class

class Tree{
	public:
	
	Node* root;
	
	Tree(Node* newRoot){
		root = newRoot;
	}//Tree()
	
	void insert(Node* insertNode){
	
	}//insert()
	
	void printTree(Node* nodeToPrint){
		
	}
	
	private:
	Node* findSpot(data){
	
	}
	
};//Tree class


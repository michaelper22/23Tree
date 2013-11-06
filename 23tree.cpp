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
	
	void printNode(fstream& outstream){
		outstream << "(parent = ";
		
		if(parent!=NULL)
			outstream << parent->key1;
		else
			outstream << "0";
		
		outstream << ", key1 = " << key1;
		outstream << ", key2 = " << key2 << ", child1 = ";
		
		if(child1 != NULL)
			outstream << child1->key1;
		else 
			outstream << "-1";
		
		outstream << ", child2 = ";
		
		if(child2 != NULL)
			outstream << child2->key1;
		else	
			outstream << "-1";
		
		outstream << ", child3 = ";
		
		if(child3 != NULL)
			outstream << child2->key1;
		else	
			outstream << "-1";
		
		outstream << ")" << endl;
	}//printNode()
};//Node class

class Tree{
	public:
	
	Node* root;
	
	Tree(){
		root = new Node(NULL, -1, -1, NULL, NULL, NULL);
	}//Tree()
	
	void insert(int data){
		cout << "In insert()" << endl;
		Node* spot = findSpot(root, data);
		cout << "found spot" << endl;
		
		
		// Case 0: Spot has 0 children
		if(spot->child1 == NULL && spot->child2 == NULL && spot->child3 == NULL){
			spot->child1 = new Node(spot, data);			
		}
			
		// Case 1: Spot has 1 child
		else if(spot->child1 != NULL && spot->child2 == NULL && spot->child3 == NULL){
			if(spot->child1->key2 <= data)
				spot->child2 = new Node(spot, data);
			else {
				spot->child2 = spot->child1;
				spot->child1 = new Node(spot, data);
			}
		}
		
		// Case 2: Spot has 2 children
		else if(spot->child1 != NULL && spot->child2 != NULL && spot->child3 == NULL){
			// Modified bubble sort from beginning of semester
			// to put children in ascending order
			int children[3] = {spot->child1->key2, spot->child2->key2, data};
			int begin=0, end=2, swapflag=1, walker;

			while(end>begin && swapflag>0){
				swapflag=0;
				walker=begin;		
				while(walker < end){
					if(children[walker] > children[walker+1]){
						//swap
						int temp=children[walker];
						children[walker]=children[walker+1];
						children[walker+1]=temp;
						swapflag++;
						walker++;
					}//if
					end--;
				}//while
			}//while
			spot->child1->key2 = children[0];
			spot->child2->key2 = children[1];
			spot->child3->key2 = children[2];
		}//if
		// Case 3: Spot has 3 children
		// code to come
	}//insert()
	
	void printTree(Node* nodeToPrint, fstream& outstream){
		if(nodeToPrint==NULL)
			return;
		else{
			nodeToPrint->printNode(outstream);
			printTree(nodeToPrint->child1, outstream);
			printTree(nodeToPrint->child2, outstream);
			printTree(nodeToPrint->child3, outstream);
		}//else
	}//printTree()
	
	Node* findSpot(Node* currentNode, int data){
		cout << "in findSpot()" << endl;
		if(currentNode->child1 == NULL || currentNode->child1->key1 == -1)
			return currentNode;
		
		else if(data < currentNode->key1)
			return findSpot(currentNode->child1, data);
		
		else if((data >= currentNode->key1 && data > currentNode->key2) || currentNode->key2 == -1)
			return findSpot(currentNode->child2, data);
		
		else if(data >= currentNode->key2 && currentNode->key2 == -1)
			return findSpot(currentNode->child3, data);
	}//findSpot()
};//Tree class

int main(){
	fstream infile;
	infile.open("infile.txt", fstream::in);
	
	if(!infile.is_open()){
		cout << "Error opening infile.txt, quitting." << endl;
		return 0;
	}//if
	
	fstream outfile;
	outfile.open("outfile.txt", fstream::out | fstream::trunc);
	
	if (!outfile.is_open()) {
		cout << "Error opening outfile.txt, quitting." << endl;
		return 0;
	}//if
	
	Tree* tree = new Tree();
	
	while(!infile.eof()){
		int input;
		infile >> input;
		tree->insert(input);
		cout << "Calling printTree()" << endl;
		tree->printTree(tree->root, outfile);
	}//while
	
	return 0;
}
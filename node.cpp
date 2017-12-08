//Node class implementation
//Frank Lee, 1/11
//updated for proj. 2 7/12

#include "node.h"
#include <string>
using std::string;

//constructor

Node::Node(){
	integer1=0;
	integer2=0;
	leftNode=NULL;
	rightNode=NULL;
	myoperator='f';
	parent=NULL;
}

//methods

void Node::setoperator(char op){
	if (op != '+' && op != '-' && op != '*' && op!= '/'){
		return;
	}
	myoperator=op;
}

void Node::setleftNode(Node* leftpointer){
	leftNode=leftpointer;
}

void Node::setrightNode(Node* rightpointer){
	rightNode=rightpointer;
}

void Node::setvariable(){
	variable='x';
}

void Node::setparent(Node* theparent){
	parent=theparent;
}

void Node::setinteger1(int myvalue){		//perhaps need to check if myvalue lies within [1,9]
	integer1=myvalue;
}

void Node::setinteger2(int myvalue){
	integer2=myvalue;
}

//observers

Node* Node::left() const{
	return leftNode;
}

Node* Node::right() const{
	return rightNode;
}

int Node::value1() const{
	return integer1;
}

int Node::value2() const{
	return integer2;
}

Node* Node::getparent() const{
	return parent;
}

char Node::getoperator() const{
	return myoperator;
}

Node* Node::getnextleft(Node* currNode) const{
	if (currNode->left()==NULL){
		return currNode;
	} else {
		return currNode->left();
	}
}

Node* Node::getnextright(Node* currNode) const{
	if (currNode->right()==NULL){
		return currNode;
	} else {
		return currNode->right();
	}
}

bool Node::leftexist(){
	if (leftNode==NULL){
		return false;
	} else return true;
}

bool Node::rightexist(){
	if (rightNode==NULL){
		return false;
	} else return true;
}
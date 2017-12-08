//list implementation
//Frank Lee, 1/11
//now need to remove variables
//updated for proj. 2 7/12

#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <string>
using std::string;

class list{

public:
	//constructors
	list();								//defaults to NULL head
	list(string atomicexpression);		//creates actual data structure. 
	list(Node* myhead);					//points head to given Node
	//observers
	Node* gethead() const;

private:
	Node* head;
};
#endif
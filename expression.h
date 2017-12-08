//Expression class
//Frank Lee 3/11
//updated for proj. 2 7/12

#include <string>
#include "list.h"
#ifndef EXPRESSION_H
#define EXPRESSION_H
using std::string;

class Expression{
public:
	//constructors
	Expression();				//needed to change class to the following
	Expression(Node* header);
	//methods
	string infixstring();		//returns infix Expression provided input head Node for list
	string prefixstring();
	string postfixstring();

	int Evaluate();				//evaluates the input
	char Compare(int secondnum); //project 2

private:
	Node* head;					//head Node for tree-list
};
#endif
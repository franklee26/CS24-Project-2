//CS24 Proj 1; Frank Lee 27/10
//updated for proj. 2 7/12
#ifndef NODE_H
#define NODE_H
#include <string>
using std::string;

class Node{

public:
	//constructor: do we need one? Apparently yes. 

	Node();										//defaults to integer=0 (out of range), operator=f, left/right=NULL and parent=NULL

	//methods

	void setoperator(char op);
	void setleftNode(Node* leftpointer);
	void setrightNode(Node* rightpointer);
	void setvariable();							//sets variable to x by default, kind of redundant?
	void setparent(Node* theparent);
	void setinteger1(int myvalue);
	void setinteger2(int myvalue);

	//oberservers

	Node* left() const;			//recover the left pointer
	Node* right() const;		//recover the right pointer
	int value1() const;			//recover the integer
	int value2() const;
	Node* getparent() const;	//recover parent Node
	char getoperator() const;

	Node* getnextleft(Node* currNode) const; //move to the next linked Node (if there is one) for the left
	Node* getnextright(Node* currNode) const; //these seem redundant. Remove?

	bool leftexist();			//not very useful... could just use if (left()!=NULL)...
	bool rightexist();
	
private:
	char myoperator;			//+,-,*,/ default is set to 'f'
	Node* leftNode;				//default to NULL
	Node* rightNode;			//default to NULL
	string variable;			//not sure how useful this is...
	int integer1;				//should be [1-9] and defaults to 0
	int integer2;				//same as integer1, but will only be used if integer1 is allocated something
	Node* parent;				//defaults to NULL and must be manually allocated
};
#endif
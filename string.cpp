//string function for CS24 proj
//Frank Lee 5/11
//updated for proj. 2 7/12

#include "node.h"
#include "list.h"
#include "expression.h"
#include "string.h"			//provides userprompt(), and determine(...,...)
#include <iostream>
#include <string>

int main(){
	string expr1;
	string expr2;
	std::cout<<"Please enter your first atomic expression or enter 'q' to quit: ";
	getline(std::cin,expr1);
	if (expr1=="q"){
		std::cout<<"Exiting..."<<std::endl;
		return 0;
	}
	std::cout<<"Please enter your second atomic expression or enter 'q' to quit: ";
	getline(std::cin,expr2);
	if (expr2=="q"){
		std::cout<<"Exiting..."<<std::endl;
		return 0;
	} else{
		std::cout<<std::endl;
		determine(expr1,expr2);
	}
	return 0;
}
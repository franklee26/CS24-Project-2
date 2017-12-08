//string.h framework
//Frank Lee 5/11
//updated for proj. 2 7/12

#include "node.h"
#include "list.h"
#include "expression.h"
#include <iostream>
#include <string> //ehh... not necessary

//function templates for string.cpp


//outdated function from project 1
void userprompt(string expr1, string expr2){
	list l(expr1);															//constructs binary tree
	list m(expr2);
	Expression e(l.gethead());									//creates expression object
	Expression f(m.gethead());
	string x;
	std::cout<<"Would you like the evaluations (e), a printout of the expressions (p) or a comparison (c) or would you like to quit (q)?"<<std::endl;
	std::cin>>x;
	if (x=="p"){
		std::cout<<"The infix expression for the first expression is: "<<e.infixstring()<<std::endl;
		std::cout<<"The prefix expression for the first expression is: "<<e.prefixstring()<<std::endl;
		std::cout<<"The postfix expression for the first expression is: "<<e.postfixstring()<<std::endl;
		std::cout<<"===================================================================="<<std::endl;
		std::cout<<"The infix expression for the second expression is: "<<f.infixstring()<<std::endl;
		std::cout<<"The prefix expression for the second expression is: "<<f.prefixstring()<<std::endl;
		std::cout<<"The postfix expression for the second expression is: "<<f.postfixstring()<<std::endl;
	} else if (x=="e"){
		std::cout<<"The evaluation is for the first expression is: "<<e.Evaluate()<<std::endl;
		std::cout<<"The evaluation is for the second expression is: "<<f.Evaluate()<<std::endl;
	} else if (x=="c"){
		std::cout<<"Comparing the two values: Expression1 "<<e.Compare(f.Evaluate())<<" Expression2."<<std::endl;
	} else if (x=="q"){
		return;
	}
	std::cout<<std::endl;
	userprompt(expr1,expr2);
}

void eval(string expr1, string expr2){
	list l(expr1);															//constructs binary tree
	list m(expr2);
	Expression e(l.gethead());									//creates expression object
	Expression f(m.gethead());
	std::cout<<"The evaluation is for the first expression is: "<<e.Evaluate()<<std::endl;
	std::cout<<"The evaluation is for the second expression is: "<<f.Evaluate()<<std::endl;
}	

void printout(string expr1, string expr2){
	list l(expr1);															//constructs binary tree
	list m(expr2);
	Expression e(l.gethead());									//creates expression object
	Expression f(m.gethead());
	std::cout<<"The infix expression for the first expression is: "<<e.infixstring()<<std::endl;
	std::cout<<"The prefix expression for the first expression is: "<<e.prefixstring()<<std::endl;
	std::cout<<"The postfix expression for the first expression is: "<<e.postfixstring()<<std::endl;
	std::cout<<"===================================================================="<<std::endl;
	std::cout<<"The infix expression for the second expression is: "<<f.infixstring()<<std::endl;
	std::cout<<"The prefix expression for the second expression is: "<<f.prefixstring()<<std::endl;
	std::cout<<"The postfix expression for the second expression is: "<<f.postfixstring()<<std::endl;
}

void compar(string expr1, string expr2){
	list l(expr1);															//constructs binary tree
	list m(expr2);
	Expression e(l.gethead());									//creates expression object
	Expression f(m.gethead());
	std::cout<<"Comparing the two values: Expression1 "<<e.Compare(f.Evaluate())<<" Expression2."<<std::endl;
}

void determine(string expr1, string expr2){
	string x;
	std::cout<<"Would you like the evaluations (e), a printout of the expressions (p) or a comparison (c) or would you like to quit (q)?"<<std::endl;
	std::cin>>x;
	if (x=="p"){
		printout(expr1,expr2);
		std::cout<<std::endl;
	} else if (x=="c"){
		compar(expr1,expr2);
		std::cout<<std::endl;
	} else if (x=="e"){
		eval(expr1,expr2);
		std::cout<<std::endl;
	} else if (x=="q"){
		return;
	}
	determine(expr1,expr2);
}
//Expression.cpp implementation for Expression class
//Frank Lee 3/11
//updated for proj. 2 7/12

#include "expression.h"
#include <string>
#include <iostream>
using std::string;

Expression::Expression(){
	head=NULL;
}

Expression::Expression(Node* header){
	head=header;
}

string Expression::infixstring(){
	string x;
	while (head->left()!=NULL || head->right()!=NULL || head->getoperator()!='f'){
		if (head->left()!=NULL){
			while (head->left()!=NULL){
				head=head->left();
				x=x+"(";
			}
			x=x+std::to_string(head->value1());
			x+=head->getoperator();
			x=x+std::to_string(head->value2());
			x=x+")";
			head=head->getparent();
			head->setleftNode(NULL);
		} else if (head->left()==NULL && head->right()!=NULL){
			x+=head->getoperator();
			x=x+"(";
			head=head->right();
		} else if (head->left()==NULL && head->right()==NULL){
			if (head->value1()==0){
				head=head->getparent();
				x=x+")";
				if (head->left()!=NULL){
					head->setleftNode(NULL);
				} else if (head->right()!=NULL){
					head->setrightNode(NULL);
				}
			} else {
				//x=x+"(";
				x=x+std::to_string(head->value1());
				x+=head->getoperator();
				x=x+std::to_string(head->value2());
				head=head->getparent();
				x=x+")";
				head->setrightNode(NULL);
			}
		} 
	}
	list copylist(x);
	Node* newhead=new Node;
	newhead=copylist.gethead();
	*head=*newhead;
	return x;
}

string Expression::prefixstring(){								
	string x=infixstring();	
	int len=x.length();
	int k=0;
	for (int i=0; i<len; i++){
		if (x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'){
			for (int l=0; l<i; l++){
				if (x[l]=='('){
					k=l;
				}
			} x[k]=x[i];
			x[i]=' ';
		}
	}
	int i=0;
	while (i<len){
		if (x[i]==')'){
			x[i]=' ';
		}
		i++;
	}string y;
	int j=0;
	while (j<len){
		if (x[j]!=' '){
			y=y+x[j];
		}
		j++;
	}
	return y;
}

string Expression::postfixstring(){
	string x=infixstring();
	int len=x.length();
	for (int i=len-1; i>=0; i--){
		if (x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'){
			int k=i;
			while (x[k]!=')' && k<len){
				k++;
			} x[k]=x[i];
			x[i]=' ';
		}
	}
	int i=0;
	while (i<len){
		if (x[i]=='('){
			x[i]=' ';
		}
		i++;
	}string y;
	int j=0;
	while (j<len){
		if (x[j]!=' '){
			y=y+x[j];
		}
		j++;
	}
	return y;
}

int Expression::Evaluate(){
	string x=postfixstring();
	int len=x.length();
	for (int l=0; l<len; l++){
		if (x[l]!='+'&&x[l]!='-'&&x[l]!='*'&&x[l]!='/'&&x[l]!=0){
			x[l]=x[l]-'0';
		}
	} //now all string ints are actual ints
	for (int i=0; i<len; i++){
		int stored1(0);
		int stored2(0);
		int k(i-1);
		if (x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'){
			if (x[i]=='+'){
				while (x[k]==0 && k>=0){
					k=k-1;
				} 
				stored1=x[k];
				//now, either i-1 is not zero or k is not zero
				x[k]=0;
				int j=k-1;
				while (j<k && j>=0){
					if (x[j]!=0){
						stored2=x[j];
						x[j]=0;
						break;
					} else {
						j=j-1;
					}
				}
				x[i]=stored1+stored2;
			} else if (x[i]=='-'){
				while (x[k]==0 && k>=0){
					k=k-1;
				} 
				stored1=x[k];
				//now, either i-1 is not zero or k is not zero
				x[k]=0;
				int j=k-1;
				while (j<k && j>=0){
					if (x[j]!=0){
						stored2=x[j];
						x[j]=0;
						break;
					} else {
						j=j-1;
					}
				}
				x[i]=stored2-stored1;
			} else if (x[i]=='*'){
				while (x[k]==0 && k>=0){
					k=k-1;
				} 
				stored1=x[k];
				//now, either i-1 is not zero or k is not zero
				x[k]=0;
				int j=k-1;
				while (j<k && j>=0){
					if (x[j]!=0){
						stored2=x[j];
						x[j]=0;
						break;
					} else {
						j=j-1;
					}
				}
				x[i]=stored1*stored2;
			} else if (x[i]=='/'){
				while (x[k]==0 && k>=0){
					k=k-1;
				} 
				stored1=x[k];
				//now, either i-1 is not zero or k is not zero
				x[k]=0;
				int j=k-1;
				while (j<k && j>=0){
					if (x[j]!=0){
						stored2=x[j];
						x[j]=0;
						break;
					} else {
						j=j-1;
					}
				}
				x[i]=stored2/stored1;
			}
		}
	}
	return x[len-1];
}

char Expression::Compare(int secondnum){
	int first=Evaluate(); //wow?
	if (first>secondnum){
		return '>';
	} else if (first==secondnum){
		return '=';
	} else {
		return '<';
	}
}
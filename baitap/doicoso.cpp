#include<bits/stdc++.h>
#include<iostream>

using namespace std;

typedef char Data;

struct Node
{
    Data data;
    struct  Node *next;
};


void pop(Stack &s,Data &x){
	if(isEmpty(s)){
		cout<<"Ngan xep rong"<<endl;
	}
	else{
		NodePtr p=s.top;
		x=p->data;
		s.top=s.top->next;
		p->next
	}
}

void bai_toan_doi_co_so(){
	int pd,pn,a;
	char x;
	int coso;
	Stack s;
	initStack(s);
	cout<<"Nhap so he co so 10 la";
	cin>>a;
	cout<<"Nhap co so can chuyen";
	cin>>coso;
}

















#include<bits/stdc++.h>
#include <iostream>
using namespace std;


struct SoPhuc {
    int phanThuc;
    int phanAo;
};
typedef SoPhuc Data;

struct Node{
	Data data;
	struct Node *next;
};

typedef struct Node *NodePtr;

struct Stack{
	NodePtr top;
	int size;
};

void initStack(Stack &s){
	s.top=NULL;
	s.size=0;
}

bool isEmpty(Stack s){
	return s.top==NULL;
}

int sizeOfStack(Stack s){
	return s.size;
}

NodePtr createNode(Data data){
	NodePtr p=new Node;
	if(p==NULL) return NULL;
	p->next=NULL;
	p->data=data;
	return p;
}

void push(Stack &s,Data x){
	NodePtr p=createNode(x);
	if(p==NULL){
		cout<<"Khong them duoc vao Stack"
		<<"do khong cap phap bo nho dong"<<endl;
		return;
	}
	p->next=s.top;
	s.top=p;
	s.size++;
}

void pop(Stack &s,Data &x){
	if(isEmpty(s))
		cout<<"Ngan xep rong"<<endl;
	else{
		NodePtr p=s.top;
		x=p->data;
		s.top=s.top->next;
		p->next=NULL;
		s.size--;
		delete p;
	}
}

void printData(NodePtr pnode)
{
    cout<<"Phan thuc"<<pnode->data.phanThuc<<endl;
    cout<<"Phan ao"<<pnode->data.phanAo<<endl;
    
}

void traverse(Stack s){
	if(isEmpty(s)) cout<<"Stack rong"<<endl;
	else
	{
		NodePtr q=s.top;
		while(q!=NULL){
			printData(q);
			q=q->next;
		}
	}
}


// Tính tổng các số phức trong ngăn xếp
SoPhuc tongSoPhuc(Stack s) {
    SoPhuc tong = {0, 0};
    Node* temp = s.top;
    while (temp != nullptr) {
        tong.phanThuc += temp->data.phanThuc;
        tong.phanAo += temp->data.phanAo;
        temp = temp->next;
    }
    return tong;
}

int main() {
    Stack s;
    initStack(s);
    int n;
    cout << "Nhập số lượng số phức: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        SoPhuc sp;
        cout << "Nhập số phức thứ " << i + 1 << " (phần thực, phần ảo): ";
        cin >> sp.phanThuc >> sp.phanAo;
        push(s, sp);
    }

    cout << "\nCác số phức trong ngăn xếp:\n";
    traverse(s);

    SoPhuc tong = tongSoPhuc(s);
    cout << "\nTổng các số phức: " << tong.phanThuc << " + " << tong.phanAo << "i" << endl;
    
    return 0;
}

















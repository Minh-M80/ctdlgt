#include<bits/stdc++.h>
#include<iostream>

using namespace std;
struct PHANSO{
    int tuSo;
    int mauSo;
};
typedef PHANSO Data;

struct Node
{
   Data data;
   struct Node *next;
};
typedef struct Node *NodePtr;

struct Queue{
    NodePtr first;
    NodePtr last;
    int size;
};

void initQueue(Queue &q){
    q.first=NULL;
    q.last=NULL;
    q.size=0;
}
int sizeOfQueue(Queue q){
    return q.size;
}
bool isEmpty(Queue q){
    return q.first==NULL || q.last==NULL;
}

//tạo nút mới
NodePtr createNode(Data data){
    NodePtr p=new Node;
    if(p==NULL) return NULL;
    p->next=NULL;
    p->data=data;
    return p
}

//thêm 1 phần tử vào hàng đợi
void enQueue(Queue &q,Data x){
    NodePtr p=createNode(x);
    if(p==NULL){
        cout<<"Khong them duoc vao queue";
        return;
    }
    if(isEmpty(q)){
        q.first=p;
        q.last=p;
    }
    else{
        q.last->next=p;
        q.last=p;
    }
    q.size++;
}

void deQueue(Queue &q,Data &x){
    if(isEmpty(q)){
        cout<<"Hang doi rong"<<endl;
    }else{
        NodePtr p=q.first;
        x=p->data;
        q.first=q.first->next;
        if(q.first==NULL) q.last=NULL;// t hợp 1 p tử
        p->next=NULL;// ngắt kết nối
        q.size--;
        delete p;
    }
}

void traverse(Queue q){
    if(isEmpty(q)){
        cout<<"queue rong"<<endl;
    }
    else{
        NodePtr p=q.first;
        while (p!=NULL)
        {
           printData(p->data);
           p=p->next;
        }
        
    }
}
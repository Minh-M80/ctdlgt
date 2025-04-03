#include<bits/stdc++.h>
#include<iostream>

using namespace std;
struct HangHoa{
    int maHang;
    float gia;
};
typedef HangHoa Data;

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
    return p;
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

//lấy hết hàng hóa
void layHetHangHoa(Queue &q){
    int i=1;
    while (!isEmpty(q))
    {
        Data hh;
        deQueue(q,hh);
        cout<<"Lay hang hoa "<<i<<" : ";  
        printData(hh);
        i++; 
    }
    
}



int main(){
    Queue q;
    int ch;
    
    Data hh;
    initQueue(q);
    do
    {
        system("cls");
        cout<<"CHUONG TRINH QUAN LY KHO"<<endl;
        cout<<"1.Nhap mot hang hoa"<<endl;
        cout<<"2.Nhap nhieu hang hoa"<<endl;
        cout<<"3.Xuat mot hang hoa"<<endl;
        cout<<"4.Xem hang hoa moi nhap"<<endl;
        cout<<"5.Xem hang hoa chuan bi xuat"<<endl;
        cout<<"6.Xem cac hang hoa trong kho"<<endl;
        cout<<"7.Xuat toan bo kho"<<endl;
        cout<<"0.Ket thuc chuong trinh"<<endl;
        cout<<"Lua chon chuc nang cua chuong trinh chuong trinh"<<endl;
    } while (condition);
    
    switch (ch)
    {
    case 1:
        hh=inputData();
        enQueue(q,hh);

        break;
    case 2:
    int n;
    do
    {
       cout<<"Nhap so luong cac hang hoa:";
       cin<<n;
    } while (n<=0);
    for (int i = 0; i < n; i++)
    {
        cout<<"Nhap hang hoa: "<<i+1<<": "<<endl;
        hh=inputData();
        enQueue(q,hh);
    }
        break;
        case 3:
        if(isEmpty(q)){
            deQueue(q,hh);
            cout<<"Hang hoa xuat kho la: "<<endl;
            printData(hh);
        }
        else cout<<"Khong con hang hoa trong kho"<<endl;
        break;
        case 4:
        if(!isEmpty(q)){
            cout<<"Hang hoa moi nhap kho la:"<<endl;
            printData(q.last->data);

        }
        else{
            cout<<"Khogn con hang hoa trong kho"<<endl;
        }
        break;
    default:
        break;
    }
}











int main(){

}
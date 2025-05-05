#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

struct Khachhang
{
    int makh;
    string tenkh;
    string diachi;
    string sdt;
    float tongtien;
};
typedef struct Khachhang Data;

struct Node{
    Data data;
    struct Node *next;
    struct Node *prev;
}
typedef struct Node *NodePtr;

struct List{
    NodePtr head;
    NodePtr tail;
    }

Data inputData(){
    Data khachhang;
    cout<<"Ma khach hang";
    cin>>khachhang.makh;
    cout<<"Ten khach hang";
    cin.ignore();
    getline(cin,khachhang.tenkh);
    cout<<"Dia chi";
    cin.ignore();
    getline(cin,khachhang.diachi);
    cout<<"So dien thoai";
    cin.ignore();
    cin>>khachhang.sdt;
    cout<<"Tong tien";
    cin>>khachhang.tongtien;
    return khachhang;
}

void printNodeInfo(NodePtr pnode){
    cout<<"Ma khach hang: "<<pnode->data.makh;
    cout<<"Ten khach hang: "<<pnode->data.tenkh;
    cout<<"Dia chi: "<<pnode->data.diachi;
    cout<<"So dien thoai: "<<pnode->data.sdt;
    cout<<"Tong tien: "<<pnode->data.tongtien<<endl;
}

// khởi tạo

void initialize(List &L){
    L.head = NULL;
    L.tail = NULL;
}

//Kiểm tra rỗng
bool isEmpty(List L){
    return L.head==NULL || L.tail==NULL;
}

NodePtr CreateNode(Data data){
    NodePtr newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

//thêm 1 phần tử vào cuối danh sách
void insertTail(List &L,Data data){
    NodePtr newNode=CreateNode(data);
    if(isEmpty(L)){
        L.head=newNode;
        L.tail=newNode;
    }else{
        L.tail->next=newNode;
        newNode->prev=L.tail;
        L.tail=newNode;
    }
}

//Duyệt danh sách từ đầu
void traverseFromHead(List L){
    if(L.head==NULL){
        cout<<"Danh sach rong"<<endl;
    }else{
        NodePtr q=L.head;
        while(q!=NULL){
            printNodeInfo(q);
            q=q->next;
        }
    }
}

//Duyệt danh sách từ cuối

void traverseFromTail(List L){
    if(L.tail==NULL){
        cout<<"Danh sach rong"<<endl;
    } else{
        NodePtr q=L.tail;
        while(q!=NULL){
            printNodeInfo(q);
            q=q->prev;
        }
    }
}

//liệt kê theo tổng tiền (từ đầu)

void lietKeTuDauTheoTongTien(float tongTien,List L){
    if(isEmpty(L)) cout<<"Danh sach rong"<<endl;
    else
    {
        NodePtr q=L.head;
        while(q!=NULL ){
            if(q->data.tongtien<tongTien) 
                printNodeInfo(q);
            q=q->next;
        }
    }
}

//Liệt kê theo tổng tiền (từ cuối)

void lietKeTuCuoiTheoTongTien(float tongTien,List L){
    if(isEmpty(L)) cout<<"Danh sach rong"<<endl;
    else
    {
        NodePtr q=L.tail;
        while(q!=NULL ){
            if(q->data.tongtien<tongTien)
                printNodeInfo(q);
            q=q->prev;
        }
    }
}
//Xóa một phần tử từ đầu danh sách

void deleteHead(List &L){
    if(isEmpty(L)) cout<<"Danh sach rong"<<endl;
    else{
        NodePtr p=L.head;
        L.head=p->next;
        if(L.head!=NULL) L.head->prev=NULL;
        delete p;
    }
}

//xóa phần tử cuối danh sách

void deleteTail(List &L){
    if(isEmpty(L)) cout<<"Danh sach rong"<<endl;
    else{
        NodePtr p=L.tail;
        if(L.head==L.tail){
            L.head=NULL;
            L.tail=NULL;
        }else{
            L.tail=L.tail->prev;
            L.tail->next=NULL;
            p->prev=NULL;
        }
        delete p;
    }
}


int main(){
    
}
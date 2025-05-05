#include<bits/stdc++.h>
using namespace std;


struct NhanVien{
    int ma;
    string ten,diachi,sdt;
    float luong;
};
typedef NhanVien Data;
struct Node{
    Data data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node *NodePtr;


struct List{
    NodePtr head;
    NodePtr tail;
};

void initialize(List &L){
    L.head=NULL;
    L.tail=NULL;
}
bool isEmpty(List L){
    return L.head==NULL || L.tail==NULL;
}
Data inputData(){
    Data nhanvien;
    cout<<"Nhap ma nv:";
    cin>>nhanvien.ma;
    cin.ignore();
    cout<<"Nhap ten nhan vien:";
    getline(cin,nhanvien.ten);
    cout<<"Nhap dia chi nhan vien:";
    getline(cin,nhanvien.diachi);
    cout<<"Nhap so dien thoai:";
    getline(cin,nhanvien.sdt);
    cout<<"Nhap so tien luong:";
    cin>>nhanvien.luong;
    cin.ignore();
    return nhanvien;
}
void printData(Data data){
    cout<<"ma nhan vien:"<<data.ma<<" "<<"ten nhan vien:"<<data.ten<<" "
    <<"dia chi:"<<data.diachi<<" "<<"so dien thoai:"<<data.sdt<<" "
    <<"tien luong:"<<data.luong<<endl;
}
void printNode( NodePtr pnode){
    printData(pnode->data);
}
NodePtr createNode(Data data){
    NodePtr newNode=new Node;
    newNode->next=NULL;
    newNode->prev=NULL;
    newNode->data=data;
    return newNode;
}

void insertTail(List &L,Data data){
    NodePtr newNode=createNode(data);
    if(isEmpty(L)){
        L.head=newNode;
        L.tail=newNode;
    }
    else{
        L.tail->next=newNode;
        newNode->prev=L.tail;
        L.tail=newNode;
    }
}

void traverse(List L){
    if(isEmpty(L)){
        cout<<"Danh sach rong"<<endl;
    }
    else{
        NodePtr q=L.head;
        while(q!=NULL){
            printNode(q);
            q=q->next;
        }
    }
}

void deleteHead(List &L){
    if(isEmpty(L)) cout<<"Danh sach rong"<<endl;
    else{
        NodePtr q=L.head;
    if(L.head==L.tail){
        L.head=NULL;
        L.tail=NULL;
    }
    else{
        L.head=L.head->next;
        q->next=NULL;

    }
    delete q;

    }
}



int main(){
    List L;
    initialize(L);
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin nhan vien thu:"<<i+1<<endl;
        Data data=inputData();
        insertTail(L,data);
    }
    traverse(L);
}
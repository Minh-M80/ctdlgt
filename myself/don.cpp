#include<bits/stdc++.h>
using namespace std;

struct SinhVien{
    int maSinhVien;
    string tenSinhVien,lop,hanhKiem;
    float diemTongKet;
};
typedef SinhVien Data;

struct Node{
    Data data;
    struct Node *next;
};
typedef struct Node *NodePtr;
struct List{
    NodePtr head;
    NodePtr tail;
}
Data inputData(){
    Data sinhvien;
    cout<<"Ma sinh vien: ";
    cin>>sinhvien.maSinhVien;
    cin.ignore();
    cout<<"Ten sinh vien: ";
    getline(cin,sinhvien.tenSinhVien);
    cin.ignore();
    cout<"Lop: ";
    getline(cin,sinhvien.lop);
    cout<<"Diem tong ket: ";
    cin>>sinhvien.diemTongKet;
    cin.ignore();
    cout<<"Hanh kiem: ";
    getline(cin,sinhvien.hanhKiem);
    return sinhvien;
}
//In thông tin của 1 nút
void printNodeInfo(NodePtr pnode){
    cout<<"Ma sinh vien: "<<pnode->data.maSinhVien<<" Ten sinh vien: "<<pnode->data.tenSinhVien<<" Lop: "<<pnode->data.lop<<" Diem tong ket: "<<pnode->data.diemTongKet<<" Hanh kiem: "<<pnode->data.hanhKiem<<endl;
}

void initialize(List &L){
    L.head=NULL;
    L.tail=NULL;
}
//Kiểm tra rỗng
bool isEmpty(List L){
    return L.head==NULL || L.tail==NULL;
}

//Tạo một nút
NodePtr createNode(Data data){
    NodePtr newNode=new Node;
    newNode->next=NULL;
    newNode->data=data;
    return newNode;
}

//Thêm một phần tử vào đầu ds
void insertHead(List &L,Data data){
    NodePtr newNode=createNode(data);
    if(isEmpty(L)){
        L.head=newNode;
        L.tail=newNode;
    }
    else{
        newNode->next=L.head;
        L.head=newNode;
    }
}

//Duyệt danh sách
void traverse(List L){
    if(isEmpty(L)) cout<<"Danh sach rong"<<endl;
    else{
        NodePtr q=L.head;
        while(q!=NULL){
            printNodeInfo(q);
            q=q->next;
        }
    }
}

//Xóa một phần tử cuối danh sách
void deleteTail(List &L){
    if(isEmpty(L)){
        cout<<"Danh sach rong"<<endl;
    
    }
    else{
        NodePtr p=L.tail;
        if(L.head==L.tail){
            L.head=NULL;
            L.tail=NULL;
        }else{
            NodePtr q=L.head;
            while (q!=NULL &&q->next!=L.tail)
            {
                q=q->next;
            }
            q->next=NULL;
            L.tail=q;
            
        }
        delete p;
    }
}

//Xóa đầu
void deleteHead(List &L){
    if(isEmpty(L)) cout<<"Danh dach rong"<<endl;
    else{
        NodePtr p=L.head;
        if(L.head==L.tail){
            L.head=NULL;
            L.tail=NULL;
        }
        else{
            L.head=L.head->next;
            p->next=NULL;
        }
        delete p;
    }
}

//Thêm 1 p tử vào cuối ds
void insertTail(List &L,Data data){
    NodePtr newNode=createNode(data);
    if(isEmpty(L)){
        L.head=p;
        L.tail=p;
    }
    else{
        L.tail->next=newNode;
        L.tail=newNode;
    }
}






















int main(){

}
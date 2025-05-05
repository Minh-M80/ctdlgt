// Bài 14:

// Trên ngôn ngữ C/C++, viết chương trình thực hiện yêu cầu sau:
// Câu 1. Định nghĩa một cấu trúc Vé máy bay, bao gồm các trường thông tin như sau: Mã
// vé (kiểu số nguyên), loại vé (hạng nhất, hạng thương gia, hạng phổ thông), điểm khởi hành
// (chuỗi ký tự), điểm đến (kiểu chuối ký tự), giá vé (kiểu số thực).
// Câu 2. Cài đặt một cấu trúc danh sách liên kết đơn cho kiểu dữ liệu vé máy bay, với các
// thao tác: 1) Khởi tạo danh sách; 2) Tạo mới một nút chứa dữ liệu; 3) Chèn nút vào đầu
// danh sách; 4) Duyệt danh sách; 5)hàm xóa cuối.
// Câu 3. Chương trình chính: Sử dụng cấu trúc danh sách liên kết đơn và các thao tác ở trên
// để:
// - Nhập vào một danh sách liên kết đơn gồm n vé máy bay (n bất kỳ).
// - Hiển thị danh sách đã nhập ra màn hình.
// - Liệt kê ra màn hình danh sách tất cả vé máy bay khởi hành từ TPHCM .
// - Xóa vé máy bay cuối cùng trong danh sách.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct veMayBay
{
    int maVe;
    string loaiVe;
    string diemKhoiHanh;
    string diemDen;
    float gia;
};

typedef veMayBay Data;

struct  Node
{
    Data data;
    struct Node *next;

};
typedef struct Node *NodePtr;

struct List
{
    NodePtr head;
    NodePtr tail;
};

Data inputData()
{
    Data veMayBay;
    cout<<"Nhap ma ve: ";
    cin>>veMayBay.maVe;
    cin.ignore();
    cout<<"Nhap loai ve: ";
    getline(cin,veMayBay.loaiVe);
    cout<<"Nhap diem khoi hanh: ";
    getline(cin,veMayBay.diemKhoiHanh);
    cout<<"Nhap diem den: ";
    getline(cin,veMayBay.diemDen);
    cout<<"Nhap gia ve: ";
    cin>>veMayBay.gia;
    return veMayBay;
}

void printNodeInfo(NodePtr pnode){
    cout<<"Ma ve: "<<pnode->data.maVe<<" "<<"Loai ve: "<<pnode->data.loaiVe<<" "<<"Diem khoi hanh: "<<
    pnode->data.diemKhoiHanh<<" "<<"Diem den: "<<pnode->data.diemDen<<" "<<"Gia ve: "<<pnode->data.gia<<endl;
}
void initialize(List &L){
    L.head=NULL;
    L.tail=NULL;
}
bool isEmpty(List L){
    return L.head==NULL || L.tail==NULL;
}

NodePtr CreateNode(Data data){
    NodePtr newNode=new Node;
    newNode->next=NULL;
    newNode->data=data;
    return newNode;
}

void insertHead(List &L,Data data){
    NodePtr newNode=CreateNode(data);
    if(isEmpty(L)){
        L.head=newNode;
        L.tail=newNode;
    }else{
        newNode->next=L.head;
        L.head=newNode;
    }
}

void traverse(List L){
    if(isEmpty(L)) cout<<"Danh sach rong"<<endl;
    else
    {
        NodePtr q=L.head;
        while (q!=NULL)
        {
            printNodeInfo(q);
            q=q->next;
        }
        
    }
    
}

void deleteTail(List &L){
    if (isEmpty(L))
    {
       cout<<"Danh sach rong"<<endl;
    }
    else{
        NodePtr p=L.tail;
        if (L.head==L.tail)
        {
            L.head=NULL;
            L.tail=NULL;
        }
        else{
            NodePtr q=L.head;
            while (q!=NULL && q->next!=L.tail)
            {
                q=q->next;
            }
            q->next=NULL;
            L.tail=q;
            
        }
        delete p;
        
    }
    
}
// Hàm liệt kê vé máy bay khởi hành từ TPHCM


int main(){
    int n;
    cout<<"Nhap so luong ve may bay: ";
    cin>>n;
    List L;
    initialize(L);
    for (int  i = 0; i < n; i++)
    {
        cout<<"Nhap thong tin ve may bau "<<i+1<<":"<<endl;
        Data vemaybay=inputData();
        insertHead(L,vemaybay);
    }
    cout<<"============================"<<endl;
    cout<<"  DANH SACH VUA NHAP"<<endl;
    cout<<"===> DANH SACH VE MAY BAY VUA NHAP:"<<endl;

    traverse(L);

    cout<<"Danh sach may bay khoi hanh tu HCM la:"<<endl;
    listTicketsFromTPHCM(L);
    cout<<"========================"<<endl;
    cout<<"Xoa ve may bay cuoi danh sach:"<<endl;
    deleteTail(L);
cout<<"Danh sach ve may bay sau khi xoa o cuoi danh sach:"<<endl;
traverse(L);

}
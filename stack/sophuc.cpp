#include<bits/stdc++.h>
using namespace std;

struct SoPhuc{
    int thuc;
    int ao;
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

//Nhập dữ liệu cho SoPhuc
Data inputData(){
    Data sp;
    cout<<"- Phan thuc: ";
    cin>>sp.thuc;
    cout<<"- Phan ao: ";
    cin>>sp.ao;
    return sp;
}

//In số phức
void printData(Data data){
    cout<<data.thuc<<" + "<<data.ao<<"*i"<<endl;

}

//Khởi tạo
void initStack(Stack &s){
    s.top=NULL;
    s.size=0;
}
// Kiếm tra rỗng
bool isEmpty(Stack s){
    return s.top==NULL;
}

//Trả về số lượng phần tử trong ngăn xếp
int sizeOfStack(Stack s){
    return s.size;
}

//Tạo một nút
NodePtr createNode(Data data){
    NodePtr p=new Node;
    if(p==NULL) return NULL;
    p->next=NULL;
    p->data=data;
    return p;
}

//Thêm vào ngăn xếp một phần tử x (Thêm vào đầu)
void push(Stack &s,Data x){
    NodePtr p=createNode(x);
    if(p==NULL){
        cout<<"Khong them duoc vao Stack "<<"do khong cap phap duoc bo nho"<<endl;
        return;
    }
    p->next=s.top;
    s.top=p;
    s.size++;
}
//Lấy một phần tử từ ngăn xếp và gán vào biến x(Xóa đầu)

void pop(Stack &s,Data &x)
{
    if(isEmpty(s)) cout<<"Ngan xep rong"<<endl;
    else{
        NodePtr p=s.top;
        x=p->data;
        s.top=s.top->next;
        p->next=NULL;
        s.size--;
        delete p;
    }
}

void traverse(Stack s){
    if(isEmpty(s)) cout<<"Stack rong!"<<endl;
    else{
        NodePtr q=s.top;
        while(q!=NULL){
            printData(q->data);
            q=q->next;
        }
    }
}

//Hiển thị các số phức có trong ngăn xếp và tính tổng
//Hàm này lấy các số phức trong ngăn xếp ,in ra màn hình và tính tổng

void hienThiVaTinhTong(Stack &s){
    Data sum;
    sum.thuc=0;
    sum.ao=0;
    int i=1;
    while(!isEmpty(s)){
        Data sp;
        pop(s,sp);
        cout<<"So phuc "<<i<<": ";
        printData(sp);
        sum.thuc+=sp.thuc;
        sum.ao+=sp.ao;
        i++;
    }
    cout<<"Tong cac so phuc la: ";
    printData(sum);
}

//Hiển thị các số phức có trong ngăn xếp và tính tổng
//Hàm này duyệt tất cả các số phức trong ngăn xếp,in ra màn hình và tính tổng

void hienThiVaTinhTong2(Stack s){
    Data sum;
    sum.thuc=0;
    sum.ao=0;
    int i=1;
    for(NodePtr p=s.top;p!=NULL;p=p->next){
        cout<<"So phuc "<<i<<": ";
        printData(p->data);
        sum.thuc+=p->data.thuc;
        sum.ao+=p->data.ao;
        i++;
    }
    cout<<"Tong cac phan so phuc la: ";
    printData(sum);
}

int main(){
    Stack s;
    initStack(s);
    //Cau 3:
    cout<<"====NHAP DANH SACH SO PHUC VAO NGAN XEP===="<<endl;
    int n;
    cout<<"Nhap so luong so phuc: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap so phuc "<<i+1<<": "<<endl;
        Data sp=inputData();
        push(s,sp);

    }
    cout<<"====DANH SACH CAC SO PHUC CO TRONG NGAN XEP===="<<endl;
    traverse(s);
    cout<<"====DANH SACH CAC SO PHUC CO TRONG NGAN XEP VA TONG CUA CHUNG===="<<endl;
     hienThiVaTinhTong(s);
//    hienThiVaTinhTong2(s);
    traverse(s);
    if(isEmpty(s)) cout<<"Stack is empty"<<endl;
}

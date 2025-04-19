#include<bits/stdc++.h>
using namespace std;

struct PhanSo{
    int tuSo;
    int mauSo;

};

typedef PhanSo Data;
struct Node
{
    Data data;
    struct Node *next;
};
typedef struct Node *NodePtr;

struct Stack{
    NodePtr top;
    int size;
};

Data inputData(){
    Data ps;
    cout<<"- Tu so: ";
    cin>>ps.tuSo;
    cout<<" - Mau so: ";
    int mauSo;
    do
    {
        cin>>mauSo;
        if(mauSo==0) cout<<"Nhap lai mau so (khac khong): " 
    } while (mauSo==0);
    ps.mauSo=mauSo;
    return ps;
}


// In phan so
void printData(Data data){
    cout<<data.tuSo<<"/"<<data.mauSo<<endl;
}

// khoi tao
void initStack(Stack &s){
    s.top=NULL:
    s.size=0;
}

//kiem tra rong
bool isEmpty(Stack s){
    return s.top==NULL;
}

//tra ve so luong phan tu trong ngan xep

int sizeOfStack(Stack s){
    return s.size;
}

//Tao mot nut
NodePtr createNode(Data data){
    NodePtr p=new Node;
    if(p==NULL) return NULL;
    p->next=NULL;
    p->data=data;
    return p;
}
//them vao ngan xep 1 phan tu x( them vao dau)
void push(Stack &s,Data x){
    NodePtr p=createNode(x);
    if(p==NULL){
        cout<<"Khong them duoc vao Stack "<<" do khong cap phat duoc bo nho dong"<<endl;

        return;
    }
    p->next=s.top;
    s.top=p;
    s.size++;
}

//lay mot phan tu tu ngan xep va gan vap bien x(xoa dau)
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

void traverse(Stack s){
    if(isEmpty(s)) cout<<"Stack rong"<<endl;
    else{
        NodePtr q=s.top;
        while(q!=NULL){
            printData(q->data);
            q=q->next;
        }
    }
}

//Hiển thị các phân số có trong ngăn xếp và tính tổng
// hàm này lấy các phân số trong ngăn xếp,in ra màn hình và tính tổng

void hienThiVaTinhTong(Stack &s){
    float sum=0;
    int i=1;
    while(!isEmpty(s)){
        Data ps;
        pop(s,ps);
        cout<<"Phan so "<<i<<": ";
        printData(ps);
        sum+=(float)ps.tuSo/ps.mauSo;
        i++;
    }
    cout<<"Tong cac phan so la: "<<sum<<endl;
}

//Hiển thị các phân số có trong ngăn xếp và tính tổng
//Hàm này duyệt tất cả các phân số trong ngăn xếp,in ra màn hình và tính tổng

void hienThiVaTinhTong2(Stack s){
    float sum=0;
    int i=1;
    for(NodePtr p=s.top;p!=NULL;p=p->next){
        cout<<"Phan so "<<i<<": ";
        printData(p->data);
        sum+=(float)p->data.tuSo/p->data.mauSo;
        i++;
    }
    cout<<"Tong cac phan so la: "<<sum<<endl;
}


//Hàm tìm ước số chung lớn nhất
int USCLN(int m,int n)
{
    int uscln;
    if(n==0 || m==0) uscln=m+n;
    else{
        int r=m%n;
        while(r!=0){
            m=n;
            n=r;
            r=m%n;
        }
        uscln=n;
    }
    return uscln;
}


//Hiển thị các phân số có trong ngăn xếp và tính tổng
//Tổng hai phân số được tính bằng qui đồng mẫu số
//Hàm này lấy phân số trong ngăn xếp,in ra màn hình và tính tổng

void hienThiVaTinhTong3(Stack s){
    Data sum;
    sum.tuSo=0;
    sum.mauSo=1;
    int i=1;
    while(!isEmpty(s)){
        Data ps;
        pop(s,ps);
        cout<<"Phan so "<<i<<": ";
        printData(ps);

        //Tìm mẫu số chung nhỏ nhất của hai phân số
        int msc=sum.mauSo*ps.mauSo/USCLN(sum.mauSo,ps.mauSo);
        sum.tuSo=sum.tuSo*(msc/sum.mauSo)+ps.tuSo*(msc/ps.mauSo);
        sum.mauSo=msc;
        i++
    }

    cout<<"Tong cac phan so la: ";
    printData(sum);
    cout<<" = "<<(float)sum.tuSo/sum.mauSo<<endl;

}

int main(){
    Stack s;
    initStack(s);

    //Cau 3;
    cout<<"=====NHAP DANH SACH PHAN SO VAO NGAN XEP ====="<<endl;
    int n;
    cout<<"Nhap so luong phan so: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap phan so "<<i+1<<":"<<endl;
        Data ps=inputData();
        push(s,ps);
    }
    cout<<"=====DANH SACH CAC PHAN SO CO TRONG NGAN XEP===="<<endl;
    traverse(s);
 cout<<"===== DANH SACH CAC PHAN SO CO TRONG NGAN XEP VA TONG CUA CHUNG==="<<endl;
    // hienThiVaTinhTong(s);
    // hienThiVaTinhTong2(s);
    hienThiVaTinhTong3(s);
    if(isEmpty(s)) cout<<"Stack is empty!"<<endl;

}















int main(){

}
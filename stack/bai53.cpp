// Bài 53: 
// Trên ngôn ngữ C/C++, viết chương trình thực hiện yêu cầu sau: 
// Câu 1. Định nghĩa một cấu trúc Sách bao gồm các trường thông tin như sau: Mã sách (kiểu  số nguyên), Giá (Kiểu số thực) 
// Câu 2. Cài đặt một cấu trúc ngăn xếp (Stack) bằng danh sách liên kết, với các thao tác: 1)  Khởi tạo ngăn xếp ; 2) Kiểm tra ngăn xếp rỗng; 3) Đưa một phần tử vào ngăn xếp ; 4) Lấy  một phần tử ra khỏi ngăn xếp . 
// Câu 3. Xây dựng chương trình chính để, sử dụng cấu trúc ngăn xếp và các thao tác đã cài  đặt trên ngăn xếp để: 
// - Đưa vào ngăn xếp n cuốn sách bất kỳ (được nhập từ bàn phím). 
// - Hiển thị các cuốn sách đã lưu trong ngăn xếp và giá của chúng ra màn hình.  
#include<bits/stdc++.h>
using namespace std;

struct Sach{
	int maSach;
	float gia;
};
typedef Sach Data;

struct Node{
	Data data;
	struct Node *next;
};
typedef struct Node *NodePtr;

struct Stack{
	NodePtr top;
	int size;
};

Data inputData(){
	Data data;
	cout<<"Nhap ma sach:";
	cin>>data.maSach;
	cin.ignore();
	cout<<"Nhap gia sach:";
	cin>>data.gia;
	return data;
}

void printData(Data data){
	cout<<"Ma sach: "<<data.maSach<<" Gia: "<<data.gia<<endl;
}

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
		cout<<"Khong them duoc vao Stack "<<"do khong cap phat duoc bo nho dong"<<endl;
		return;
	}
	p->next=s.top;
	s.top=p;
	s.size++;
}

void pop(Stack &s,Data x){
	if(isEmpty(s)){
		cout<<"Ngan xep rong"<<endl;
	}
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


int main(){
	Stack s;
	initStack(s);
	cout<<"====Nhap thong tin sach vao ngan xep sach ===="<<endl;
	int n;
	cout<<"Nhap so luong sach: ";
	cin>>n;
	cin.ignore();
	 for(int i=0;i<n;i++){
        cout<<"Nhap sach thu "<<i+1<<":"<<endl;
        Data sach=inputData();
        push(s,sach);
    }
    cout<<"====Thong tin sach co trong ngan xep===="<<endl;
    traverse(s);
}

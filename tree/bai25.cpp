// Bài 25:
// Trên ngôn ngữ C/C++, viết chương trình thực hiện yêu cầu sau:
// Câu 1. Định nghĩa một cấu trúc Dự án, gồm các trường thông tin như sau: Mã dự án (kiểu
// số nguyên), Tên dự án (kiểu chuỗi ký tự), Qui mô dự án (nhỏ, trung bình, lớn), Tổng kinh
// phí (kiểu số thực- đơn vị tính bằng tỷ đồng).
// Câu 2. Cài đặt một cấu trúc Cây nhị phân tìm kiếm cho kiểu dữ liệu dự án, với các thao
// tác: 1) Khởi tạo cây; 2) Tạo mới một nút chứa dữ liệu; 3) Chèn nút vào cây; 4) Duyệt cây;
// 5)hàm tìm kiếm.
// Câu 3. Chương trình chính: Sử dụng cấu trúc cây nhị phân và các thao tác ở trên để:
// - Nhập vào một cây nhị phân tìm kiếm gồm n dự án (n bất kỳ).
// - Hiển thị các dự án đã nhập ra màn hình.
// - Liệt kê ra màn hình tất cả dự án có tổng kinh phí lớn hơn 10 tỷ .
// - Tìm xem có hay không dự án có kính phí 100 tỷ.
#include<bits/stdc++.h>
using namespace std;

struct DuAn{
	int maDA;
	string tenDA,quiMo;
	float kinhPhi;
};
typedef DuAn Data;

struct Node{
	Data data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node *BinaryTree;
typedef struct Node *NodePtr;

Data inputData(){
	Data data;
	cout<<"Ma du an: ";
	cin>>data.maDA;
	cin.ignore();
	cout<<"Ten du an: ";
	getline(cin,data.tenDA);
	cout<<"Qui mo: ";
	getline(cin,data.quiMo);
	cout<<"Kinh phi: ";
	cin>>data.kinhPhi;
	cin.ignore();
	
	return data;	
}

//In thôn tin của 1 nút
void printData(Data data){
	cout<<"Ma du an: "<<data.maDA
	<<" Ten Du AN: "<<data.tenDA
	<<" Qui mo: "<<data.quiMo
	<<" Kinh phi: "<<data.kinhPhi
	
	<<endl;
}

//In thông tin của một nút
void printNode(NodePtr pnode){
	printData(pnode->data);
}

//Khoi tao
void initialize(BinaryTree &T){
	T=NULL;
}

//Tao mot nut
NodePtr createNode(Data data){
	NodePtr p=new Node;
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void insertToTree(BinaryTree &T,Data data){
	NodePtr q;
	if(T==NULL){
		q=createNode(data);
		T=q;
	}
	else if(data.maDA <T->data.maDA)
		insertToTree(T->left,data);
	else if(data.maDA >T->data.maDA)
		insertToTree(T->right,data);
	
}

void preOrder(BinaryTree T){
	if(T!=NULL){
		printNode(T);
		preOrder(T->left);
		preOrder(T->right);
	}
}

void inOrder(BinaryTree T){
	if(T!=NULL){
		inOrder(T->left);
		printNode(T);
		inOrder(T->right);
	}
}

void postOrder(BinaryTree T){
	if(T!=NULL){
		postOrder(T->left);
		postOrder(T->right);
		printNode(T);
	}
}

NodePtr searchByMaDA(int maDA,BinaryTree T){
	NodePtr p=T;
	if(p!=NULL){
		if(maDA<p->data.maDA)
			return searchByMaDA(maDA,p->left);
		else if(maDA>p->data.maDA)
			return searchByMaDA(maDA,p->right);
		else return p;
	}
	else return NULL;
}

void lietKePreOrder(BinaryTree T)
{
	if (T != NULL)
	{
		if (T->data.kinhPhi >10.0 )
			printNode(T);
		lietKePreOrder(T->left);
		lietKePreOrder(T->right);
	}
}

void lietKeInOrder(BinaryTree T)
{
	if (T != NULL)
	{
		lietKeInOrder(T->left);
		if (T->data.kinhPhi >10.0)
			printNode(T);
		lietKeInOrder(T->right);
	}
}

void lietKePostOrder(BinaryTree T)
{
	if (T != NULL)
	{
		lietKePostOrder(T->left);
		lietKePostOrder(T->right);
		if (T->data.kinhPhi >10.0)
			printNode(T);
	}
}
void checkDAKinhPhiPreOrder(BinaryTree T,NodePtr &found){
	if(T!=NULL){
		if(T->data.kinhPhi ==100){
			found=T;
			return;
		}
		checkDAKinhPhiPreOrder(T->left,found);
		checkDAKinhPhiPreOrder(T->right,found);
	}
}
int main(){
	BinaryTree T;
	initialize(T);
	cout<<"====Nhap danh sach du an vao cay===="<<endl;
	int n;
	cout<<"Nhap so luong du an: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Nhap du an "<<i+1<<":"<<endl;
		Data data=inputData();
		insertToTree(T,data);
	}
	cout<<"====Danh sach tat ca du an co trong cay===="<<endl;
	cout<<endl<<"===>Danh sach InOrder: "<<endl;
	inOrder(T);
	cout<<"====Danh sach cac du an co kinh phi lon hon 10 ty===="<<endl;
	cout<<endl<<"===>Danh sach inorder: "<<endl;
	lietKeInOrder(T);
	cout<<"====Tim du an co kinh phi 100 ty hay khong===="<<endl;
	NodePtr found=NULL;
	checkDAKinhPhiPreOrder(T,found);
	if(found!=NULL){
		cout<<"===> Co,du an co kinh phi 100 ty "<<endl;
		printNode(found);
	}
	else
		cout<<"====> Khong co du an co kinh phi 100 ty"<<endl;
	
	getchar();
}


#include<bits/stdc++.h>
using namespace std;

struct SinhVien{
	int maSV;
	string tenSV,lop,hanhKiem;
	float tongKet;
};
typedef SinhVien Data;
struct Node{
	Data data;
	struct Node *left;
	struct Node *right;	
};
typedef struct Node *BinaryTree;
typedef struct Node *NodePtr;


Data inputData(){
	Data data;
	cout<<"Ma sinh vien: ";
	cin>>data.maSV;
	cin.ignore();
	cout<<"Ten sinh vien: ";
	getline(cin,data.tenSV);
	cout<<"Lop: ";
	getline(cin,data.lop);
	cout<<"Diem tong ket: ";
	cin>>data.tongKet;
	cin.ignore();
	cout<<"Hanh kiem: ";
	getline(cin,data.hanhKiem);
	return data;
	
}

//In thôn tin của 1 nút
void printData(Data data){
	cout<<"Ma SV: "<<data.maSV
	<<" Ten SV: "<<data.tenSV
	<<" Lop: "<<data.lop
	<<" Diem TK: "<<data.tongKet
	<<" Hanh kiem: "<<data.hanhKiem
	<<endl;
}

//In thông tin của một nút
void printNode(NodePtr pnode){
	printData(pnode->data);
}

//Khoi tao
void initialize(BinaryTree &T){
	T=NULL:
}

//Tao mot nut
NodePtr createNode(Data data){
	NodePtr p=new Node;
	p->data=data;
	p->left=NULL:
	p->right=NULL:
	return p;
}

void insertToTree(BinaryTree &T,Data data){
	NodePtr q;
	if(T==NULL){
		q=createNode(data);
		T=q;
	}
	else if(data.maSV <T->data.maSV)
		insertToTree(T->left,data);
	else if(data.maSV >T->data.maSV)
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

NodePtr searchByMaSV(int maSV,BinaryTree T){
	NodePtr p=T;
	if(p!=NULL){
		if(maSV<p->data.maSV)
			return searchByMaSV(maSV,p->left);
		else if(maSV>p->data.maSV)
			return searchByMaSV(maSV,p->right);
		else return p;
	}
	else return NULL;
}

void lietKePreOrder(BinaryTree T)
{
	if (T != NULL)
	{
		if (T->data.tongKet >8.0 )
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
		if (T->data.tongKet >8.0)
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
		if (T->data.tongKet >8.0)
			printNode(T);
	}
}

void checkDiemTKPreOrder(BinaryTree T,NodePtr &found){
	if(T!=NULL){
		if(T->data.tongKet ==10){
			found=T;
			return;
		}
		checkDiemTKPreOrder(T->left,found);
		checkDiemTKPreOrder(T->right,found);
	}
}
int main(){
	BinaryTree T;
	initialize(T);
	cout<<"====Nhap danh sach sinh vien vao cay===="<<endl;
	int n;
	cout<<"Nhap so luong sinh vien: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Nhap sin vien "<<i+1<<":"<<endl;
		Data data=inputData();
		insertToTree(T,data);
	}
	cout<<"====Danh sach tat ca sinh vien co trong cay===="<<endl;
	cout<<endl<<"===>Danh sach InOrder: "<<endl;
	inOrder(T);
	cout<<"====Danh sach cac sinh vien co diem tk >8===="<<endl;
	cout<<endl<<"===>Danh sach inorder: "<<endl;
	lietKeInOrder(T);
	cout<<"====Tim sinh vien co diem tong ket 10 hay khong===="<<endl;
	NodePtr found=NULL;
	checkDiemTKPreOrder(T,found);
	if(found!=NULL){
		cout<<"===>Co,SV duoc 10 diem la: "<<endl;
		printNode(found);
	}
	else
		cout<<"====> Khong"<<endl;
	
	getchar();
}



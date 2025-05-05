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
typedef struct Node *NodePtr;
typedef struct Node *BinaryTree;

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


void printData(Data data){
	cout<<"Ma du an: "<<data.maDA
	<<" Ten du an: "<<data.tenDA
	<<" Qui mo: "<<data.quiMo
	<<" Kinh phi: "<<data.kinhPhi
	<<endl;
}

void printNode(NodePtr pnode){
	printData(pnode->data);
}

void initialize(BinaryTree &T){
	T=NULL;
}

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
	else if(data.maDA > T->data.maDA)
		insertToTree(T->right,data);	
}

void inOrder(BinaryTree T){
	if(T!=NULL){
		inOrder(T->left);
		printNode(T);
		inOrder(T->right);
	}
}

NodePtr searchByMaDA(int maDA,BinaryTree T){
	NodePtr p=T;
	if(p!=NULL){
		if(maDA<p->data.maDA)
			return searchByMaDA(maDA,p->left);
		if(maDA>p->data.maDA)
			return searchByMaDA(maDA,p->right);	
		else return p;
	}
	else return NULL;
}

void lietKeInOrder(BinaryTree T){
	if(T!=NULL){
		lietKeInOrder(T->left);
		if(T->data.kinhPhi>10.0)
			printNode(T);
		lietKeInOrder(T->right);
	}
}

void checkDAKinhPhiPreOrder(BinaryTree T,NodePtr &found){
	if(T!=NULL){
		if(T->data.kinhPhi==100){
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
	cin.ignore();
	for(int i=0;i<n;i++){
		cout<<"Nhap du an "<<i+1<<":"<<endl;
		Data data=inputData();
		insertToTree(T,data);
	}
	cout<<"====Danh sach tat ca du an co trong cay===="<<endl;
	cout<<endl<<"===>Danh sach InOrder: "<<endl;
	inOrder(T);
//	cout<"====Danh sach cac du an co kinh phi lon hon 10 ty===="<<endl;
//	cout<<endl<<"Danh sach inorder: "<<endl;
//	lietKeInOrder(T);
//	cout<<"====Tim du an co kinh phi 100 ty hay khong===="<<endl;
//	Nodeptr found=NULL;
//	checkDAKinhPhiPreOrder(T,found);
//	if(found!=NULL){
//		cout<<"====>Co du an co kinh phi 100 ty"<<endl;
//		printNode(found);
//	}
//	else
//		cout<<"====>khong co du an co kinh phi 100 ty"<<endl;
	
	getchar();
}






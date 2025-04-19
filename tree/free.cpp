#include<iostream>
#include<string>

using namespace std;

struct SinhVien
{
	int maSV;
	string tenSV;
	string lop;
	float tongKet;
	string hanhKiem;
};

typedef SinhVien TypeOfData;

TypeOfData inputData()
{
	TypeOfData data;

	cout << " - Ma sinh vien: ";
	cin >> data.maSV;

	fflush(stdin);
	cout << " - Ten sinh vien: ";
	getline(cin, data.tenSV);

	fflush(stdin);
	cout << " - Lop: ";
	getline(cin, data.lop);

	cout << " - Diem tong ket: ";
	cin >> data.tongKet;

	fflush(stdin);
	cout << " - Hanh kiem: ";
	getline(cin, data.hanhKiem);

	return data;
}

///// In thông tin c?a m?t nút
void printData(TypeOfData data)
{
	cout << " - Ma SV: " << data.maSV 
		 << "; Ten SV: " << data.tenSV
		 << "; Lop: " << data.lop
		 << "; Diem TK: " << data.tongKet
		 << "; Hanh kiem: " << data.hanhKiem
		 << endl;
}

struct TypeOfNode
{
	TypeOfData data;
	struct TypeOfNode *left;
	struct TypeOfNode *right;
};

typedef struct TypeOfNode *BinaryTree;
typedef struct TypeOfNode *NodePtr;

///// In thông tin c?a m?t nút
void printNode(NodePtr pnode)
{
	printData(pnode->data);
}

///// Kh?i t?o
void initialize(BinaryTree &T)
{
	T = NULL;
}

///// T?o m?t nút
NodePtr createNode(TypeOfData data) {
	NodePtr newNode = new TypeOfNode;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

void insertToTree(BinaryTree &T, TypeOfData data)
{
	NodePtr q;
	if (T == NULL)
	{
		q = createNode(data);
		T = q;
	}
	else if (data.maSV < T->data.maSV)
		insertToTree(T->left, data);
	else if (data.maSV > T->data.maSV)
		insertToTree(T->right, data);
}

void preOrder(BinaryTree T)
{
	if (T != NULL)
	{
		printNode(T);
		preOrder(T->left);
		preOrder(T->right);
	}
}

void inOrder(BinaryTree T)
{
	if (T != NULL)
	{
		inOrder(T->left);
		printNode(T);
		inOrder(T->right);
	}
}

void postOrder(BinaryTree T)
{
	if (T != NULL)
	{
		postOrder(T->left);
		postOrder(T->right);
		printNode(T);
	}
}

NodePtr search(TypeOfData data, BinaryTree T)
{
	NodePtr p;
	p = T;
	if (p != NULL)
	{
		if (data.maSV < p->data.maSV)
			return search(data, p->left);
		else if (data.maSV > p->data.maSV)
			return search(data, p->right);
		else return p;
	}
	else return NULL;
}

NodePtr searchByMaSV(int maSV, BinaryTree T)
{
	NodePtr p;
	p = T;
	if (p != NULL)
	{
		if (maSV < p->data.maSV)
			return searchByMaSV(maSV, p->left);
		else if (maSV > p->data.maSV)
			return searchByMaSV(maSV, p->right);
		else return p;
	}
	else return NULL;
}

void lietKePreOrder(BinaryTree T)
{
	if (T != NULL)
	{
		if (T->data.tongKet >= 8.5 && T->data.hanhKiem == "tot")
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
		if (T->data.tongKet >= 8.5 && T->data.hanhKiem == "tot")
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
		if (T->data.tongKet >= 8.5 && T->data.hanhKiem == "tot")
			printNode(T);
	}
}

void deleteFromTree(BinaryTree &T, TypeOfData data)
{
	if (T == NULL) return;
	if (data.maSV < T->data.maSV)
		deleteFromTree(T->left, data);
	else if (data.maSV > T->data.maSV)
		deleteFromTree(T->right, data);
	else
	{
		NodePtr p;
		if (T->left == NULL)
		{
			p = T;
			T = T->right;
			delete p;
		}
		else if (T->right == NULL)
		{
			p = T;
			T = T->left;
			delete p;
		}
		else
		{
			p = T->right;
			NodePtr q = NULL;
			while (p->left != NULL)
			{
				q = p;
				p = p->left;
			}
			
			T->data = p->data;
			if (q == NULL) T->right = p->right;
			else q->left = p->right;
			p->right = NULL;
			delete p;
		}
	}
}

int main()
{
	BinaryTree T;
	initialize(T);

	///// Cau 3:
	cout << "===== NHAP DANH SACH SINH VIEN VAO CAY =====" << endl;
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap sinh vien " << i + 1 << ":" << endl;
		TypeOfData data = inputData();
		insertToTree(T, data);
	}

	///// Cau 4:
	cout << "===== DANH SACH TAT CA SINH VIEN CO TRONG CAY =====" << endl;
	cout << "===> Danh sach PreOder: " << endl;
	preOrder(T);
	cout << endl << "===> Danh sach InOder: " << endl;
	inOrder(T);
	cout << endl << "===> Danh sach PostOder: " << endl;
	postOrder(T);

	///// Cau 5:
	cout << "===== TIM KIEM THEO MA SINH VIEN =====" << endl;
	int maSV;
	cout << "Nhap Ma sinh vien de tim kiem: ";
	cin >> maSV;
	NodePtr found = searchByMaSV(maSV, T);
	if (found == NULL) cout << "Khong co sinh vien voi Ma SV " << maSV << " trong cay" << endl;
	else
	{
		cout << "Sinh vien can tim la: " << endl;
		printNode(found);
	}
	
	///// Cau 6:
	cout << "===== DANH SACH CAC SINH VIEN CO DIEM TK >= 8.5 VA HANH KIEM TOT =====" << endl;
	cout << "===> Danh sach PreOder: " << endl;
	lietKePreOrder(T);
	cout << endl << "===> Danh sach InOder: " << endl;
	lietKeInOrder(T);
	cout << endl << "===> Danh sach PostOder: " << endl;
	lietKePostOrder(T);
	
	getchar();
}

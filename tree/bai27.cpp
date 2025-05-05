#include <bits/stdc++.h>

using namespace std;

typedef struct KhachHang {
    int ma;
    string ten;
    string diachi;
    string sdt;
    float tien;
} Data;

typedef struct Node {
    Data data;
    struct Node *left;
    struct Node *right;
} *BinaryTree;

void initialize(BinaryTree &T) {
    T=NULL;
}

Data inputdata() {
    Data kh;
    cout << "Nhap ma khach hang: ";
    cin >> kh.ma;
    cin.ignore();
    cout << "Nhap ten khach hang: ";
    getline(cin, kh.ten);
    cout << "Nhap dia chi: ";
    getline(cin, kh.diachi);
    cout << "Nhap so dien thoai: ";
    getline(cin, kh.sdt);
    cout << "Nhap tong tien thanh toan: ";
    cin >> kh.tien;
    cin.ignore();
    return kh;
}

BinaryTree createNode(Data x) {
    BinaryTree p = new Node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void insert(BinaryTree &T, Data x) {
    BinaryTree p;
    if (T==NULL) {
        p=createNode(x);
        T=p;
    }
    else if (x.ma<T->data.ma)
        insert(T->left,x);
    else if (x.ma>T->data.ma)
        insert(T->right,x);
}

void printData(Data data) {
    cout << "Ma khach hang: " << data.ma << endl;
    cout << "Ten khach hang: " << data.ten << endl;
    cout << "Dia chi: " << data.diachi << endl;
    cout << "So dien thoai: " << data.sdt << endl;
    cout << "Tong tien thanh toan: " << data.tien << endl;
}

void printNode(BinaryTree T) {
    printData(T->data);
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

BinaryTree search(BinaryTree T,int ma) {
    BinaryTree p = T;
    if (p!=NULL) {
        if (ma<p->data.ma)
            return search(p->left,ma);
        else if (ma>p->data.ma)
            return search(p->right,ma);
        else
            return p;
    }
    else return NULL;
}

void lietke(BinaryTree T) {
    if (T!=NULL) {
        if (T->data.tien>5)
            printNode(T);
        lietke(T->left);
        lietke(T->right);
    }
}

void check(BinaryTree T, BinaryTree &found)
{
    if (T != NULL)
    {
        if (T->data.tien == 100)
        {
            found = T;
            return;
        }
        check(T->left, found);
        check(T->right, found);
    }
}

int main() {
    BinaryTree T;
    initialize(T);
    int n;
    do {
        cout << "Nhap so luong khach hang: ";
        cin >> n;
    } while (n<=0);
    
    cout << "\n======================\n";
    for (int i=0; i<n; i++) {
        cout << "Nhap khach hang thu " << i+1 << ": " << endl;
        Data data = inputdata();
        insert(T,data);
    }
    cout << "\n======================\n";

    cout << "Danh sach khach hang da nhap: " << endl;
    for (int i=0; i<n; i++) {
        cout << "Khach hang thu " << i+1 << ": " << endl;
        printNode(T);
    }

    cout << "\n======================\n";
    cout << "Danh sach khach hang co tong tien thanh toan hon 5 trieu: " << endl;
    lietke(T);

    cout << "\n======================\n";
    cout << "Khach hang co tong tien thanh toan 100 trieu: " << endl;
    BinaryTree found = NULL;
    check(T, found);
    if (found != NULL)
    {
        cout << "Co khach hang co tong tien thanh toan 100 trieu: " << endl;
        printNode(found);
    }
    else
    {
        cout << "Khong co khach hang nao co tong tien thanh toan 100 trieu." << endl;
    }
    getchar();
}
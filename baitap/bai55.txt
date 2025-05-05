#include"bits/stdc++.h"
using namespace std;

struct maytinh{
    int mamt;
    string tenmt;
    float gia;
};
typedef maytinh Data;
struct Node
{
    Data data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node *BinareTree;
typedef struct Node *NodePtr;
Data inputData(){
    Data data;
    cout<<"nhap ma may tinh";
    cin>>data.mamt;
    fflush(stdin);
    cout<<"nhap ten may tinh";
    getline(cin,data.tenmt);
    cout<<"nhap tong gia";
    cin>>data.gia;
    return data;
}
void prinData(Data data){
    cout << "Ma may tinh: " << data.mamt << endl
         << "Ten may tinh: " << data.tenmt << endl
         << "tong gia: " << data.gia << endl;
}

void printNode(NodePtr pnode){
    prinData(pnode->data);
}
void initialize(BinareTree &T){
    T=NULL;
}
NodePtr createNode(Data data){
    NodePtr p=new Node;
    p->left=NULL;
    p->right=NULL;
    p->data = data;
    return p;
}
void insertToTree(BinareTree &T, Data data){
    NodePtr q;
    if(T==NULL){
        q=createNode(data);
        T=q;
    }
    else if(data.mamt<T->data.mamt)
         insertToTree(T->left,data);
    else if(data.mamt>T->data.mamt)
         insertToTree(T->right,data);
}
void preoder(BinareTree T){
    if(T!=NULL){
        printNode(T);
        preoder(T->left);
        preoder(T->right);
    }
}

NodePtr searchBymaduan(int mamt, BinareTree T){
    NodePtr p = T;
    if(p != NULL){
        if(mamt < p->data.mamt)
            return searchBymaduan(mamt, p->left);
        else if(mamt > p->data.mamt)
            return searchBymaduan(mamt, p->right);
        else return p;
    }
    return NULL;
}
void lietkeproder(BinareTree T){
    if(T!=NULL){
        if(T->data.gia>20)
          printNode(T);
        lietkeproder(T->left);
        lietkeproder(T->right);
    }
}
void check(BinareTree T,NodePtr &found){
    if(T!=NULL){
        if(T->data.gia==100){
            found=T;
            return;
        }
        check(T->left,found);
        check(T->right,found);
    }
}

int  main(){
    BinareTree T;
    initialize(T);
    int n;
    cout<<"nhap so luong du an";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"nhap duan"<<i+1<<":"<<endl;
        Data data =inputData();
        insertToTree(T,data);
    }
    cout<<"danh sach du an la:";
    preoder(T);
    cout<<"danh sach may tinh co gia bang  bang 10 ty la:";
    lietkeproder(T);
    NodePtr found=NULL;
    check(T,found);
    if(found!=NULL){
        cout<<"may tinh 100 ty";
        printNode(found);
    }
    else{
        cout<<"khong";
    }
    getchar();
    
}
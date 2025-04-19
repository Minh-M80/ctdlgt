#include<bits/stdc++.h>
using namespace std;


void init

void preOrder(BinaryTree T){
    if(T !=NULL){
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
void lietKePreOrder(BinaryTree T){
    if(T!=NULL){
        if(T->data.tongKet >8){
            printNode(T);
        }
    lietKePreOrder(T->left);
    lietKePreOrder(T->right);

    }
}

void lietKeInOrder(BinaryTree T){
    if(T!=NULL){
        lietKeInOrder(T->left);
        if(T->data.tongKet >8){
            printNode(T);
        }
    
        lietKeInOrder(T->right);

    }
}
void lietKePostOrder(BinaryTree T){
    if(T!=NULL){
        lietKePostOrder(T->left);      
        lietKePostOrder(T->right);
    if(T->data.tongKet >8){
        printNode(T);
    }
    }
}

void findMaxByDiem(BinaryTree T,NodePtr &max){
    if(T!=NULL){
        if(max->data.tongKet <max->data.tongKet){
            max=T;
        }
        findMaxByDiem(T->left,max);
        findMaxByDiem(T->right,max);

    }
}

void findDiem10(BinaryTree T){
    int count=0;
    if(T!=NULL){
        if(T->data.tongKet==10){
            cout<<"Co hs diem 10";
            count++;
            return;
        }
        findDiem10(T->left);
        findDiem10(T->right);
    }
    if(count==0){
        cout<<"Khong co diem 10"
    }
}


void checkDiemTKPreOrder(BinaryTree T,bool &isOke){
    if(T!=NULL){
        if(T->data.tongKet==10){
            isOke=true;
            return;

        }
        checkDiemTKPreOrder(T->left,isOke);
        checkDiemTKPreOrder(T->right,isOke);
    }
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




int main(){

}
#include <bits/stdc++.h>
using namespace std;

struct DuAn {
    int maDuAn;
    float tongTien;
};

typedef DuAn Data;
struct Node {
    Data data;
    struct Node *next;
};
typedef struct Node *NodePtr;

struct Queue {
    NodePtr first;
    NodePtr last;
    int size;
};

void initQueue(Queue &q) {
    q.first = NULL;
    q.last = NULL;
    q.size = 0;
}

bool isEmpty(Queue q) {
    return q.first == NULL;
}

NodePtr createNode(Data data) {
    NodePtr p = new Node;
    if (p == NULL) return NULL;
    p->next = NULL;
    p->data = data;
    return p;
}

void enQueue(Queue &q, Data x) {
    NodePtr p = createNode(x);
    if (p == NULL) {
        cout << "Khong them duoc vao queue";
        return;
    }
    if (isEmpty(q)) {
        q.first = p;
        q.last = p;
    } else {
        q.last->next = p;
        q.last = p;
    }
    q.size++;
}

void deQueue(Queue &q, Data &x) {
    if (isEmpty(q)) {
        cout << "Hang doi rong" << endl;
    } else {
        NodePtr p = q.first;
        x = p->data;
        q.first = q.first->next;
        if (q.first == NULL) q.last = NULL;
        delete p;
        q.size--;
    }
}

void printData(Data data) {
    cout << "Ma du an: " << data.maDuAn << ", Tong tien: " << data.tongTien << endl;
}

void traverse(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue rong" << endl;
        return;
    }
    NodePtr p = q.first;
    float tongTienDauTu = 0;
    while (p != NULL) {
        printData(p->data);
        tongTienDauTu += p->data.tongTien;
        p = p->next;
    }
    cout << "Tong tien dau tu cua tat ca du an: " << tongTienDauTu << endl;
}

int main() {
    Queue q;
    initQueue(q);
    int n;
    cout << "Nhap so luong du an: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Data duAn;
        cout << "Nhap ma du an: ";
        cin >> duAn.maDuAn;
        cout << "Nhap tong tien dau tu: ";
        cin >> duAn.tongTien;
        enQueue(q, duAn);
    }
    cout << "\nDanh sach du an trong hang doi:" << endl;
    traverse(q);
    return 0;
}

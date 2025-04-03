#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

struct Hocvien
{
    int mahv;
    string tenhv;
    string lop;
    string chuyennganh;
    float diemtk;
};
typedef struct Hocvien Data;

struct Node
{
    Data data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node *NodePtr;
struct List
{
    NodePtr head;
    NodePtr tail;
};
Data inputData()
{
    Data hocvien;
    cout << "Ma hoc vien";
    cin >> hocvien.mahv;
    cout << "Ten hoc vien";
    cin.ignore();
    getline(cin, hocvien.tenhv);
    cout << "Lop";
    cin.ignore();
    getline(cin, hocvien.lop);
    cout << "Chuyen nganh";
    cin.ignore();
    getline(cin, hocvien.chuyennganh);
    cout << "Diem trung kien";
    cin >> hocvien.diemtk;
    return hocvien;
}

void printNodeInfo(NodePtr pnode)
{
    cout << "Ma hoc vien: " << pnode->data.mahv;
    cout << "Ten hoc vien: " << pnode->data.tenhv;
    cout << "Lop: " << pnode->data.lop;
    cout << "Chuyen nganh: " << pnode->data.chuyennganh;
    cout << "Diem tk: " << pnode->data.diemtk << endl;
}

// khởi tạo

void initialize(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

// Kiểm tra rỗng
bool isEmpty(List L)
{
    return L.head == NULL || L.tail == NULL;
}
// tạo node moi
NodePtr CreateNode(Data data)
{
    NodePtr newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// chèn đầu ds

void insertFirst(List &L, Data data)
{
    NodePtr newNode = CreateNode(data);
    if (isEmpty(L))
    {
        L.head = newNode;
        L.tail = newNode;
    }
    else
    {
        newNode->next = L.head;
        L.head->prev = newNode;
        L.head = newNode;
    }
}

// Duyệt ds
void traverseFromHead(List L)
{
    if (L.head == NULL)
    {
        cout << "Danh sach rong" << endl;
    }
    else
    {
        NodePtr q = L.head;
        while (q != NULL)
        {
            printNodeInfo(q);
            q = q->next;
        }
    }
}

// xóa cuối

void deleteTail(List &L)
{
    if (isEmpty(L))
        cout << "Danh sach rong" << endl;
    else
    {
        NodePtr p = L.tail;
        if (L.head == L.tail)
        {
            L.head = NULL;
            L.tail = NULL;
        }
        else
        {
            L.tail = L.tail->prev;
            L.tail->next = NULL;
            p->prev = NULL;
        }
        delete p;
    }
}

void lietKeHocVienTMDT(List L)
{
    NodePtr q = L.head;
    cout << "Danh sach hoc vien thuoc chuyen nganh 'Thuong mai dien tu' va diem >= 8.0:\n";
    while (q != NULL)
    {
        if (q->data.chuyennganh == "Thuong mai dien tu" && q->data.diemtk >= 8.0)
        {
            cout << "Ma HV: " << q->data.mahv << " - Ten: " << q->data.tenhv << " - Lop: " << q->data.lop;
            cout << " - Diem: " << q->data.diemtk << endl;
        }
        q = q->next;
    }
}
int main()
{
    List hocVienList;
    initialize(hocVienList);
    int n;
    do
    {
        cout << "Nhap so luong hoc vien: ";
        cin >> n;
    } while (n <= 0);

    for (int i = 0; i < n; i++)
    {
        Data hv;
        cout << "Nhap ma hoc vien: ";
        cin >> hv.mahv;
        cin.ignore();
        cout << "Nhap ten hoc vien: ";
        getline(cin, hv.tenhv);
        cout << "Nhap lop: ";
        getline(cin, hv.lop);
        cout << "Nhap chuyen nganh (Khoa hoc may tinh / Thuong mai dien tu / Quan tri an ninh mang): ";
        getline(cin, hv.chuyennganh);
        cout << "Nhap diem tong ket: ";
        cin >> hv.diemtk;
        insertFirst(hocVienList, hv);
    }

    cout << "Danh sach hoc vien sau khi nhap: " << endl;
    traverseFromHead(hocVienList);
    cout << endl;

    lietKeHocVienTMDT(hocVienList);

    cout << "\nXoa hoc vien cuoi cung...\n";
    deleteTail(hocVienList);

    cout << "\nDanh sach hoc vien sau khi xoa:\n";
    traverseFromHead(hocVienList);
}
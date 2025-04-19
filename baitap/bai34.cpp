#include<bits/stdc++.h>
using namespace std;

struct NhanVien{
	int maNhanVien;
	string tenNhanVien,diaChi,dienThoai;
	float luong;
};
typedef struct NhanVien Data;

struct Node{
	Data data;
	struct Node *next;	
};
typedef struct Node *NodePtr;

struct List{
	NodePtr head;
	NodePtr tail;
};
Data inputData(){
	Data nhanvien;
	cout<<"ma nhan vien:";
	cin>>nhanvien.maNhanVien;
	cin.ignore();
	cout<<"ten nhan vien:";
	getline(cin,nhanvien.tenNhanVien);
	cout<<"dia chi";
	getline(cin,nhanvien.)
}
void initialize(List &L){
	L.head=NULL;
	L.tail=NULL;
}
void insertAfterAllMatches(List &L) {
    if (isEmpty(L)) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    string tenCanTim;
    cout << "Nhap ten sinh vien de chen sau: ";
    getline(cin, tenCanTim);

    cout << "Nhap thong tin sinh vien moi can chen:" << endl;
    Data sinhvienMoi = inputData();

    NodePtr q = L.head;
    bool found = false;

    while (q != NULL) {
        if (q->data.tenSinhVien == tenCanTim) {
            NodePtr newNode = createNode(sinhvienMoi);
            newNode->next = q->next;
            q->next = newNode;
            if (q == L.tail) {
                L.tail = newNode;
            }
            q = newNode; // Bỏ qua node vừa thêm để tránh chèn đè liên tục
            found = true;
        }
        q = q->next;
    }

    if (!found) {
        cout << "Khong tim thay sinh vien ten \"" << tenCanTim << "\" trong danh sach." << endl;
    } else {
        cout << "Da chen sinh vien moi vao sau tat ca sinh vien ten \"" << tenCanTim << "\"." << endl;
    }
}

int main(){
	int n;
    cout<<"Nhap so luong nhan vien:";
    cin>>n;
    cin.ignore();
    List L;
    initialize(L);
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin nhan vien:"<<i+i<<":"<<endl;
        Data nhanvien=inputData();
        insertHead(L,nhanvien);
    }
}
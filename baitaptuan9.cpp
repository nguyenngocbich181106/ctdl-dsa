#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// --- 1. KHAI BÁO CẤU TRÚC ---
struct Ngay {
    int ngay, thang, nam;
};

struct SinhVien {
    char maSV[8];
    char hoTen[50];
    int gioiTinh; // 0: Nam, 1: Nữ
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

struct Node {
    SinhVien data;
    Node *link;
};

struct List {
    Node *first;
    Node *last;
};

void Init(List &l) {
    l.first = l.last = NULL;
}

Node* CreateNode(SinhVien sv) {
    Node *p = new Node;
    p->data = sv;
    p->link = NULL;
    return p;
}

// --- 2. HÀM THÊM SINH VIÊN CÓ SẮP XẾP ---
void InsertOrder(List &l, SinhVien sv) {
    Node *p = CreateNode(sv);
    // Nếu danh sách rỗng hoặc mã SV nhỏ hơn node đầu tiên
    if (l.first == NULL || strcmp(sv.maSV, l.first->data.maSV) < 0) {
        p->link = l.first;
        l.first = p;
        if (l.last == NULL) l.last = p;
    } else {
        Node *ins = l.first;
        while (ins->link != NULL && strcmp(ins->link->data.maSV, sv.maSV) < 0) {
            ins = ins->link;
        }
        p->link = ins->link;
        ins->link = p;
        if (p->link == NULL) l.last = p;
    }
}

// --- HÀM IN DANH SÁCH ---
void PrintList(List l) {
    cout << left << setw(10) << "MSSV" 
         << setw(20) << "Ho Ten" 
         << setw(12) << "Ngay Sinh" << endl;
    cout << "--------------------------------------------" << endl;
    for (Node *p = l.first; p != NULL; p = p->link) {
        cout << left << setw(10) << p->data.maSV 
             << setw(20) << p->data.hoTen 
             << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam << endl;
    }
}

// --- 3. IN SINH VIÊN CÙNG NGÀY SINH ---
void SearchByBirthday(List l, Ngay d) {
    bool found = false;
    for (Node *p = l.first; p != NULL; p = p->link) {
        if (p->data.ngaySinh.ngay == d.ngay && p->data.ngaySinh.thang == d.thang && p->data.ngaySinh.nam == d.nam) {
            cout << "Tim thay: " << p->data.hoTen << " [" << p->data.maSV << "]" << endl;
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay sinh vien cung ngay sinh" << endl;
}

// --- 4. LOẠI BỎ SINH VIÊN CÙNG NGÀY SINH ---
void RemoveByBirthday(List &l, Ngay d) {
    Node *p = l.first;
    Node *prev = NULL;

    while (p != NULL) {
        if (p->data.ngaySinh.ngay == d.ngay && p->data.ngaySinh.thang == d.thang && p->data.ngaySinh.nam == d.nam) {
            Node *temp = p;
            if (prev == NULL) { // Xóa đầu
                l.first = p->link;
                p = l.first;
            } else {
                prev->link = p->link;
                p = prev->link;
            }
            if (temp == l.last) l.last = prev;
            delete temp;
        } else {
            prev = p;
            p = p->link;
        }
    }
}

    int main() {
    List myDS;
    Init(myDS);

    // Dữ liệu mẫu (Test Case)
    SinhVien sv1 = {"197401", "Nguyen Van A", 0, {15, 5, 2005}, "Ha Noi", "CNTT1", "K21"};
    SinhVien sv2 = {"197403", "Nguyen Thi B", 1, {20, 8, 2005}, "HCM", "DTVT", "K21"};
    SinhVien sv3 = {"197402", "Nguyen Thi Thu T", 0, {15, 5, 2005}, "Da Nang", "KT", "K21"};

    cout << "--- TEST 1: Them SV (Tu dong sap xep MSSV) ---" << endl;
    InsertOrder(myDS, sv1); // MSSV: 01
    InsertOrder(myDS, sv2); // MSSV: 03
    InsertOrder(myDS, sv3); // MSSV: 02 
    PrintList(myDS);

    cout << "\n--- TEST 2: Tim SV cung ngay 15/5/2005 ---" << endl;
    Ngay checkDate = {15, 5, 2005};
    SearchByBirthday(myDS, checkDate);

    cout << "\n--- TEST 3: Loai bo SV ngay 15/5/2005 ---" << endl;
    RemoveByBirthday(myDS, checkDate);
    PrintList(myDS);
    
    return 0;
}
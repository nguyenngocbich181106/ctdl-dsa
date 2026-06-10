#include <iostream>
using namespace std;
struct Nut {
    int khoa;
    Nut *trai;
    Nut *phai;
    int chieuCao;
};

// Lấy chiều cao của nút
int layChieuCao(Nut *nut) {
    if (nut == NULL)
        return 0;
    return nut->chieuCao;
}

// Tìm số lớn hơn
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Tạo nút mới
Nut* taoNut(int khoa) {
    Nut *nut = new Nut;
    nut->khoa = khoa;
    nut->trai = NULL;
    nut->phai = NULL;
    nut->chieuCao = 1;
    return nut;
}

// Quay phải
Nut* quayPhai(Nut *y) {
    Nut *x = y->trai;
    Nut *T2 = x->phai;

    x->phai = y;
    y->trai = T2;

    y->chieuCao = max(layChieuCao(y->trai),
                      layChieuCao(y->phai)) + 1;

    x->chieuCao = max(layChieuCao(x->trai),
                      layChieuCao(x->phai)) + 1;

    return x;
}

// Quay trái
Nut* quayTrai(Nut *x) {
    Nut *y = x->phai;
    Nut *T2 = y->trai;

    y->trai = x;
    x->phai = T2;

    x->chieuCao = max(layChieuCao(x->trai),
                      layChieuCao(x->phai)) + 1;

    y->chieuCao = max(layChieuCao(y->trai),
                      layChieuCao(y->phai)) + 1;

    return y;
}

// Hệ số cân bằng
int heSoCanBang(Nut *nut) {
    if (nut == NULL)
        return 0;

    return layChieuCao(nut->trai)
         - layChieuCao(nut->phai);
}

// Chèn phần tử vào cây AVL
Nut* chen(Nut *goc, int khoa) {

    if (goc == NULL)
        return taoNut(khoa);

    if (khoa < goc->khoa)
        goc->trai = chen(goc->trai, khoa);
    else if (khoa > goc->khoa)
        goc->phai = chen(goc->phai, khoa);
    else
        return goc;

    goc->chieuCao = 1 + max(
        layChieuCao(goc->trai),
        layChieuCao(goc->phai));

    int canBang = heSoCanBang(goc);

    // LL
    if (canBang > 1 && khoa < goc->trai->khoa)
        return quayPhai(goc);

    // RR
    if (canBang < -1 && khoa > goc->phai->khoa)
        return quayTrai(goc);

    // LR
    if (canBang > 1 && khoa > goc->trai->khoa) {
        goc->trai = quayTrai(goc->trai);
        return quayPhai(goc);
    }

    // RL
    if (canBang < -1 && khoa < goc->phai->khoa) {
        goc->phai = quayPhai(goc->phai);
        return quayTrai(goc);
    }

    return goc;
}

// Duyệt NLR
void duyetNLR(Nut *goc) {
    if (goc != NULL) {
        cout << goc->khoa << " ";
        duyetNLR(goc->trai);
        duyetNLR(goc->phai);
    }
}

// Duyệt LNR
void duyetLNR(Nut *goc) {
    if (goc != NULL) {
        duyetLNR(goc->trai);
        cout << goc->khoa << " ";
        duyetLNR(goc->phai);
    }
}

// Duyệt LRN
void duyetLRN(Nut *goc) {
    if (goc != NULL) {
        duyetLRN(goc->trai);
        duyetLRN(goc->phai);
        cout << goc->khoa << " ";
    }
}

int main() {

    int daySo[] = {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int n = sizeof(daySo) / sizeof(daySo[0]);

    Nut *goc = NULL;

    for (int i = 0; i < n; i++)
        goc = chen(goc, daySo[i]);

    cout << "Duyet NLR: ";
    duyetNLR(goc);

    cout << "\nDuyet LNR: ";
    duyetLNR(goc);

    cout << "\nDuyet LRN: ";
    duyetLRN(goc);

    return 0;
}

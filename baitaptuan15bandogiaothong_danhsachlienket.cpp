#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

#define MAX_THANHPHO 20

class DoThiDanhSachKe {
private:
    int V;
    string tenDinh[MAX_THANHPHO];
    vector<int> dsKe[MAX_THANHPHO];
    map<string, int> anhXaTen;

public:
    DoThiDanhSachKe() {
        V = 0;
    }

    void themDinh(string ten) {
        if (anhXaTen.find(ten) == anhXaTen.end() && V < MAX_THANHPHO) {
            tenDinh[V] = ten;
            anhXaTen[ten] = V;
            V++;
        }
    }

    void themCanh(string u, string v) {
        if (anhXaTen.find(u) == anhXaTen.end() ||
            anhXaTen.find(v) == anhXaTen.end()) {
            cout << "Loi: Dinh khong ton tai!\n";
            return;
        }

        int id_u = anhXaTen[u];
        int id_v = anhXaTen[v];

        dsKe[id_u].push_back(id_v);
        dsKe[id_v].push_back(id_u); // Đồ thị vô hướng
    }

    void hienThiDanhSachKe() {
        cout << "\nDanh sach ke:\n";

        for (int i = 0; i < V; i++) {
            cout << tenDinh[i] << ": ";

            for (int dinhKe : dsKe[i]) {
                cout << tenDinh[dinhKe] << " ";
            }

            cout << endl;
        }
    }

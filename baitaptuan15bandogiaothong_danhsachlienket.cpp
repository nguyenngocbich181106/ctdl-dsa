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
    void BFS(string dinhBatDau) {
        if (anhXaTen.find(dinhBatDau) == anhXaTen.end()) {
            cout << "Khong tim thay dinh!\n";
            return;
        }

        int start = anhXaTen[dinhBatDau];

        vector<bool> daTham(V, false);
        queue<int> hangDoi;

        daTham[start] = true;
        hangDoi.push(start);

        cout << "\nThu tu duyet BFS tu " << dinhBatDau << ":\n";

        while (!hangDoi.empty()) {
            int u = hangDoi.front();
            hangDoi.pop();

            cout << tenDinh[u] << " ";

            for (int v : dsKe[u]) {
                if (!daTham[v]) {
                    daTham[v] = true;
                    hangDoi.push(v);
                }
            }
        }

        cout << endl;
    }
};
int main() {
    DoThiDanhSachKe g;

    // Thêm các thành phố
    g.themDinh("Ha Noi");
    g.themDinh("Hai Duong");
    g.themDinh("Hung Yen");
    g.themDinh("Phu Ly");
    g.themDinh("Hoa Binh");
    g.themDinh("Son Tay");
    g.themDinh("Thai Nguyen");
    g.themDinh("Bac Ninh");
    g.themDinh("Bac Giang");
    g.themDinh("Uong Bi");
    g.themDinh("Hai Phong");

    // Thêm các tuyến đường
    g.themCanh("Ha Noi", "Hai Duong");
    g.themCanh("Hai Duong", "Hung Yen");
    g.themCanh("Hung Yen", "Phu Ly");
    g.themCanh("Phu Ly", "Ha Noi");
    g.themCanh("Hoa Binh", "Ha Noi");
    g.themCanh("Son Tay", "Ha Noi");
    g.themCanh("Thai Nguyen", "Ha Noi");
    g.themCanh("Ha Noi", "Bac Ninh");
    g.themCanh("Bac Ninh", "Bac Giang");
    g.themCanh("Bac Giang", "Uong Bi");
    g.themCanh("Bac Ninh", "Uong Bi");
    g.themCanh("Uong Bi", "Hai Phong");
    g.themCanh("Hai Duong", "Hai Phong");

    g.hienThiDanhSachKe();

    g.BFS("Ha Noi");

    return 0;
}

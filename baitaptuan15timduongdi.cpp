#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_THANHPHO 20

class DoThiMaTranKe {
private:
    int V;
    string tenDinh[MAX_THANHPHO];
    int maTran[MAX_THANHPHO][MAX_THANHPHO];
    map<string, int> anhXaTen;

public:
    DoThiMaTranKe() {
        V = 0;
        for (int i = 0; i < MAX_THANHPHO; i++) {
            for (int j = 0; j < MAX_THANHPHO; j++) {
                maTran[i][j] = 0;
            }
        }
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

        maTran[id_u][id_v] = 1;
        maTran[id_v][id_u] = 1;
    }

    void hienThiMaTranKe() {
        cout << "\n===== MA TRAN KE =====\n\n";

        cout << "\t";
        for (int i = 0; i < V; i++)
            cout << tenDinh[i] << "\t";

        cout << endl;

        for (int i = 0; i < V; i++) {
            cout << tenDinh[i] << "\t";

            for (int j = 0; j < V; j++) {
                cout << maTran[i][j] << "\t";
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

        cout << "\n===== DUYET BFS TU " << dinhBatDau << " =====\n";

        while (!hangDoi.empty()) {
            int u = hangDoi.front();
            hangDoi.pop();

            cout << tenDinh[u] << " ";

            for (int v = 0; v < V; v++) {
                if (maTran[u][v] == 1 && !daTham[v]) {
                    daTham[v] = true;
                    hangDoi.push(v);
                }
            }
        }

        cout << endl;
    }
void duongDiNganNhat(string diemDau, string diemCuoi) {

        cout << "\n===== DUONG DI NGAN NHAT =====\n";

        timDuongDi(diemDau, diemCuoi);
    }
};

int main() {

    DoThiMaTranKe g;

    // Them cac thanh pho
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

    // Them cac tuyen duong (D1 -> D13)
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

    // Hien thi ma tran ke
    g.hienThiMaTranKe();

    // BFS tu Ha Noi
    g.BFS("Ha Noi");

    // Tim duong di
    g.timDuongDi("Ha Noi", "Hai Phong");

    // Tim duong di ngan nhat
    g.duongDiNganNhat("Hoa Binh", "Hai Phong");

    return 0;
}

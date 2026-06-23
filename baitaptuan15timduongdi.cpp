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
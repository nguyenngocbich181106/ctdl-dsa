#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

const int MAX_THANHPHO = 20;

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
};

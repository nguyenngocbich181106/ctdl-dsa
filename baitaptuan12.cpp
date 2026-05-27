#include <iostream>
#include <vector>

using namespace std;

// Hàm in mảng ra màn hình với định dạng dễ nhìn
void inMang(const vector<int>& arr, int kichThuocDong) {
    cout << "[ ";
    for (int i = 1; i < arr.size(); i++) {
        if (i <= kichThuocDong) {
            cout << arr[i] << " "; // Phần tử vẫn nằm trong đống
        } else {
            cout << "(" << arr[i] << ") "; // Phần tử đã được sắp xếp cố định
        }
    }
    cout << "]" << endl;
}

// Hàm hiệu chỉnh đống (Vun đống) tại một nút có chỉ số 'i'
// kichThuocDong là số lượng phần tử hiện tại còn lại trong đống
void vunDong(vector<int>& arr, int n, int i) {
    int lonNhat = i;       // Khởi tạo vị trí lớn nhất ban đầu là nút cha
    int conTrai = 2 * i;   // Chỉ số của con bên trái
    int conPhai = 2 * i + 1; // Chỉ số của con bên phải

    // Nếu con bên trái lớn hơn nút cha hiện tại
    if (conTrai <= n && arr[conTrai] > arr[lonNhat])
        lonNhat = conTrai;

    // Nếu con bên phải lớn hơn nút lớn nhất từ trước đến nay
    if (conPhai <= n && arr[conPhai] > arr[lonNhat])
        lonNhat = conPhai;

    // Nếu nút lớn nhất không phải là nút cha
    if (lonNhat != i) {
        swap(arr[i], arr[lonNhat]);

        // Đệ quy tiếp tục vun đống phía dưới hạ tầng tại nhánh bị ảnh hưởng
        vunDong(arr, n, lonNhat);
    }
}

// Hàm thực hiện thuật toán Sắp xếp vun đống (Heap Sort)
void sapXepVunDong(vector<int>& arr) {
    int n = arr.size() - 1; // Số lượng phần tử thực tế (bỏ qua chỉ số 0)

    // 1: Vun đống ban đầu
    cout << " GIAI DOAN 1: VUN DONG BAN DAU " << endl;
    for (int i = n / 2; i >= 1; i--) {
        vunDong(arr, n, i);
    }
    cout << "Trang thai mang sau khi vun dong xong:\n";
    inMang(arr, n);
    cout << "-----------------------------------------------------\n\n";

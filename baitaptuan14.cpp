#include <iostream>
using namespace std;
// Hàm xuất trạng thái lưu trữ của mảng tại mỗi bước
void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm vun đống tại một nút có chỉ số `i`
void vunDong(int arr[], int n, int i) {
    int lonNhat = i;          // Khởi tạo lonNhat là nút gốc hiện tại
    int conTrai = 2 * i + 1;  // Vị trí con trái trong mảng index từ 0
    int conPhai = 2 * i + 2;  // Vị trí con phải trong mảng index từ 0
// Nếu con trái lớn hơn nút gốc hiện tại
    if (conTrai < n && arr[conTrai] > arr[lonNhat]) {
        lonNhat = conTrai;
    }

    // Nếu con phải lớn hơn nút lớn nhất tính đến hiện tại
    if (conPhai < n && arr[conPhai] > arr[lonNhat]) {
        lonNhat = conPhai;
    }

    // Nếu nút lớn nhất không phải là gốc ban đầu
    if (lonNhat != i) {
        swap(arr[i], arr[lonNhat]); // Hoán đổi giá trị

        // Đệ quy tiếp tục vun đống cho cây con bị ảnh hưởng
        vunDong(arr, n, lonNhat);
    }
}
// Hàm thực hiện giải thuật Sắp xếp vun đống 
void sapXepVunDong(int arr[], int n) {
    cout << "GIAI DOAN 1: VUN DONG BAN DAU " << endl;
    // Bắt đầu vun từ nút nội bộ cuối cùng (n/2 - 1) ngược lên gốc
    for (int i = n / 2 - 1; i >= 0; i--) {
        vunDong(arr, n, i);
        cout << "Vun dong tai node index " << i << ": ";
        inMang(arr, n);
    }

    cout << "\n GIAI DOAN 2: TACH GOC VA TAI CAU TRUC DONG" << endl;
    for (int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        cout << "Doi cho goc (max) voi arr[" << i << "]: ";
        inMang(arr, n);

        vunDong(arr, i, 0);
        cout << "Hieu chinh lai dong (kich thuoc " << i << "): ";
        inMang(arr, n);
        cout << "-----------------------------------------------" << endl;
    }
}
int main() {
    int arr[] = {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang khoi tao ban dau: ";
    inMang(arr, n);
    cout << endl;

    // Chạy thuật toán sắp xếp
    sapXepVunDong(arr, n);

    cout << "\nMang sau khi da sap xep tang dan: ";
    inMang(arr, n);

    return 0;
}

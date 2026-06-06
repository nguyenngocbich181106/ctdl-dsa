#include <iostream>
using namespace std;


// Hàm vun đống tại một nút có chỉ số `i`
void vunDong(int arr[], int n, int i) {
    int lonNhat = i;          // Khởi tạo lonNhat là nút gốc hiện tại
    int conTrai = 2 * i + 1;  // Vị trí con trái trong mảng index từ 0
    int conPhai = 2 * i + 2;  // Vị trí con phải trong mảng index từ 0
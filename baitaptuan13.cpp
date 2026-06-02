#include <iostream>
using namespace std;

// 1. Định nghĩa cấu trúc của một Nút (Node) trên cây
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Hàm tạo một nút mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
// 2. Hàm chèn một phần tử vào Cây nhị phân tìm kiếm (BST)
Node* insert(Node* root, int value) {
    // Nếu cây rỗng, nút mới trở thành nút gốc
    if (root == nullptr) {
        return createNode(value);
    }

    // Nếu giá trị nhỏ hơn nút hiện tại -> đi sang trái
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Nếu giá trị lớn hơn nút hiện tại -> đi sang phải
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Nếu giá trị đã tồn tại (trùng lặp), bỏ qua không chèn để đúng tính chất BST chuẩn
    return root;
}
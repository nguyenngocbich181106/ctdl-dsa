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
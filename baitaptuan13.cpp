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
// 3. Hàm tìm kiếm một phần tử trên BST
// Trả về true nếu tìm thấy, false nếu không tìm thấy, dùng bôl
bool search(Node* root, int key, int &steps) {
    steps++; 

    // Trường hợp cơ bản: Cây rỗng hoặc tìm thấy khóa ở nút gốc
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }

    // Khóa nhỏ hơn giá trị nút hiện tại -> Tìm bên nhánh trái
    if (key < root->data) {
        return search(root->left, key, steps);
    }
    
    // Khóa lớn hơn giá trị nút hiện tại -> Tìm bên nhánh phải
    return search(root->right, key, steps);
}

// 4. Hàm duyệt cây theo thứ tự giữa (In-order Traversal: Left-Node-Right)
// Kết quả in ra của BST chuẩn luôn là một dãy tăng dần
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
}

int main() {
    Node* root = nullptr;
    
    // Mảng dữ liệu đầu vào theo ví dụ của bài toán
    int arr[] = { 2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "--- 1. Bat dau chen cac phan tu vao BST ---" << endl;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    cout << "Da thiet lap cay thanh cong!" << endl;

    cout << "\n--- 2. Duyet cay theo thu tu In-order (Tang dan) ---" << endl;
    inorder(root);
    cout << endl;

    cout << "\n--- 3. Thu nghiem kiem tra thuat toan tim kiem & Do phuc tap ---" << endl;
    
    // Thử nghiệm tìm kiếm 1 phần tử có trong cây (ở vị trí sâu nhất để thấy Worst-case)
    int target1 = 2005;
    int steps1 = 0;
    if (search(root, target1, steps1)) {
        cout << "Tim thay " << target1 << " sau " << steps1 << " buoc so sanh." << endl;
    } else {
        cout << "Khong tim thay " << target1 << " sau " << steps1 << " buoc so sanh." << endl;
    }

    // Thử nghiệm tìm kiếm 1 phần tử không có trong cây
    int target2 = 2010;
    int steps2 = 0;
    if (search(root, target2, steps2)) {
        cout << "Tim thay " << target2 << " sau " << steps2 << " buoc so sanh." << endl;
    } else {
        cout << "Khong tim thay " << target2 << " sau " << steps2 << " buoc so sanh (Duyet het nhanh)." << endl;
    }
}

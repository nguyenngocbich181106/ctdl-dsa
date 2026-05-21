#include <iostream>
#include <string>
using namespace std;

// 1. Định nghĩa cấu trúc một nút (Node) trên cây biểu thức
struct Node {
    string data;      // Chứa toán tử hoặc toán hạng
    Node* left;       // Con trỏ trỏ đến nút con bên trái
    Node* right;      // Con trỏ trỏ đến nút con bên phải
// Hàm khởi tạo nhanh một nút mới
    Node(string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// 2. Các hàm duyệt cây biểu thức

// Duyet truoc
void duyetTruoc(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " "; // Duyệt roots
    duyetTruoc(root->left);    // Duyệt left
    duyetTruoc(root->right);   // Duyệt right
}

// Duyet giua
void duyetGiua(Node* root) {
    if (root == nullptr) return;

    // Kiểm tra nếu là toán tử (nút cha) thì thêm dấu ngoặc đơn mở
    if (root->left != nullptr || root->right != nullptr) {
        cout << "(";
    }

    duyetGiua(root->left);     // Duyệt Trái
    cout << " " << root->data << " "; // Duyệt Gốc
    duyetGiua(root->right);    // Duyệt Phải

    // Kiểm tra nếu là toán tử thì thêm dấu ngoặc đơn đóng
    if (root->left != nullptr || root->right != nullptr) {
        cout << ")";
    }
}

// Duyet sau
void duyetSau(Node* root) {
    if (root == nullptr) return;

    duyetSau(root->left);      // Duyệt Trái
    duyetSau(root->right);     // Duyệt Phải
    cout << root->data << " "; // Duyệt Gốc
}

// Hàm main
int main() {
    // 3. (a+b) * c
    // Tạo nút gốc là toán tử nhân '*'
    Node* root = new Node("*");

    // Tạo nhánh bên trái cho phép cộng: (a + b)
    root->left = new Node("+");
    root->left->left = new Node("a");
    root->left->right = new Node("b");

    // Tạo nhánh bên phải cho toán hạng 'c'
    root->right = new Node("c");

    // 4. Tiến hành in biểu thức theo 3 cách duyệt
    cout << "--- KET QUA DUYET CAY BIEU THUC ---" << endl;

    cout << "1. Duyet truoc (Prefix): ";
    duyetTruoc(root);
    cout << endl;

    cout << "2. Duyet giua  (Infix) : ";
    duyetGiua(root);
    cout << endl;

    cout << "3. Duyet sau   (Postfix): ";
    duyetSau(root);
    cout << endl;

    // Giải phóng bộ nhớ (Khuyến khích làm để tránh rò rỉ bộ nhớ)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

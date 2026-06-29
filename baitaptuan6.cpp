#include <iostream>
#include <cstring>
using namespace std;
// cau truc File
struct File {
    char name[100];
    float size;
    int time;
};
 
struct Node {
    File data;
    Node* next;
};
// tao node
Node* createNode(File f) {
    Node* node = new Node;
    node->data = f;
    node->next = NULL;
    return node;
}

// Chèn theo thời gian tăng dần
void insertSorted(Node*& head, File f) {
    Node* node = createNode(f);

    if (head == NULL || f.time < head->data.time) {
        node->next = head;
        head = node;
        return;
    }

    Node* cur = head;
    while (cur->next != NULL && cur->next->data.time < f.time) {
        cur = cur->next;
    }

    node->next = cur->next;
    cur->next = node;
}//hien thi danh sach
void display(Node* head) {
    while (head != NULL) {
        cout << head->data.name << " | "
             << head->data.size << "MB | "
             << head->data.time << endl;
        head = head->next;
    }
}
//tinh tong dung luong
float totalSize(Node* head) {
    float sum = 0;
    while (head != NULL) {
        sum += head->data.size;
        head = head->next;
    }
    return sum;
}

// Xóa file nhỏ nhất
void removeSmallest(Node*& head) {
    if (head == NULL) return;

    Node *minNode = head, *minPrev = NULL;
    Node *cur = head, *prev = NULL;

    while (cur != NULL) {
        if (cur->data.size < minNode->data.size) {
            minNode = cur;
            minPrev = prev;
        }
        prev = cur;
        cur = cur->next;
    }

    if (minPrev == NULL) {
        head = head->next;
    } else {
        minPrev->next = minNode->next;
    }

    delete minNode;
}

// Fit vào USB
void fitToUSB(Node*& head, float limit) {
    while (totalSize(head) > limit) {
        removeSmallest(head);
    }
}
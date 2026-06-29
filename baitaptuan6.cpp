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
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {
        cout << val << endl;
    }

    ~Node() {
        cout <<  data << " destroyed" << endl;
    }
};

Node* createLinkedList(int n) {
    if (n <= 0)
    
    return nullptr;

    Node* head =   (Node*) malloc(sizeof(Node)); 
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = new Node(i);
        current = current->next;
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = createLinkedList(1000); 
    printList(head);
}
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} // constructor
};

// Function to create a linked list and return head
Node* createLinkedList() {
    // Create nodes
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    // Connect nodes
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr; // last node

    return first; // return head
}

// Function to print linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = createLinkedList(); // get head of linked list
    printList(head);                 // print it
    return 0;
}

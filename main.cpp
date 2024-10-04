#include <iostream>
using namespace std;

// Constants
const int SIZE = 7;

// Struct definition
struct Node {
    float value;
    Node *next;
};

// Function prototypes
void output(Node *);
Node* addNodeToFront(Node *, float);
Node* addNodeToTail(Node *, float);
void deleteNode(Node *&, int);
void insertNode(Node *&, int, float);
void deleteList(Node *&);

int main() {
    Node *head = nullptr;

    // Create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addNodeToFront(head, tmp_val);
    }
    output(head);

    // Deleting a node
    int entry;
    cout << "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    output(head);

    // Insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    output(head);

    // Deleting the entire linked list
    deleteList(head);
    output(head);

    return 0;
}

// Function to output the entire linked list
void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// Function to add a node to the front of the list
Node* addNodeToFront(Node *head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

// Function to add a node to the tail of the list
Node* addNodeToTail(Node *head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    
    if (!head) {
        return newNode;  // If list is empty, new node is the head
    }

    Node *current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    
    return head;
}

// Function to delete a node at a specific position
void deleteNode(Node *&head, int position) {
    if (!head || position <= 0) return;

    Node *current = head;
    if (position == 1) {
        head = head->next;
        delete current;
        return;
    }

    Node *prev = nullptr;
    for (int i = 1; i < position && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }

    if (current) {
        prev->next = current->next;
        delete current;
    }
}

// Function to insert a node after a specific position
void insertNode(Node *&head, int position, float value) {
    Node *newNode = new Node;
    newNode->value = value;

    Node *current = head;
    Node *prev = nullptr;

    for (int i = 1; i <= position && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }

    if (prev) {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

// Function to delete the entire linked list
void deleteList(Node *&head) {
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}


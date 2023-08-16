#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int data;
    Node* next;
};

class DoubleLL {
private:
    Node* head;

public:
    DoubleLL();
    void display();
    void insert(int x);
    void Reverse();
};

DoubleLL::DoubleLL() {
    head = NULL;
}

void DoubleLL::display() {
    if (!head) {
        return;
    }
    
    Node* current = head;
    
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    
    cout << endl;
}

void DoubleLL::insert(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    
    if (!head) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

void DoubleLL::Reverse() {
    if (!head) {
        return;
    }
    
    Node* current = head;
    Node* temp = NULL;
    
    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;
    } while (current != head);
    
    head = head->prev; // Update the new head
}

int main() {
    DoubleLL list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "Original List: ";
    list.display();

    list.Reverse();
    cout << "Reversed List: ";
    list.display();

    return 0;
}

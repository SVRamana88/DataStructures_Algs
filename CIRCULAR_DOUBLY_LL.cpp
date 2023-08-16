#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class DoubleLL
{
private:
    Node *head;

public:
    DoubleLL(int A[], int n);
    void display();
    Node *getHead() { return head; }
    int Length();
    void insert(int index, int x);
    int Delete(int index);
    void Reverse();
    ~DoubleLL();
};

DoubleLL::DoubleLL(int A[], int n)
{
    Node *t = new Node;
    t->data = A[0];
    t->prev = NULL;
    t->next = NULL;
    head = t;
    t->next = head; // Circular connection
    t->prev = head; // Circular connection

    Node *last = t; // Keep track of the last node

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = head; // Circular connection
        t->prev = last; // Circular connection

        last->next = t;
        head->prev = t; // Update head's prev to the new last node
        last = t;
    }
}

void DoubleLL::display()
{
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head); // Traverse the circular list
    cout << endl;
}

int DoubleLL::Length()
{
    Node *p = head;
    int l = 0;
    do
    {
        l++;
        p = p->next;
    } while (p != head); // Traverse the circular list
    return l;
}

void DoubleLL::insert(int index, int x)
{
    if (index < 0 || index > Length())
        return;
    Node *t = new Node;
    t->data = x;
    if (index == 0)
    {
        if (!head)
        {
            head = t;
            t->next = t;
            t->prev = t;
        }
        t->next = head;
        t->prev = head->prev;
        head->prev->next = t;
        head->prev = t;
        head = t;
    }
    else
    {
        Node *p = head;
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        p->next = t;
        t->next->prev = t;
    }
}

int DoubleLL::Delete(int index)
{
    if (index < 0 || index > Length())
        return -1;
    int x;
    Node *p = head;
    if (index == 1)
    {
        if (head->next == head) {
            delete head;
            head = NULL;
        }
        head->prev->next = head->next;
        head->next->prev = head->prev;
        x = head->data;
        head = head->next;
        delete p;
    }
    for (int i = 0; i < index - 1; i++)
        p=p->next;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    x = p->data;
    delete p;
    return x;
}

void DoubleLL::Reverse() {
    if (!head) {
        return;
    }
    
    Node* current = head;
    Node* temp = NULL;
    
    do
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;
    } while (current != head);
    
    
    head = head->next; // Update the new head


    //  do {
    //     temp = current->prev;
    //     current->prev = current->next;
    //     current->next = temp;
    //     current = current->prev;
    // } while (current != head);
    
    // head = head->prev; // Update the new head
}


DoubleLL::~DoubleLL()
{
    if (head)
    {
        Node *p = head;
        do
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        } while (p != head);
    }
}

int main()
{
    system("cls");
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(A[0]);

    DoubleLL list(A, n);
    list.display();
    list.Reverse();
    list.display();

    return 0;
}

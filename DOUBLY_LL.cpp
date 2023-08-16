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
    Node *first, *last;

public:
    DoubleLL(int A[], int n);
    void display();
    Node *getfirst() { return first; }
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
    first = last = t;
    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;
        t->data = A[i];
        t->next = NULL; // t farward
        last->next = t; // last farward link
        t->prev = last; // t backward link
        last = last->next;
    }
}

void DoubleLL::display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int DoubleLL::Length()
{
    Node *p = first;
    int l;
    while (p != NULL)
    {
        l++;
        p = p->next;
    }
    return l;
}

void DoubleLL::insert(int index, int x)
{
    if (index < 0 || index > Length())
    {
        return;
    }
    else
    {
        Node *t = new Node;
        t->data = x;
        if (index == 0)
        {
            t->prev = NULL;
            if (first)
            {
                t->next = first;
                first->prev = t;
                first = t;
            }
            else {
                t->next = NULL;
                first = t;
            }
        }
        else {
            Node *p = first;
            for (int i = 0; i < index - 1; i++) 
                p=p->next;
            t->next = p->next;
            t->prev = p;
            if(p->next)
                p->next->prev = t;
            p->next = t;
        }
    }
}


int DoubleLL::Delete(int index) {
    int x = -1;
    Node* p = first;
 
    if (index < 0 || index > Length()){
        return x;
    }
 
    if (index == 1){
        first = first->next;
        if (first){
            first->prev = nullptr;
        }
        x = p->data;
        delete p;
    } else {
        for (int i=0; i<index-1; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next){
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
}

void DoubleLL::Reverse() {
    Node *temp = NULL,*p = first;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p && p->next == NULL) {
            p->next = p->prev;
            p->prev = NULL;
            first = p;
            break;
        }
    }
}

DoubleLL::~DoubleLL()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

int main()
{
    
    return 0;
}

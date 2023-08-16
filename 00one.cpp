#include <iostream>                                                                             
#include <cstdlib>
using namespace std;

class Node
{
private:
    int data;
    Node *next;
public:
    void insertlast(int value);
    void display(Node *p);
} *first = NULL, *last = NULL;

void Node::insertlast(int value)
{
    Node *t = new Node;
    t->data = value;
    t->next = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void Node::display(Node *p) {
    while (p)
    {
        cout << p->data;
        p = p->next;
    } 
}

int main()
{
    system("cls");
    for (int i = 1; i < 6; i++)
        first->insertlast(i);
    first->display(first);
    return 0;
}
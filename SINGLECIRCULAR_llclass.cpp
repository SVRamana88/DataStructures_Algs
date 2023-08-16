#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class ScircularLL
{
private:
    Node *head = NULL, *tail;

public:
    // ScircularLL();
    ScircularLL(int A[], int n);
    void display();
    void Rdisplay(Node *h);
    Node *getHead() { return head; }
    void Insert(int index, int x);
    int Length();
    int Delete(int index);
    void Reverse();
    ~ScircularLL();
};

// ScircularLL::ScircularLL()
// {
//     head = NULL;
//     tail = NULL;
// }

ScircularLL::ScircularLL(int A[], int n)
{
    head = new Node;
    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;
        t->data = A[i];
        t->next = head; // t->next = tail->next
        tail->next = t;
        tail = t;
    }
}

void ScircularLL::display()
{
    Node *h = head;
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while (h != head);
    cout << endl;
}

void ScircularLL::Rdisplay(Node *h)
{
    static int flag = 0;
    if (h != head || flag == 0)
    {
        flag = 1;
        cout << h->data << " -> ";
        Rdisplay(h->next);
    }
    flag = 0; // flag = 0;   no problem
}

int ScircularLL::Length()
{
    int l = 0;
    Node *h = head;
    do
    {
        l++;
        h = h->next;
    } while (h != head);
    return l;
}

void ScircularLL::Insert(int index, int x)
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
            if (head == NULL)
            {
                head = t;
                t->next = head;
            }
            else
            {
                Node *p = head;
                while (p->next != head)
                    p = p->next;
                t->next = head;
                p->next = t;
                head = t;
            }
        }
        else
        {
            Node *p = head;
            for (int i = 0; i < index - 1; i++)
                p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}

int ScircularLL::Delete(int index)
{
    if (index < 0 || index > Length())
    {
        return -1;
    }
    else
    {
        int x;
        Node *p = head;
        if (index == 1)
        {
            x = head->data;
            while (p->next != head)
                p = p->next;
            if (p == head)
            {
                delete head;
                head = NULL;
            }
            else
            {
                p->next = head->next;
                delete head;
                head = p->next;
            }
        }
        else
        {
            Node *q = NULL;
            for (int i = 0; i < index - 2; i++)
                p = p->next;
            q = p->next;
            p->next = q->next;
            x = q->data;
            delete q;
        }
        return x;
    }
}

void ScircularLL::Reverse()
{
    if (!head || !head->next)
    {
        return;
    }

    Node *prev = nullptr;
    Node *current = head;
    Node *next;

    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;
    head = prev;
}

ScircularLL::~ScircularLL()
{
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }

    while (p != head)
    {
        p->next = head->next;
        delete head;
        head = p->next;
    }

    if (p == head)
    {
        delete head;
        head = nullptr;
    }
}

int main()
{
    system("cls");
    int A[] = {1, 2, 3, 4, 5};
    ScircularLL scl(A, sizeof(A) / sizeof(A[0]));
    scl.Reverse();
    scl.display();
    return 0;
}

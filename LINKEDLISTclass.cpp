#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Linkedlist
{
private:
    Node *first, *last;

public:
    Linkedlist();
    void insertlast(int value);
    void display();
    int Length();
    void Insert(int index,int x);
    int Delete(int index);
    ~Linkedlist();
};

Linkedlist::Linkedlist()
{
    first = NULL;
    last = NULL;
}

void Linkedlist::insertlast(int value)
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

Linkedlist::~Linkedlist()
{
    Node *p = first;
    while (p)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void Linkedlist::display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Linkedlist::Length()
{
    Node *p = first;
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Linkedlist::Insert(int index, int x)
{
    Node *t, *p = first;

    if (index < 0 || index > Length())
        return;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
int Linkedlist::Delete(int index)
{
    Node *p, *q = NULL;
    int x = -1;

    if (index < 1 || index > Length())
        return -1;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    system("cls");
    Linkedlist ll;
    for (int i = 1; i < 6; i++)
        ll.insertlast(i);
    ll.Insert(3,10);
    ll.Delete(4);
    ll.display();
    return 0;
}

/*



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


Regarding Parentheses with new and Dynamic Allocation: When using the new operator for dynamic memory allocation, you have the flexibility to include or omit parentheses when calling the default constructor. Both Linkedlist* ll = new Linkedlist; and Linkedlist* ll = new Linkedlist(); are entirely equivalent and will effectively allocate objects on the heap. The optional nature of parentheses comes into play when the constructor has no arguments.

About the "Most Vexing Parse" Issue: Understanding the distinction between Linkedlist ll; and Linkedlist ll(); is crucial. Despite their apparent similarity, they hold distinct meanings due to a phenomenon known as the "most vexing parse." Linkedlist ll; declares an object named ll of the Linkedlist type, utilizing the default constructor. On the other hand, Linkedlist ll(); is interpreted as the declaration of a function named ll that takes no arguments and returns an object of type Linkedlist. This intricacy can indeed lead to confusion, and it's a fundamental point to remember while coding.

Parameterized Constructor Example: When dealing with a parameterized constructor, such as Linkedlist(A, 5);, you're passing arguments to the constructor during object creation. This approach enables you to initialize your object with specific values, aiding in customization based on your requirements. Importantly, the compiler won't treat this as a function call, recognizing it as a constructor invocation instead.

In Short:

The use of parentheses when calling the default constructor while dynamically allocating with new is optional.

Linkedlist* ll = new Linkedlist; and Linkedlist* ll = new Linkedlist(); are equivalent and correctly allocate objects on the heap.

Linkedlist ll; and Linkedlist ll(); are not equivalent due to the "most vexing parse" issue. The former declares an object, while the latter declares a function.

Using a parameterized constructor like Linkedlist(A, 5); allows you to initialize objects with specific values during creation. Importantly, the compiler recognizes it as a constructor invocation, not a function call.

Kindly note that the preceding content has been provided by ChatGPT. If there are any errors present, I would appreciate your assistance in correcting them.           

This explanation can be particularly Helpful to students who find themselves in a similar state of confusion, helping them navigate these subtle yet significant distinctions in C++ syntax.

*/

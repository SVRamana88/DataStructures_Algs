#include <iostream>
#include <cstdlib>
#include <limits.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last = NULL,*second = NULL,*last2 = NULL,*third = NULL, *tlast = NULL;

void create(Node *p, int n)
{

    first = new Node;
    first->data = 0;
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;
        t->data = i;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p)
    {
        cout << p->data << "  ";
        p = p->next;
    }
}

void Rdisplay(Node *p)
{
    if (p != NULL)
    {
        Rdisplay(p->next);
        cout << p->data;
    }
}

int count(Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int Rcount(Node *p)
{
    if (p == 0)
        return 0;
    else
        return Rcount(p->next) + 1;
}

int Add(Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int RAdd(Node *p)
{
    if (p == 0)
        return 0;
    else
        return RAdd(p->next) + p->data;
}

int max(Node *p)
{
    int max = INT_MIN;
    while (p)
    {
        if (max < p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}

int Rmax(Node *p)
{
    int x = 0;
    if (p == 0)
        return INT32_MIN;
    x = Rmax(p->next);
    return x > p->data ? x : p->data;

    /*
    int RMax(struct Node *p)
    {
    int x=0;

    if(p==0)
    return INT32_MIN;
    x=RMax(p->next);
    if(x>p->data)
    return x;
    else
    return p->data;
    }
    */
}

Node *LSearch(Node *p, int key)
{
    while (p)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

Node *RLsearch(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    return RLsearch(p->next, key);
}

Node *ILSearch(Node *p, int key)
{
    if (first->data == key)
        return first;
    Node *q = NULL; // q points to previous node
    while (p)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return first;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void insert0(int pos, int x)
{
    Node *p, *t;
    if (pos == 0)
    {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else if (pos > 0)
    {
        p = first;
        for (int i = 0; i < pos - 1 && p; i++)
            p = p->next;

        if (p)
        {
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

void insert(Node *p, int pos, int x)
{

    if (pos < 0 || pos > count(first))
        return;

    Node *t = new Node;
    t->data = x;

    if (pos == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
        if (t->next == NULL)
        {
            last = t;
        }
    }
}

void insertlast(int x,int fs)
{
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if(fs == 1) {
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
    else {
    if (second == NULL)
    {
        second = last2 = t;
    }
    else
    {
        last2->next = t;
        last2 = t;
    }
    }
}

void sortedInsert(Node *p, int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = last = t;
    }

    else
    {
        Node *q = NULL;
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
            if (t->next == NULL)
            {
                last = t;
            }
        }
    }
}

int Delete(Node *p, int index)
{
    Node *q = NULL;
    int x = -1;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;//free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;//free(p);

        if (q->next == NULL) last = q;
        
        return x;
    }
}

bool issorted(Node *p) {
    int x = INT32_MIN;
    while (p!=NULL)
    {
        if(p->data < x) {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

void removeDuplicates(Node *p) { //for shorted
    Node *q=p->next;
    if(p->data != q->data) {
        p = q;
        q = q->next;
    }
    else {
        p->next = q->next;
        delete q;
        q = p->next;
        if(p->next == NULL) last = p;
    }  
}

void reverse(Node *p) {
    Node *r=NULL,*q=NULL;
    last = p;
    while (p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;
}

void Rreverse(Node *q, Node *p) {
    static bool isFirstCall = true; // Static variable to track the initial call
    
    if (isFirstCall) {
        last = p; // This will execute only in the initial function call
        isFirstCall = false; // Mark that the initial call has been made
    }
    
    if (p == NULL) {
        first = q;
    } else {
        Rreverse(p, p->next);
        p->next = q;
    }
}

void concatenate(Node *first,Node *second) {
    Node *p = first;
    while (p->next!=NULL)
        p=p->next;
    p->next = second;
    second = NULL;
}

// void merge(Node *first,Node *second) {
//     if(first->data < second->data) {
//         third = tlast = first;
//         third->next = NULL;
//        // tlast->next = NULL;
//         first = first->next;
//     }
//     else {
//         third = tlast = second;
//         third->next = NULL;
//         //tlast->next = NULL;
//         second = second->next;
//     }
//     while (first && second ) //(first!=NULL && second!=NULL)
//     {
//         if(first->data < second->data) {
//             tlast->next = first;
//             tlast = first;//tlast = tlast->next;
//             first = first->next;
//             tlast->next = NULL;
//         }
//         else {
//             tlast->next = second;
//             tlast = second;//tlast = tlast->next;
//             second = second->next;
//             tlast->next = NULL;
//         }
//     }
//     if (first)  { //(first != NULL) {
//         tlast->next = first;
//     }
//     if (second)  { //(second != NULL) {
//         tlast->next = second;
//     }
// }

void merge(Node *p,Node *q) { //if i write as merge(Node *first, Node *second) // first and secocond are local not glabal
    if(p->data < q->data) {
        third = tlast = p;
        p = p->next;
        third->next = NULL;
    }
    else {
        third = tlast = q;
        q = q->next;
        third->next = NULL;
        /*
        third->next = NULL;
        q = q->next;                      THSI IS BULLSET
        */
    }
    while (p && q ) //(p!=NULL && q!=NULL)
    {
        if(p->data < q->data) {
            tlast->next = p;
            tlast = p;//tlast = tlast->next;
            p = p->next;
            tlast->next = NULL;
        }
        else {
            tlast->next = q;
            tlast = q;//tlast = tlast->next;
            q = q->next;
            tlast->next = NULL;
        }
    }
    if (p)  { //(p != NULL) {
        tlast->next = p;
        tlast = last;
    }
    if (q)  { //(q != NULL) {
        tlast->next = q;
        tlast = last2;
    }
}

bool isloop(Node *first) //here first is local not global
{
    Node *p,*q;
    p = q = first;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q; //q = (q == NULL) ? q : q->next; //
    } while (p && q && p!=q);

    return p == q ? true : false;
}

int main()
{
    system("cls");
    for (int i = 1; i < 6; i++)
        insertlast(i,1);
    
    display(first);
    
    last->next = first->next->next;
    if ( isloop(first) ) { cout << "true"; }


    return 0;
}

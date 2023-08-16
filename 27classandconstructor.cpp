#include<iostream>
#include<cstdlib>
using namespace std;

class Rectangle
{
private:
    int l,b;
public:
    Rectangle();
    Rectangle(int a, int b);
    int area();
    ~Rectangle();
};

Rectangle::Rectangle() {
    l=b=0;
}

Rectangle::Rectangle(int a, int c)
{
    l=a;
    b=c;
}

// Rectangle::Rectangle(int l, int b)     same names
// {
//     this->l=l;      //this.l=l
//     this->b=b;      //this.b=b not word
// }

Rectangle::area() {
    return l*b;
}

Rectangle::~Rectangle()
{
}

int main() {
    system("cls");
    Rectangle r(5,5);
    cout << "Area :" << r.area() << endl;
}

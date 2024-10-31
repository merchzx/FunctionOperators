#include<iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()  // construct by default
    {
        cout << "Construct\n";
        x = y = 0;
    }
    Point(int x1, int y1)   // Construct by 2 param
    {
        cout << "Construct by 2 param\n";
        x = x1;
        y = y1;
    }
    void Init()
    {
        x = rand() % 10;
        y = rand() % 10;
    }
    void Init(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    void Output()
    {
        cout << "X: " << x << "\tY: " << y << endl;
    }
    // перегрузка бинарных операции

    Point operator+(Point& b)
    {
        Point temp;
        temp.x = this->x + b.x;
        temp.y = this->y + b.y;
        return temp;
    }
    Point operator+(int a)
    {
        Point temp(x + a, y + a);
        return temp;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    void SetX(int a)
    {
        x = a;
    }
    void SetY(int a)
    {
        y = a;
    }
};

Point operator+(int a, Point b)
{
    Point rez;
    rez.SetX(b.GetX() + a);
    rez.SetY(b.GetY() + a);
    return rez;
}
//Point operator+( Point b, int a)
//{
//    Point rez;
//    rez.SetX(b.GetX() + a);
//    rez.SetY(b.GetY() + a);
//    return rez;
//}

Point operator--(Point&a) {
    a.SetX(a.GetX() - 1);
    a.SetY(a.GetY() - 1);
    return a;
}

Point operator--(Point& a,int) {
    Point temp;
    a.SetX(a.GetX() - 1);
    a.SetY(a.GetY() - 1);
    return temp;
}
Point operator++(Point& a)// ++a
{
    a.SetX(a.GetX() + 10);
    a.SetY(a.GetY() + 10);
    return a;

}
Point operator++(Point& a, int)// a++
{
    Point temp = a;
    a.SetX(a.GetX() + 10);
    a.SetY(a.GetY() + 10);
    return temp;
}

Point operator+=(Point& b,int a) {
    Point rez = b;
    b.SetX(b.GetX() + a);
    b.SetY(b.GetY()+a);
    return rez;
}

Point operator+=(Point& b,Point&  a) {
    Point rez = b;
    b.SetX(b.GetX() + a.GetX());
    b.SetY(b.GetY() + a.GetY());
    return rez;
}

Point operator-=(Point& b, int a) {
    Point rez = b;
    b.SetX(b.GetX() - a);
    b.SetY(b.GetY() - a);
    return rez;
}

Point operator-=(Point& b, Point& a) {
    Point rez = b;
    b.SetX(b.GetX() - a.GetX());
    b.SetY(b.GetY() - a.GetY());
    return rez;
}

Point operator*=(Point& b, int a) {
    Point rez = b;
    b.SetX(b.GetX() * a);
    b.SetY(b.GetY() * a);
    return rez;
}

Point operator*=(Point& b, Point& a) {
    Point rez = b;
    b.SetX(b.GetX() * a.GetX());
    b.SetY(b.GetY() * a.GetY());
    return rez;
}

Point operator/=(Point& b, int a) {
    Point rez = b;
    b.SetX(b.GetX() / a);
    b.SetY(b.GetY() / a);
    return rez;
}

Point operator/=(Point& b, Point& a) {
    Point rez = b;
    b.SetX(b.GetX() / a.GetX());
    b.SetY(b.GetY() / a.GetY());
    return rez;
}

Point operator-(int a, Point& b) {
    Point temp(a-b.GetX(), a - b.GetY());
    return temp;
}

Point operator*(int a, Point& b) {
    Point temp(a * b.GetX(), a * b.GetY());
    return temp;
}
Point operator/(int a, Point& b) {
    Point temp(a / b.GetX(), a / b.GetY());
    return temp;
}

int operator+(Point& a, Point& b) {
    int temp = a.GetX() + b.GetX() + a.GetY() + b.GetY();
    return temp;
}

int main()
{
    srand(unsigned(time(0)));

    Point a(1, 2);
    Point b(3, 4);
    a += 10;
    a += b;
    a /= b;
    a *= b;
    a -= b;
    a.Output();
    /// дз
    //// ---------- уровень 1
    //Point q = 100 - a;
    //q = 10*a;
    //q = 100 / a;
    //int res = a + b;//  через функцию!

    //Point t = --a;
    //Point d = a--;

    // Уровень 2  еще реализовать перегрузку сокращенных форм через функцию!!
    /*
    a+=10;
    a+=b;
      и т.д. для остальных операции
    */

}
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
class shapes
{
public:
	int a;
	shapes(int x)
	{
		a = x;
	}
	~shapes()
	{
		cout << "调用析构函数" << endl;
	}
	virtual void display()
	{
		cout << "shapes::a" << "="<<a<<endl;
	}
};
class rechangle:public shapes
{
public:
	int a;
	rechangle(int x, int y) :shapes(x)
	{
		a = y;
		shapes::a += 2;
	}
	~rechangle()
	{
		cout << "调用析构函数" << endl;
	}
	void display()
	{
		shapes::display();
		cout << "rechangle::a" << "=" << a << endl;
	}
};
class cirle:public shapes
{
	const double pi;
public:
	int a;
	cirle(int x) :pi(3.14), shapes(x)
	{
		a = x * x*pi;
	}
	~cirle()
	{
		cout << "调用析构函数" << endl;
	}
	void display()
	{
		shapes::display();
		cout<< "cirle::a" << "=" << a << endl;
	}
};
void f(shapes &bb)
{
	bb.display();
}
int main()
{
	shapes b(50), *p;
	rechangle d(100, 200);
	p = &b;
	p->display();
	p = &d;
	p->display();
	f(b);
	f(d);
	system("pause");
	return 0;

}
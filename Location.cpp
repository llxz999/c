#include <iostream>
#include <cstdlib>
#include"cmath"
#include <windows.h>

using namespace std;
class location
{
	float x;
	float y;
public:
	location(float m, float n)
	{
		x = m;
		y = n;
		cout << "调用location（）构造函数" << endl;
	}
	~location()
	{
		cout << "调用location（）析构函数" << endl;
	}
	void move()
	{
		float &xa = y;
		float &xb = x;
		cout << "交换之后的x,y的值：" <<xa<<","<<xb<< endl;
	}
};
class point:public location
{
	float a;
	float b;
public:
	point(float c,float d):location(c,d)
	{
		a = c;
		b = d;
		cout << "调用point（）构造函数" << endl;
	}
	~point()
	{
		cout << "调用point（）析构函数" << endl;
	}
	void move()
	{
		location::move();
	
	}
	void draw()
	{
		cout <<"点坐标："<<"(" <<a << "," << b<<")" << endl;
	}
};
class circle :public point
{
	float s;
	float f;
	const float pi;
public:
	circle(float q,float p):point(q,p),pi(3.14)
	{
		s = q;
		f = p;
		cout << "调用circle（）构造函数" << endl;
	}
	~circle()
	{
		cout << "调用~circle（）构造函数" << endl;
	}
	void move()
	{
		point::move();

	}
	void draw()
	{
		point::draw();
		float l;
		l = pi * sqrt(s*s + f * f);
		cout <<"面积是" << l << endl;
	}
};
int main()
{
	circle A(3, 4);
	A.move();
	A.draw();
	system("pause");
	return 0;
}
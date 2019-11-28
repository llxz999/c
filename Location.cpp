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
		cout << "����location�������캯��" << endl;
	}
	~location()
	{
		cout << "����location������������" << endl;
	}
	void move()
	{
		float &xa = y;
		float &xb = x;
		cout << "����֮���x,y��ֵ��" <<xa<<","<<xb<< endl;
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
		cout << "����point�������캯��" << endl;
	}
	~point()
	{
		cout << "����point������������" << endl;
	}
	void move()
	{
		location::move();
	
	}
	void draw()
	{
		cout <<"�����꣺"<<"(" <<a << "," << b<<")" << endl;
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
		cout << "����circle�������캯��" << endl;
	}
	~circle()
	{
		cout << "����~circle�������캯��" << endl;
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
		cout <<"�����" << l << endl;
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
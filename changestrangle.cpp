#include <iostream>
#include <Cmath>
#include <cstdlib>
using namespace std;
class triangle
{
private:
	double a, b, c;
public:
	void setabc(double x, double y, double z)
	{
		if (((x + y) > z)&((x + z) > y)&((y + z) > x))
		{
			a = x;
			b = y;
			c = z;
		}
		else
		{
			cout << "不能构成三角形" << endl;
			exit(0);
		}
		cout << "x的地址：" << &x << endl;
		cout << "y的地址：" << &y << endl;
		cout << "z的地址：" << &z<< endl;
	}
	void perimeter()
	{
		double per;
		per = a + b + c;
		cout << per << endl;
		cout << "per的地址：" << &per << endl;
	}
	void area()
	{
		double p = (a + b + c) / 2;
		double s;
		s = sqrt(p*(p - a)*(p - b)*(p - c));
		cout << s << endl;
		cout << "p的地址：" << &p << endl;
		cout << "s的地址：" << &s << endl;
	}
	void typeabc()
	{
		double A, B, C;
		A = (b*b + c * c - a * a) / (2 * b*c);
		B = (a*a + c * c - b * b) / (2 * a*c);
		C = (a*a + b * b - c * c) / (2 * a*b);
		if (A > 0 && B > 0 && C > 0)
		{
			cout << "此三角形为锐角三角形" << endl;
		}
		else if ((A < 0)&(B < 0)&(C < 0))
		{
			cout << "此三角形为钝角三角形" << endl;
		}
		else
			cout << "此三角形为直角三角形" << endl;
		cout <<"A的地址："<< &A << endl;
		cout << "B的地址：" << &B << endl;
		cout << "C的地址：" << &C << endl;
	}
	void display()
	{
		cout << "调用该函数的对象的this指针是：";
		cout << this << endl;
		cout << "当前对象a成员的起始地址是：";
		cout << &this->a<< endl;
		cout << "当前对象b成员的起始地址是：";
		cout << &this->b<< endl;
		cout << "当前对象c成员的起始地址是：";
		cout << &this->c<< endl;
		cout << "a=" << a << "b=" << b << "c" << c << endl;
	}
};
int main()
{
	triangle test;
	double x, y, z;
	cout << "输入三角形的三条边：" << endl;
	cin >> x >> y >> z;
	test.setabc(x, y, z);
	cout << "此三角形周长为:" << endl;
	test.perimeter();
	cout << "此三角形面积为:" << endl;
	test.area();
	test.typeabc();
	test.display();
	system("pause");
	return 0;
}
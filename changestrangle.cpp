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
			cout << "���ܹ���������" << endl;
			exit(0);
		}
		cout << "x�ĵ�ַ��" << &x << endl;
		cout << "y�ĵ�ַ��" << &y << endl;
		cout << "z�ĵ�ַ��" << &z<< endl;
	}
	void perimeter()
	{
		double per;
		per = a + b + c;
		cout << per << endl;
		cout << "per�ĵ�ַ��" << &per << endl;
	}
	void area()
	{
		double p = (a + b + c) / 2;
		double s;
		s = sqrt(p*(p - a)*(p - b)*(p - c));
		cout << s << endl;
		cout << "p�ĵ�ַ��" << &p << endl;
		cout << "s�ĵ�ַ��" << &s << endl;
	}
	void typeabc()
	{
		double A, B, C;
		A = (b*b + c * c - a * a) / (2 * b*c);
		B = (a*a + c * c - b * b) / (2 * a*c);
		C = (a*a + b * b - c * c) / (2 * a*b);
		if (A > 0 && B > 0 && C > 0)
		{
			cout << "��������Ϊ���������" << endl;
		}
		else if ((A < 0)&(B < 0)&(C < 0))
		{
			cout << "��������Ϊ�۽�������" << endl;
		}
		else
			cout << "��������Ϊֱ��������" << endl;
		cout <<"A�ĵ�ַ��"<< &A << endl;
		cout << "B�ĵ�ַ��" << &B << endl;
		cout << "C�ĵ�ַ��" << &C << endl;
	}
	void display()
	{
		cout << "���øú����Ķ����thisָ���ǣ�";
		cout << this << endl;
		cout << "��ǰ����a��Ա����ʼ��ַ�ǣ�";
		cout << &this->a<< endl;
		cout << "��ǰ����b��Ա����ʼ��ַ�ǣ�";
		cout << &this->b<< endl;
		cout << "��ǰ����c��Ա����ʼ��ַ�ǣ�";
		cout << &this->c<< endl;
		cout << "a=" << a << "b=" << b << "c" << c << endl;
	}
};
int main()
{
	triangle test;
	double x, y, z;
	cout << "���������ε������ߣ�" << endl;
	cin >> x >> y >> z;
	test.setabc(x, y, z);
	cout << "���������ܳ�Ϊ:" << endl;
	test.perimeter();
	cout << "�����������Ϊ:" << endl;
	test.area();
	test.typeabc();
	test.display();
	system("pause");
	return 0;
}
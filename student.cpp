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
		if (((x + y )> z)&((x + z) > y)&((y + z )> x))
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
	}
	void perimeter()
	{
		double per;
		per = a + b + c;
		cout << per << endl;
	}
	void area()
	{
		double p = (a + b + c) / 2;
		double s;
		s = sqrt(p*(p - a)*(p - b)*(p - c));
		cout << s << endl;
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
	system("pause");
	return 0;
}

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
class triangle
{
private:
	
	double a, b, c;
	double n,per;
public:
	
	triangle(double x=3, double y=4,double z=5)
	{	
		this->a = x;
		this->b = y;
		this->c = z;
		this->n = area();
		this->per = perimeter();
		cout << "�����вι��캯��" << endl;
	}
	triangle(const triangle &r)
	{
		a = r.a;
		b = r.b;
		c = r.c;
		n = r.n;
		per = r.per;
		cout << "���ÿ������캯��" << endl;
	}
	~triangle()
	{
		
		cout << "������������" << endl;
	}
	double perimeter()//�ܳ�
	{
		
		per = a + b + c;
		cout << "�ܳ�Ϊ��" << per << endl;
		return per;
		
	}
	double area()//���
	{
		double p = (a + b + c) / 2;
		n= sqrt(p*(p - a)*(p - b)*(p - c));
		cout << "���Ϊ��"<<n << endl;
		return n;
		
		
	}
    triangle operator + (const triangle &v)
	{
		triangle temp;
		temp.n = this->n+ v.n;
		return temp;
	}
	
	 friend ostream & operator << ( ostream &x,const triangle &y)
	{
		 x << y.n<<endl;
		 return x;
	}
};
int main()
{
	triangle A(3,4,5), B(6, 8, 10),C;
	cout << "C�����=A�����+B�����" << endl;
	C = A + B;
	cout << C;
	cout << "C�����=B���������ֵ��" << endl;
	C = B;
	cout << C;
	system("pause");
	return 0;
}
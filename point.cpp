#include <iostream>
#include <string>
#include "cmath"
using namespace std;
class point
{
	double x, y;
public:
	point();                                                                            //�޲ι��캯��
	point(double a, double b);                                                          //���ι��캯��
	point(const point &r);                                                               //��������
	~point();                                                                           //��������
	double getx();                                                                      //��ȡ������
	double gety();                                                                      //��ȡ������
	void setx(double ax);                                                               //�ı������
	void sety(double bx);                                                               //�ı�������
	void swapaxis();                                              //��������ֵ
	friend double getlength(point &A, point &B);                                        //������֮�����

};
point::point()
{
	cout << "�����޲ι��캯��" << endl;
}
point::point(double a, double b)
{
	this->x = a;
	this->y = b;
	cout << "�����вι��캯��" << endl;
}
point::point(const point &r)
{
	this->x = r.x;
	this->y = r.y;
	cout << "���ÿ����ι��캯��" << endl;
}
point::~point()
{
	cout << "������������" << endl;
}
double point::getx()
{
	cout << "x��ֵ��"<<x << endl;
	
	return x;
}
double point::gety()
{
	cout << "y��ֵ��"<<y << endl;
	
	return y;
}
void point::setx(double ax)
{
	x = ax;
	cout << "�޸ĺ�x��ֵ��" << x << endl;
}
void point::sety(double bx)
{
	y = bx;
	cout << "�޸ĺ�y��ֵ��"<<y << endl;
}
void point::swapaxis()
{
	double &xa = y;
	double &xb = x;
	
	cout << "����֮���x,y��ֵ��"<<xa<<"     " << xb<<endl;
}
double getlength(point &A, point &B)
{
	double s;
	s = sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
	cout << "����֮�����Ϊ��" << s << endl;
	return s;
}
int main()
{
	point A(4,5);
	point B(6,9);
	point C = A;
	A.getx();                                                                //��ȡ������
	A.gety();                                                                //��ȡ������
	A.setx(7);                                                               //�ı������
	A.sety( 8);                                                              //�ı�������
	A.swapaxis();                                                            //��������ֵ
	cout << "A,B��" << endl;
	getlength(A, B);
	cout << "A,C��" << endl;
	getlength(A, C);
	system("pause");
	return 0;
}

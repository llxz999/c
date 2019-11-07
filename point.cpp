#include <iostream>
#include <string>
#include "cmath"
using namespace std;
class point
{
	double x, y;
public:
	point();                                                                            //无参构造函数
	point(double a, double b);                                                          //带参构造函数
	point(const point &r);                                                               //拷贝函数
	~point();                                                                           //析构函数
	double getx();                                                                      //提取横坐标
	double gety();                                                                      //提取纵坐标
	void setx(double ax);                                                               //改变横坐标
	void sety(double bx);                                                               //改变纵坐标
	void swapaxis();                                              //交换坐标值
	friend double getlength(point &A, point &B);                                        //求两点之间距离

};
point::point()
{
	cout << "调用无参构造函数" << endl;
}
point::point(double a, double b)
{
	this->x = a;
	this->y = b;
	cout << "调用有参构造函数" << endl;
}
point::point(const point &r)
{
	this->x = r.x;
	this->y = r.y;
	cout << "调用拷贝参构造函数" << endl;
}
point::~point()
{
	cout << "调用析构函数" << endl;
}
double point::getx()
{
	cout << "x的值："<<x << endl;
	
	return x;
}
double point::gety()
{
	cout << "y的值："<<y << endl;
	
	return y;
}
void point::setx(double ax)
{
	x = ax;
	cout << "修改后x的值：" << x << endl;
}
void point::sety(double bx)
{
	y = bx;
	cout << "修改后y的值："<<y << endl;
}
void point::swapaxis()
{
	double &xa = y;
	double &xb = x;
	
	cout << "交换之后的x,y的值："<<xa<<"     " << xb<<endl;
}
double getlength(point &A, point &B)
{
	double s;
	s = sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
	cout << "两点之间距离为：" << s << endl;
	return s;
}
int main()
{
	point A(4,5);
	point B(6,9);
	point C = A;
	A.getx();                                                                //提取横坐标
	A.gety();                                                                //提取纵坐标
	A.setx(7);                                                               //改变横坐标
	A.sety( 8);                                                              //改变纵坐标
	A.swapaxis();                                                            //交换坐标值
	cout << "A,B：" << endl;
	getlength(A, B);
	cout << "A,C：" << endl;
	getlength(A, C);
	system("pause");
	return 0;
}

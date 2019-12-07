#include<iostream>
#include<string>
using namespace std;
class vect
{
	int x, y;
public:
	vect()
	{

	}
	vect(int a, int b):x(a),y(b)
	{

	}
	friend vect operator +=(vect& v1, vect& v2)
	{
		v1.x += v2.x;
		v1.y += v2.y;
		return v1;
	}
	vect operator -=(vect v)
	{
		x -= v.x;
		y -= v. y;
		return *this;
	}
	void display()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
};
int main()
{
	vect v1(6, 8), v2(3, 6), v3;
	cout << "original v1=" << endl;
	v1.display();
	cout << "original v2=" << endl;
	v2.display();
	v3 = v1;
	cout << "original v3=" << endl;
	v3.display();
	v1 += v2;
	cout << "after v1+=v2,v1=" << endl;
	v1.display();
	cout << "after v1+=v2,v2=" << endl;
	v2.display();
	v2 -= v3;
	cout << "after v2-=v3,v2=" << endl;
	v2.display();
	cout << "after v2-=v3,v3=" << endl;
	v3.display();
	system("pause");
	return 0;
}

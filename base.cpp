#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
class base
{
public:int a;
	   static int count;
	   base(int a=0,int b=0, int c=0)
	   {
		   cout << "base() is called" << endl;
		   this->a = a;
		   this->b = b;
		   this->c = c;
		   count++;
	   }
	   ~base()
	   {
		   cout << "~base() is called" << endl;
		   getchar();

	   }
	   void print()
	   {
		   cout << "基类对象成员数据:" <<a<<b<<c<<endl;
		  
	   }
	   static int statistic()
	   {
		   cout << "类对象个数："<<count << endl;
		   return 0;
	   }
protected: int b;
private: int c; 
};
int base::count = 0;
class derived1 :public base //公有继承
{
private:
	int bb;

public:
	derived1(int b = 2) :base(2, 2, 2)
	{
		this->bb = b;
		cout << "derived1() is called" << endl;
	}
	~derived1()
	{
		cout << "~derived1() is called" << endl;
		getchar();

	}

	void print()//探索公有继
	{
		//基类数据传承探索
		a = 200;//a仍为公有数据,子类内可以直接访问
		b = 200;//b仍为保护数据,子类内可以直接访问
		//c = 200;//报错,基类私有成员在子类不可见

		//基类函数传承探索
		base::print();
		base::statistic();
		cout << "自身添加数据成员: bb = " << bb << endl;


	}

};

class derived2 : protected base//保护继承
{

private:
	int cc;
public:
	derived2(int c = 3) :base(3, 3, 3)
	{
		cout << "derived2() is called" << endl;

		this->cc = c;
	}
	~derived2()
	{
		cout << "~derived2() is called" << endl;
		getchar();


	}

	void print()//探索保护继承
	{
		//基类数据传承探索
		a = 300;//a变为保护数据,类内可以直接访问
		b = 300;//b变为保护数据,类内可以直接访问
		//c = 300;//报错,基类私有成员在子类不可见

		//基类函数传承探索
		base::print();
		base::statistic();
		cout << "自身添加数据成员: cc = " << cc << endl;


	}
};

class derived3 : private base //私有继承
{

private:
	int dd;
public:
	derived3(int d = 4) : base(4, 4, 4)
	{
		cout << "derived3() is called" << endl;

		this->dd = d;
	}

	~derived3()
	{
		cout << "~derived3() is called" << endl;
		getchar();

	}
	void print()//探索私有继承
	{
		//基类数据传承探索
		a= 400;//a变为私有数据,子类内可以直接访问
		b = 400;//b变为私有数据,子类内可以直接访问
		//c = 400;//报错,基类私有成员在子类不可见

		//基类函数传承探索
		base::print();
		base::statistic();
		cout << "自身添加数据成员: dd = " << dd << endl;


	}
};

int main()
{

	//功能1:通过比较类的大小,证明无论哪种继承方式都会全盘接受基类成员,包括私有的成员

#if 1

	cout << "基类base的大小为: " << sizeof(base) << endl;
	cout << "--类derived1的大小为: " << sizeof(derived1) << endl;
	cout << "--类derived2的大小为: " << sizeof(derived2) << endl;
	cout << "--类derived3的大小为: " << sizeof(derived3) << endl;

	cout << "---------------------------------" << endl;

#endif


	//功能2:构造函数和析构函数的调用
#if 1
	base a;
	cout << "---------------" << endl;
	a.print();
	derived1 b;
	cout << "---------------" << endl;
	b.print();

	derived2 c;
	cout << "---------------" << endl;
	c.print();

	derived3 d;
	cout << "---------------" << endl;
	d.print();

#endif

	//功能3:三种继承的使用(类外访问探索)

#if 0
	//------------类derived1--公有继承--类base---------------
	derived1 b;//派生类derived1的对象

	b.a = 200; //正确, 子类内仍然为公有成员,类内外均可访问
  //b.b = 200; //错误,子类内仍然为保护成员,类内可直接访问,类外部可以
  //b.c = 200; //错误,基类私有成员在子类内外均不可见
  //b.base::print();//正确, 子类内函数仍然为公有成员,类内外均可访问

#endif

#if 0
	//------------类derived2--保护继承--类base---------------
	derived2 c;//派生类derived2的对象
	//c.a = 300;//错误,变为子类保护成员,无法类外直接访问
	//c.b = 300;//错误,变为子类保护成员,无法类外直接访问
	//c.c = 300;//错误,基类私有成员在子类内外均不可见
	//c.base::print(); //错误,变为子类的保护函数,不可类外访问


#endif

#if 0
	//------------类derived3--私有继承--类base---------------

	derived3 d;//派生类derived3的对象

	//d.a = 400; //报错,变为子类的私有成员,无法类外直接访问
	//d.b = 400; //报错,变为子类的私有成员,无法类外直接访问
	//d.c = 400; //报错,基类私有成员在子类内外均不可见

	//d.print();    //报错,变为子类私有成员,无法类外直接访问
	//d.base::print(); //错误,继承后变为子类私有函数,无法类外直接访问

#endif

	system("pause");

	return 0;
}
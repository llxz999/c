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
		   cout << "��������Ա����:" <<a<<b<<c<<endl;
		  
	   }
	   static int statistic()
	   {
		   cout << "����������"<<count << endl;
		   return 0;
	   }
protected: int b;
private: int c; 
};
int base::count = 0;
class derived1 :public base //���м̳�
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

	void print()//̽�����м�
	{
		//�������ݴ���̽��
		a = 200;//a��Ϊ��������,�����ڿ���ֱ�ӷ���
		b = 200;//b��Ϊ��������,�����ڿ���ֱ�ӷ���
		//c = 200;//����,����˽�г�Ա�����಻�ɼ�

		//���ຯ������̽��
		base::print();
		base::statistic();
		cout << "����������ݳ�Ա: bb = " << bb << endl;


	}

};

class derived2 : protected base//�����̳�
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

	void print()//̽�������̳�
	{
		//�������ݴ���̽��
		a = 300;//a��Ϊ��������,���ڿ���ֱ�ӷ���
		b = 300;//b��Ϊ��������,���ڿ���ֱ�ӷ���
		//c = 300;//����,����˽�г�Ա�����಻�ɼ�

		//���ຯ������̽��
		base::print();
		base::statistic();
		cout << "����������ݳ�Ա: cc = " << cc << endl;


	}
};

class derived3 : private base //˽�м̳�
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
	void print()//̽��˽�м̳�
	{
		//�������ݴ���̽��
		a= 400;//a��Ϊ˽������,�����ڿ���ֱ�ӷ���
		b = 400;//b��Ϊ˽������,�����ڿ���ֱ�ӷ���
		//c = 400;//����,����˽�г�Ա�����಻�ɼ�

		//���ຯ������̽��
		base::print();
		base::statistic();
		cout << "����������ݳ�Ա: dd = " << dd << endl;


	}
};

int main()
{

	//����1:ͨ���Ƚ���Ĵ�С,֤���������ּ̳з�ʽ����ȫ�̽��ܻ����Ա,����˽�еĳ�Ա

#if 1

	cout << "����base�Ĵ�СΪ: " << sizeof(base) << endl;
	cout << "--��derived1�Ĵ�СΪ: " << sizeof(derived1) << endl;
	cout << "--��derived2�Ĵ�СΪ: " << sizeof(derived2) << endl;
	cout << "--��derived3�Ĵ�СΪ: " << sizeof(derived3) << endl;

	cout << "---------------------------------" << endl;

#endif


	//����2:���캯�������������ĵ���
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

	//����3:���ּ̳е�ʹ��(�������̽��)

#if 0
	//------------��derived1--���м̳�--��base---------------
	derived1 b;//������derived1�Ķ���

	b.a = 200; //��ȷ, ��������ȻΪ���г�Ա,��������ɷ���
  //b.b = 200; //����,��������ȻΪ������Ա,���ڿ�ֱ�ӷ���,���ⲿ����
  //b.c = 200; //����,����˽�г�Ա��������������ɼ�
  //b.base::print();//��ȷ, �����ں�����ȻΪ���г�Ա,��������ɷ���

#endif

#if 0
	//------------��derived2--�����̳�--��base---------------
	derived2 c;//������derived2�Ķ���
	//c.a = 300;//����,��Ϊ���ౣ����Ա,�޷�����ֱ�ӷ���
	//c.b = 300;//����,��Ϊ���ౣ����Ա,�޷�����ֱ�ӷ���
	//c.c = 300;//����,����˽�г�Ա��������������ɼ�
	//c.base::print(); //����,��Ϊ����ı�������,�����������


#endif

#if 0
	//------------��derived3--˽�м̳�--��base---------------

	derived3 d;//������derived3�Ķ���

	//d.a = 400; //����,��Ϊ�����˽�г�Ա,�޷�����ֱ�ӷ���
	//d.b = 400; //����,��Ϊ�����˽�г�Ա,�޷�����ֱ�ӷ���
	//d.c = 400; //����,����˽�г�Ա��������������ɼ�

	//d.print();    //����,��Ϊ����˽�г�Ա,�޷�����ֱ�ӷ���
	//d.base::print(); //����,�̳к��Ϊ����˽�к���,�޷�����ֱ�ӷ���

#endif

	system("pause");

	return 0;
}
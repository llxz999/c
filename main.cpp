#include <iostream>
#include <string>
#include<cstdlib>

using namespace std;
char n[20];
char i[3];
/*----------------------------------*
		 Class Definition
*-----------------------------------*/
class student
{
private:
	char *name;
	char  *id;
	float age;
	string address;

public:
	//���캯������������
	student();
	~student();
	student(const student &r);
	student(const char *username, const char *userid, float age, std::string address);
	void input();
	void display();
	void rewrite();
};
student::student()
{
	cout << "�����޲ι��캯��" << endl;
}
student::~student()
{
	cout << "������������" << endl;
	delete[]name;
	delete[]n;
	delete[]i;
}
student::student(const student &r)
{
	age = r.age;
	address = r.address;
	if (r.name != NULL)
	{
		int len = strlen(r.name);
		this->name = new char[len + 1];
		strcpy(this->name, r.name);
	}
	if (r.id != NULL)
	{
		this->id = new char[3];
		strcpy(this->id, r.id);
	}
	cout << "���ÿ������캯��" << endl;
}
student::student(const char *username, const char *userid, float age, std::string address)
{
	if (username != NULL)
	{
		int len = strlen(username);
		name = new char[len + 1];
		strcpy(name, username);
	}
	if (userid != NULL)
	{
		id = new char[3];
		strcpy(id, userid);
	}
	this->age = age;
	this->address = address;
	cout << "�����вι��캯��" << endl;

}
void student::input()
{
	cout << "��������" << endl;
	cin >> n;
	cout << "������ѧ�ţ�" << endl;
	cin >> i;
	cout << "���������䣺" << endl;
	cin >> age;
	cout << "�������ͥסַ" << endl;
	cin >> address;
}
void student::display()
{
	cout << "������Ϊ��" << endl;
	cout << "������" << n << endl;
	cout << "ѧ��:" << i << endl;
	cout << "����:" << age << endl;
	cout << "��ͥסַ:" << address << endl;
}
void student::rewrite()
{
	int m;
	cout << "���������֣�" << endl;
	cout << "����1�޸�����" << endl;
	cout << "����2�޸�ѧ��" << endl;
	cout << "����3�޸�����" << endl;
	cout << "����4�޸ļ�ͥ��ַ" << endl;
	cout << "����0����Ҫ�޸��˳�ѭ��" << endl;
	cin >> m;
	switch (m)
	{
	case 1:cout << "�޸�����"; cin >> n; break;
	case 2:cout << "�޸�ѧ��"; cin >> i; break;
	case 3:cout << "�޸�����"; cin >> age; break;
	case 4:cout << "�޸ļ�ͥסַ"; cin >> address; break;
	default:break;
	}
	cout << "�޸ĳɹ�" << endl;
}
int main()
{
	char *name = new char[20];
	strcpy(name, n);
	char *id = new char[3];
	strcpy(id, i);
	student test;
	test.input();
	test.rewrite();
	test.display();
	student test1(name, id, 20, "sdnu");
	student test2(test1);
	test1.display();
	test2.display();
	system("pause");
	return 0;


}
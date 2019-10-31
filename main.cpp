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
	//构造函数和析构函数
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
	cout << "调用无参构造函数" << endl;
}
student::~student()
{
	cout << "调用析构函数" << endl;
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
	cout << "调用拷贝构造函数" << endl;
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
	cout << "调用有参构造函数" << endl;

}
void student::input()
{
	cout << "输入姓名" << endl;
	cin >> n;
	cout << "请输入学号：" << endl;
	cin >> i;
	cout << "请输入年龄：" << endl;
	cin >> age;
	cout << "请输入家庭住址" << endl;
	cin >> address;
}
void student::display()
{
	cout << "输出结果为：" << endl;
	cout << "姓名：" << n << endl;
	cout << "学号:" << i << endl;
	cout << "年龄:" << age << endl;
	cout << "家庭住址:" << address << endl;
}
void student::rewrite()
{
	int m;
	cout << "请输入数字：" << endl;
	cout << "输入1修改姓名" << endl;
	cout << "输入2修改学号" << endl;
	cout << "输入3修改年龄" << endl;
	cout << "输入4修改家庭地址" << endl;
	cout << "输入0不需要修改退出循环" << endl;
	cin >> m;
	switch (m)
	{
	case 1:cout << "修改姓名"; cin >> n; break;
	case 2:cout << "修改学号"; cin >> i; break;
	case 3:cout << "修改年龄"; cin >> age; break;
	case 4:cout << "修改家庭住址"; cin >> address; break;
	default:break;
	}
	cout << "修改成功" << endl;
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
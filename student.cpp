#include <iostream>
#include <string>
#include<time.h>

using namespace std;
class school;
class student
{
private:
	string name;
	bool gender;
	string id;
	double GPA;
public:
	static double  n;
	student();
	student(std::string name,bool gender,std::string id);
	double printgpa();
	~student();
	void display(school &);
	void sdisplay();
	
	
};
class school
{
private:
	string city;
	string street;
	int number;
public:
	school();
	school(std::string city, std::string street, int number);
	~school();
	friend  class student;
	void sprint() const;
};
class date
{
	int year;
	int month;
	int day;
	int age;
public:
	date();
	date(int year, int month, int day,int age);
	~date();
	void print(student a) const;
};

date::date()
{
	cout << "调用date无参构造函数" << endl;
}
date::date(int year, int month, int day,int age)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->age = age;
	cout << "调用date有参构造函数" << endl;
}

date::~date()
{
	cout << "调用date析构函数" << endl;
}

school::school()
{
	cout << "调用school无参构造函数" << endl;
}
school::school(std::string city, std::string street, int number)
{
	this->city = city;
	this->street = street;
	this->number = number;
	cout << "调用school有参构造函数" << endl;
}
school::~school()
{
	cout << "调用school析构函数" << endl;
}
double student::n = 0;
student::student()
{
	cout << "调用student无参构造函数" << endl;
}
void school::sprint() const
{
	cout<< "城市:"<<city<<endl;
	cout<< "街道:"<<street<<endl;
	cout<<"街道号:"<<number<<endl;
}
student::student(std::string name, bool gender, std::string id)
{
	this->name = name;
	this->gender = gender;
	this->id = id; 
	n++;
	cout << "调用student有参构造函数" << endl;
}

student::~student()
{
	cout << "调用student析构函数" << endl;
}
void student::sdisplay()
{
	cout << "姓名:" << name << endl;
	cout << "性别（男1女0）：" << gender << endl; 
	cout << "学号：" << id << endl;
	
	
}
void date::print(student a) const 
{
	cout << "出生日期:" << endl;
	cout << "年:" <<year<< endl;
	cout << "月:" << month<< endl;
	cout << "日:" << day<< endl;
	cout << "年龄:"<<age << endl;
}
double student:: printgpa()
{
	GPA=rand() % 6 + 1;
	cout << "绩点:"<<GPA <<endl;
	cout << "学生个数:" << n << endl;
	return 0;
}
void student::display(school& obj)
{
	obj.sprint();
}
int main()
{
	student A("lili",1,"201811010125");
	A.sdisplay();
	srand((int)time(NULL));
	A.printgpa();
	date q(1999, 9, 9,20);
	q.print(A);
	school w("济南", "大学路", 1);
	A.display(w);
	system("pause");
	return 0;
}
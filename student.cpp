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
	cout << "����date�޲ι��캯��" << endl;
}
date::date(int year, int month, int day,int age)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->age = age;
	cout << "����date�вι��캯��" << endl;
}

date::~date()
{
	cout << "����date��������" << endl;
}

school::school()
{
	cout << "����school�޲ι��캯��" << endl;
}
school::school(std::string city, std::string street, int number)
{
	this->city = city;
	this->street = street;
	this->number = number;
	cout << "����school�вι��캯��" << endl;
}
school::~school()
{
	cout << "����school��������" << endl;
}
double student::n = 0;
student::student()
{
	cout << "����student�޲ι��캯��" << endl;
}
void school::sprint() const
{
	cout<< "����:"<<city<<endl;
	cout<< "�ֵ�:"<<street<<endl;
	cout<<"�ֵ���:"<<number<<endl;
}
student::student(std::string name, bool gender, std::string id)
{
	this->name = name;
	this->gender = gender;
	this->id = id; 
	n++;
	cout << "����student�вι��캯��" << endl;
}

student::~student()
{
	cout << "����student��������" << endl;
}
void student::sdisplay()
{
	cout << "����:" << name << endl;
	cout << "�Ա���1Ů0����" << gender << endl; 
	cout << "ѧ�ţ�" << id << endl;
	
	
}
void date::print(student a) const 
{
	cout << "��������:" << endl;
	cout << "��:" <<year<< endl;
	cout << "��:" << month<< endl;
	cout << "��:" << day<< endl;
	cout << "����:"<<age << endl;
}
double student:: printgpa()
{
	GPA=rand() % 6 + 1;
	cout << "����:"<<GPA <<endl;
	cout << "ѧ������:" << n << endl;
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
	school w("����", "��ѧ·", 1);
	A.display(w);
	system("pause");
	return 0;
}
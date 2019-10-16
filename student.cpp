#include <iostream>
#include <string>

using namespace std;

/*----------------------------------*
 Class Definition
*-----------------------------------*/
class student
{
private:
 string name;
	int number;
	bool gender;
	int year;
	int month;
	int day;
	float high;
	float weight;
	float score;
 string address;

public:
	void input()
	{
 cout << "请输入姓名：" << endl;
 cin >> name;
 cout << "请输入性别(1为男生0为女生）：" << endl;
 cin >> gender;
 cout << "请输入出生年月日" << endl;
 cin >> year >> month >> day;
 cout << "请输入身高(cm)体重(kg)" << endl;
 cin >> weight >> high;
 cout << "请输入高考成绩" << endl;
 cin >> score;
 cout << "请输入家庭住址" << endl;
 cin >> address;
	}
	void display()
	{
 cout << "输出结果为：" << endl;
 cout << "名字:" << name << endl;
 cout << "性别(1为男生0为女生）:" << gender << endl;
 cout << "出生年月日:" << year <<"."<< month<<"." << day << endl;
 cout << "身高（cm）体重(kg):" << weight<<"  " << high << endl;
 cout << "高考成绩:" << score << endl;
 cout << "家庭住址:" << address << endl;
	}
	void rewrite()
	{
		int n;
 cout << "请输入数字：" << endl;
 cout << "输入1修改姓名" << endl;
 cout << "输入2修改性别" << endl;
 cout << "输入3修改出生年月日" << endl;
 cout << "输入4修改身高体重" << endl;
 cout << "输入5修改高考成绩" << endl;
 cout << "输入6修改家庭住址" << endl;
 cout << "输入0不需要修改" << endl;
 cin >> n;
		switch (n)
		{
		case 1:cout << "修改姓名"; cin >> name; break;
		case 2:cout << "修改性别"; cin >> gender; break;
		case 3:cout << "修改出生年月日"; cin >> year >> month >> day; break;
		case 4:cout << "修改身高体重"; cin >> weight >> high; break;
		case 5:cout << "修改高考成绩"; cin >> score; break;
		case 6:cout << "修改家庭住址"; cin >> address; break;
		default:break;
		}
 cout << "修改成功" << endl;
	}
};

void main()
{
 student test;
 test.input();
 test.rewrite();
 test.display();
	system("pause");



} 

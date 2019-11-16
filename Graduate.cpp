#include <iostream>
#include <string>
using namespace std;
class graduate
{
	char *name;                 //名字
	bool gender;                //性别
	long long id;                 //学号
	double score;               //入学成绩
	string research;            //研究领域
	string tutor;               //指导老师
	double averagescores;
public:
	static double  n;
	graduate();                                                           //无参构造函数
	graduate(const char *username, double score, bool gender, long long id, std::string research, std::string tutor);//带参构造函数
	graduate(const graduate &r);                                        //拷贝函数
	~graduate();                                                        //析构函数
	void displayscore();
	void display();
	void display() const;
	friend void grade(double s);
	double sco();
};
double graduate::n = 0;
graduate::graduate()
{

	cout << "调用无参构造函数" << endl;
}
graduate::~graduate()
{
	cout << "调用析构函数" << endl;
}
graduate::graduate(const graduate &r)
{
	gender = r.gender;
	id = r.id;
	score = r.score;
	research = r.research;
	tutor = r.tutor;
	if (r.name != NULL)
	{
		int len = strlen(r.name);
		this->name = new char[len + 1];
		strcpy(this->name, r.name);
	}
	cout << "调用拷贝构造函数" << endl;
}
graduate::graduate(const char *username, double score, bool gender, long long id, std::string research, std::string tutor)
{
	if (username != NULL)
	{
		int len = strlen(username);
		name = new char[len + 1];
		strcpy(name, username);
	}
	this->gender = gender;
	this->id = id;
	this->research = research;
	this->tutor = tutor;
	this->score = score;
	n++;
	cout << "调用有参构造函数" << endl;

}
double graduate::sco()
{
	return score;
}

void graduate::displayscore()
{
	int i = 0;
	double t[20];
	double s = 0;
	cout << "请输入" << n << "个学生的成绩：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> t[i];
		s += t[i];
	}
	averagescores = (s / n);
	cout << "平均成绩" << averagescores << endl;
}
void graduate::display()
{
	cout << "姓名：" << name << endl;
	cout << "性别(男为1女为0)：" << gender << endl;
	cout << "学号：" << id << endl;
	cout << "成绩：" << score << endl;
	cout << "研究领域：" << research << endl;
	cout << "指导老师：" << tutor << endl;
}
void graduate::display() const
{
	cout << "姓名：" << name << endl;
	cout << "性别(男为1女为0)：" << gender << endl;
	cout << "学号：" << id << endl;
	cout << "成绩：" << score << endl;
	cout << "研究领域：" << research << endl;
	cout << "指导老师：" << tutor << endl;
}
void grade(double s)
{
	cout << "成绩等级：" << endl;
	if (s >= 90)
	{
		cout << "A" << endl;
	}
	else if ((s >= 80)&(s < 90))
	{
		cout << "B" << endl;
	}
	else if ((s >= 70)&(s < 80))
	{
		cout << "C" << endl;
	}
	else if ((s >= 60)&(s < 70))
	{

		cout << "D" << endl;
	}
	else
	{
		cout << "E" << endl;
	}

}
int  main()
{
	char *name = new char[20];
	strcpy(name, "lv");
	graduate A(name, 87, 1, 201811010125, "计算机", "张庆科");
	graduate B("liao", 89, 0, 201811010127, "计算机", "张庆科");
	const graduate C("lili", 80, 0, 201811010133, "计算机", "张庆科");
	A.display();
	grade(A.sco());
	B.display();
	grade(B.sco());
	C.display();
	grade(80);
	A.displayscore();
	system("pause");
	return 0;
}
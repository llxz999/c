#include <iostream>
#include <string>
using namespace std;
class graduate
{
	char *name;                 //����
	bool gender;                //�Ա�
	long long id;                 //ѧ��
	double score;               //��ѧ�ɼ�
	string research;            //�о�����
	string tutor;               //ָ����ʦ
	double averagescores;
public:
	static double  n;
	graduate();                                                           //�޲ι��캯��
	graduate(const char *username, double score, bool gender, long long id, std::string research, std::string tutor);//���ι��캯��
	graduate(const graduate &r);                                        //��������
	~graduate();                                                        //��������
	void displayscore();
	void display();
	void display() const;
	friend void grade(double s);
	double sco();
};
double graduate::n = 0;
graduate::graduate()
{

	cout << "�����޲ι��캯��" << endl;
}
graduate::~graduate()
{
	cout << "������������" << endl;
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
	cout << "���ÿ������캯��" << endl;
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
	cout << "�����вι��캯��" << endl;

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
	cout << "������" << n << "��ѧ���ĳɼ���" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> t[i];
		s += t[i];
	}
	averagescores = (s / n);
	cout << "ƽ���ɼ�" << averagescores << endl;
}
void graduate::display()
{
	cout << "������" << name << endl;
	cout << "�Ա�(��Ϊ1ŮΪ0)��" << gender << endl;
	cout << "ѧ�ţ�" << id << endl;
	cout << "�ɼ���" << score << endl;
	cout << "�о�����" << research << endl;
	cout << "ָ����ʦ��" << tutor << endl;
}
void graduate::display() const
{
	cout << "������" << name << endl;
	cout << "�Ա�(��Ϊ1ŮΪ0)��" << gender << endl;
	cout << "ѧ�ţ�" << id << endl;
	cout << "�ɼ���" << score << endl;
	cout << "�о�����" << research << endl;
	cout << "ָ����ʦ��" << tutor << endl;
}
void grade(double s)
{
	cout << "�ɼ��ȼ���" << endl;
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
	graduate A(name, 87, 1, 201811010125, "�����", "�����");
	graduate B("liao", 89, 0, 201811010127, "�����", "�����");
	const graduate C("lili", 80, 0, 201811010133, "�����", "�����");
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
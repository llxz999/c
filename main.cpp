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
		cout << "������������" << endl;
		cin >> name;
		cout << "�������Ա�(1Ϊ����0ΪŮ������" << endl;
		cin >> gender;
		cout << "���������������" << endl;
		cin >> year >> month >> day;
		cout << "���������(cm)����(kg)" << endl;
		cin >> weight >> high;
		cout << "������߿��ɼ�" << endl;
		cin >> score;
		cout << "�������ͥסַ" << endl;
		cin >> address;
	}
	void display()
	{
		cout << "������Ϊ��" << endl;
		cout << "����:" << name << endl;
		cout << "�Ա�(1Ϊ����0ΪŮ����:" << gender << endl;
		cout << "����������:" << year <<"."<< month<<"." << day << endl;
		cout << "��ߣ�cm������(kg):" << weight<<"  " << high << endl;
		cout << "�߿��ɼ�:" << score << endl;
		cout << "��ͥסַ:" << address << endl;
	}
	void rewrite()
	{
		int n;
		cout << "���������֣�" << endl;
		cout << "����1�޸�����" << endl;
		cout << "����2�޸��Ա�" << endl;
		cout << "����3�޸ĳ���������" << endl;
		cout << "����4�޸��������" << endl;
		cout << "����5�޸ĸ߿��ɼ�" << endl;
		cout << "����6�޸ļ�ͥסַ" << endl;
		cout << "����0����Ҫ�޸�" << endl;
		cin >> n;
		switch (n)
		{
		case 1:cout << "�޸�����"; cin >> name; break;
		case 2:cout << "�޸��Ա�"; cin >> gender; break;
		case 3:cout << "�޸ĳ���������"; cin >> year >> month >> day; break;
		case 4:cout << "�޸��������"; cin >> weight >> high; break;
		case 5:cout << "�޸ĸ߿��ɼ�"; cin >> score; break;
		case 6:cout << "�޸ļ�ͥסַ"; cin >> address; break;
		default:break;
		}
		cout << "�޸ĳɹ�" << endl;
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
/*************************************************
** ���� : Snippet Demo
** ���� : lvliaoxingzi
** �汾 : 2019-8-30 / 20:00
** ��Ȩ : GNU General Public License(GNU GPL)
/**************************************************/


#include <iostream>
#include<string>


using namespace std;

/*----------------------------------*
		 Class Definition
*-----------------------------------*/




/*----------------------------------*
		  Main Function
*-----------------------------------*/
/*�������һ��
int add(int a,int b)
{
	return a + b;
}
int main()
{
	int x, y, sum;
	cout << "Please input x and y:" << endl;
	cin >> x >> y;
	sum = add(x, y);
	cout << "sum is:" << endl;
	cout << sum << endl;
	system("pause");
	return 0;
}
*/
/*������ڶ���
int main()
{
	float r;										//�뾶
	cout << "������뾶r:" << endl;
	cin >> r;
	float s;									//���
	float c;									//�ܳ�
	const float x = 3.14;
	s = x * r*r;
	c = 2 * x*r;
	cout << "�����s�ǣ�" << s << endl;
	cout << "���ܳ�c�ǣ�" << c << endl;
	system("pause");
	return 0;
}*/
/*�����������
int main()
{
	int *ptr;
	int a = 0, b = 0;
	ptr = new int[20];
	int i;
	cout>>"�������ʮ����������>>endl;
	for ( i=0;i<20;i++)
	{
		cin >> ptr[i];
		if (ptr[i] > 0)
			a = a + 1;
		else
			b = b + 1;
	}
	cout << "�����ĸ���Ϊ��" << endl;
	cout << a << endl;
	cout << "�����ĸ���Ϊ��" << endl;
	cout << b<< endl;
	delete[]ptr;
	system("pause");
	return 0;

}*/
float checkagescore(float age, float score)
{
	if (age > 16 || age < 25)
	{
		cout << age << endl;
	}

	if (score >= 0 || score <= 5)
	{
		cout << score << endl;
	}
	if (age < 16 || age>25)
		throw age;
	if (score < 0 || score>5)
		throw score;
	return 0;
}
int main()
{
	cout << "��������" << endl;
	string  ptr;
	cin >> ptr;
	float t;
	float s;
	cout << "��������ͳɼ���������16-25���ɼ�Ϊ0-5��" << endl;
	cin >> t >> s;
	cout << "���Ϊ" << endl;
	cout << "����Ϊ" << endl;
	cout << ptr<< endl;
	cout << "������ɼ�:" << endl;
	try
	{
		cout << checkagescore(t, s) << endl;
	}

	catch (float)
	{
		cout << "�����������ɼ�������Ҫ��" << endl;
	}
	cout << "calculate finished" << endl;
	system("pause");
	return 0;

}

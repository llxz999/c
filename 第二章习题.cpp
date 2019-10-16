/*************************************************
** 功能 : Snippet Demo
** 作者 : lvliaoxingzi
** 版本 : 2019-8-30 / 20:00
** 版权 : GNU General Public License(GNU GPL)
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
/*第五题第一问
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
/*第五题第二问
int main()
{
	float r;										//半径
	cout << "请输入半径r:" << endl;
	cin >> r;
	float s;									//面积
	float c;									//周长
	const float x = 3.14;
	s = x * r*r;
	c = 2 * x*r;
	cout << "其面积s是：" << s << endl;
	cout << "其周长c是：" << c << endl;
	system("pause");
	return 0;
}*/
/*第五题第三问
int main()
{
	int *ptr;
	int a = 0, b = 0;
	ptr = new int[20];
	int i;
	cout>>"请输入二十个整数：“>>endl;
	for ( i=0;i<20;i++)
	{
		cin >> ptr[i];
		if (ptr[i] > 0)
			a = a + 1;
		else
			b = b + 1;
	}
	cout << "正数的个数为：" << endl;
	cout << a << endl;
	cout << "负数的个数为：" << endl;
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
	cout << "输入名字" << endl;
	string  ptr;
	cin >> ptr;
	float t;
	float s;
	cout << "输入年龄和成绩（年龄在16-25，成绩为0-5）" << endl;
	cin >> t >> s;
	cout << "结果为" << endl;
	cout << "名字为" << endl;
	cout << ptr<< endl;
	cout << "年龄与成绩:" << endl;
	try
	{
		cout << checkagescore(t, s) << endl;
	}

	catch (float)
	{
		cout << "不符合年龄或成绩的输入要求" << endl;
	}
	cout << "calculate finished" << endl;
	system("pause");
	return 0;

}

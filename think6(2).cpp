#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class A
{
	int len;
	char *str;
public:
	A(const char *s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
		len = strlen(s);
	}
	char & operator[](int n)
	{
		if (n<0 || n>len - 1)
		{
			cout << "overstep the boundary" << endl;
			exit(1);
		}
		else
		{
			return *(str + n);
		}
	}
	void display()
	{
		cout << str << endl;
	}
};
int main()
{
	A word("this is a apple");
	cout << "this sentence is:" ;
	word.display();
	cout << "word[0] is:" ;
	cout << word[0] << endl;
	cout << word[20] << endl;
	system("pause");
	return 0;

}
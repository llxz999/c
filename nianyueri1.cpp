#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "nianyueri.h"

using namespace std;
bool check(time &t)
{
	if (t.year <= 0 || (t.month <= 0 || t.month > 12) || t.day <= 0) 
		return false;
	else {
		if ((t.month == 1 || t.month == 3 || t.month == 5 || t.month == 7
			|| t.month == 8 || t.month == 10 || t.month == 12) && t.day > 31)
			return false;
		else
		{
			if ((t.month == 4 || t.month == 6 || t.month == 9 || t.month == 11
				) && t.day > 30)return false;
			else
			{
				if (t.month == 2) {
					if (isleapyear(t)) {
						if (t.day > 29)return false; 
						else return true;
					}
					else
					{
						if (t.day > 28)return false; 
						else return true;
					}
				}
			}
		}
	}
}
void initialtime(time & t)
{
	cout << "输入年月日:\n";
	cin >> t.year;
	cin.get();
	cin >> t.month;
	cin.get();
	cin >> t.day;
	cin.get();
	if (!check(t)) { cout << "Try again:\n"; initialtime(t); }
	else
		t.weekday = Weekdaycount(t);
}
void Show(time & t)
{
	cout << "年: " << t.year << "\t";
	cout << "月: " << t.month << "\t";
	cout << "日: " << t.day << "\t";
	cout << "星期: " << t.weekday << endl;
	cout << "这是一个";
	if (isleapyear(t))cout << "闰年"; else cout << "平年";
	cout << " 今年是.\n";
	cout << "这天是这一年的" << Daysyearcount(t) << " 天.\n";
	system("pause");

}
int Weekdaycount(time & t)
{
	return Daycount(t) % 7;
}
int Daycount(time & t)
{
	int days = 0;
	days = (t.year - 1) * 365 + (t.year - 1) / 4 - (t.year - 1) / 100+ (t.year - 1) / 400 + Daysyearcount(t);
	return days;
}
bool isleapyear(time & t)
{
	if (t.year % 4 == 0 && t.year % 100 != 0) return true;//年是四的倍数而且不是100的倍数，是闰年
	if (t.year % 400 == 0)return true;
	else return false;
}
int Daysyearcount(time & t)
{
	int days = 0;
	int mtemp = t.month - 1;
	while (mtemp > 0)
	{
		switch (mtemp)
		{
		case(1):
		case(3):
		case(5):
		case(7):
		case(8):
		case(10):
		case(12):
			days += 31; break;
		case(4):
		case(6):
		case(9):
		case(11):
			days += 30; break;
		case(2):
			days += 28; break;
		default:
			break;
		}
		--mtemp;
	}
	if (isleapyear(t))++days;//如果是闰年，再加上一天
	return days + t.day;//返回计算的天数加上当月的天数
}


#pragma once
#ifndef __NIANYUERI_H__
#define __NIANYUERI_H__


/*************************************************
** 功能 : 年月日
** 作者 : 吕廖杏孜
** 版权 :
/**************************************************/

#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
typedef struct time
{
	int year;
	int month;
	int day;
	unsigned int weekday;
}time;

void initialtime(time & t);//输入初始化时间
void Show(time & t);//显示时间信息
int Weekdaycount(time & t);//计算当日是星期几
int Daycount(time & t);//计算当日是第多少天
int Daysyearcount(time & t);//计算当日是该年的第多少天
bool isleapyear(time & t);//判断该年是不是闰年
bool check(time &t);//检查时间格式是否正确

#endif
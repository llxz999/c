#pragma once
#ifndef __NIANYUERI_H__
#define __NIANYUERI_H__


/*************************************************
** ���� : ������
** ���� : ��������
** ��Ȩ :
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

void initialtime(time & t);//�����ʼ��ʱ��
void Show(time & t);//��ʾʱ����Ϣ
int Weekdaycount(time & t);//���㵱�������ڼ�
int Daycount(time & t);//���㵱���ǵڶ�����
int Daysyearcount(time & t);//���㵱���Ǹ���ĵڶ�����
bool isleapyear(time & t);//�жϸ����ǲ�������
bool check(time &t);//���ʱ���ʽ�Ƿ���ȷ

#endif
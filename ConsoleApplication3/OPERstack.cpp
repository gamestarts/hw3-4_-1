#include "pch.h"
#include "OPERstack.h"
#include<iostream>
using namespace std;
	void OPERstack::start()//��ʼ������ջ���ջ�׷�һ"="�����ж���ʽ����
	{
		oper[0] = '=';
		for (int i = 1; i < 1000; i++)
			oper[i] = NULL;
		top = 1;//ջ��ָ������ջ�׵���һλ
	}

	void OPERstack::push(char a)
	{
		oper[top] = a;
		top++;//������ջ��ͬһѹջ�Ϳ�������ָ��
	}
	char OPERstack::pop()
	{
		top--;
		char op = oper[top];
		oper[top] = NULL;
		return op;//��������� ���ڼ���
	}
	char OPERstack::getTop()
	{
		return oper[top - 1];//ȡջ������ ������ջ �������ж����ȼ�
	}

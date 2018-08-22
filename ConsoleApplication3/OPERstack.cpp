#include "pch.h"
#include "OPERstack.h"
#include<iostream>
using namespace std;
	void OPERstack::start()//初始化函数栈清空栈底放一"="用于判定算式结束
	{
		oper[0] = '=';
		for (int i = 1; i < 1000; i++)
			oper[i] = NULL;
		top = 1;//栈顶指针置于栈底的上一位
	}

	void OPERstack::push(char a)
	{
		oper[top] = a;
		top++;//与数字栈不同一压栈就可以提升指针
	}
	char OPERstack::pop()
	{
		top--;
		char op = oper[top];
		oper[top] = NULL;
		return op;//弹出计算符 用于计算
	}
	char OPERstack::getTop()
	{
		return oper[top - 1];//取栈顶符号 但不弹栈 可用于判定优先级
	}

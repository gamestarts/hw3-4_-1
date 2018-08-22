#include "pch.h"
#include "NUMstack.h"
void NUMstack::start()//初始化栈清空栈顶指针置底
	{
		for (int i = 0; i < 1000; i++)
			num[i] = 0;
		top = 0;
	}

void NUMstack:: push(char a)//因为有多位数的运算因此不能一压栈就提升栈顶指针
   {
		num[top] = num[top] * 10 + (a - '0');//把字符转成数因为每次入栈之前要乘10 所以初始化要清0
   }
double NUMstack::pop()
   {
		top--;
		double number = num[top];
		num[top] = 0;
		return number;
   }//弹栈函数 弹掉栈顶元素 栈顶归0 top指针下降
double NUMstack::getTop()//取栈顶元素但不必弹栈
   {
		return num[top - 1];
   }
void NUMstack::lift()//提升top指针的函数
   {
		top++;
   }

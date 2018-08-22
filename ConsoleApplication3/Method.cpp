#include "pch.h"
#include "Method.h"
using namespace std;
double Method::D_Operate(double x, char op, double y)//双目运算符的运算定义
{
	double a;//计算结果
	switch (op)
	{
	case'+': a = x + y; break;
	case'-': a = x - y; break;
	case'*': a = x * y; break;
	case'/': a = x / y; break;
	case'^': a = pow(x, y); break;//幂运算包括乘方和开方
	}//因为都是利用double进行运算 因此不定义取模运算
	return a;
}
double Method::S_Operate(char op, double x)//前缀单目运算符的运算定义
{
	double a;//计算结果
	switch (op)
	{
	case's': a = sin(x); break;
	case'c': a = cos(x); break;
	case't': a = tan(x); break;
	case'l': a = log10(x); break;//以10为底的对数
	case'n': a = log(x); break;//以e（2.718281828）为底的对数
	case'_': a = -x; break;//取负用下划线代替负号 定义为一元运算
	}
	return a;
}
char Method::Precede(char op1, char op2) //判断符号的优先级 op1在返回的结果符的左边 op2在右边
{
	if (((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-' || op2 == ')' || op2 == '=')) || \
		((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' || op2 == ')' || op2 == '='))\
		|| (op1 == '^' && (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' || op2 == ')' || op2 == '=' || op2 == 's' || op2 == 'c' || op2 == 't' || op2 == '_' || op2 == 'l' || op2 == 'n'))\
		|| ((op1 == '_' || op1 == 's' || op1 == 'c' || op1 == 't' || op1 == 'l' || op1 == 'n') && (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' || op2 == ')' || op2 == '=' || op2 == 's' || op2 == 'c' || op2 == 't' || op2 == '_' || op2 == 'l' || op2 == 'n')))
		return '>';//上述情况下 栈顶运算符优先级高于待定运算符 需弹栈
	if ((op1 == '('&&op2 == ')') || (op1 == '='&&op2 == '='))
		return '=';
	else
		return '<';
}
int Method::illegal_char(string s, int i)//非法输入字符判定函数
{
	int j = 0;
	while (j < i)
	{
		if (s[j] >= '0'&&s[j] <= '9')
			j++;

		else if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/' || s[j] == '.' || s[j] == '(' || s[j] == ')' || s[j] == '^' || s[j] == '!' || s[j] == 'e' || s[j] == '_')
			j++;
		else if ((s[j] == 'p'&&s[j + 1] == 'i') || (s[j] == 'l'&&s[j + 1] == 'n'))
			j += 2;

		else if ((s[j] == 's'&&s[j + 1] == 'i'&&s[j + 2] == 'n') || (s[j] == 'c'&&s[j + 1] == 'o'&&s[j + 2] == 's') || (s[j] == 't'&&s[j + 1] == 'a'&&s[j + 2] == 'n') || (s[j] == 'l'&&s[j + 1] == 'o'&&s[j + 2] == 'g'))
			j += 3;
		//以上都是标准的数字字符和运算符 如若存在其他形式的字符 则是非法输入
		else
		{
			cout << "程序终止，存在非法的字符输入！！！" << endl;
			return 0;
		}
	}
	return 1;//没有非法字符 返回1 否则返回0
}
int Method::match(string s)//栈结构的括号匹配检测函数
{
	int i = 0, top = 0;
	char stack[50];
	while (s[i] != '\0')
	{
		if (s[i] == '(')
		{
			stack[top] = s[i];
			top++;
		}
		//push 左括号压入栈内
		if (s[i] == ')')
			if (stack[top - 1] == '(')
			{
				int a = i + 1;
				stack[top - 1] = NULL;
				top--;
			}//把与右括号匹配的左括号弹掉
			else
			{
				cout << "括号输入有误" << endl;
				return 0;//多了右括号 括号失陪 返回非法
			}//pop'('
		i++;
	}
	if (top != 0)
	{
		cout << "括号输入有误" << endl;
		return 0;//多了左括号 括号失陪 返回非法
	}
	return 1;//返回合法
}
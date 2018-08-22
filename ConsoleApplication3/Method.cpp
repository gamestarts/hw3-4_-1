#include "pch.h"
#include "Method.h"
using namespace std;
double Method::D_Operate(double x, char op, double y)//˫Ŀ����������㶨��
{
	double a;//������
	switch (op)
	{
	case'+': a = x + y; break;
	case'-': a = x - y; break;
	case'*': a = x * y; break;
	case'/': a = x / y; break;
	case'^': a = pow(x, y); break;//����������˷��Ϳ���
	}//��Ϊ��������double�������� ��˲�����ȡģ����
	return a;
}
double Method::S_Operate(char op, double x)//ǰ׺��Ŀ����������㶨��
{
	double a;//������
	switch (op)
	{
	case's': a = sin(x); break;
	case'c': a = cos(x); break;
	case't': a = tan(x); break;
	case'l': a = log10(x); break;//��10Ϊ�׵Ķ���
	case'n': a = log(x); break;//��e��2.718281828��Ϊ�׵Ķ���
	case'_': a = -x; break;//ȡ�����»��ߴ��渺�� ����ΪһԪ����
	}
	return a;
}
char Method::Precede(char op1, char op2) //�жϷ��ŵ����ȼ� op1�ڷ��صĽ��������� op2���ұ�
{
	if (((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-' || op2 == ')' || op2 == '=')) || \
		((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' || op2 == ')' || op2 == '='))\
		|| (op1 == '^' && (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' || op2 == ')' || op2 == '=' || op2 == 's' || op2 == 'c' || op2 == 't' || op2 == '_' || op2 == 'l' || op2 == 'n'))\
		|| ((op1 == '_' || op1 == 's' || op1 == 'c' || op1 == 't' || op1 == 'l' || op1 == 'n') && (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' || op2 == ')' || op2 == '=' || op2 == 's' || op2 == 'c' || op2 == 't' || op2 == '_' || op2 == 'l' || op2 == 'n')))
		return '>';//��������� ջ����������ȼ����ڴ�������� �赯ջ
	if ((op1 == '('&&op2 == ')') || (op1 == '='&&op2 == '='))
		return '=';
	else
		return '<';
}
int Method::illegal_char(string s, int i)//�Ƿ������ַ��ж�����
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
		//���϶��Ǳ�׼�������ַ�������� ��������������ʽ���ַ� ���ǷǷ�����
		else
		{
			cout << "������ֹ�����ڷǷ����ַ����룡����" << endl;
			return 0;
		}
	}
	return 1;//û�зǷ��ַ� ����1 ���򷵻�0
}
int Method::match(string s)//ջ�ṹ������ƥ���⺯��
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
		//push ������ѹ��ջ��
		if (s[i] == ')')
			if (stack[top - 1] == '(')
			{
				int a = i + 1;
				stack[top - 1] = NULL;
				top--;
			}//����������ƥ��������ŵ���
			else
			{
				cout << "������������" << endl;
				return 0;//���������� ����ʧ�� ���طǷ�
			}//pop'('
		i++;
	}
	if (top != 0)
	{
		cout << "������������" << endl;
		return 0;//���������� ����ʧ�� ���طǷ�
	}
	return 1;//���غϷ�
}
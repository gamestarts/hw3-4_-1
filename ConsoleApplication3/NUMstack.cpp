#include "pch.h"
#include "NUMstack.h"
void NUMstack::start()//��ʼ��ջ���ջ��ָ���õ�
	{
		for (int i = 0; i < 1000; i++)
			num[i] = 0;
		top = 0;
	}

void NUMstack:: push(char a)//��Ϊ�ж�λ����������˲���һѹջ������ջ��ָ��
   {
		num[top] = num[top] * 10 + (a - '0');//���ַ�ת������Ϊÿ����ջ֮ǰҪ��10 ���Գ�ʼ��Ҫ��0
   }
double NUMstack::pop()
   {
		top--;
		double number = num[top];
		num[top] = 0;
		return number;
   }//��ջ���� ����ջ��Ԫ�� ջ����0 topָ���½�
double NUMstack::getTop()//ȡջ��Ԫ�ص����ص�ջ
   {
		return num[top - 1];
   }
void NUMstack::lift()//����topָ��ĺ���
   {
		top++;
   }

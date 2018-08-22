#include "pch.h"
#include "Calculate.h"


void Calculate:: calculate(string equation,Method calculator1)
{
	NUMstack number;
	OPERstack oper;
	number.start();
	oper.start();
	int i = 0, len = 0, k;//�����ַ�����
	char p, sig;
	double yuan1, yuan2;
	while (equation[i] != '\0')
	{
		len++;
		i++;
	}
	if (equation[len - 1] != '=')
	{
		cout << "��������û��������ֹ����--�Ⱥš�=��" << endl;
		return;
	}
	int le;
	le = calculator1.illegal_char(equation, len - 1);
	if (le == 0)
		return;//�Ƿ��ַ���ֹ
	le = calculator1.match(equation);
	if (le == 0)
		return;//�Ƿ�������ֹ
	for (i = 0; i < len; i++)//��ʼ����
	{
		if (equation[i] == '!')//�׳�
		{
			yuan1 = number.pop();
			if (yuan1 == 0)
			{
				number.num[number.top] = 0;
				number.lift();
			}
			else
			{
				number.num[number.top] = 1;
				for (k = 1; k <= yuan1; k++)
					number.num[number.top] = k * number.num[number.top];
				number.lift();
			}
		}
		else if (equation[i] >= '0'&&equation[i] <= '9')//��λ����ȡ
		{
			number.push(equation[i]);
			if ((equation[i + 1]<'0' || equation[i + 1]>'9') && equation[i + 1] != '.')
				number.lift();
		}
		else if (equation[i] == 'p')//Բ����
		{
			number.num[number.top] = 3.1415926536;
			number.lift();
			i++;
		}
		else if (equation[i] == 'e')//��Ȼ����
		{
			number.num[number.top] = 2.718281828459;
			number.lift();
		}
		else if (equation[i] == '.')//С��
		{
			int x = 1;
			while (equation[i + x] >= '0'&&equation[i + x] <= '9')
			{
				number.num[number.top] += ((equation[i + x] - '0') / pow(10, x));
				x++;
			}
			x--;
			number.lift();
			i = i + x;
		}
		else if (equation[i] == '(')
		{
			oper.push(equation[i]);
		}
		else
		{
			if (oper.top == 1)//�������
			{
				if (equation[i] == 'l'&&equation[i + 1] == 'o')
					oper.push('l');
				else if (equation[i] == 'l'&&equation[i + 1] == 'n')
					oper.push('n');
				else
					oper.push(equation[i]);
			}
			else//�����ջ��Ϊ����Ҫ�������ȼ��ж�
			{
				char temp1 = oper.getTop();//ȡ��ջ������
				char temp2;//����ջ����
				if (equation[i] == 'l'&&equation[i + 1] == 'o')
					temp2 = 'l';
				else if (equation[i] == 'l'&&equation[i + 1] == 'n')
					temp2 = 'n';//log��ln���ٴ�����
				else
					temp2 = equation[i];
				p = calculator1.Precede(temp1, temp2);
				if (p == '<')
					oper.push(temp2);//ջ�������ȼ��ϵ����ڴ�����������Ϳ�����ջ��
				if (p == '>' || p == '=')
				{
					char rep = p;//��ջ�������ȼ������ڴ���ջ�ķ��� �������ջ��ͣ�ص�ջ
					//��������ֱ�����ڴ���ջ����Ϊֹ rep���ڼ�¼�ȽϽ�� Ҫ��ν����ж�
					while ((rep == '>' || p == '=') && (oper.top - 1 > 0))
					{
						sig = oper.pop();
						yuan1 = number.pop();
						yuan2 = number.getTop();//��ǰ��һ��������ֻҪȡ�ò�Ҫ������
						if (sig == '/'&&yuan1 == 0)//yuan1��˫Ŀ���������ĵڶ�����Ԫ
						{
							cout << "����ʱ�����������˳���Ϊ0���������" << endl;
							return;
						}
						if (sig == '^'&&yuan2 < 0 && yuan1>0 && yuan1 < 1 && (static_cast <int>(1 / yuan1)) % 2 == 0)
							//�Ը�����ż�θ��ŵ�����
						{
							cout << "����ʱ�����������˸�����ż�θ��ŵ��������" << endl;
							return;
						}
						if (sig == '_' || sig == 's' || sig == 'c' || sig == 't' || sig == 'l' || sig == 'n')//��Ϊǰ׺��Ŀ�����
						{
							double tt;
							tt = calculator1.S_Operate(sig, yuan1);
							number.num[number.top] = tt;//������ѹ��ԭ��yuan1��ջ�ڵ�λ��
							number.lift();//����ָ��
							temp1 = oper.getTop();
							rep = calculator1.Precede(temp1, temp2);//�������ȼ�
						}
						else
						{
							number.num[(number.top) - 1] = calculator1.D_Operate(yuan2, sig, yuan1);
							temp1 = oper.getTop();
							rep = calculator1.Precede(temp1, temp2);//˫Ŀ������ļ���
						}
					}
					if (equation[i] == ')')//���ջ�����������Ҫ����֮ƥ��������ŵ���ջ��
						oper.pop();
					else if (equation[i] == 'l'&&equation[i + 1] == 'o')
						oper.push('l');//����log��l
					else if ((equation[i] == 'l') && (equation[i + 1] == 'n'))
						oper.push('n');//����ln��n
					else
						oper.push(equation[i]);
				}
			}
			if (equation[i] == 's' || equation[i] == 'c' || equation[i] == 't' || (equation[i] == 'l'&&equation[i + 1] == 'o'))
				i = i + 2;
			if (equation[i] == 'l'&&equation[i + 1] == 'n')
				i++;
			//���ڲ�ֹһ���ַ�������� sin log ln�ȵ� Ҫ�ƶ�ɨ����ʽ��ָ�� ������һ��������
		}
	}
	ofstream write;
	if (number.num[0] == ceil(number.num[0]))
	{
		cout << equation << number.num[0] << endl;
		write.open("d://a.txt", ios::app);
		write << equation << number.num[0] << endl;
		write.close();
	}
	else
	{
		cout << equation << fixed << setprecision(8) << number.num[0] << endl;
		write.open("d://a.txt", ios::app);
		write << equation << number.num[0] << endl;
		write.close();
	}//���������ƾ���8λС��

}


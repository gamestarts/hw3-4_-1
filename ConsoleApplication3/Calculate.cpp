#include "pch.h"
#include "Calculate.h"


void Calculate:: calculate(string equation,Method calculator1)
{
	NUMstack number;
	OPERstack oper;
	number.start();
	oper.start();
	int i = 0, len = 0, k;//输入字符长度
	char p, sig;
	double yuan1, yuan2;
	while (equation[i] != '\0')
	{
		len++;
		i++;
	}
	if (equation[len - 1] != '=')
	{
		cout << "输入有误没有输入终止符号--等号“=”" << endl;
		return;
	}
	int le;
	le = calculator1.illegal_char(equation, len - 1);
	if (le == 0)
		return;//非法字符终止
	le = calculator1.match(equation);
	if (le == 0)
		return;//非法括号终止
	for (i = 0; i < len; i++)//开始计算
	{
		if (equation[i] == '!')//阶乘
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
		else if (equation[i] >= '0'&&equation[i] <= '9')//多位数读取
		{
			number.push(equation[i]);
			if ((equation[i + 1]<'0' || equation[i + 1]>'9') && equation[i + 1] != '.')
				number.lift();
		}
		else if (equation[i] == 'p')//圆周率
		{
			number.num[number.top] = 3.1415926536;
			number.lift();
			i++;
		}
		else if (equation[i] == 'e')//自然对数
		{
			number.num[number.top] = 2.718281828459;
			number.lift();
		}
		else if (equation[i] == '.')//小数
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
			if (oper.top == 1)//空运算符
			{
				if (equation[i] == 'l'&&equation[i + 1] == 'o')
					oper.push('l');
				else if (equation[i] == 'l'&&equation[i + 1] == 'n')
					oper.push('n');
				else
					oper.push(equation[i]);
			}
			else//运算符栈不为空则要进行优先级判断
			{
				char temp1 = oper.getTop();//取出栈顶符号
				char temp2;//待入栈符号
				if (equation[i] == 'l'&&equation[i + 1] == 'o')
					temp2 = 'l';
				else if (equation[i] == 'l'&&equation[i + 1] == 'n')
					temp2 = 'n';//log与ln的再次讨论
				else
					temp2 = equation[i];
				p = calculator1.Precede(temp1, temp2);
				if (p == '<')
					oper.push(temp2);//栈顶符优先级较低现在待定的运算符就可以入栈了
				if (p == '>' || p == '=')
				{
					char rep = p;//当栈顶符优先级不低于待入栈的符号 则运算符栈不停地弹栈
					//进行运算直到低于待入栈符号为止 rep用于记录比较结果 要多次进行判断
					while ((rep == '>' || p == '=') && (oper.top - 1 > 0))
					{
						sig = oper.pop();
						yuan1 = number.pop();
						yuan2 = number.getTop();//靠前的一个运算数只要取得不要弹出来
						if (sig == '/'&&yuan1 == 0)//yuan1是双目运算符后面的第二运算元
						{
							cout << "计算时出错！！出现了除数为0的情况！！" << endl;
							return;
						}
						if (sig == '^'&&yuan2 < 0 && yuan1>0 && yuan1 < 1 && (static_cast <int>(1 / yuan1)) % 2 == 0)
							//对负数开偶次根号的限制
						{
							cout << "计算时出错！！出现了负数开偶次根号的情况！！" << endl;
							return;
						}
						if (sig == '_' || sig == 's' || sig == 'c' || sig == 't' || sig == 'l' || sig == 'n')//若为前缀单目运算符
						{
							double tt;
							tt = calculator1.S_Operate(sig, yuan1);
							number.num[number.top] = tt;//运算结果压回原来yuan1在栈内的位置
							number.lift();//提升指针
							temp1 = oper.getTop();
							rep = calculator1.Precede(temp1, temp2);//再判优先级
						}
						else
						{
							number.num[(number.top) - 1] = calculator1.D_Operate(yuan2, sig, yuan1);
							temp1 = oper.getTop();
							rep = calculator1.Precede(temp1, temp2);//双目运算符的计算
						}
					}
					if (equation[i] == ')')//如果栈外符是右括号要把与之匹配的左括号弹出栈外
						oper.pop();
					else if (equation[i] == 'l'&&equation[i + 1] == 'o')
						oper.push('l');//代表log的l
					else if ((equation[i] == 'l') && (equation[i + 1] == 'n'))
						oper.push('n');//代表ln的n
					else
						oper.push(equation[i]);
				}
			}
			if (equation[i] == 's' || equation[i] == 'c' || equation[i] == 't' || (equation[i] == 'l'&&equation[i + 1] == 'o'))
				i = i + 2;
			if (equation[i] == 'l'&&equation[i + 1] == 'n')
				i++;
			//对于不止一个字符的运算符 sin log ln等等 要移动扫描算式的指针 往后跳一个或两个
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
	}//输出结果控制精度8位小数

}


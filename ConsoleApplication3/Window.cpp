#include "pch.h"
#include "Window.h"
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼������

int Window::windowMain()

{

	system("color 7E");//���ÿ���̨���汳����ɫ��ǰ����ɫ
	system("mode con cols=100 lines=40");//��ʼ����������С
	blue_border();
	pos(5, 5);
	cout << "___________________________________________________________________________________________";
	pos(5, 6);
	cout << "                                 �򵥼�����                                                ";
	pos(5, 7);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";//�ϱ߿�

	pos(5, 25);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	pos(5, 26);
	cout << "w, a, s, d ���ƹ��ѡ�񣻿ո� ȷ��_________________________________________________________";
	//�±߿�

	for (int i = 6, j = 6; j < 25; j++) //��߿�
	{
		pos(i, j);
		cout << "*";
	}
	for (int i = 5, j = 6; j < 25; j++) //��߿�
	{
		pos(i, j);
		cout << "|";
	}
	for (int i = 94, j = 6; j < 25; j++) //�ұ߿�
	{
		pos(i, j);
		cout << "*";
	}
	for (int i = 95, j = 6; j < 25; j++) //�ұ߿�
	{
		pos(i, j);
		cout << "|";
	}

	cyan_choose();
	pos(25, 10);
	cout << "1. ʹ��˵�� ";
	pos(65, 10);
	cout << "2. ������ʽ ";
	pos(25, 20);
	cout << "3. �鿴��ʷ��¼ ";
	pos(65, 20);
	cout << "0. �˳����� ";
	on_Select();
	//wsad���ƹ��Խ�������ѡ��
	int x = 25, y = 10;
	char sel;
	sel = _getch();
	while (sel != ' ')
	{
		star();
		switch (sel)
		{
		case 'w':
			y = y - 10;
			break;
		case 's':
			y = y + 10;
			break;
		case 'a':
			x = x - 40;
			break;
		case 'd':
			x = x + 40;
			break;
		}
		//��ֹ������Χ
		if (x >= 65)
		{
			x = 65;
		}
		if (y >= 20)
		{
			y = 20;
		}
		if (x <= 25)
		{
			x = 25;
		}
		if (y <= 10)
		{
			y = 10;
		}
		pos(x, y);
		onChoose(x, y);
		sel = _getch();
	}	
	pos(0, 30);
	white_back();//��ԭĬ������
	if (x == 25&& y == 10) 
	{ 
	    a = 1; 
	}
	else if (x == 65&& y == 10)
	{
	    a = 2;
	}
	else if (x == 25&&y == 20)
	{
		a = 3;
	}
	else
	{
		a = 0;
	}
	return a;
}

void Window::pos(int x, int y)
{
	COORD posPoint = { x,y }; //��������
	SetConsoleCursorPosition(hOut, posPoint);
}

void Window::blue_border()
{
	WORD blue = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;//����������ɫ��������ɫ
	SetConsoleTextAttribute(hOut, blue);//������ʽ
}

void Window::white_back()
{
	WORD white = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(hOut, white);
}

void Window::cyan_choose()
{
	WORD cyan = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE;
	SetConsoleTextAttribute(hOut, cyan);
}

void Window::on_Select()
{
	WORD select = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED;
	SetConsoleTextAttribute(hOut, select);
}

void Window::onChoose(int x, int y)
{
	if (x == 25 && y == 10)
	{
		on_Select();
		cout << "1. ʹ��˵�� ";
	}

	else if (x == 25 && y == 20)
	{
		on_Select();
		cout << "3. �鿴��ʷ��¼ ";
	}

	else if (x == 65 && y == 10)
	{
		on_Select();
		cout << "2. ������ʽ ";
	}

	else if (x == 65 && y == 20)
	{
		on_Select();
		cout << "0. �˳����� ";
	}

}

void Window::star()
{
	cyan_choose();
	pos(25, 10);
	cout << "1. ʹ��˵�� ";
	pos(65, 10);
	cout << "2. ������ʽ ";
	pos(25, 20);
	cout << "3. �鿴��ʷ��¼ ";
	pos(65, 20);
	cout << "0. �˳����� ";
}

#include "pch.h"
#include "Window.h"
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出句柄

int Window::windowMain()

{

	system("color 7E");//设置控制台界面背景颜色和前景颜色
	system("mode con cols=100 lines=40");//初始化缓冲区大小
	blue_border();
	pos(5, 5);
	cout << "___________________________________________________________________________________________";
	pos(5, 6);
	cout << "                                 简单计算器                                                ";
	pos(5, 7);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";//上边框

	pos(5, 25);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	pos(5, 26);
	cout << "w, a, s, d 控制光标选择；空格 确定_________________________________________________________";
	//下边框

	for (int i = 6, j = 6; j < 25; j++) //左边框
	{
		pos(i, j);
		cout << "*";
	}
	for (int i = 5, j = 6; j < 25; j++) //左边框
	{
		pos(i, j);
		cout << "|";
	}
	for (int i = 94, j = 6; j < 25; j++) //右边框
	{
		pos(i, j);
		cout << "*";
	}
	for (int i = 95, j = 6; j < 25; j++) //右边框
	{
		pos(i, j);
		cout << "|";
	}

	cyan_choose();
	pos(25, 10);
	cout << "1. 使用说明 ";
	pos(65, 10);
	cout << "2. 计算算式 ";
	pos(25, 20);
	cout << "3. 查看历史记录 ";
	pos(65, 20);
	cout << "0. 退出程序 ";
	on_Select();
	//wsad控制光标对进行自由选择
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
		//防止超出范围
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
	white_back();//还原默认字体
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
	COORD posPoint = { x,y }; //设置坐标
	SetConsoleCursorPosition(hOut, posPoint);
}

void Window::blue_border()
{
	WORD blue = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;//设置字体颜色、背景颜色
	SetConsoleTextAttribute(hOut, blue);//字体样式
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
		cout << "1. 使用说明 ";
	}

	else if (x == 25 && y == 20)
	{
		on_Select();
		cout << "3. 查看历史记录 ";
	}

	else if (x == 65 && y == 10)
	{
		on_Select();
		cout << "2. 计算算式 ";
	}

	else if (x == 65 && y == 20)
	{
		on_Select();
		cout << "0. 退出程序 ";
	}

}

void Window::star()
{
	cyan_choose();
	pos(25, 10);
	cout << "1. 使用说明 ";
	pos(65, 10);
	cout << "2. 计算算式 ";
	pos(25, 20);
	cout << "3. 查看历史纪录 ";
	pos(65, 20);
	cout << "0. 退出程序 ";
}

// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
using namespace std;

int main()
{
	Method method1;
	Menu menu1;
	Guide guide1;
	Calculate calculate1;
	ReadTxt readTxt1;
	Window window1;
	while (true)
	{
		int choice=window1.windowMain();
		string equation;
		char goOn = 'y';
		switch (choice)
		{
		case 1:guide1.guide(window1); break;
		case 2:
			system("cls");
			while (goOn == 'y')
			{
				cout << endl << endl << "请输入算式，以=（等号）结束：" << endl;
				cin >> equation;
				calculate1.calculate(equation,method1);
				cout << "继续使用吗？是请输入y 否则输入任意键：";
				cin >> goOn;//可以循环进行算式计算
			}
			system("cls");
			break;
		case 3:
			system("cls");
			readTxt1.readTxt("d:\\a.txt"); 
			char goOn1;
			cout << "按任意键继续" << endl;
			cin >> goOn1;
			break;		
		case 0:
			return 0;
		}
	}
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

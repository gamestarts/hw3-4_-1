#include "pch.h"
#include "Menu.h"


int Menu::menu()
{
	
		cout << "简易计算器" << endl;
		cout << "420三兄弟" << endl;
		cout << endl;
		cout << " 请在英文格式下输入括号!!!" << endl;
		cout << "请选择你需要的功能：（0，1, 2或者3）" << endl;
		cout << "----------" << endl;
		cout << "1.使用说明" << endl;
		cout << "2.计算算式" << endl;
		cout << "3.查看历史纪录" << endl;
		cout << "0.退出程序" << endl;
		cout << "----------" << endl;
		cout << "你的选择是：";
		int choice;
		cin >> choice;
		if (choice != 0 && choice != 1 && choice != 2 && choice != 3)
			return 4;
		else return choice;
	
}

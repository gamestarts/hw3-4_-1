#include "pch.h"
#include "Menu.h"


int Menu::menu()
{
	
		cout << "���׼�����" << endl;
		cout << "420���ֵ�" << endl;
		cout << endl;
		cout << " ����Ӣ�ĸ�ʽ����������!!!" << endl;
		cout << "��ѡ������Ҫ�Ĺ��ܣ���0��1, 2����3��" << endl;
		cout << "----------" << endl;
		cout << "1.ʹ��˵��" << endl;
		cout << "2.������ʽ" << endl;
		cout << "3.�鿴��ʷ��¼" << endl;
		cout << "0.�˳�����" << endl;
		cout << "----------" << endl;
		cout << "���ѡ���ǣ�";
		int choice;
		cin >> choice;
		if (choice != 0 && choice != 1 && choice != 2 && choice != 3)
			return 4;
		else return choice;
	
}

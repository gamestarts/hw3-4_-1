#pragma once
#include <iostream>
#include <bits.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class Window
{
public:
	int windowMain();
	void pos(int x, int y);//ȷ�����λ��
	void blue_border();//��ɫ����
	void white_back();//��ԭ����ɫ����
	void cyan_choose();//��ɫ����
	void on_Select();//��ѡ��ʱ����ʽ
	void onChoose(int x, int y);//ȷ����ѡ�е�λ��
	void star();//��ʼ������
	int a;
};


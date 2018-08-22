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
	void pos(int x, int y);//确定光标位置
	void blue_border();//蓝色字体
	void white_back();//还原亮白色字体
	void cyan_choose();//青色字体
	void on_Select();//被选中时的样式
	void onChoose(int x, int y);//确定所选中的位置
	void star();//初始化界面
	int a;
};


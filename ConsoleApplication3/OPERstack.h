#pragma once
class OPERstack//��ջ
{
public:
	char oper[1000];
	int top;
	void start();
	void push(char a);
	char pop();
	char getTop();
};


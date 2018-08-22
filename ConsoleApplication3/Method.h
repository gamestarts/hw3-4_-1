#pragma once
#include <cmath>
#include<string>
#include <iostream>
using namespace std;
class Method
{
	public:
		double  D_Operate(double x, char op, double y);
		double S_Operate(char op, double x);
		char Precede(char op1, char op2);
		int illegal_char(string s, int i);
		int match(string s);
};



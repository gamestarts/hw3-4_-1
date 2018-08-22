#include "pch.h"
#include "ReadTxt.h"


void ReadTxt::readTxt(string file)
{

		ifstream infile;
		infile.open(file.data());   //将文件流对象与文件连接起来 
		assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

		char c;
		infile >> noskipws;
		while (!infile.eof())
		{
			infile >> c;
			cout << c;
		}
		infile.close();             //关闭文件输入流 
	
}



#include "pch.h"
#include "ReadTxt.h"


void ReadTxt::readTxt(string file)
{

		ifstream infile;
		infile.open(file.data());   //���ļ����������ļ��������� 
		assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 

		char c;
		infile >> noskipws;
		while (!infile.eof())
		{
			infile >> c;
			cout << c;
		}
		infile.close();             //�ر��ļ������� 
	
}



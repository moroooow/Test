#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const string ERROR_FILE_NOT_OPEN = " Не открыт";
const string ERROR_FILE_NOT_NUMBER = " Должно быть целое число";
const string ERROR_FILE = "Ошибка: файл ";

char* propisnie(char* source);


int mai2n()
{
	setlocale(LC_ALL, "ru");

	const int maxlen = 256;

	string infilename = "";
	string outfilename = "";
	ifstream in;
	ofstream out;
	cout << "Enter filename to read:";
	cin >> infilename;
	in.open(infilename);
	if (!in)
	{
		cerr << infilename + ERROR_FILE_NOT_OPEN;
		return -1;
	}
	cout << "Enter a file name for the recording:";
	cin >> outfilename;
	out.open(outfilename);
	while (!in.eof()) 
	{
		char str[maxlen]{};
		in >> str;
		propisnie(str);
		out << str<<endl;
	}
	in.close();
	out.close();
	return 0;
}
char* propisnie(char* source)
{
	for (int i = 0; source[i]!='\0'; i++)
	{
		if (source[i] >= 65 && source[i] <= 90)
		{
			source[i] =source[i] + 32;
		}
	}
	return source;
}
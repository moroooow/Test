#include <iostream>
#include <fstream>
#include <iomanip>

const int lenth = 14;
const std::string error_open = ", not open";


bool isLetter(char*& string);
bool isNumber(char*& string);
bool isId(char*& string);
bool isCalc(char*& string);
bool isMultiDivide(char*& string);
bool isPlusMinus(char*& string);
bool isUnsignedInt(char*& string);
bool isMultiplier(char*& string);
bool isTerm(char*& string);
bool isFormula(char*& string)
int main()
{
	int i = 1;
	std::string inFileName = "";
	std::ifstream in;
	try
	{
		std::cout << " Enter file to read: ";
		std::cin >> inFileName;
		in.open(inFileName);
		if (!in)
		{
			throw inFileName + error_open;
		}
		std::cout << "	Recursion\n Is the number real:\n";
		while (!in.eof())
		{
			char* string;
			string = new char[lenth];
			in.getline(string, lenth, '\n');
			char* buf = string;
			std::cout.width(3);
			std::cout << i << ") ";
			std::cout.width(13);
			std::cout << string;
			if (isFormula(buf))
			{
				std::cout << "  True\n";
			}
			else
			{
				std::cout << " False\n";
			}
			i++;
			delete[] string;
		}
	}
	catch (const std::string& error)
	{
		std::cerr << "Error: fail " << error << "\n";
		return -1;
	}
	in.close();
	
	return 0;

}

bool isLetter(char*& string)
{
	if (*string == 'a' || *string == 'b' || *string == 'c' || *string == 'd' || *string == 'e')
	{
		string++;
		return true;
	}
	return false;
}

bool isId(char*& string)
{
	if (isLetter(string))
	{
		return true;
	}
	return false;
}

bool isCalc(char*& string)
{
	if (*string == '*' || *string == '/' || *string == '+' || *string == '-' || *string == '\0')
	{
		string++;
		return true;
	}
	return false;
}
bool isMultiDivide(char*& string)
{
	if (*string == '*' || *string == '/')
	{
		string++;
		return true;
	}
	return false;
}

bool isPlusMinus(char*& string)
{
	if (*string == '+' || *string == '-')
	{
		string++;
		return true;
	}
	return false;
}

bool isNumber(char*& string)
{
	if (*string >= '0' && *string <= '9')
	{
		string++;
		return true;
	}
	return false;
}

bool isUnsignedInt(char*& string)
{
	if (isNumber(string))
	{
		if (isCalc(string))
		{
			return true;
		}
		return isUnsignedInt(string)
	}
	return false;
}

bool isMultiplier(char*& string)
{
	if (isUnsignedInt(string) || isId(string))
	{
		return true;
	}
	return false;
}

bool isTerm(char*& string)
{
	if (isMultiplier(string))
	{
		if (isMultiDivide(string))
		{
			return true;
		}
		return isTerm;
	}
	return false;
}

bool isFormula(char*& string)
{
	if (isTerm(string))
	{
		if (isPlusMinus(string))
		{
			return true;
		}
		return isFormula;
	}
	return False
}





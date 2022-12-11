#include <iostream>
#include <fstream>
#include <string>

const int M = 5;
const int N = 5;
const std::string error_input = ", input error";
const std::string error_open = ", not open";
const std::string error_size = ", error size";

bool inputMatrix(int matrix[M][N], std::ifstream& in);
void outputMatrix(int matrix[M][N], int count);
int searchDuplicateRows(int matrix[M][N]);


bool inputMatrix(int** matrix, int size, std::ifstream& in);
void outputMatrix(int** matrix, int size, int count);
int RowsEqualElements(int** matrix, int size);

int Compare(int a, int b);

int main()
{
	int count = 1,
		result = 0,
		size = 0;
	int matrix[M][N] = { 0 };
	std::string inFileName = "";
	std::string outFileName = "";
	std::ifstream in;
	std::ofstream out;
	try
	{
		std::cout << "	 MATRIX\n Enter filename to read: ";
		std::cin >> inFileName;
		in.open(inFileName);
		if (!in)
		{
			throw inFileName + error_open;
		}
		std::cout << " Enter a file name for the recording: ";
		std::cin >> outFileName;
		out.open(outFileName);
		if (!out)
		{
			throw outFileName + error_open;
		}
		if (!inputMatrix(matrix, in))
		{
			throw inFileName + error_input;
		}
		outputMatrix(matrix, count);
		result = searchDuplicateRows(matrix);
		std::cout << "Rows with duplicate elements: " << result << std::endl;
		out << count << ") Rows with duplicate elements: " << result << std::endl;
		++count;
		while (!in.eof())
		{
			in >> size;
			if (in.fail() || in.peek() != '\n' || size < 3)
			{
				throw inFileName + error_size;
			}
			int** matrix_d = new int* [size];
			for (int i = 0; i < size; i++)
			{
				matrix_d[i] = new int[size];
			}
			if (!inputMatrix(matrix_d, size, in))
			{
				throw inFileName + error_input;
			}
			outputMatrix(matrix_d, size, count);
			result = RowsEqualElements(matrix_d, size);
			std::cout << " A rows with the maximum number of equal elements: " << result+1 << std::endl;
			out << count << ") A rows with the maximum number of equal elements: " << result+1 << std::endl;
			for (int i = 0; i < size; i++)
			{
				delete[] matrix_d[i];
			}
			delete[] matrix_d;
			++count;
		}
	}
	catch (const std::string& error)
	{
		std::cerr << " Error: file " << error << "\n";
		return -1;
	}
	out.close();
	in.close();
	return 0;
}

bool inputMatrix(int matrix[M][N], std::ifstream& in)
{
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			in >> matrix[i][j];
			if (in.fail() || in.peek() == '.' || in.peek() == ',')
			{
				return false;
			}
		}
	}
}

void outputMatrix(int matrix[M][N], int count)
{
	std::cout << "\n ===========================================================\n\n";
	std::cout << " Matrix " << count << ": \n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout.width(2);
			std::cout << '|' << matrix[i][j] << '|';
		}
		std::cout << "\n";
	}
}

int searchDuplicateRows(int matrix[M][N])
{
	int count = 0;
	bool flag = true;
	for (int i = 0; i < M; ++i)
	{
		flag = false;
		for (int j = 1; j < N; ++j)
		{
			if (matrix[i][j] == matrix[i][j - 1])
			{
				flag = true;
				break;
			}
		}
		count += flag;
	}
	return count;
}

bool inputMatrix(int** matrix, int size, std::ifstream& in)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			in >> matrix[i][j];
			if (in.fail() || in.peek() == '.' || in.peek() == ',')
			{
				return false;
			}
		}
	}
}

void outputMatrix(int** matrix, int size, int count)
{
	std::cout << "\n ===========================================================\n\n";
	std::cout << " Matrix " << count << ": \n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout.width(2);
			std::cout << '|' << matrix[i][j] << '|';
		}
		std::cout << "\n";
	}
}

int RowsEqualElements(int** matrix, int size)
{
	int max = 0;
	int v = 0;
	for (int i = 0; i<size; ++i)
	{
		int count = 0;
		int max_in_row = 0;
		for (int j = 0; j <size-1; ++j)
		{
			if (matrix[i][j] == matrix[i][j + 1])
			{
				count += 1;
			}
			else
			{
				max_in_row = Compare(max_in_row, count);
				count = 0;
			}
		}
		if (max_in_row > max)
		{
			max = max_in_row;
			v = i;
		}

	}
	return v;
}



int Compare(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
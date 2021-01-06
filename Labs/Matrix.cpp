#include "Matrix.h"


Matrix::Matrix() : BaseMatrix()
{
}

Matrix::Matrix(int columnsCount, int rowsCount)
	: BaseMatrix(columnsCount, rowsCount)
{
}

Matrix::Matrix(const BaseMatrix& obj) : BaseMatrix(obj)
{
}

Matrix::~Matrix()
{
}

void Matrix::SortRow(int row)
{
	// Сортируем пузырьком data[row]
	int temp = 0;
	for (int i = 0; i < columnsCount - 1; i++)
		for (int j = 0; j < columnsCount - i - 1; j++)
			if (data[row][j] > data[row][j + 1])
			{
				temp = data[row][j];
				data[row][j] = data[row][j + 1];
				data[row][j + 1] = temp;
			}
}

void Matrix::SortColumn(int column)
{
	int temp = 0;
	// Сортируем пузырьком data[][column]
	for (int i = 0; i < rowsCount - 1; i++)
		for (int j = 0; j < rowsCount - i - 1; j++)
			if (data[j][column] > data[j + 1][column])
			{
				temp = data[j][column];
				data[j][column] = data[j + 1][column];
				data[j + 1][column] = temp;
			}
}


Matrix& Matrix::operator=(const BaseMatrix& obj)
{
	if (this == &obj)
		return *this;

	// Освобождаем память
	for (int i = 0; i < rowsCount; i++)
		delete[] data[i];
	delete[] data;


	columnsCount = obj.ColumnsCount();
	rowsCount = obj.RowsCount();

	// Выделяем память заного под новую матрицу и заполняем её
	data = new int* [rowsCount];
	for (int i = 0; i < rowsCount; i++)
	{
		data[i] = new int[columnsCount];
		for (int j = 0; j < columnsCount; j++)
			data[i][j] = obj.GetValue(j, i);
	}
	return *this;
}

bool Matrix::operator()(int column, int row, int value)
{
	return SetValue(column, row, value);
}

bool Matrix::SetValue(int column, int row, int value)
{
	if (row > rowsCount || row < 0 || column > columnsCount || column < 0)
		return false;
	data[row][column] = value;
	return true;
}

std::string Matrix::ToString()
{
	std::string str = "Full matrix:\n";
	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < columnsCount; j++)
		{
			str += std::to_string(data[i][j]) + " ";
		}
		str += "\n";
	}
	str += "\0";
	return str;
}
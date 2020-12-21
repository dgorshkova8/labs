#include "Matrix.h"
// ���������� ��� �������� ����������� id
unsigned int Matrix::idCounter = 0;

Matrix::Matrix(int columnsCount, int rowsCount)
{
	id = idCounter;
	idCounter++;

	this->columnsCount = columnsCount;
	this->rowsCount = rowsCount;

	// �������� ������ ��� �����
	data = new int* [rowsCount];
	for (int i = 0; i < rowsCount; i++)
	{
		// �������� ������ ��� ��������� �����
		data[i] = new int[columnsCount];

		// ��������� ������ ����� ��������� �������� �����
		for (int j = 0; j < columnsCount; j++)
			data[i][j] = 0;
	}
}



Matrix::Matrix() : Matrix::Matrix(3, 3) /* �������� ����������� ������� 3�3*/ {}

Matrix::Matrix(const Matrix& obj)
{
	// ��� ����������� � �����������, ������ ������ ���� �� ����������� ������
	id = idCounter;
	idCounter++;

	columnsCount = obj.columnsCount;
	rowsCount = obj.rowsCount;

	data = new int* [rowsCount];
	for (int i = 0; i < rowsCount; i++)
	{
		data[i] = new int[columnsCount];
		for (int j = 0; j < columnsCount; j++)
			data[i][j] = obj.data[i][j];
	}
}

Matrix::~Matrix()
{
	// ������� ������ ���������� ��� ��������� �����
	for (int i = 0; i < rowsCount; i++)
		delete[] data[i];
	// ������� ������ ���������� ��� ������
	delete[] data;
}

int Matrix::RowsCount()
{
	return rowsCount;
}

int Matrix::ColumnsCount()
{
	return columnsCount;
}

int Matrix::GetValue(int column, int row)
{
	return data[row][column];
}

bool Matrix::SetValue(int column, int row, int value)
{
	data[row][column] = value;
	return true;
}

std::string Matrix::ToString()
{
	std::string str = "";
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

void Matrix::SortRow(int row)
{
	// ��������� ��������� data[row]
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
	// ��������� ��������� data[][column]
	for (int i = 0; i < rowsCount - 1; i++)
		for (int j = 0; j < rowsCount - i - 1; j++)
			if (data[j][column] > data[j + 1][column])
			{
				temp = data[j][column];
				data[j][column] = data[j + 1][column];
				data[j + 1][column] = temp;
			}
}

int Matrix::Id()
{
	return id;
}

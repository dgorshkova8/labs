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

Matrix& Matrix::operator=(const Matrix& obj)
{
	if (this == &obj)
		return *this;

	columnsCount = obj.columnsCount;
	rowsCount = obj.rowsCount;

	// ����������� ������
	for (int i = 0; i < rowsCount; i++)
		delete[] data[i];
	delete[] data;

	// �������� ������ ������ ��� ����� ������� � ��������� �
	data = new int* [rowsCount];
	for (int i = 0; i < rowsCount; i++)
	{
		data[i] = new int[columnsCount];
		for (int j = 0; j < columnsCount; j++)
			data[i][j] = obj.data[i][j];
	}
}

int& Matrix::operator[](int i)
{
	int col = i % columnsCount;
	int row = i / rowsCount;
	return data[row][col];
}

bool Matrix::operator()(int column, int row, int value)
{
	return SetValue(column, row, value);
}

Matrix operator+(const Matrix& obj1, const Matrix& obj2)
{
	// ���������� �����������
	if (obj1.columnsCount != obj2.columnsCount || obj1.rowsCount != obj2.rowsCount)
		return Matrix();

	// ������ ����� ������ �������
	Matrix m(obj1);
	// ��������� �������� ������
	for (int i = 0; i < m.rowsCount; i++)
		for (int j = 0; j < m.columnsCount; j++)
			m.data[i][j] = m.data[i][j] + obj2.data[i][j];

	return m;
}

Matrix operator-(const Matrix& obj1, const Matrix& obj2)
{
	// ���������� �����������
	if (obj1.columnsCount != obj2.columnsCount || obj1.rowsCount != obj2.rowsCount)
		return Matrix();

	// ������ ����� ������ �������
	Matrix m(obj1);
	// �������� �������� ������
	for (int i = 0; i < m.rowsCount; i++)
		for (int j = 0; j < m.columnsCount; j++)
			m.data[i][j] = m.data[i][j] - obj2.data[i][j];

	return m;
}

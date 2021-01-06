#include "TMatrix.h"

// Вызываем конструктор для единичной матрицы 3x3
TMatrix::TMatrix() : TMatrix(3)
{
}

// Создаём базовую квадратную матрицу
TMatrix::TMatrix(int range)
	: BaseMatrix(range, range)
{
	this->range = range;
}

TMatrix::TMatrix(const TMatrix& obj)
	: BaseMatrix(obj)
{
	range = obj.range;
}

TMatrix::~TMatrix()
{
}

int TMatrix::GetRange() const
{
	return range;
}

bool TMatrix::SetValue(int column, int row, int value)
{
	if (row > rowsCount || row < 0 || column > columnsCount || column < 0)
		return false;
	if (column > row)
		return false;
	data[row][column] = value;
	return true;
}

std::string TMatrix::ToString()
{
	std::string str = "TMatrix:\n";
	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < columnsCount; j++)
		{
			str += ((j <= i) ? std::to_string(data[i][j]) : " ") + " ";
		}
		str += "\n";
	}
	str += "\0";
	return str;
}
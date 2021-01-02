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
#include "EMatrix.h"

// Вызываем конструктор для единичной матрицы 3x3
EMatrix::EMatrix() : EMatrix(3)
{
}

// Создаём базовую квадратную матрицу
EMatrix::EMatrix(int range)
	: BaseMatrix(range, range)
{
	this->range = range;
	// Заполняем диагональ единицами
	for (int i = 0; i < range; i++)
		data[i][i] = 1;
}

EMatrix::EMatrix(const EMatrix& obj)
	: BaseMatrix(obj)
{
	range = obj.range;
}

EMatrix::~EMatrix()
{
}

int EMatrix::GetRange() const
{
	return range;
}
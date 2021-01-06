#pragma once
#include "BaseMatrix.h"
#include "ISettableMatrix.h"
class Matrix : public BaseMatrix, public ISettableMatrix 
{
public:
	Matrix();
	Matrix(int columnsCount, int rowsCount);
	Matrix(const BaseMatrix&);
	~Matrix();
	// Сортирует заданную строку.
	void SortRow(int row);
	// Сортирует заданный столбец.
	void SortColumn(int column);

	// Перегрузка оператора присваивания
	// Осуществляет проверку на самокопирование (BaseMatrix a; a = a;)
	// Если объект не равен сам себе, то копирует данные из переданного объкта
	Matrix& operator=(const BaseMatrix& obj);

	// Оператор вызова функции
	// Параметры столбец, строка, значение
	// Выполняет функцию SetValue
	bool operator()(int column, int row, int value);

	bool SetValue(int column, int row, int value);

	std::string ToString();
};


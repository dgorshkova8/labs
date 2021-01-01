#pragma once
// Интерфейс, который добавляет возможность устанавливать значения для матрицы
class ISettableMatrix
{
public:
	// Виртуальный деструктор для правильного полиморфного использования
	virtual ~ISettableMatrix() {}
	// Заменяет значение элемента матрицы по заданным столбцу и строке на значение value
	virtual bool SetValue(int column, int row, int value) = 0;
};


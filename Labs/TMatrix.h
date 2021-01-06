#pragma once
#include "BaseMatrix.h"
#include "ISettableMatrix.h"
class TMatrix :
    public BaseMatrix, public ISettableMatrix
{
protected:
	int range;
public:
	// ≈динична€ матрица- квадратна€ матрица с диагональю заполненноей 1
	TMatrix();
	TMatrix(int range);
	TMatrix(const TMatrix&);

	~TMatrix();

	// ¬озвращает ранг единичной матрицы
	int GetRange() const;

	bool SetValue(int column, int row, int value);
	std::string ToString();
};


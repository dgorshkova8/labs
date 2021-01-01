#pragma once
#include "BaseMatrix.h"
class EMatrix :
    public BaseMatrix
{
protected:
	int range;
public:
	// ≈динична€ матрица- квадратна€ матрица с диагональю заполненноей 1
	EMatrix();
	EMatrix(int range);
	EMatrix(const EMatrix&);

	~EMatrix();

	// ¬озвращает ранг единичной матрицы
	int GetRange() const;
};


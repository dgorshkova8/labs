#pragma once
#include "BaseMatrix.h"
#include "ISettableMatrix.h"
class TMatrix :
    public BaseMatrix, public ISettableMatrix
{
protected:
	int range;
public:
	// ��������� �������- ���������� ������� � ���������� ������������ 1
	TMatrix();
	TMatrix(int range);
	TMatrix(const TMatrix&);

	~TMatrix();

	// ���������� ���� ��������� �������
	int GetRange() const;

	bool SetValue(int column, int row, int value);
	std::string ToString();
};


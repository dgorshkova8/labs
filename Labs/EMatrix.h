#pragma once
#include "BaseMatrix.h"
class EMatrix :
    public BaseMatrix
{
protected:
	int range;
public:
	// ��������� �������- ���������� ������� � ���������� ������������ 1
	EMatrix();
	EMatrix(int range);
	EMatrix(const EMatrix&);

	~EMatrix();

	// ���������� ���� ��������� �������
	int GetRange() const;
};


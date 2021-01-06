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
	// ��������� �������� ������.
	void SortRow(int row);
	// ��������� �������� �������.
	void SortColumn(int column);

	// ���������� ��������� ������������
	// ������������ �������� �� ��������������� (BaseMatrix a; a = a;)
	// ���� ������ �� ����� ��� ����, �� �������� ������ �� ����������� ������
	Matrix& operator=(const BaseMatrix& obj);

	// �������� ������ �������
	// ��������� �������, ������, ��������
	// ��������� ������� SetValue
	bool operator()(int column, int row, int value);

	bool SetValue(int column, int row, int value);

	std::string ToString();
};


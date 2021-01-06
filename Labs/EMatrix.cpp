#include "EMatrix.h"

// �������� ����������� ��� ��������� ������� 3x3
EMatrix::EMatrix() : EMatrix(3)
{
}

// ������ ������� ���������� �������
EMatrix::EMatrix(int range)
	: BaseMatrix(range, range)
{
	this->range = range;
	// ��������� ��������� ���������
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

std::string EMatrix::ToString()
{
	std::string str = "EMatrix:\n";
	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < columnsCount; j++)
		{
			str += ((i == j) ? std::to_string(data[i][j]) : " ") + " ";
		}
		str += "\n";
	}
	str += "\0";
	return str;
}
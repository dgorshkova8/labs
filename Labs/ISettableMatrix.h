#pragma once
// ���������, ������� ��������� ����������� ������������� �������� ��� �������
class ISettableMatrix
{
public:
	// ����������� ���������� ��� ����������� ������������ �������������
	virtual ~ISettableMatrix() {}
	// �������� �������� �������� ������� �� �������� ������� � ������ �� �������� value
	virtual bool SetValue(int column, int row, int value) = 0;
};


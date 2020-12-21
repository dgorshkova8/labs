#include <iostream>
#include "Matrix.h"
#include "Tests.hpp"

using namespace std;

int main()
{
	Matrix matrix;

	bool active = true;
	while (active)
	{
		int a = -1;
		int col = 0;
		int row = 0;
		int val = 0;
		cout << "Matrix 3x3 menu:\n"
			<< "1. Show\n"
			<< "2. RousCount\n"
			<< "3. ColumnsCount\n"
			<< "4. GetValue\n"
			<< "5. SetValue\n"
			<< "6. SortRow\n"
			<< "7. SortColumn\n"
			<< "9. Tests\n"
			<< "0. Exit\n"
			<< "---> ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << matrix.ToString() << endl;
			break;
		}
		case 2:
		{
			cout << matrix.RowsCount() << endl;
			break;
		}
		case 3:
		{
			cout << matrix.ColumnsCount() << endl;
			break;
		}
		case 4:
		{
			cout << "input column: ";
			cin >> col;
			cout << "input row: ";
			cin >> row;

			if (col < 0 || row < 0 || col >= matrix.ColumnsCount() || row >= matrix.RowsCount())
			{
				cout << "Bad index\n";
				break;
			}
			cout << matrix.GetValue(col, row) << endl;
			break;
		}
		case 5:
		{
			cout << "input column: ";
			cin >> col;
			cout << "input row: ";
			cin >> row;
			cout << "input value: ";
			cin >> val;
			if (col < 0 || row < 0 || col >= matrix.ColumnsCount() || row >= matrix.RowsCount())
			{
				cout << "Bad index\n";
				break;
			}
			matrix.SetValue(col, row, val);
			cout << "Setted"<< endl;
			break;
		}
		case 6:
		{
			cout << "input row: ";
			cin >> row;
			if (row < 0 || row >= matrix.RowsCount())
			{
				cout << "Bad index\n";
				break;
			}
			matrix.SortRow(row);
			cout << "Sorted" << endl;
			break;
		}
		case 7:
		{
			cout << "input column: ";
			cin >> col;
			if (col < 0 || col >= matrix.ColumnsCount())
			{
				cout << "Bad index\n";
				break;
			}
			matrix.SortColumn(col);
			cout << "Sorted" << endl;
			break;
		}
		case 9:
		{
			MatrixTests::FullTest();
			break;
		}
		case 0:
		{
			active = false;
			break;
		}
		default:
		{
			cout << "Unknowing comand";
		}
		}
		if (active)
		{
			cin.get();
			cin.get();
		}
	}
	return 0;
}
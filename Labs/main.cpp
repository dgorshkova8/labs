#include <iostream>
#include "Matrix.h"
#include "Tests.hpp"

using namespace std;

int main()
{
	Matrix matrix;
	const char* serializePath = "serialized.b";

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
			<< "8. inputMatrix\n"
			<< "9. serialize\n"
			<< "10. deserialize\n"
			<< "11. append EMatrix\n"
			<< "12. input EMatrix\n"
			<< "20. Tests\n"
			<< "0. Exit\n"
			<< "---> ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			cout << matrix << endl;
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
		case 8:
		{
			cout << "input columns rows values: ";
			cin >> matrix;
			cout << "Saved";
			break;
		}
		case 9:
		{
			cout << ((matrix.serialize(serializePath)) ? "serialized" : "Can't serialize");
			break;
		}
		case 10:
		{
			cout << ((matrix.deserialize(serializePath)) ? "deserialized" : "Can't deserialize");
			break;
		}
		case 11:
		{
			if (matrix.ColumnsCount() != matrix.RowsCount())
			{
				cout << "Matrix shoold be quad";
				break;
			}
			EMatrix em(matrix.ColumnsCount());
			matrix = matrix + em;
			cout << "Appended";
			break;
		}
		case 12:
		{
			cout << "input rank: ";
			cin >> col;
			if (col <= 0)
			{
				cout << "rank shoold be bigger than 0";
				break;
			}
			EMatrix em(col);
			matrix = em;
			cout << "matrix setted";
			break;
		}
		case 20:
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
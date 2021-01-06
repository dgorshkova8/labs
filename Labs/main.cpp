#include <iostream>
#include "Matrix.h"
#include "Tests.hpp"
#include "BaseMatrixList.h"

using namespace std;

int main()
{
	Matrix matrix;
	BaseMatrixList matrixList;
	const char* serializePath = "serialized.b";

	BaseMatrix B1(3, 2);
	EMatrix E1(5);
	TMatrix T1(3);
	T1.SetValue(0, 0, 0);
	T1.SetValue(0, 1, 1);
	T1.SetValue(1, 1, 2);
	T1.SetValue(0, 2, 3);
	T1.SetValue(1, 2, 4);
	T1.SetValue(2, 2, 5);

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
			<< "\n\tMatrixList:\n"
			<< "13. append this matrix in list\n"
			<< "14. append matrix E1\n"
			<< "15. append matrix T1\n"
			<< "16. append matrix B1\n"
			<< "17. call ToString for all list elements\n"
			<< "18. clear list\n"
			<< "\n\tTests:\n"
			<< "20. Tests\n"
			<< "0. Exit\n________\n\n"
			<< "---> ";
		cin >> a;
		cout << "\n";
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

			try
			{
				cout << matrix.GetValue(col, row) << endl;
			}
			catch (const std::exception& e)
			{
				cout << e.what();
			}
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
			cout << (matrix.SetValue(col, row, val) ? "Setted" : "Out of range");
			break;
		}
		case 6:
		{
			cout << "input row: ";
			cin >> row;
			try
			{
				matrix.SortRow(row);
				cout << "Sorted" << endl;
			}
			catch (const std::exception& e)
			{
				cout << e.what();
			}
			break;
		}
		case 7:
		{
			cout << "input column: ";
			cin >> col;
			try
			{
				matrix.SortColumn(col);
				cout << "Sorted" << endl;
			}
			catch (const std::exception& e)
			{
				cout << e.what();
			}
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
			try
			{
				EMatrix em(col);
				matrix = em;
				cout << "matrix setted";
			}
			catch (const std::exception& e)
			{
				cout << e.what();
			}
			break;
		}
		case 13:
		{
			matrixList.Append(matrix);
			cout << "Appended";
			break;
		}
		case 14:
		{
			matrixList.Append(E1);
			cout << "Appended";
			break;
		}
		case 15:
		{
			matrixList.Append(T1);
			cout << "Appended";
			break;
		}
		case 16:
		{
			matrixList.Append(B1);
			cout << "Appended";
			break;
		}
		case 17:
		{
			for (int i = 0; i < matrixList.GetSize(); i++)
			{
				cout << matrixList[i].ToString() << endl;
			}
			break;
		}
		case 18:
		{
			matrixList.Clear();
			cout << "Cleared";
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
#pragma once
#include <iostream>
#include <string>
#include "Matrix.h"
namespace Asserts
{
	void AssertEqual(int x, int y)
	{
		std::cout << ((x == y) ? "Success!\n"
			: std::string("Failed on ") + std::to_string(x) + " == " + std::to_string(y) + "\n");
	}
}
namespace MatrixTests
{
	using namespace Asserts;
	void DefaultMatrixInitTest()
	{
		std::cout << "DefaultMatrix(3x3)InitTest:\n";
		Matrix matrix;

		std::cout << "\t(matrix.RowsCount() == 3): ";
		AssertEqual(matrix.RowsCount(), 3);

		std::cout << "\t(matrix.ColumnsCount() == 3): ";
		AssertEqual(matrix.ColumnsCount(), 3);
		
		std::cout << "\t(matrix.GetValue(0, 0) == 0): ";
		AssertEqual(matrix.GetValue(0, 0), 0);

		std::cout << "\t(matrix.GetValue(2, 2) == 0): ";
		AssertEqual(matrix.GetValue(2, 2), 0);
	}

	void Matrix1x1InitTest()
	{
		std::cout << "Matrix1x1InitTest:\n";
		Matrix matrix(1,1);

		std::cout << "\t(matrix.RowsCount() == 1): ";
		AssertEqual(matrix.RowsCount(), 1);

		std::cout << "\t(matrix.ColumnsCount() == 1): ";
		AssertEqual(matrix.ColumnsCount(), 1);

		std::cout << "\t(matrix.GetValue(0, 0) == 0): ";
		AssertEqual(matrix.GetValue(0, 0), 0);
	}

	void MatrixSetValueTest()
	{
		std::cout << "MatrixSetValueTest:\n";
		Matrix matrix;

		matrix.SetValue(0, 0, 0);
		std::cout << "\t(Set matrix[0][0] to 0): ";
		AssertEqual(matrix.GetValue(0, 0), 0);

		matrix.SetValue(0, 0, -1);
		std::cout << "\t(Set matrix[0][0] to -1): ";
		AssertEqual(matrix.GetValue(0, 0), -1);

		matrix.SetValue(0, 0, 1);
		std::cout << "\t(Set matrix[0][0] to 1): ";
		AssertEqual(matrix.GetValue(0, 0), 1);
	}

	void MatrixSortRowTest()
	{
		std::cout << "MatrixSortRowTest:\n";
		Matrix matrix(3,1);

		matrix.SetValue(0, 0, 0);
		matrix.SetValue(1, 0, -5);
		matrix.SetValue(2, 0, 4);

		matrix.SortRow(0);

		std::cout << "\t(sort row 0 in ([0, -5, 4]) and check matrix[0][0] == -5): ";
		AssertEqual(matrix.GetValue(0, 0), -5);

		std::cout << "\t(sort row 0 in ([0, -5, 4]) and check matrix[1][0] == 0): ";
		AssertEqual(matrix.GetValue(1, 0), 0);

		std::cout << "\t(sort row 0 in ([0, -5, 4]) and check matrix[2][0] == 4): ";
		AssertEqual(matrix.GetValue(2,0), 4);
	}


	void MatrixSortColumnTest()
	{
		std::cout << "MatrixSortColumnTest:\n";
		Matrix matrix(1, 3);

		matrix.SetValue(0, 0, 0);
		matrix.SetValue(0, 1, -5);
		matrix.SetValue(0, 2, 4);

		matrix.SortColumn(0);

		std::cout << "\t(sort column 0 in ([0], [-5], [4]) and check matrix[0][0] == -5): ";
		AssertEqual(matrix.GetValue(0, 0), -5);

		std::cout << "\t(sort column 0 in ([0], [-5], [4]) and check matrix[0][1] == 0): ";
		AssertEqual(matrix.GetValue(0, 1), 0);

		std::cout << "\t(sort column 0 in ([0], [-5], [4]) and check matrix[0][2] == 4): ";
		AssertEqual(matrix.GetValue(0, 2), 4);
	}

	void FullTest()
	{
		DefaultMatrixInitTest();
		std::cout << std::endl;
		Matrix1x1InitTest();
		std::cout << std::endl;
		MatrixSetValueTest();
		std::cout << std::endl;
		MatrixSortRowTest();
		std::cout << std::endl;
		MatrixSortColumnTest();
		std::cout << std::endl;
	}
}


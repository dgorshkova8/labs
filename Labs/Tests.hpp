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
	
	void MatrixAssignmentTest()
	{
		std::cout << "MatrixAssignmentTest:\n";
		Matrix m1;
		Matrix m2(2,2);
		m2.SetValue(0, 0, 1);
		m2.SetValue(1, 0, 2);
		m2.SetValue(0, 1, 3);
		m2.SetValue(1, 1, 4);
		m1 = m2;
		std::cout << "\t(deafult assignment ([1,2],[3,4]) and check rows count = 2): ";
		AssertEqual(m1.RowsCount(), 2);
		std::cout << "\t(deafult assignment ([1,2],[3,4]) and check columns count = 2): ";
		AssertEqual(m1.ColumnsCount(), 2);
		std::cout << "\t(deafult assignment ([1,2],[3,4]) and check (0,0) = 1): ";
		AssertEqual(m1.GetValue(0, 0), 1);
		std::cout << "\t(deafult assignment ([1,2],[3,4]) and check (1,0) = 2): ";
		AssertEqual(m1.GetValue(1, 0), 2);
		std::cout << "\t(deafult assignment ([1,2],[3,4]) and check (0,1) = 3): ";
		AssertEqual(m1.GetValue(0, 1), 3);
		std::cout << "\t(deafult assignment ([1,2],[3,4]) and check (1,1) = 4): ";
		AssertEqual(m1.GetValue(1, 1), 4);
	}

	void MatrixSummTest()
	{
		std::cout << "MatrixSummTest:\n";
		Matrix m1(2, 2);
		m1.SetValue(0, 0, 1);
		m1.SetValue(1, 0, 1);
		m1.SetValue(0, 1, -1);
		m1.SetValue(1, 1, 0);
		Matrix m2(2, 2);
		m2.SetValue(0, 0, 1);
		m2.SetValue(1, 0, 2);
		m2.SetValue(0, 1, 3);
		m2.SetValue(1, 1, 4);
		Matrix m3 = m2 + m1;
		std::cout << "\t( ([1,2],[3,4]) + ([1,1],[-1,0]) and check (0,0) = 2): ";
		AssertEqual(m3.GetValue(0, 0), 2);
		std::cout << "\t( ([1,2],[3,4]) + ([1,1],[-1,0]) and check (1,0) = 3): ";
		AssertEqual(m3.GetValue(1, 0), 3);
		std::cout << "\t( ([1,2],[3,4]) + ([1,1],[-1,0]) and check (0,1) = 2): ";
		AssertEqual(m3.GetValue(0, 1), 2);
		std::cout << "\t( ([1,2],[3,4]) + ([1,1],[-1,0]) and check (1,1) = 4): ";
		AssertEqual(m3.GetValue(1, 1), 4);
	}

	void MatrixMinusTest()
	{
		std::cout << "MatrixMinusTest:\n";
		Matrix m1(2, 2);
		m1.SetValue(0, 0, 1);
		m1.SetValue(1, 0, 1);
		m1.SetValue(0, 1, -1);
		m1.SetValue(1, 1, 0);
		Matrix m2(2, 2);
		m2.SetValue(0, 0, 1);
		m2.SetValue(1, 0, 2);
		m2.SetValue(0, 1, 3);
		m2.SetValue(1, 1, 4);
		Matrix m3 = m2 - m1;
		std::cout << "\t( ([1,2],[3,4]) - ([1,1],[-1,0]) and check (0,0) = 0): ";
		AssertEqual(m3.GetValue(0, 0), 0);
		std::cout << "\t( ([1,2],[3,4]) - ([1,1],[-1,0]) and check (1,0) = 1): ";
		AssertEqual(m3.GetValue(1, 0), 1);
		std::cout << "\t( ([1,2],[3,4]) - ([1,1],[-1,0]) and check (0,1) = 4): ";
		AssertEqual(m3.GetValue(0, 1), 4);
		std::cout << "\t( ([1,2],[3,4]) - ([1,1],[-1,0]) and check (1,1) = 4): ";
		AssertEqual(m3.GetValue(1, 1), 4);
	}

	void MatrixIndexOperatorTest()
	{
		std::cout << "MatrixIndexOperatorTest:\n";
		Matrix m2(2, 2);
		m2.SetValue(0, 0, 1);
		m2.SetValue(1, 0, 2);
		m2.SetValue(0, 1, 3);
		m2.SetValue(1, 1, 4);
		std::cout << "\t( ([1,2],[3,4]) index 0 = 1): ";
		AssertEqual(m2[0], 1);
		std::cout << "\t( ([1,2],[3,4]) index 1 = 2): ";
		AssertEqual(m2[1], 2);
		std::cout << "\t( ([1,2],[3,4]) index 2 = 3): ";
		AssertEqual(m2[2], 3);
		std::cout << "\t( ([1,2],[3,4]) index 3 = 4): ";
		AssertEqual(m2[3], 4);
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
		MatrixAssignmentTest();
		std::cout << std::endl;
		MatrixSummTest();
		std::cout << std::endl;
		MatrixMinusTest();
		std::cout << std::endl;
		MatrixIndexOperatorTest();
		std::cout << std::endl;
	}
}


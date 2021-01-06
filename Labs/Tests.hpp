#pragma once
#include <iostream>
#include <string>
#include "Matrix.h"
#include "EMatrix.h"
#include "TMatrix.h"
#include "List.hpp"
namespace Asserts
{
	void AssertEqual(int x, int y)
	{
		std::cout << ((x == y) ? "Success!\n"
			: std::string("Failed on ") + std::to_string(x) + " == " + std::to_string(y) + "\n");
	}

	void AssertEqual(float x, float y)
	{
		std::cout << ((x == y) ? "Success!\n"
			: std::string("Failed on ") + std::to_string(x) + " == " + std::to_string(y) + "\n");
	}

	void AssertEqual(bool x, bool y)
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

		std::cout << "\t( matrix.RowsCount() == 3 ): ";
		AssertEqual(matrix.RowsCount(), 3);

		std::cout << "\t( matrix.ColumnsCount() == 3 ): ";
		AssertEqual(matrix.ColumnsCount(), 3);
		
		std::cout << "\t( matrix.GetValue(0, 0) == 0 ): ";
		AssertEqual(matrix.GetValue(0, 0), 0);

		std::cout << "\t( matrix.GetValue(2, 2) == 0 ): ";
		AssertEqual(matrix.GetValue(2, 2), 0);

		bool initFlag = false;
		std::cout << "\t( init matrix(0,5) exception ): ";
		try
		{
			Matrix m(0, 5);
			initFlag = true;
		}
		catch (const std::exception&)
		{
			
		}
		AssertEqual(initFlag, false);

		initFlag = false;
		std::cout << "\t( init matrix(5,0) exception ): ";
		try
		{
			Matrix m(5, 0);
			initFlag = true;
		}
		catch (const std::exception&)
		{

		}
		AssertEqual(initFlag, false);
	}

	void Matrix1x1InitTest()
	{
		std::cout << "Matrix1x1InitTest:\n";
		Matrix matrix(1,1);

		std::cout << "\t( matrix.RowsCount() == 1 ): ";
		AssertEqual(matrix.RowsCount(), 1);

		std::cout << "\t( matrix.ColumnsCount() == 1 ): ";
		AssertEqual(matrix.ColumnsCount(), 1);

		std::cout << "\t( matrix.GetValue(0, 0) == 0 ): ";
		AssertEqual(matrix.GetValue(0, 0), 0);

		bool exceptionFlag = false;
		std::cout << "\t( matrix.GetValue(-1, 0) exception ): ";
		try
		{
			matrix.GetValue(-1, 0);
			exceptionFlag = true;
		}
		catch (const std::exception&)
		{

		}
		AssertEqual(exceptionFlag, false);
	}

	void MatrixSetValueTest()
	{
		std::cout << "MatrixSetValueTest:\n";
		Matrix matrix;

		matrix.SetValue(0, 0, 0);
		std::cout << "\t( Set matrix[0][0] to 0 ): ";
		AssertEqual(matrix.GetValue(0, 0), 0);

		matrix.SetValue(0, 0, -1);
		std::cout << "\t( Set matrix[0][0] to -1 ): ";
		AssertEqual(matrix.GetValue(0, 0), -1);

		matrix.SetValue(0, 0, 1);
		std::cout << "\t( Set matrix[0][0] to 1 ): ";
		AssertEqual(matrix.GetValue(0, 0), 1);

		std::cout << "\t( Set matrix[-1][0] to 1 false ): ";
		AssertEqual(matrix.SetValue(-1, 0, 1), false);

		std::cout << "\t( Set matrix[0][-1] to 1 false ): ";
		AssertEqual(matrix.SetValue(0, -1, 1), false);
	}

	void MatrixSortRowTest()
	{
		std::cout << "MatrixSortRowTest:\n";
		Matrix matrix(3,1);

		matrix.SetValue(0, 0, 0);
		matrix.SetValue(1, 0, -5);
		matrix.SetValue(2, 0, 4);

		matrix.SortRow(0);

		std::cout << "\t( Sort row 0 in ([0, -5, 4]) and check matrix[0][0] == -5 ): ";
		AssertEqual(matrix.GetValue(0, 0), -5);

		std::cout << "\t( Sort row 0 in ([0, -5, 4]) and check matrix[1][0] == 0 ): ";
		AssertEqual(matrix.GetValue(1, 0), 0);

		std::cout << "\t( Sort row 0 in ([0, -5, 4]) and check matrix[2][0] == 4 ): ";
		AssertEqual(matrix.GetValue(2,0), 4);

		bool exceptionFlag = false;
		std::cout << "\t( Sort row -1 exception ): ";
		try
		{
			matrix.SortRow(-1);
			exceptionFlag = true;
		}
		catch (const std::exception&)
		{

		}
		AssertEqual(exceptionFlag, false);
	}


	void MatrixSortColumnTest()
	{
		std::cout << "MatrixSortColumnTest:\n";
		Matrix matrix(1, 3);

		matrix.SetValue(0, 0, 0);
		matrix.SetValue(0, 1, -5);
		matrix.SetValue(0, 2, 4);

		matrix.SortColumn(0);

		std::cout << "\t( Sort column 0 in ([0], [-5], [4]) and check matrix[0][0] == -5 ): ";
		AssertEqual(matrix.GetValue(0, 0), -5);

		std::cout << "\t( Sort column 0 in ([0], [-5], [4]) and check matrix[0][1] == 0 ): ";
		AssertEqual(matrix.GetValue(0, 1), 0);

		std::cout << "\t( Sort column 0 in ([0], [-5], [4]) and check matrix[0][2] == 4 ): ";
		AssertEqual(matrix.GetValue(0, 2), 4);

		bool exceptionFlag = false;
		std::cout << "\t( Sort column -1 exception ): ";
		try
		{
			matrix.SortColumn(-1);
			exceptionFlag = true;
		}
		catch (const std::exception&)
		{

		}
		AssertEqual(exceptionFlag, false);
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
		std::cout << "\t( Deafult(3x3) assignment ([1,2],[3,4]) and check rows count = 2 ): ";
		AssertEqual(m1.RowsCount(), 2);
		std::cout << "\t( Deafult(3x3) assignment ([1,2],[3,4]) and check columns count = 2 ): ";
		AssertEqual(m1.ColumnsCount(), 2);
		std::cout << "\t( Deafult(3x3) assignment ([1,2],[3,4]) and check (0,0) = 1 ): ";
		AssertEqual(m1.GetValue(0, 0), 1);
		std::cout << "\t( Deafult(3x3) assignment ([1,2],[3,4]) and check (1,0) = 2 ): ";
		AssertEqual(m1.GetValue(1, 0), 2);
		std::cout << "\t( Deafult(3x3) assignment ([1,2],[3,4]) and check (0,1) = 3 ): ";
		AssertEqual(m1.GetValue(0, 1), 3);
		std::cout << "\t( Deafult(3x3) assignment ([1,2],[3,4]) and check (1,1) = 4 ): ";
		AssertEqual(m1.GetValue(1, 1), 4);
		Matrix m3;
		m2 = m3;
		std::cout << "\t( ([1,2],[3,4]) assignment default(3x3) and check rows count = 3 ): ";
		AssertEqual(m2.RowsCount(), 3);
		std::cout << "\t( ([1,2],[3,4]) assignment default(3x3) and check columns count = 3 ): ";
		AssertEqual(m2.ColumnsCount(), 3);
		std::cout << "\t( ([1,2],[3,4]) assignment default(3x3) and check (2, 2) = 0 ): ";
		AssertEqual(m2.GetValue(2, 2), 0);

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
		std::cout << "\t( ([1,2],[3,4]) + ([1,1],[-1,0]) and check (0,0) = 2 ): ";
		AssertEqual(m3.GetValue(0, 0), 2);
		std::cout << "\t( ([1,2],[3,4]) + ([1,1],[-1,0]) and check (1,0) = 3 ): ";
		AssertEqual(m3.GetValue(1, 0), 3);
		std::cout << "\t( ([1,2],[3,4]) + ([1,1],[-1,0]) and check (0,1) = 2 ): ";
		AssertEqual(m3.GetValue(0, 1), 2);
		std::cout << "\t( ([1,2],[3,4]) + ([1,1],[-1,0]) and check (1,1) = 4 ): ";
		AssertEqual(m3.GetValue(1, 1), 4);

		bool exceptionFlag = false;
		std::cout << "\t( matrix 2x2 + matrix 4x4 exception ): ";
		try
		{
			m3 + Matrix(4, 4);
			exceptionFlag = true;
		}
		catch (const std::exception&)
		{

		}
		AssertEqual(exceptionFlag, false);

		exceptionFlag = false;
		std::cout << "\t( matrix 4x4 + matrix 2x2 exception ): ";
		try
		{
			Matrix(4, 4) + m3;
			exceptionFlag = true;
		}
		catch (const std::exception&)
		{

		}
		AssertEqual(exceptionFlag, false);
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
		std::cout << "\t( ([1,2],[3,4]) - ([1,1],[-1,0]) and check (0,0) = 0 ): ";
		AssertEqual(m3.GetValue(0, 0), 0);
		std::cout << "\t( ([1,2],[3,4]) - ([1,1],[-1,0]) and check (1,0) = 1 ): ";
		AssertEqual(m3.GetValue(1, 0), 1);
		std::cout << "\t( ([1,2],[3,4]) - ([1,1],[-1,0]) and check (0,1) = 4 ): ";
		AssertEqual(m3.GetValue(0, 1), 4);
		std::cout << "\t( ([1,2],[3,4]) - ([1,1],[-1,0]) and check (1,1) = 4 ): ";
		AssertEqual(m3.GetValue(1, 1), 4);

		bool exceptionFlag = false;
		std::cout << "\t( matrix 2x2 - matrix 4x4 exception ): ";
		try
		{
			m3 - Matrix(4, 4);
			exceptionFlag = true;
		}
		catch (const std::exception&)
		{

		}
		AssertEqual(exceptionFlag, false);

		exceptionFlag = false;
		std::cout << "\t( matrix 4x4 - matrix 2x2 exception ): ";
		try
		{
			Matrix(4, 4) - m3;
			exceptionFlag = true;
		}
		catch (const std::exception&)
		{

		}
		AssertEqual(exceptionFlag, false);
	}

	void MatrixIndexOperatorTest()
	{
		std::cout << "MatrixIndexOperatorTest:\n";
		Matrix m2(2, 2);
		m2.SetValue(0, 0, 1);
		m2.SetValue(1, 0, 2);
		m2.SetValue(0, 1, 3);
		m2.SetValue(1, 1, 4);
		std::cout << "\t( ([1,2],[3,4]) index 0 = 1 ): ";
		AssertEqual(m2[0], 1);
		std::cout << "\t( ([1,2],[3,4]) index 1 = 2 ): ";
		AssertEqual(m2[1], 2);
		std::cout << "\t( ([1,2],[3,4]) index 2 = 3 ): ";
		AssertEqual(m2[2], 3);
		std::cout << "\t( ([1,2],[3,4]) index 3 = 4 ): ";
		AssertEqual(m2[3], 4);
		std::cout << "\t( ( index 3 assign -1  = -1 ): ";
		m2[3] = -1;
		AssertEqual(m2[3], -1);

		bool exceptionFlag = false;
		std::cout << "\t( matrix 2x2 index 4 exception ): ";
		try
		{
			m2[4];
			exceptionFlag = true;
		}
		catch (const std::exception&)
		{

		}
		AssertEqual(exceptionFlag, false);

		exceptionFlag = false;
		std::cout << "\t( matrix 2x2 index -1 exception ): ";
		try
		{
			m2[-1];
			exceptionFlag = true;
		}
		catch (const std::exception&)
		{

		}
		AssertEqual(exceptionFlag, false);
	}

	void EMatrixTest()
	{
		std::cout << "EMatrixTest:\n";
		EMatrix em;
		std::cout << "\t( Deafult EMatrix 3x3 range = 3 ): ";
		AssertEqual(em.GetRange(), 3);
		std::cout << "\t( Deafult EMatrix 3x3 columns count = 3 ): ";
		AssertEqual(em.ColumnsCount(), 3);
		std::cout << "\t( Deafult EMatrix 3x3 rows count = 3 ): ";
		AssertEqual(em.RowsCount(), 3);
		std::cout << "\t( Deafult EMatrix 3x3 (1, 1) = 1 ): ";
		AssertEqual(em.GetValue(1, 1), 1);
		std::cout << "\t( Deafult EMatrix 3x3 (0, 1) = 0 ): ";
		AssertEqual(em.GetValue(0, 1), 0);

		Matrix m = em + em;
		std::cout << "\t( Matrix = EMatrix 3x3 + EMatrix 3x3  (1, 1) = 2 ): ";
		AssertEqual(m.GetValue(1, 1), 2);
		
	}

	void TMatrixTest()
	{
		std::cout << "TMatrixTest:\n";
		TMatrix tm;
		std::cout << "\t( Deafult TMatrix 3x3 range = 3 ): ";
		AssertEqual(tm.GetRange(), 3);
		std::cout << "\t( Deafult TMatrix 3x3 columns count = 3 ): ";
		AssertEqual(tm.ColumnsCount(), 3);
		std::cout << "\t( Deafult TMatrix 3x3 rows count = 3 ): ";
		AssertEqual(tm.RowsCount(), 3);
		std::cout << "\t( Deafult TMatrix 3x3 (1, 1) = 0 ): ";
		AssertEqual(tm.GetValue(1, 1), 0);
		std::cout << "\t( Deafult TMatrix 3x3 (0, 1) = 0 ): ";
		AssertEqual(tm.GetValue(0, 1), 0);

		Matrix m = tm + tm;
		std::cout << "\t( Matrix = TMatrix 3x3 + TMatrix 3x3  (1, 1) = 0 ): ";
		AssertEqual(m.GetValue(1, 1), 0);

		std::cout << "\t( TMatrix 3x3 (1, 1) set 5  returns true ): ";
		AssertEqual(tm.SetValue(1, 1, 5), true);
		std::cout << "\t( TMatrix 3x3 (1, 1) set 5  (1, 1) = 5 ): ";
		AssertEqual(tm.GetValue(1, 1), 5);

		
		std::cout << "\t( TMatrix 3x3 (1, 0) set 5  returns false ): ";
		AssertEqual(tm.SetValue(1, 0, 5), false);
		std::cout << "\t( TMatrix 3x3 (1, 0) set 5  (1, 0) = 0 ): ";
		AssertEqual(tm.GetValue(1, 0), 0);
		
	}

	void MatrixListTest()
	{
		std::cout << "MatrixListTest:\n";
		List<BaseMatrix> list;
		Matrix m;
		EMatrix em;
		TMatrix tm;
		BaseMatrix bm;
		std::cout << "\t( BaseMatrixList init size = 0 ): ";
		AssertEqual(list.GetSize(), 0);
		list.Append(bm);
		list.Append(m);
		list.Append(em);
		list.Append(tm);
		std::cout << "\t( BaseMatrix list with BaseMatrix, FullMatrix, EMatrix, TMatrix size = 4 ): ";
		AssertEqual(list.GetSize(), 4);
		list.Clear();
		std::cout << "\t( Cleared BaseMatrix list size = 0 ): ";
		AssertEqual(list.GetSize(), 0);
	}

	void intListTest()
	{
		std::cout << "intListTest:\n";
		List<int> intList;
		int a = 1;
		int b = 2;

		std::cout << "\t( intList init size = 0 ): ";
		AssertEqual(intList.GetSize(), 0);

		intList.Append(a);
		intList.Append(b);

		std::cout << "\t( intList with a = 1, b = 2 size = 2 ): ";
		AssertEqual(intList.GetSize(), 2);

		std::cout << "\t( intList with a = 1, b = 2 intList[0] = 1 ): ";
		AssertEqual(intList[0], 1);

		std::cout << "\t( intList with a = 1, b = 2 intList[1] = 2 ): ";
		AssertEqual(intList[1], 2);

		std::cout << "\t( intList with a = 1, b = 2 intList[2] = 1 ): ";
		AssertEqual(intList[2], 1);

		std::cout << "\t( intList with a = 1, b = 2 intList[-1] = 2 ): ";
		AssertEqual(intList[-1], 2);

		intList.Clear();
		std::cout << "\t( Cleared intList size = 0 ): ";
		AssertEqual(intList.GetSize(), 0);

	}

	void floatListTest()
	{
		std::cout << "floatListTest:\n";
		List<float> floatList;
		float a = 0.5f;
		float b = 1.5f;

		std::cout << "\t( floatList init size = 0 ): ";
		AssertEqual(floatList.GetSize(), 0);

		floatList.Append(a);
		floatList.Append(b);

		std::cout << "\t( floatList with a = 0.5f, b = 1.5f size = 2 ): ";
		AssertEqual(floatList.GetSize(), 2);

		std::cout << "\t( floatList with a = 0.5f, b = 1.5f floatList[0] = 0.5 ): ";
		AssertEqual(floatList[0], 0.5);

		std::cout << "\t( floatList with a = 0.5f, b = 1.5f floatList[1] = 1.5 ): ";
		AssertEqual(floatList[1], 1.5);

		std::cout << "\t( floatList with a = 0.5f, b = 1.5f floatList[2] = 0.5 ): ";
		AssertEqual(floatList[2], 0.5);

		std::cout << "\t( floatList with a = 0.5f, b = 1.5f floatList[-1] = 1.5 ): ";
		AssertEqual(floatList[-1], 1.5);

		floatList.Clear();
		std::cout << "\t( Cleared floatList size = 0 ): ";
		AssertEqual(floatList.GetSize(), 0);

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
		EMatrixTest();
		std::cout << std::endl;
		TMatrixTest();
		std::cout << std::endl;
		intListTest();
		std::cout << std::endl;
		floatListTest();
		std::cout << std::endl;
		MatrixListTest();
		std::cout << std::endl;

	}
}


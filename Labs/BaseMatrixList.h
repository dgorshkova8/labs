#pragma once
#include "BaseMatrix.h"
class BaseMatrixList
{
private:
	class Node
	{
	public:
		Node(BaseMatrix& obj)
		{
			matrix = &obj;
		}
		Node* next = nullptr;
		Node* prev = nullptr;
		BaseMatrix* matrix = nullptr;
	};

	Node* head = nullptr;
	int size = 0;
public:
	BaseMatrixList();
	~BaseMatrixList();
	void Append(BaseMatrix& obj);
	BaseMatrix& operator[](int index);
	void Clear();
	int GetSize();
};


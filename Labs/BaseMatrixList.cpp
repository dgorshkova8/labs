#include "BaseMatrixList.h"

BaseMatrixList::BaseMatrixList()
{
	head == nullptr;
	size = 0;
}

BaseMatrixList::~BaseMatrixList()
{
	Clear();
}

void BaseMatrixList::Append(BaseMatrix& obj)
{
	size++;
	if (head == nullptr)
	{
		head = new Node(obj);
		head->next = head;
		head->prev = head;
		return;
	}
	Node* temp = new Node(obj);
	temp->prev = head->prev;
	temp->next = head;
	head->prev->next = temp;
	head->prev = temp;
}

BaseMatrix& BaseMatrixList::operator[](int index)
{
	if (index < 0 || index >= size)
		throw std::exception("Out of range");
	Node* temp = head;
	if (index >= 0)
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
	else
		for (int i = 0; i > index; i--)
		{
			temp = temp->prev;
		}
	return *(temp->matrix);
}

void BaseMatrixList::Clear()
{
	size = 0;
	if (head != nullptr)
	{
		while (head->next != head)
		{
			Node* temp = head->next;
			head->next = temp->next;
			delete temp;
		}
		delete head;
		head = nullptr;
	}
}

int BaseMatrixList::GetSize()
{
	return size;
}

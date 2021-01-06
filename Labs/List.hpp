#pragma once
#include "BaseMatrix.h"
template <class T>
class List
{
private:
	class Node
	{
	public:
		Node(T& obj)
		{
			val = &obj;
		}
		Node* next = nullptr;
		Node* prev = nullptr;
		T* val = nullptr;
	};

	Node* head = nullptr;
	int size = 0;
public:
	List();
	~List();
	void Append(T& obj);
	T& operator[](int index);
	void Clear();
	int GetSize();
};

template<class T>
List<T>::List()
{
	head == nullptr;
	size = 0;
}

template<class T>
List<T>::~List()
{
	Clear();
}

template<class T>
void List<T>::Append(T& obj)
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

template<class T>
T& List<T>::operator[](int index)
{
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
	return *(temp->val);
}

template<class T>
void List<T>::Clear()
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

template<class T>
int List<T>::GetSize()
{
	return size;
}

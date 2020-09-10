#pragma once

#include "Node.h"
#include "Ilist.h"


template <class T>
class LinkedList : public IList<T>
{
private:	
	Node<T>* _head;	
	Node<T>* _tail;
	int _currentSize;
	
public:
	LinkedList();

	~LinkedList();

	LinkedList(const LinkedList<T>& other);

	LinkedList(const LinkedList<T>&& other) noexcept;

	void PushFront(T data) override;

	void PushBack(T data) override;

	void PopFront() override;

	void PopBack() override;

	void Insert(size_t i) override;

	void Remove(size_t i) override;

	void Print() override;

	void Clear() override;
};

template <class T>
LinkedList<T>::LinkedList() : IList<T>()
{
	_head = nullptr;
	_tail = nullptr;
	_currentSize = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	LinkedList<T>::Clear();
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	Node<T>* cur = other._head;
	for (size_t i = 0; i < other._currentSize; i++)
	{
		LinkedList<T>::PushBack(other._head->GetData());
	}
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>&& other) noexcept
{
	this->_currentSize = other._currentSize;
	this->_head = other._head;
	this->_tail = other._tail;
}

template <class T>
void LinkedList<T>::PushFront(T data)
{
	if (_currentSize == 0)
	{
		_head = new Node<T>(data);
		_tail = _head;
	}
	else
	{
		Node<T>* newHead = new Node<T>(data, nullptr, _head);
		_head->SetPrev(newHead);
		_head = newHead;
	}
	_currentSize++;
}

template <class T>
void LinkedList<T>::PushBack(T data)
{
	if (_currentSize == 0)
	{
		_tail = new Node<T>(data);
		_head = _tail;
	}
	else
	{
		auto* newTail = new Node<T>(data, _tail);
		_tail->SetNext(newTail);
		_tail = newTail;
	}
	_currentSize++;
}

template <class T>
void LinkedList<T>::PopFront()
{
	if (_currentSize == 0) return;
	if (_currentSize == 1)
	{
		delete _head;
		_head = nullptr;
		_tail = nullptr;
	}
	else
	{
		Node<T>* newHead = _head->GetNext();
		delete _head;
		newHead->SetPrev(nullptr);
		_head = newHead;
	}
	_currentSize--;
}

template <class T>
void LinkedList<T>::PopBack()
{
	if (_currentSize == 0) return;
	if (_currentSize == 1)
	{
		delete _tail;
		_head = nullptr;
		_tail = nullptr;
	}
	else
	{
		Node<T>* newTail = _tail->GetPrev();
		delete _tail;
		newTail->SetNext(nullptr);
		_tail = newTail;
	}
	_currentSize--;
}

template <class T>
void LinkedList<T>::Insert(size_t i)
{
	
}

template <class T>
void LinkedList<T>::Remove(size_t i)
{
	
}

template <class T>
void LinkedList<T>::Print()
{
	Node<T>* cur = _head;
	for (size_t i = 0; i < _currentSize; i++)
	{
		std::cout << cur->GetData();
		cur = cur->GetNext();
	}
}

template <class T>
void LinkedList<T>::Clear()
{
	while (_currentSize)
	{
		PopFront();
	}
}

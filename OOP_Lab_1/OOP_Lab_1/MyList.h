#pragma once

#include "Node.h"

template <class T>
class MyList
{
private:	
	Node<T>* _head;	
	Node<T>* _tail;
	size_t _size;	
public:
	MyList();

	void PushFront(T data);

	void PushBack(T data);

	void PopFront();

	void PopBack();
};

template <class T>
inline MyList<T>::MyList()
{
	_head = nullptr;
	_tail = nullptr;
	_size = 0;
}

template <class T>
inline void MyList<T>::PushFront(T data)
{
	if (_size == 0)
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
	_size++;
}

template <class T>
inline void MyList<T>::PushBack(T data)
{
	if (_size == 0)
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
	_size++;
}

template<class T>
inline void MyList<T>::PopFront()
{
	if (_size == 0) return;
	if (_size == 1)
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
	_size--;
}

template <class T>
inline void MyList<T>::PopBack()
{
	if (_size == 0) return;
	if (_size == 1)
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
	_size--;
}

#pragma once

#include <functional>
#include <vector>

#include "Node.h"
#include "IList.h"


template <class T>
class LinkedList final : public IList<T>
{
private:
	Node<T>* _head;	
	Node<T>* _tail;
	size_t _currentSize;
	
public:
	LinkedList();

	~LinkedList();

	LinkedList(const LinkedList<T>& other);

	LinkedList(const LinkedList<T>&& other) noexcept;

	explicit LinkedList(std::vector<T> v);
	
	void FillByVector(std::vector<T> v);

	size_t GetSize() const;

	Node<T>* GetHead() const;

	Node<T>* GetTail() const;

	void MoveHead(bool isToLeft = true);

	void MoveTail(bool isToRight = true);

	void Print(std::function<void(T)> print) const override;

	void PushFront(T data) override;

	void PushBack(T data) override;

	void PopFront() override;

	void PopBack() override;

	void Insert(T data, size_t i) override;

	void Remove(size_t i) override;

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
LinkedList<T>::LinkedList(std::vector<T> v)
{
	_head = nullptr;
	_tail = nullptr;
	_currentSize = 0;
	for (auto val : v)
	{
		PushBack(val);
	}
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
size_t LinkedList<T>::GetSize() const
{
	return _currentSize;
}

template <class T>
Node<T>* LinkedList<T>::GetHead() const
{
	return _head;
}

template <class T>
Node<T>* LinkedList<T>::GetTail() const
{
	return _tail;
}

template <class T>
void LinkedList<T>::MoveHead(const bool isToLeft)
{
	if (isToLeft)
	{
		if (_head->GetPrev())
			_head = _head->GetPrev();
	}
	else
	{
		if (_head->GetNext())
			_head = _head->GetNext();
	}
}

template <class T>
void LinkedList<T>::MoveTail(const bool isToRight)
{
	if (isToRight)
	{
		if (_tail->GetNext())
			_tail = _tail->GetNext();
	}
	else
	{
		if (_tail->GetPrev())
			_tail = _tail->GetPrev();
	}
}

template <class T>
void LinkedList<T>::FillByVector(std::vector<T> v)
{
	Clear();
	for (auto val : v)
	{
		PushBack(val);
	}
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
void LinkedList<T>::Insert(const T data, const size_t i)
{
	const auto halfSize = _currentSize / 2;
	if (i > _currentSize || i == 0)
		return;
	if (i == 1)
	{
		PushFront(data);
		return;
	}
	if (i == _currentSize)
	{
		PushBack(data);
		return;
	}
	if (i < halfSize)
	{
		Node<T>* cur = _head;
		for (size_t j = 0; j < i - 2; j++)
		{
			cur = cur->GetNext();
		}
		auto newNode = new Node<T>(data, cur, cur->GetNext());
		cur->GetNext()->SetPrev(newNode);
		cur->SetNext(newNode);
	}
	else
	{
		Node<T>* cur = _tail;
		for (auto j = _currentSize - 1; j > i; j--)
		{
			cur = cur->GetPrev();
		}
		auto newNode = new Node<T>(data, cur->GetPrev(), cur);
		cur->GetPrev()->SetNext(newNode);
		cur->SetPrev(newNode);
	}
	_currentSize++;
}

template <class T>
void LinkedList<T>::Remove(const size_t i)
{
	const auto halfSize = _currentSize / 2;
	if (i > _currentSize)
		return;
	if (i == 1)
	{
		PopFront();
		return;
	}
	if (i == _currentSize)
	{
		PopBack();
		return;
	}
	if (i < halfSize)
	{
		Node<T>* cur = _head;
		for (size_t j = 0; j < i - 2; j++)
		{
			cur = cur->GetNext();
		}
		Node<T>* oldNode = cur->GetNext();
		cur->GetNext()->GetNext()->SetPrev(cur);
		cur->SetNext(cur->GetNext()->GetNext());
		delete oldNode;
	}
	else
	{
		Node<T>* cur = _tail;
		for (auto j = _currentSize - 1; j > i; j--)
		{
			cur = cur->GetPrev();
		}
		Node<T>* oldNode = cur->GetPrev();
		cur->GetPrev()->GetPrev()->SetNext(cur);
		cur->SetPrev(cur->GetPrev()->GetPrev());
		delete oldNode;
	}
	_currentSize--;
}

template <class T>
void LinkedList<T>::Print(std::function<void(T)> print) const
{
	Node<T>* cur = _head;
	while (cur)
	{
		print(cur->GetData());
		cur = cur->GetNext();
	}
	std::cout << std::endl;
}

template <class T>
void LinkedList<T>::Clear()
{
	while (_currentSize)
	{
		PopFront();
	}
}

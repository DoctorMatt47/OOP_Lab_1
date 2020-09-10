#pragma once
#include "Node.h"

template <class T>
class IList
{
public:
	virtual ~IList() = 0;
	
	virtual void PushFront(T data) = 0;

	virtual void PushBack(T data) = 0;

	virtual void PopFront() = 0;

	virtual void PopBack() = 0;

	virtual void Insert(size_t i) = 0;

	virtual void Remove(size_t i) = 0;

	virtual void Print() = 0;

	virtual void Clear() = 0;
};


#pragma once

template <class T>
class IList
{
public:
	virtual ~IList() = default;
	
	virtual void PushFront(T data) = 0;

	virtual void PushBack(T data) = 0;

	virtual void PopFront() = 0;

	virtual void PopBack() = 0;

	virtual void Insert(T data, size_t i) = 0;

	virtual void Remove(size_t i) = 0;

	virtual void Print(std::function<void(T)> print) const = 0;

	virtual void Clear() = 0;
};


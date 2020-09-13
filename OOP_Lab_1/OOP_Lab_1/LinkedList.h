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
	
	Node<T>* Partition(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparePredicate);

	void QuickSortRecursive(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparePredicate);

	Node<T>* Split(Node<T>* head);

	Node<T>* Merge(Node<T>* first, Node<T>* second, std::function<bool(T, T)> comparePredicate);

	Node<T>* MergeSortRecursive(Node<T>* first, std::function<bool(T, T)> comparePredicate);
	
public:
	LinkedList();

	~LinkedList();

	LinkedList(const LinkedList<T>& other);

	LinkedList(const LinkedList<T>&& other) noexcept;

	explicit LinkedList(std::vector<T> v);

	size_t GetSize() const;

	Node<T>* GetFirstNode() const;

	Node<T>* GetLastNode() const;

	T GetFirst() const;

	T GetLast() const;

	T GetByIndex(size_t i) const;

	void Print(std::function<void(T)> print) const override;

	void ChangeFirst(T data);

	void ChangeLast(T data);

	void ChangeByIndex(T data, size_t i);

	void FillByVector(std::vector<T> v);

	void PushFront(T data) override;

	void PushBack(T data) override;

	void PopFront() override;

	void PopBack() override;

	void Insert(T data, size_t i) override;

	void Remove(size_t i) override;

	void Clear() override;

	void QuickSort(std::function<bool(T, T)> comparePredicate);

	void InsertionSort(std::function<bool(T, T)> comparePredicate);

	void MergeSort(std::function<bool(T, T)> comparePredicate);

	void CountingSort(std::function<size_t(T)> sortField);
	
};

template <class T>
Node<T>* LinkedList<T>::Partition(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparePredicate)
{
	// set pivot as h element  
	auto x = h->GetData();

	// similar to i = l-1 for array implementation  
	Node<T>* i = l->GetPrev();

	// Similar to "for (int j = l; j <= h- 1; j++)"  
	for (Node<T>* j = l; j != h; j = j->GetNext())
	{
		if (comparePredicate(x, j->GetData()))
		{
			// Similar to i++ for array  
			i = (i == nullptr) ? l : i->GetNext();

			if (i != j)
			{
				T temp = i->GetData();
				i->SetData(j->GetData());
				j->SetData(temp);
			}
		}
	}
	i = (i == nullptr) ? l : i->GetNext(); // Similar to i++  
	if (i != h)
	{
		T temp = i->GetData();
		i->SetData(h->GetData());
		h->SetData(temp);
	}
	return i;
}

template <class T>
void LinkedList<T>::QuickSortRecursive(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparePredicate)
{
	if (h != nullptr && l != h && l != h->GetNext())
	{
		Node<T>* p = Partition(l, h, comparePredicate);
		QuickSortRecursive(l, p->GetPrev(), comparePredicate);
		QuickSortRecursive(p->GetNext(), h, comparePredicate);
	}
}

template <class T>
Node<T>* LinkedList<T>::Split(Node<T>* head)
{
	{
		Node<T>* fast = head;
		Node<T>* slow = head;
		while (fast->GetNext() && fast->GetNext()->GetNext())
		{
			fast = fast->GetNext()->GetNext();
			slow = slow->GetNext();
		}
		Node<T>* temp = slow->GetNext();
		slow->SetNext(nullptr);
		return temp;
	}
}

template <class T>
Node<T>* LinkedList<T>::Merge(Node<T>* first, Node<T>* second, std::function<bool(T, T)> comparePredicate)
{
	// If first linked list is empty  
	if (!first)
		return second;

	// If second linked list is empty  
	if (!second)
		return first;

	// Pick the smaller value  
	if (comparePredicate(second->GetData(), first->GetData()))
	{
		first->SetNext(Merge(first->GetNext(), second, comparePredicate));
		first->GetNext()->SetPrev(first);
		first->SetPrev(nullptr);
		return first;
	}
	else
	{
		second->SetNext(Merge(first, second->GetNext(), comparePredicate));
		second->GetNext()->SetPrev(second);
		second->SetPrev(nullptr);
		return second;
	}
}

template <class T>
Node<T>* LinkedList<T>::MergeSortRecursive(Node<T>* first, std::function<bool(T, T)> comparePredicate)
{
	if (!first || !first->GetNext())
		return first;
	Node<T>* second = Split(first);

	// Recur for left and right halves  
	first = MergeSortRecursive(first, comparePredicate);
	second = MergeSortRecursive(second, comparePredicate);

	// Merge the two sorted halves  
	return Merge(first, second, comparePredicate);
}

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
Node<T>* LinkedList<T>::GetFirstNode() const
{
	return _head;
}

template <class T>
Node<T>* LinkedList<T>::GetLastNode() const
{
	return _tail;
}

template <class T>
T LinkedList<T>::GetFirst() const
{
	return _head->GetData();
}

template <class T>
T LinkedList<T>::GetLast() const 
{
	return _tail->GetData();
}

template <class T>
T LinkedList<T>::GetByIndex(const size_t i) const
{
	Node<T>* cur = _head;
	for (auto j = 0; j < i; j++)
	{
		cur = cur->GetNext();
	}
	return cur->GetData();
}

template <class T>
void LinkedList<T>::ChangeFirst(T data)
{
	_head->SetData(data);
}

template <class T>
void LinkedList<T>::ChangeLast(T data)
{
	_tail->SetData(data);
}

template <class T>
void LinkedList<T>::ChangeByIndex(T data, size_t i)
{
	Node<T>* cur = _head;
	for (auto j = 0; j < i; j++)
	{
		cur = cur->GetNext();
	}
	cur->SetData(data);
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

template <class T>
void LinkedList<T>::QuickSort(std::function<bool(T, T)> comparePredicate)
{
	if (_currentSize > 1)
		QuickSortRecursive(_head, _tail, comparePredicate);
}

template <class T>
void LinkedList<T>::InsertionSort(std::function<bool(T, T)> comparePredicate)
{
	if (_currentSize <= 1) return;

	for (Node<T>* i = _head->GetNext(); i != nullptr; i = i->GetNext())
	{
		T key = i->GetData();
		Node<T>* j = i->GetPrev();

		while (j && comparePredicate(j->GetData(), key))
		{
			j->GetNext()->SetData(j->GetData());
			j = j->GetPrev();
		}
		
		if (j)
			j->GetNext()->SetData(key);
		else 
			_head->SetData(key);
	}
}

template <class T>
void LinkedList<T>::MergeSort(std::function<bool(T, T)> comparePredicate)
{
	if (_currentSize <= 1) return;
	_head = MergeSortRecursive(_head, comparePredicate);
}

template <class T>
void LinkedList<T>::CountingSort(std::function<size_t(T)> sortField)
{
	std::vector<size_t> buckets;
	for (Node<T>* i = _head; i != nullptr; i = i->GetNext())
	{
		const int field = sortField(i->GetData());

		//Increase the bucket size, if necessary
		for (int j = buckets.size(); j <= field; j++)
			buckets.push_back(0);

		++buckets[field];
	}
	const auto size = buckets.size();
	std::vector<size_t> startIndex(buckets.size());
	for (size_t j = 1; j < buckets.size(); j++)
	{
		startIndex[j] = buckets[j - 1] + startIndex[j - 1];
	}

	std::vector<T> result(_currentSize);
	for (Node<T>* i = _head; i != nullptr; i = i->GetNext())
	{
		const int field = sortField(i->GetData());
		auto destIndex = startIndex[field]++;
		result[destIndex] = i->GetData();
	}

	FillByVector(result);
}

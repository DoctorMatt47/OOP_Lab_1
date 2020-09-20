#pragma once

#include <functional>
#include <vector>

#include "Node.h"
#include "IList.h"


/**
 * \brief Doubly-linked list
 *
 * LinkedList is a container that supports constant time insertion and removal of elements from anywhere in the container.
 * It is implemented as a doubly-linked list. This container provides bidirectional iteration capability.
 * Cannot be inherited.
 * 
 * \tparam T The type of the elements.
 */
template <class T>
class LinkedList final : public IList<T>
{
private:
	Node<T>* _head = nullptr;	
	Node<T>* _tail = nullptr;
	size_t _currentSize = 0;
	
public:
	/**
	 * Default constructor. Constructs an empty container. 
	 */
	LinkedList();

	/**
	* Constructs and fills the container with data from the vector.
	* \param v Vector with data to be placed in the container.
	*/
	explicit LinkedList(std::vector<T> v);

	/**
	 * Copy constructor. Constructs the container with the copy of the contents of other .
	 * \param other Another container to be used as source to initialize the elements of the container with.
	 */
	LinkedList(const LinkedList<T>& other);

	/**
	 * Move constructor. Constructs the container with the contents of other using move semantics.
	 * \param other Another container to be used as source to initialize the elements of the container with.
	 */
	LinkedList(const LinkedList<T>&& other) noexcept;

	/**
	* Destructs the list.
	*/
	~LinkedList();

	/**
	 *	Copies all the elements from other into the container.
	 * \param other Object of the same type.
	 */
	LinkedList<T>& operator=(const LinkedList<T>& other);

	/**
	 * Moves all the elements of other into the container.
	 * \param other Object of the same type.
	 */
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept;
	
	/**
	 * Removes all elements and fills the container with data from the vector.
	 * \param v Vector with data to be placed in the container. 
	 */
	void FillByVector(std::vector<T> v);

	/**
	* Returns the number of elements in the container.
	* \return The number of elements in the container.
	*/
	size_t GetSize() const;

	/**
	 * Returns the first element.
	 * \return Reference to the first element.
	 */
	Node<T>* GetHead() const;

	/**
	 * Returns the last element .
	 * \return Reference to the last element.
	 */
	Node<T>* GetTail() const;

	/**
	 * Moves head pointer to the side
	 * \param isToLeft Side, where pointer will be moved.
	 * If is true, it will move to the left side, if false - to the right. True by default.
	 * \warning This method does not increase size of the container!
	 */
	void MoveHead(bool isToLeft = true);

	/**
	 * Moves Tail pointer to the side
	 * \param isToRight Side, where pointer will be moved.
	 * If is true, it will move to the right side, if false - to the left. True by default.
	 * \warning This method does not increase size of the container!
	 */
	void MoveTail(bool isToRight = true);

	/**
	* Adds the element to the beginning of the container.
	* \param data The element value to add.
	*/
	void PushFront(T data);

	T Get(size_t i) override;
	
	void PopFront();

	void PushBack(T data) override;

	void PopBack() override;

	void Insert(T data, size_t i) override;

	void Remove(size_t i) override;

	void Print(std::function<void(const T&)> printer) const override;

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
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	if (&other != this)
	{
		Clear();
		Node<T>* cur = other._head;
		while (cur)
		{
			LinkedList<T>::PushBack(cur->GetData());
			cur = cur->GetNext();
		}
	}
	return *this;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other) noexcept
{
	this->_currentSize = other._currentSize;
	this->_head = other._head;
	this->_tail = other._tail;
	other._head = nullptr;
	other._tail = nullptr;
	return *this;
}

template <class T>
LinkedList<T>::LinkedList(std::vector<T> v)
{
	for (auto val : v)
	{
		LinkedList<T>::PushBack(val);
	}
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	Node<T>* cur = other._head;
	while (cur)
	{
		LinkedList<T>::PushBack(cur->GetData());
		cur = cur->GetNext();
	}
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>&& other) noexcept
{
	this->_currentSize = other._currentSize;
	this->_head = other._head;
	this->_tail = other._tail;
	other._head = nullptr;
	other._tail = nullptr;
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
T LinkedList<T>::Get(const size_t i)
{
	Node<T>* cur = _head;
	for (auto j = 0; j < i; j++)
	{
		cur = cur->GetNext();
	}
	return cur->GetData();
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
void LinkedList<T>::Print(std::function<void(const T&)> printer) const
{
	Node<T>* cur = _head;
	while (cur)
	{
		printer(cur->GetData());
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

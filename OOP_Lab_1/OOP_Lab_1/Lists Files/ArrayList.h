#pragma once

#include <functional>
#include <vector>

#include "IList.h"
#include "IArray.h"

/**
 * \brief List based on array.
 *
 * Container with data, which is representing array that can change in size.
 * ArrayList is very efficient accessing its elements and relatively efficient adding or removing elements from its end.
 * This array may need to be reallocated in order to grow in size when new elements are inserted,
 * which implies allocating a new array and moving all elements to it.
 * \tparam T Type of the elements.
 */
template <class T>
class ArrayList final : public IList<T>, public IArray<T>
{
private:
	/// Size of the array.
	size_t _capacity;

	/// Number of elements in the array.
	size_t _size;

	/// Pointer to the array.
	T* _pData;

	/**
	 * Creates new array with larger capacity and copies data from the old array.
	 */
	void ExpandArray();
	
public:
	/**
	* Default constructor. Constructs an empty container.
	*/
	ArrayList();

	/**
	* Destructs the container.
	*/
	~ArrayList();

	/**
	* Copy constructor. Constructs the container with the copy of the contents of other .
	* \param other Another container to be used as source to initialize the elements of the container with.
	*/
	ArrayList(const ArrayList<T>& other);

	/**
	* Move constructor. Constructs the container with the contents of other using move semantics.
	* \param other Another container to be used as source to initialize the elements of the container with.
	*/
	ArrayList(ArrayList<T>&& other) noexcept;

	/**
	* Copies all the elements from other into the container.
	* \param other Object of the same type.
	*/
	ArrayList<T>& operator =(const ArrayList<T>& other);

	/**
	* Moves all the elements of other into the container.
	* \param other Object of the same type.
	*/
	ArrayList<T>& operator =(ArrayList<T>&& other) noexcept;

	/**
	* Constructs and fills the container with data from the vector.
	 * \param other Vector with data to be placed in the container.
	 */
	explicit ArrayList(const std::vector<T>& other);

	/**
	 * Returns the size of the storage space currently allocated for the container. 
	 * \return The size of the currently allocated storage capacity in the container.
	 */
	size_t GetCapacity() const;

	size_t GetSize() const override;

	T& operator [](size_t index) override;

	T Get(size_t i) override;

	void PushBack(T data) override;

	void PopBack() override;

	void Insert(T data, size_t i) override;

	void Remove(size_t i) override;

	void Clear() override;

	void Print(std::function<void(const T&)> printer) const override;
};

template <class T>
void ArrayList<T>::ExpandArray()
{
	_capacity *= 2;
	T* newData = new T[_capacity];
	for (auto i = 0; i < _size; i++)
	{
		newData[i] = _pData[i];
	}
	delete[] _pData;
	_pData = newData;
}

template <class T>
ArrayList<T>::ArrayList()
{
	_capacity = 2;
	_size = 0;
	_pData = new T[_capacity];
}

template <class T>
ArrayList<T>::~ArrayList()
{
	delete[] _pData;
	_pData = nullptr;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& other)
{
	_capacity = other._capacity;
	_size = other._size;
	_pData = new T[_capacity];
	for (size_t i = 0; i < _size; i++)
	{
		_pData[i] = other._pData[i];
	}
}

template <class T>
ArrayList<T>::ArrayList(ArrayList<T>&& other) noexcept
{
	_capacity = other._capacity;
	_size = other._size;
	_pData = other._pData;
	other._pData = nullptr;
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other)
{
	if (this != &other)
	{
		Clear();
		_capacity = other._capacity;
		_size = other._size;
		_pData = new T[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			_pData[i] = other._pData[i];
		}
	}
	return *this;
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList<T>&& other) noexcept
{
	_capacity = other._capacity;
	_size = other._size;
	_pData = other._pData;
	other._pData = nullptr;
	return *this;
}

template <class T>
ArrayList<T>::ArrayList(const std::vector<T>& other)
{
	_size = other.size();
	_capacity = _size;
	_pData = new T[_capacity];
	for (size_t i = 0; i < _size; i++)
	{
		_pData[i] = other[i];
	}
}

template <class T>
size_t ArrayList<T>::GetCapacity() const
{
	return _capacity;
}

template <class T>
T& ArrayList<T>::operator[](size_t index)
{
	if (index < 0 || index > _size) 
		throw std::exception("Invalid index");
	return _pData[index];
}

template <class T>
T ArrayList<T>::Get(size_t i)
{
	return _pData[i];
}

template <class T>
void ArrayList<T>::PushBack(T data)
{
	if (_size >= _capacity)
		ExpandArray();
	_pData[_size] = data;
	_size++;
}

template <class T>
void ArrayList<T>::PopBack()
{
	// Checking size of the list.
	if (_size == 0)
		return;
	
	// Removing last element
	_pData[_size] = T();
	_size--;
}

template <class T>
void ArrayList<T>::Insert(T data, size_t i)
{
	// Allocating new memory, if necessary.
	if (_size >= _capacity)
		ExpandArray();

	// Checking for the correct index.
	if (i < 0 || i >= _size)
		return;
	
	// Shifting elements to right.
	for (auto j = _size - 1; j >= i; j--)
	{
		_pData[j + 1] = _pData[j];
	}
	
	_pData[i] = data;
	_size++;
}

template <class T>
void ArrayList<T>::Remove(size_t i)
{
	// Checking for the correct index
	if (i < 0 || i >= _size)		
		return;
	
	// Shifting elements to left.
	for (auto j = i + 1; j < _size; j++)
	{
		_pData[j - 1] = _pData[j];
	}
	
	// Removing last element
	_pData[_size - 1] = T();
	_size--;
}

template <class T>
void ArrayList<T>::Clear()
{
	if (_size != 0 && _capacity != 2)
	{
		_size = 0;
		_capacity = 2;
		delete[] _pData;
		T* newData = new T[_capacity];
		_pData = newData;
	}
}

template <class T>
size_t ArrayList<T>::GetSize() const
{
	return _size;
}

template <class T>
void ArrayList<T>::Print(std::function<void(const T&)> printer) const
{
	for (auto i = 0; i < _size; i++)
	{
		printer(_pData[i]);
	}
}

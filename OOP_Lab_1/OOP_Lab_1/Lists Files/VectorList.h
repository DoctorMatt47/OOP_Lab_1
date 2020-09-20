#pragma once

#include <functional>
#include <vector>

#include "IList.h"
#include "IArray.h"

/**
 * \brief List based on vector.
 *
 * Represents generic list of objects that can be accessed by index.
 * VectorList is very efficient accessing its elements and relatively efficient adding or removing elements from its end.
 * It is implemented based on a vector.
 * \tparam T Type of the elements.
 */
template <class T>
class VectorList final : public IList<T>, public IArray<T>
{
private:
	std::vector<T> _pData;
	
public:
	/**
* Default constructor. Constructs an empty container.
*/
	VectorList() = default;

	/**
	* Destructs the container.
	*/
	~VectorList();

	/**
	* Copy constructor. Constructs the container with the copy of the contents of other .
	* \param other Another container to be used as source to initialize the elements of the container with.
	*/
	VectorList(const VectorList<T>& other);

	/**
	* Move constructor. Constructs the container with the contents of other using move semantics.
	* \param other Another container to be used as source to initialize the elements of the container with.
	*/
	VectorList(VectorList<T>&& other) noexcept;

	/**
	* Copies all the elements from other into the container.
	* \param other Object of the same type.
	*/
	VectorList<T>& operator =(const VectorList<T>& other);

	/**
	* Moves all the elements of other into the container.
	* \param other Object of the same type.
	*/
	VectorList<T>& operator =(VectorList<T>&& other) noexcept;

	/**
	* Constructs and fills the container with data from the vector.
	 * \param other Vector with data to be placed in the container.
	 */
	explicit VectorList(const std::vector<T>& other);

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
VectorList<T>::~VectorList()
{
	_pData.clear();
}

template <class T>
VectorList<T>::VectorList(const VectorList<T>& other)
{
	this->_pData = other._pData;
}

template <class T>
VectorList<T>::VectorList(VectorList<T>&& other) noexcept
{
	this->_pData = other._pData;
}

template <class T>
VectorList<T>& VectorList<T>::operator=(const VectorList<T>& other)
{
	if (&other != this)
		this->_pData = other._pData;
	return *this;
}

template <class T>
VectorList<T>& VectorList<T>::operator=(VectorList<T>&& other) noexcept
{
	this->_pData = other._pData;
	return *this;
}

template <class T>
VectorList<T>::VectorList(const std::vector<T>& other)
{
	_pData = other;
}

template <class T>
size_t VectorList<T>::GetCapacity() const
{
	return _pData.capacity();
}

template <class T>
size_t VectorList<T>::GetSize() const
{
	return _pData.size();
}

template <class T>
T& VectorList<T>::operator[](size_t index)
{
	return _pData[index];
}

template <class T>
T VectorList<T>::Get(size_t i)
{
	return _pData[i];
}

template <class T>
void VectorList<T>::PushBack(T data)
{
	_pData.push_back(data);
}

template <class T>
void VectorList<T>::PopBack()
{
	_pData.pop_back();
}

template <class T>
void VectorList<T>::Insert(T data, size_t i)
{
	_pData.insert(_pData.begin() + i, data);
}

template <class T>
void VectorList<T>::Remove(size_t i)
{
	_pData.erase(_pData.begin() + i);
}

template <class T>
void VectorList<T>::Clear()
{
	_pData.clear();
}

template <class T>
void VectorList<T>::Print(std::function<void(const T&)> printer) const
{
	for (auto& value : _pData)
		printer(value);
}


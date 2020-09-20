#pragma once

/**
 * \brief Represents a collection of objects
 *
 * The IArray<T> is the base interface of all generic array-based collections.
 * \tparam T Type of elements inside collection.
 */
template <class T>
class IArray
{
public:
	/**
	* Destructs the list.
	*/
	virtual ~IArray() = default;

	/**
	* Returns the number of elements in the container.
	* \return The number of elements in the container.
	*/
	virtual size_t GetSize() const = 0;
	
	/**
	 * Returns a reference to the element at position i in the container.
	 * \param i Position of an element in the container.
	 * \return The element at the specified position in the container.
	 */
	virtual T& operator [](size_t i) = 0;
};


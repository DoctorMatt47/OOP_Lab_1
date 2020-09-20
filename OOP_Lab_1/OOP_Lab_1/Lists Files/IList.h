#pragma once

/**
 * \brief Represents a collection of objects
 *
 * The IList<T> is the base interface of all resizable generic collections.
 * \tparam T Type of elements inside collection.
 */
template <class T>
class IList
{
public:
	/**
	* Destructs the list.
	*/
	virtual ~IList() = default;

	/**
	 * Returns an element at position i in the container.
	 * \param i Position of an element in the container.
	 * \return The element at the specified position in the container.
	 */
	virtual T Get(size_t i) = 0;

	/**
	* Adds the element to the end of the container.
	* \param data The element value to add.
	*/
	virtual void PushBack(T data) = 0;

	/**
	* Removes the last element of the container.
	*/
	virtual void PopBack() = 0;

	/**
	* Inserts the element at the specified location in the container.
	* \param data The element value to insert.
	* \param i Position of the element.
	*/
	virtual void Insert(T data, size_t i) = 0;

	/**
	* Removes the element from the container.
	* \param i Position of the element.
	*/
	virtual void Remove(size_t i) = 0;
	
	/**
	* Erases all elements from the container.
	*/
	virtual void Clear() = 0;
	
	/**
	* Prints the container to somewhere using passed function.
	* \param printer Function which get element and output it to somewhere.
	*/
	virtual void Print(std::function<void(const T&)> printer) const = 0;
};


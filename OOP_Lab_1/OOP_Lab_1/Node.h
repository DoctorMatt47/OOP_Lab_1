#pragma once

/**
 * \brief Represents a node in a LinkedList<T>.
 *
 * This class using for iterating throw the doubly linked list.
 * Store data and pointers to the adjacent elements of the list.
 * Provides bidirectional iteration capability.
 * Cannot be inherited.
 * 
 * \tparam T Type of data that stored in the node. 
 */
template <class T>
class Node final
{
private:
	T _data;
	Node<T>* _pNext;
	Node<T>* _pPrev;
public:
	
	/**
	 * Initializes a new instance of the node class.
	 * \param data The value to contain in the node.
	 * \param pPrev Pointer to the previous node in the list. Null by default.
	 * \param pNext Pointer to the next node in the list. Null by default.
	 */
	explicit Node(T data, Node<T>* pPrev = nullptr, Node<T>* pNext = nullptr);
	
	/**
	 * Gets the value that is stored in the node.
	 * \return Data from node.
	 */
	T GetData();

	/**
	 * Sets or change the value that is stored in the node. 
	 * \param data Data that will be stored in the node.
	 */
	void SetData(T data);

	/**
	 * Gets pointer to the next node in the list.
	 * \return Pointer to the node.
	 */
	Node* GetNext();

	/**
	 * Sets or change pointer to the next node in the list.
	 * \param pNext Pointer to the node.
	 */
	void SetNext(Node<T>* pNext);

	/**
	 * Gets pointer to the previous node in the list.
	 * \return Pointer to the node.
	 */
	Node* GetPrev();

	/**
	 * Sets or change pointer to the next node in the list.
	 * \param pPrev Pointer to the node.
	 */
	void SetPrev(Node<T>* pPrev);
};

template <class T>
Node<T>::Node(T data, Node* pPrev, Node* pNext)
{
	_data = data;
	_pPrev = pPrev;
	_pNext = pNext;
}

template <class T>
T Node<T>::GetData()
{
	return _data;
}

template <class T>
void Node<T>::SetData(T data)
{
	_data = data;
}

template <class T>
Node<T>* Node<T>::GetNext()
{
	return _pNext;
}

template <class T>
void Node<T>::SetNext(Node<T>* pNext)
{
	_pNext = pNext;
}

template <class T>
Node<T>* Node<T>::GetPrev()
{
	return _pPrev;
}

template <class T>
void Node<T>::SetPrev(Node<T>* pPrev)
{
	_pPrev = pPrev;
}

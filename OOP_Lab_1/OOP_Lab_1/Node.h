#pragma once

template <class T>
class Node
{
private:
	T _data;
	Node<T>* _pNext;
	Node<T>* _pPrev;
public:
	
	explicit Node(T data, Node* pPrev = nullptr, Node* pNext = nullptr);
	
	T GetData();
	
	void SetData(T data);

	Node* GetNext();

	void SetNext(Node<T>* pNext);

	Node* GetPrev();

	void SetPrev(Node<T>* pPrev);
};

template <class T>
inline Node<T>::Node(T data, Node* pPrev, Node* pNext)
{
	_data = data;
	_pPrev = pPrev;
	_pNext = pNext;
}

template <class T>
inline T Node<T>::GetData()
{
	return _data;
}

template <class T>
inline void Node<T>::SetData(T data)
{
	_data = data;
}

template <class T>
inline Node<T>* Node<T>::GetNext()
{
	return _pNext;
}

template <class T>
inline void Node<T>::SetNext(Node<T>* pNext)
{
	_pNext = pNext;
}

template <class T>
inline Node<T>* Node<T>::GetPrev()
{
	return _pPrev;
}

template <class T>
inline void Node<T>::SetPrev(Node<T>* pPrev)
{
	_pPrev = pPrev;
}

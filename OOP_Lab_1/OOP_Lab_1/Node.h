#pragma once

template <class T>
class Node
{
private:
	T _data;
	Node<T>* _pNext;
	Node<T>* _pPrev;
public:
	
	explicit Node(T data, Node<T>* pPrev = nullptr, Node<T>* pNext = nullptr);
	
	T GetData();
	
	void SetData(T data);

	Node* GetNext();

	void SetNext(Node<T>* pNext);

	Node* GetPrev();

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

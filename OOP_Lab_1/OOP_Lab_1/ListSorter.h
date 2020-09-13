#pragma once

#include "LinkedList.h"

template <class T>
class ListSorter
{
private:
	static Node<T>* Partition(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparePredicate);

	static void QuickSortRecursive(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparePredicate);

	static Node<T>* Split(Node<T>* head);

	static Node<T>* Merge(Node<T>* first, Node<T>* second, std::function<bool(T, T)> comparePredicate);

	static Node<T>* MergeSortRecursive(Node<T>* first, std::function<bool(T, T)> comparePredicate);
	
public:
	
	static void QuickSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate);

	static void InsertionSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate);

	static void MergeSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate);

	static void CountingSort(LinkedList<T>& list, std::function<size_t(T)> sortField);
};

template <class T>
Node<T>* ListSorter<T>::Partition(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparePredicate)
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
void ListSorter<T>::QuickSortRecursive(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparePredicate)
{
	if (h != nullptr && l != h && l != h->GetNext())
	{
		Node<T>* p = Partition(l, h, comparePredicate);
		QuickSortRecursive(l, p->GetPrev(), comparePredicate);
		QuickSortRecursive(p->GetNext(), h, comparePredicate);
	}
}

template <class T>
Node<T>* ListSorter<T>::Split(Node<T>* head)
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

template <class T>
Node<T>* ListSorter<T>::Merge(Node<T>* first, Node<T>* second, std::function<bool(T, T)> comparePredicate)
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
Node<T>* ListSorter<T>::MergeSortRecursive(Node<T>* first, std::function<bool(T, T)> comparePredicate)
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
void ListSorter<T>::QuickSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate)
{
	if (list.GetSize() > 1)
	{
		QuickSortRecursive(list.GetHead(), list.GetTail(), comparePredicate);
	}
}

template <class T>
void ListSorter<T>::InsertionSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate)
{
	if (list.GetSize() <= 1) return;

	for (Node<T>* i = list.GetHead()->GetNext(); i != nullptr; i = i->GetNext())
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
			list.GetHead()->SetData(key);
	}
}

template <class T>
void ListSorter<T>::MergeSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate)
{
	if (list.GetSize() <= 1) return;
	MergeSortRecursive(list.GetHead(), comparePredicate);
	while (list.GetHead()->GetPrev())
	{
		list.MoveHead();
	}
	while (list.GetTail()->GetNext())
	{
		list.MoveTail();
	}
}

template <class T>
void ListSorter<T>::CountingSort(LinkedList<T>& list, std::function<size_t(T)> sortField)
{
	std::vector<size_t> buckets;
	for (Node<T>* i = list.GetFirst(); i != nullptr; i = i->GetNext())
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

	std::vector<T> result(list.GetSize());
	for (Node<T>* i = list.GetFirst(); i != nullptr; i = i->GetNext())
	{
		const int field = sortField(i->GetData());
		auto destIndex = startIndex[field]++;
		result[destIndex] = i->GetData();
	}

	FillByVector(result);
}

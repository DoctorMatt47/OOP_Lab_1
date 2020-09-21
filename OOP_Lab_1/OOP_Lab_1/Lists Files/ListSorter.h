#pragma once

#include <algorithm>

#include "LinkedList.h"
#include "IArray.h"

/**
 * \brief Sort algorithms for lists.
 *
 * This class contains different methods which can be used to sort the list. It is has only static methods.
 * \tparam T Type of data that is sorted in the list.
 */
template <class T>
class ListSorter
{
private:
	/**
	 * Additional function for Quick sort algorithm. 
	 * \param list An array with data to be sorted.
	 * \param low Low limit of the partition.
	 * \param high High limit of the partition.
	 * \param comparePredicate Predicate used to compare elements the the array.
	 * \return Mid number.
	 */
	static int Partition(IArray<T>& list, int low, int high, std::function<bool(T, T)> comparePredicate);
	
	/**
	 * Additional function for Quick sort algorithm.  
	 * \param l Low limit of the partition.
	 * \param h High limit of the partition.
	 * \param comparePredicate Predicate used to compare elements the the array.
	 * \return
	 */
	static Node<T>* Partition(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparePredicate);

	/**
	 * Additional function for Quick sort algorithm. 
	 * \param list An array with data to be sorted.
	 * \param low Low limit
	 * \param high High limit
	 * \param comparePredicate Predicate used to compare elements the the array.
	 */
	static void QuickSortRecursive(IArray<T>& list, int low, int high, std::function<bool(T, T)> comparePredicate);

	/**
	 * Additional function for Quick sort algorithm. 
	 * \param l Low limit.
	 * \param h High limit.
	 * \param comparePredicate Predicate used to compare elements the the array. 
	 */
	static void QuickSortRecursive(Node<T>* l, Node<T>* h, std::function<bool(T, T)> comparePredicate);

	/**
	 * Additional function for Merge sort algorithm.  
	 * \param head First element of the list.
	 * \return Middle element.
	 */
	static Node<T>* Split(Node<T>* head);

	/**
	 * Additional function for Merge sort algorithm.  
	 * \param first First list to merge
	 * \param second Second list to merge.
	 * \param comparePredicate Predicate used to compare elements the the array.
	 * \return Middle element.
	 */
	static Node<T>* Merge(Node<T>* first, Node<T>* second, std::function<bool(T, T)> comparePredicate);

	/**
	 * Additional function for Merge sort algorithm. 
	 * \param list An array with data to be sorted.
	 * \param low Low element index.
	 * \param mid Mid element index.
	 * \param high High element index.
	 * \param comparePredicate Predicate used to compare elements the the array.
	 */
	static void Merge(IArray<T>& list, int low, int mid, int high, std::function<bool(T, T)> comparePredicate);

	/**
	 * Additional function for Merge sort algorithm.
	 * \param first First element to merge.
	 * \param comparePredicate Predicate used to compare elements the the array. 
	 * \return Middle element.
	 */
	static Node<T>* MergeSortRecursive(Node<T>* first, std::function<bool(T, T)> comparePredicate);

	/**
	 *  Additional function for Merge sort algorithm.
	 * \param list An array with data to be sorted.
	 * \param low Low element index.
	 * \param high High element index.
	 * \param comparePredicate Predicate used to compare elements the the array.
	 */
	static void MergeSortRecursive(IArray<T>& list, int low, int high, std::function<bool(T, T)> comparePredicate);
	
public:

	ListSorter() = delete;
	
	/**
	 * A function to sort an array using gnome sort algorithm.
	 * \param list An array with data to be sorted. That class must be inherited from IArray interface.
	 * \param comparePredicate Predicate used to compare elements the the array.
	 * Returns ​true if the first argument is greater than or equals to the second.
	 */
	static void GnomeSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate);
	
	/**
	 * A function to sort a linked list using gnome sort algorithm.
	 * \param list Linked list with data to be sorted.
	 * \param comparePredicate Predicate used to compare elements at the list.
	 * Returns ​true if the first argument is greater than or equals to the second.
	 */
	static void GnomeSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate);

	/**
	 * A function to sort an array using bubble sort algorithm.
	 * \param list An array with data to be sorted. That class must be inherited from IArray interface.
	 * \param comparePredicate Predicate used to compare elements at the array.
	 * Returns ​true if the first argument is greater than or equals to the second.
	 */
	static void BubbleSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate);

	/**
	 * A function to sort a linked list using bubble sort algorithm.
	 * \param list Linked list with data to be sorted.
	 * \param comparePredicate Predicate used to compare elements at the list.
	 * Returns ​true if the first argument is greater than or equals to the second.
	 */
	static void BubbleSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate);

	/**
	 * A function to sort an array using selection sort algorithm.
	 * \param list An array with data to be sorted. That class must be inherited from IArray interface.
	 * \param comparePredicate Predicate used to compare elements at the array.
	 * Returns ​true if the first argument is greater than or equals to the second.
	 */
	static void SelectionSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate);
	
	/**
	 * A function to sort a linked list using selection sort algorithm.
	 * \param list Linked list with data to be sorted.
	 * \param comparePredicate Predicate used to compare elements at the list.
	 * Returns ​true if the first argument is greater than or equals to the second.
	 */
	static void SelectionSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate);

	/**
	 * A function to sort an array using insertion sort algorithm.
	 * \param list An array with data to be sorted. That class must be inherited from IArray interface.
	 * \param comparePredicate Predicate used to compare elements at the array.
	 * Returns ​true if the first argument is greater than or equals to the second.
	 */
	static void InsertionSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate);

	/**
	* A function to sort a linked list using insertion sort algorithm.
	* \param list Linked list with data to be sorted.
	* \param comparePredicate Predicate used to compare elements at the list.
	* Returns ​true if the first argument is greater than or equals to the second.
	*/
	static void InsertionSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate);

	/**
	 * A function to sort an array using quick sort algorithm.
	 * \param list An array with data to be sorted. That class must be inherited from IArray interface.
	 * \param comparePredicate Predicate used to compare elements at the array.
	 * Returns ​true if the first argument is greater than or equals to the second.
	 */
	static void QuickSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate);

	/**
	* A function to sort a linked list using quick sort algorithm.
	* \param list Linked list with data to be sorted.
	* \param comparePredicate Predicate used to compare elements at the list.
	*/
	static void QuickSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate);

	/**
	* A function to sort an array using merge sort algorithm.
	* \param list An array with data to be sorted. That class must be inherited from IArray interface.
	* \param comparePredicate Predicate used to compare elements at the array.
	* Returns ​true if the first argument is greater than or equals to the second.
	*/
	static void MergeSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate);

	/**
	* A function to sort a linked list merge quick sort algorithm.
	* \param list Linked list with data to be sorted.
	* \param comparePredicate Predicate used to compare elements at the list.
	* Returns ​true if the first argument is greater than or equals to the second.
	*/
	static void MergeSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate);

	/**
	* A function to sort an array using counting sort algorithm.
	* \param list An array with data to be sorted.
	* \param sortField Function returns field which used to compare elements at the list.
	* This field must be an integer and not negative.
	*/
	static void CountingSort(IArray<T>& list, std::function<size_t(T)> sortField);

	/**
	* A function to sort a linked list using counting sort algorithm.
	* \param list Linked list with data to be sorted.
	* \param sortField Function returns field which used to compare elements at the list.
	* This field must be an integer and not negative.
	*/
	static void CountingSort(LinkedList<T>& list, std::function<size_t(T)> sortField);
	
	/**
	* A function to sort an array using bucket sort algorithm.
	* \param list An array with data to be sorted.
	* \param sortField Function returns field which used to compare elements at the list.
	* This field must be float and from zero to one.
	*/
	static void BucketSort(IArray<T>& list, std::function<float(T)> sortField);

	/**
	* A function to sort an linked list using bucket sort algorithm.
	* \param list Linked list with data to be sorted.
	* \param sortField Function returns field which used to compare elements at the list.
	* This field must be float and from zero to one.
	*/
	static void BucketSort(LinkedList<T>& list, std::function<float(T)> sortField);
};

template <class T>
int ListSorter<T>::Partition(IArray<T>& list, const int low, const int high, std::function<bool(T, T)> comparePredicate)
{
	T pivot = list[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (comparePredicate(pivot, list[j]))
		{
			i++; // increment index of smaller element  
			std::swap(list[i], list[j]);
		}
	}
	std::swap(list[i + 1], list[high]);
	return (i + 1);
}

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
void ListSorter<T>::QuickSortRecursive(IArray<T>& list, int low, int high, std::function<bool(T, T)> comparePredicate)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		const int pi = Partition(list, low, high, comparePredicate);

		// Separately sort elements before  
		// partition and after partition  
		QuickSortRecursive(list, low, pi - 1, comparePredicate);
		QuickSortRecursive(list, pi + 1, high, comparePredicate);
	}
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
void ListSorter<T>::Merge(IArray<T>& list, const int low, const int mid, const int high,
                          std::function<bool(T, T)> comparePredicate)
{
	int i, j;
	auto n1 = mid - low + 1;
	auto n2 = high - mid;

	/* create temp arrays */
	T* l = new T[n1];
	T* r = new T[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		l[i] = list[low + i];
	for (j = 0; j < n2; j++)
		r[j] = list[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	auto k = low; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (comparePredicate(r[j], l[i]))
		{
			list[k] = l[i];
			i++;
		}
		else
		{
			list[k] = r[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		list[k] = l[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		list[k] = r[j];
		j++;
		k++;
	}

	delete[] l;
	delete[] r;
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
void ListSorter<T>::MergeSortRecursive(IArray<T>& list, int low, int high,
                                       std::function<bool(T, T)> comparePredicate)
{
	if (low < high)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		auto m = low + (high - low) / 2;

		// Sort first and second halves 
		MergeSortRecursive(list, low, m, comparePredicate);
		MergeSortRecursive(list, m + 1, high, comparePredicate);

		Merge(list, low, m, high, comparePredicate);
	}
}

template <class T>
void ListSorter<T>::GnomeSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate)
{
	auto index = 0;

	while (index < list.GetSize())
	{
		if (index == 0)
			index++;
		if (comparePredicate(list[index], list[index - 1]))
			index++;
		else 
		{
			std::swap(list[index], list[index - 1]);
			index--;
		}
	}
}

template <class T>
void ListSorter<T>::GnomeSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate)
{
	Node<T>* index = list.GetHead();

	while (index)
	{
		if (index == list.GetHead())
			index = index->GetNext();
		
		if (comparePredicate(index->GetData(), index->GetPrev()->GetData()))
			index = index->GetNext();
		
		else
		{
			auto temp = index->GetData();
			index->SetData(index->GetPrev()->GetData());
			index->GetPrev()->SetData(temp);
			index = index->GetPrev();
		}
	}
}

template <class T>
void ListSorter<T>::BubbleSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate)
{
	for (auto i = 0; i < list.GetSize() - 1; i++)
		for (auto j = 0; j < list.GetSize() - i - 1; j++)
			if (comparePredicate(list[j], list[j + 1]))
				std::swap(list[j], list[j + 1]);
}

template <class T>
void ListSorter<T>::BubbleSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate)
{
	/* Checking for empty list */
	if (list.GetSize() <= 1)
		return;

	bool isSwapped;
	Node<T>* last = nullptr;
	do
	{
		isSwapped = false;
		Node<T>* cur = list.GetHead();

		while (cur->GetNext() != last)
		{
			if (comparePredicate(cur->GetData(), cur->GetNext()->GetData()))
			{
				auto temp = cur->GetData();
				cur->SetData(cur->GetNext()->GetData());
				cur->GetNext()->SetData(temp);
				isSwapped = true;
			}
			cur = cur->GetNext();
		}
		last = cur;
	}
	while (isSwapped);
}

template <class T>
void ListSorter<T>::SelectionSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate)
{
	// One by one move boundary of unsorted subarray.
	for (auto i = 0; i < list.GetSize() - 1; i++)
	{
		// Find the minimum element in unsorted array . 
		auto minIdx = i;
		for (auto j = i + 1; j < list.GetSize(); j++)
			if (comparePredicate(list[minIdx], list[j]))
				minIdx = j;

		// Swap the found minimum element with the first element . 
		std::swap(list[minIdx], list[i]);
	}
}

template <class T>
void ListSorter<T>::SelectionSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate)
{
	Node<T>* temp = list.GetHead();

	// Traverse the List 
	while (temp)
	{
		Node<T>* min = temp;
		Node<T>* r = temp->GetNext();

		// Traverse the unsorted sublist 
		while (r)
		{
			if (comparePredicate(min->GetData(), r->GetData()))
				min = r;

			r = r->GetNext();
		}

		// Swap Data 
		auto x = temp->GetData();
		temp->SetData(min->GetData());
		min->SetData(x);
		temp = temp->GetNext();
	}
}

template <class T>
void ListSorter<T>::InsertionSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate)
{
	for (auto i = 1; i < list.GetSize(); i++)
	{
		T key = list[i];
		auto j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && comparePredicate(list[j], key))
		{
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
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
void ListSorter<T>::QuickSort(LinkedList<T>& list, std::function<bool(T, T)> comparePredicate)
{
	if (list.GetSize() > 1)
		QuickSortRecursive(list.GetHead(), list.GetTail(), comparePredicate);
}

template <class T>
void ListSorter<T>::QuickSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate)
{
	if (list.GetSize() > 1)
		QuickSortRecursive(list, 0, list.GetSize() - 1, comparePredicate);
}

template <class T>
void ListSorter<T>::MergeSort(IArray<T>& list, std::function<bool(T, T)> comparePredicate)
{
	MergeSortRecursive(list, 0, list.GetSize() - 1, comparePredicate);
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
void ListSorter<T>::CountingSort(IArray<T>& list, std::function<size_t(T)> sortField)
{
	std::vector<T> output(list.GetSize());
	
	int max = sortField(list[0]);
	for (auto i = 1; i < list.GetSize(); i++) 
	{
		auto field = sortField(list[i]);
		if (field > max)
			max = field;
	}

	//create count array (max+1 number of elements)
	std::vector<int> count(max + 1);

	//initialize count array to all zero
	for (auto i = 0; i < max + 1; i++)
		count[i] = 0; 

	//increase number count in count array.
	for (auto i = 0; i < list.GetSize(); i++)
		++count[sortField(list[i])];

	//find cumulative frequency
	for (auto i = 1; i < max + 1; i++)
		count[i] += count[i - 1];

	//decrease count for same numbers
	for (int i = list.GetSize() - 1; i >= 0; --i)
	{
		output[count[sortField(list[i])] - 1] = list[i];
		count[sortField(list[i])] -= 1;
	}

	//store output array to main array
	for (auto i = 0; i < list.GetSize(); i++)
	{
		list[i] = output[i];
	}
}

template <class T>
void ListSorter<T>::CountingSort(LinkedList<T>& list, std::function<size_t(T)> sortField)
{
	std::vector<size_t> buckets;
	for (Node<T>* i = list.GetHead(); i != nullptr; i = i->GetNext())
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
	for (Node<T>* i = list.GetHead(); i != nullptr; i = i->GetNext())
	{
		const int field = sortField(i->GetData());
		auto destIndex = startIndex[field]++;
		result[destIndex] = i->GetData();
	}

	list.FillByVector(result);
}

template <class T>
void ListSorter<T>::BucketSort(IArray<T>& list, std::function<float(T)> sortField)
{
	// 1) Create n empty buckets 
	std::vector<std::vector<T>> b(list.GetSize());

	// 2) Put array elements in different buckets 
	for (auto i = 0; i < list.GetSize(); i++)
	{
		const auto bi = static_cast<int>(list.GetSize() * sortField(list[i])); // Index in bucket 
		b[bi].push_back(list[i]);
	}

	// 3) Sort individual buckets 
	for (auto i = 0; i < list.GetSize(); i++)
		std::sort(b[i].begin(), b[i].end(), [&sortField](T t1, T t2)
		{
			return sortField(t1) < sortField(t2);
		});

	// 4) Concatenate all buckets into arr[] 
	auto index = 0;
	for (auto i = 0; i < list.GetSize(); i++)
		for (auto j = 0; j < b[i].size(); j++)
			list[index++] = b[i][j];
}

template <class T>
void ListSorter<T>::BucketSort(LinkedList<T>& list, std::function<float(T)> sortField)
{
	// 1) Create n empty buckets
	auto n = list.GetSize();
	std::vector<std::vector<T>> b(n);

	// 2) Put array elements in different buckets 
	for (Node<T>* index = list.GetHead(); index; index = index->GetNext())
	{
		auto bi = static_cast<int>(n * sortField(index->GetData())); // Index in bucket
		b[bi].push_back(index->GetData());
	}

	// 3) Sort individual buckets 
	for (size_t i = 0; i < n; i++)
		std::sort(b[i].begin(), b[i].end(), [&sortField](T t1, T t2)
		{
			return sortField(t1) < sortField(t2);
		});

	// 4) Concatenate all buckets into arr[] 
	Node<T>* index = list.GetHead();
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < b[i].size(); j++)
		{
			index->SetData(b[i][j]);
			index = index->GetNext();
		}

}
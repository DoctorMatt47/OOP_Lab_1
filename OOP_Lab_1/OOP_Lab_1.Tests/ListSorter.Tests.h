#pragma once

#include "pch.h"

#include "../OOP_Lab_1/Lists Files/ListSorter.h"

TEST(ListSorter, TestLinkedListGnomeSort)
{
	LinkedList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));
	
	ListSorter<std::pair<int, char>>::GnomeSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.first >= p2.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);

	ListSorter<std::pair<int, char>>::GnomeSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.second >= p2.second;
	});

	EXPECT_EQ(list1.Get(0).second, 'a');
	EXPECT_EQ(list1.Get(8).second, 'h');
}

TEST(ListSorter, TestLinkedListBubbleSort)
{
	LinkedList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::BubbleSort(list1, [](std::pair<int, char> p1,
		std::pair<int, char> p2)
		{
			return p1.first >= p2.first;
		});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);

	ListSorter<std::pair<int, char>>::BubbleSort(list1, [](std::pair<int, char> p1,
		std::pair<int, char> p2)
		{
			return p1.second >= p2.second;
		});

	EXPECT_EQ(list1.Get(0).second, 'a');
	EXPECT_EQ(list1.Get(8).second, 'h');
}

TEST(ListSorter, TestLinkedListSelectionSort)
{
	LinkedList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::SelectionSort(list1, [](std::pair<int, char> p1,
	                                                          std::pair<int, char> p2)
	{
		return p1.first >= p2.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);

	ListSorter<std::pair<int, char>>::SelectionSort(list1, [](std::pair<int, char> p1,
	                                                          std::pair<int, char> p2)
	{
		return p1.second >= p2.second;
	});

	EXPECT_EQ(list1.Get(0).second, 'a');
	EXPECT_EQ(list1.Get(8).second, 'h');
}

TEST(ListSorter, TestLinkedListQuickSort)
{
	LinkedList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::QuickSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.first >= p2.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);

	ListSorter<std::pair<int, char>>::QuickSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.second >= p2.second;
	});

	EXPECT_EQ(list1.Get(0).second, 'a');
	EXPECT_EQ(list1.Get(8).second, 'h');
}

TEST(ListSorter, TestLinkedListMergeSort)
{
	LinkedList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::MergeSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.first >= p2.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);

	ListSorter<std::pair<int, char>>::MergeSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.second >= p2.second;
	});

	EXPECT_EQ(list1.Get(0).second, 'a');
	EXPECT_EQ(list1.Get(8).second, 'h');
}

TEST(ListSorter, TestLinkedListCountingSort)
{
	LinkedList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::CountingSort(list1, [](std::pair<int, char> p1)
	{
		return p1.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);
}

TEST(ListSorter, TestLinkedListBucketSort)
{
	LinkedList<std::pair<float, char>> list1;
	list1.PushBack(std::pair<float, char>(0.4, 'f'));
	list1.PushBack(std::pair<float, char>(0.5, 'a'));
	list1.PushBack(std::pair<float, char>(0.3, 'g'));
	list1.PushBack(std::pair<float, char>(0.7, 'e'));
	list1.PushBack(std::pair<float, char>(0.1, 'g'));
	list1.PushBack(std::pair<float, char>(0.0, 'c'));
	list1.PushBack(std::pair<float, char>(0.8, 'h'));
	list1.PushBack(std::pair<float, char>(0.1, 'b'));
	list1.PushBack(std::pair<float, char>(0.2, 'd'));

	ListSorter<std::pair<float, char>>::BucketSort(list1, [](std::pair<float, char> p1)
	{
		return p1.first;
	});

	EXPECT_FLOAT_EQ(list1.Get(0).first, 0.0);
	EXPECT_FLOAT_EQ(list1.Get(8).first, 0.8);
}

TEST(ListSorter, TestArrayListGnomeSort)
{
	ArrayList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::GnomeSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.first >= p2.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);

	ListSorter<std::pair<int, char>>::GnomeSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.second >= p2.second;
	});

	EXPECT_EQ(list1.Get(0).second, 'a');
	EXPECT_EQ(list1.Get(8).second, 'h');
}

TEST(ListSorter, TestArrayListBubbleSort)
{
	ArrayList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::BubbleSort(list1, [](std::pair<int, char> p1,
	                                                       std::pair<int, char> p2)
	{
		return p1.first >= p2.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);

	ListSorter<std::pair<int, char>>::BubbleSort(list1, [](std::pair<int, char> p1,
	                                                       std::pair<int, char> p2)
	{
		return p1.second >= p2.second;
	});

	EXPECT_EQ(list1.Get(0).second, 'a');
	EXPECT_EQ(list1.Get(8).second, 'h');
}

TEST(ListSorter, TestArrayListSelectionSort)
{
	ArrayList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::SelectionSort(list1, [](std::pair<int, char> p1,
	                                                          std::pair<int, char> p2)
	{
		return p1.first >= p2.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);

	ListSorter<std::pair<int, char>>::SelectionSort(list1, [](std::pair<int, char> p1,
	                                                          std::pair<int, char> p2)
	{
		return p1.second >= p2.second;
	});

	EXPECT_EQ(list1.Get(0).second, 'a');
	EXPECT_EQ(list1.Get(8).second, 'h');
}

TEST(ListSorter, TestArrayListQuickSort)
{
	LinkedList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::QuickSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.first >= p2.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);

	ListSorter<std::pair<int, char>>::QuickSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.second >= p2.second;
	});

	EXPECT_EQ(list1.Get(0).second, 'a');
	EXPECT_EQ(list1.Get(8).second, 'h');
}

TEST(ListSorter, TestArrayListMergeSort)
{
	LinkedList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::MergeSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.first >= p2.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);

	ListSorter<std::pair<int, char>>::MergeSort(list1, [](std::pair<int, char> p1,
	                                                      std::pair<int, char> p2)
	{
		return p1.second >= p2.second;
	});

	EXPECT_EQ(list1.Get(0).second, 'a');
	EXPECT_EQ(list1.Get(8).second, 'h');
}

TEST(ListSorter, TestArrayListCountingSort)
{
	LinkedList<std::pair<int, char>> list1;
	list1.PushBack(std::pair<int, char>(4, 'f'));
	list1.PushBack(std::pair<int, char>(5, 'a'));
	list1.PushBack(std::pair<int, char>(3, 'g'));
	list1.PushBack(std::pair<int, char>(7, 'e'));
	list1.PushBack(std::pair<int, char>(1, 'g'));
	list1.PushBack(std::pair<int, char>(0, 'c'));
	list1.PushBack(std::pair<int, char>(8, 'h'));
	list1.PushBack(std::pair<int, char>(10, 'b'));
	list1.PushBack(std::pair<int, char>(2, 'd'));

	ListSorter<std::pair<int, char>>::CountingSort(list1, [](std::pair<int, char> p1)
	{
		return p1.first;
	});

	EXPECT_EQ(list1.Get(0).first, 0);
	EXPECT_EQ(list1.Get(8).first, 10);
}

TEST(ListSorter, TestArrayListBucketSort)
{
	LinkedList<std::pair<float, char>> list1;
	list1.PushBack(std::pair<float, char>(0.4, 'f'));
	list1.PushBack(std::pair<float, char>(0.5, 'a'));
	list1.PushBack(std::pair<float, char>(0.3, 'g'));
	list1.PushBack(std::pair<float, char>(0.7, 'e'));
	list1.PushBack(std::pair<float, char>(0.1, 'g'));
	list1.PushBack(std::pair<float, char>(0.0, 'c'));
	list1.PushBack(std::pair<float, char>(0.8, 'h'));
	list1.PushBack(std::pair<float, char>(0.1, 'b'));
	list1.PushBack(std::pair<float, char>(0.2, 'd'));

	ListSorter<std::pair<float, char>>::BucketSort(list1, [](std::pair<float, char> p1)
	{
		return p1.first;
	});

	EXPECT_FLOAT_EQ(list1.Get(0).first, 0.0);
	EXPECT_FLOAT_EQ(list1.Get(8).first, 0.8);
}
#pragma once

#include "pch.h"

#include "../OOP_Lab_1/Lists Files/LinkedList.h"


TEST(LinkedList, TestDefaultConstructor)
{
	LinkedList<int> list;
	EXPECT_EQ(list.GetSize(), 0);
}

TEST(LinkedList, TestUndefaultConstructor)
{
	LinkedList<int> list({0, 1, 2, 3, 4, 5});
	EXPECT_EQ(list.GetSize(), 6);
	EXPECT_EQ(list.Get(0), 0);
	EXPECT_EQ(list.Get(5), 5);
}

TEST(LinkedList, TestCopyConstructor)
{
	LinkedList<int> list1({0, 1, 2, 3, 4, 5 });
	LinkedList<int> list2(list1);
	EXPECT_EQ(list2.GetSize(), 6);
	EXPECT_EQ(list2.Get(0), 0);
	EXPECT_EQ(list2.Get(5), 5);
}

TEST(LinkedList, TestPushBack)
{
	LinkedList<int> list;
	list.PushBack(1);
	EXPECT_EQ(list.GetSize(), 1);
	EXPECT_EQ(list.GetHead()->GetData(), 1);
	list.PushBack(2);
	list.PushBack(3);
	EXPECT_EQ(list.GetSize(), 3);
	EXPECT_EQ(list.GetTail()->GetData(), 3);
}

TEST(LinkedList, TestPushFront)
{
	LinkedList<int> list;
	list.PushFront(3);
	EXPECT_EQ(list.GetSize(), 1);
	EXPECT_EQ(list.GetHead()->GetData(), 3);
	list.PushFront(2);
	list.PushFront(1);
	EXPECT_EQ(list.GetSize(), 3);
	EXPECT_EQ(list.GetTail()->GetData(), 3);
	EXPECT_EQ(list.GetHead()->GetData(), 1);
}

TEST(LinkedList, TestPopBack)
{
	LinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PopBack();
	EXPECT_EQ(list.GetSize(), 4);
	EXPECT_EQ(list.GetTail()->GetData(), 4);
	list.PushBack(6);
	EXPECT_EQ(list.GetSize(), 5);
	EXPECT_EQ(list.GetTail()->GetData(), 6);
}

TEST(LinkedList, TestPopFront)
{
	LinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PopFront();
	EXPECT_EQ(list.GetSize(), 4);
	EXPECT_EQ(list.GetHead()->GetData(), 2);
	list.PushFront(0);
	EXPECT_EQ(list.GetSize(), 5);
	EXPECT_EQ(list.GetHead()->GetData(), 0);
}

TEST(LinkedList, TestInsert)
{
	LinkedList<int> list;
	list.PushBack(0);
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(4);
	list.PushBack(5);
	list.Insert(3, 3);
	EXPECT_EQ(list.GetSize(), 6);
	EXPECT_EQ(list.Get(3), 3);
}

TEST(LinkedList, TestRemove)
{
	LinkedList<int> list;
	list.PushBack(0);
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.Remove(4);
	EXPECT_EQ(list.GetSize(), 5);
	EXPECT_EQ(list.Get(4), 5);
}

TEST(LinkedList, TestClear)
{
	LinkedList<int> list;
	list.PushBack(0);
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.Clear();
	EXPECT_EQ(list.GetSize(), 0);
	list.PushBack(0);
	EXPECT_EQ(list.Get(0), 0);
}
#pragma once

#include "pch.h"

#include "../OOP_Lab_1/Lists Files/VectorList.h"


TEST(VectorList, TestDefaultConstructor)
{
	VectorList<int> list;
	EXPECT_EQ(list.GetSize(), 0);
}

TEST(VectorList, TestUndefaultConstructor)
{
	VectorList<int> list({ 0, 1, 2, 3, 4, 5 });
	EXPECT_EQ(list.GetSize(), 6);
	EXPECT_EQ(list.Get(0), 0);
	EXPECT_EQ(list.Get(5), 5);
}

TEST(VectorList, TestCopyConstructor)
{
	VectorList<int> list1({ 0, 1, 2, 3, 4, 5 });
	VectorList<int> list2(list1);
	EXPECT_EQ(list2.GetSize(), 6);
	EXPECT_EQ(list2.Get(0), 0);
	EXPECT_EQ(list2.Get(5), 5);
}

TEST(VectorList, TestPushBack)
{
	VectorList<int> list;
	list.PushBack(1);
	EXPECT_EQ(list.GetSize(), 1);
	EXPECT_EQ(list.Get(0), 1);
	list.PushBack(2);
	list.PushBack(3);
	EXPECT_EQ(list.GetSize(), 3);
	EXPECT_EQ(list.Get(2), 3);
}

TEST(VectorList, TestPopBack)
{
	VectorList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PopBack();
	EXPECT_EQ(list.GetSize(), 4);
	list.PushBack(6);
	EXPECT_EQ(list.GetSize(), 5);
	EXPECT_EQ(list.Get(4), 6);
}

TEST(VectorList, TestInsert)
{
	VectorList<int> list;
	list.PushBack(0);
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(4);
	list.PushBack(5);
	list.Insert(3, 3);
	EXPECT_EQ(list.GetSize(), 6);
	EXPECT_EQ(list.Get(3), 3);
}

TEST(VectorList, TestRemove)
{
	VectorList<int> list;
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

TEST(VectorList, TestClear)
{
	VectorList<int> list;
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
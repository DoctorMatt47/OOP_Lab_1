#include "pch.h"

#include "LinkedList.Tests.h"
#include "VectorList.Tests.h"
#include "ArrayList.Tests.h"
#include "ListSorter.Tests.h"

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#include "Dice Files/Set.h"

using namespace std;

int main()
{
	Set s1;
	s1.InitializeWithConsole();
	s1.Print();
	s1.FindProbabilityForSums();
	
	return 0;
}

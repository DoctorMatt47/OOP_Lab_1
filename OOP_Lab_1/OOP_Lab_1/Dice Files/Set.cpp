#include "Set.h"

Set::Set()
{
	_amountOfDices = 0;
}

void Set::FindProbabilityForSums()
{
	if (_amountOfDices == 0)
		return;
	const int n = _amountOfDices * 2;
	size_t maxSumProb = 0;
	std::vector<size_t> sol;
	std::vector<std::vector<size_t>> arr;
	
	for (auto i = 0; i < _amountOfDices; i++)
	{
		maxSumProb += _dice[i].GetAmountOfFaces();
		
		std::vector<size_t> temp;
		for (auto j = 1; j <= _dice[i].GetAmountOfFaces(); j++)
			temp.push_back(j);
		arr.push_back(temp);
	}
	
	maxSumProb = maxSumProb - _amountOfDices + 1;
	std::vector<double> sumsProb(maxSumProb);
	
	FindCombinations(arr, sumsProb, sol, 0, n);

	for (auto i = 0; i < sumsProb.size(); i++)
	{
		std::cout << i + _amountOfDices << " | " << sumsProb[i] << std::endl;
	}
}

void Set::InitializeWithConsole()
{
	system("CLS");
	std::cout << "Enter number of dices:" << std::endl;
	std::cin >> _amountOfDices;
	std::cout << std::endl;
	if (_amountOfDices == 0)
		return;
	
	int j;
	for (auto i = 0; i < _amountOfDices; i++)
	{
		size_t amountOfFaces;
		
		std::cout << "Enter amount of faces for " << i + 1 << " dice:" << std::endl;
		std::cin >> amountOfFaces;
		if (amountOfFaces == 0 || amountOfFaces % 2 != 0 || amountOfFaces > 20)
			throw std::exception("Amount of dice faces must be even and from 2 to 20");

		Dice tempDice;
		double sumProb = 0;
		for (j = 0; j < amountOfFaces; j++)
		{
			double prob;
			
			if (j == amountOfFaces - 1)
			{
				prob = 1 - sumProb;
				Face tempFace(j + 1, prob);
				tempDice.AddFace(tempFace);
				continue;
			}
			
			std::cout << "Enter probability for " << j + 1 << " face:" << std::endl;
			std::cin >> prob;

			if (sumProb + prob >= 1)
				throw std::exception("Invalid entering data, sum of probability must be 1");
			else
			{
				sumProb += prob;
				Face tempFace(j + 1, prob);
				tempDice.AddFace(tempFace);
			}
		}
		tempDice.SetAmountOfFaces(j);
		_dice.PushBack(tempDice);
		std::cout << std::endl;
	}
	
}


void Set::FindCombinations(std::vector<std::vector<size_t>>& array,
                           std::vector<double>& sumsProb,
                           std::vector<size_t>& sol, size_t i, const int n)
{
	//Stop condition for the recursion.
	if (sol.size() == n)
	{
		//Find sum of sol array.
		int sum = 0;
		double prob = 1;
		for (auto j = 0; j < sol.size(); j++)
		{
			prob *= _dice[j].GetProbabilityByNumber(sol[j]);
			sum += sol[j];
		}

		sumsProb[sum - _amountOfDices] += prob;
		return;
	}
	if (i >= array.size())
		i = 0;
	for (auto& value : array[i])
	{
		sol.push_back(value);

		//Recursive call.
		FindCombinations(array, sumsProb, sol, i + 1, n - 1);

		//Cleaning up environment.
		sol.pop_back();
	}
}

void Set::Print()
{
	for (auto i = 0; i < _amountOfDices; i++)
	{
		std::cout << i + 1 << " dice:" << std::endl;
		for (auto j = 1; j <= _dice[i].GetAmountOfFaces(); j++)
			std::cout << _dice[i].GetProbabilityByNumber(j) << std::endl;
	}

	std::cout << std::endl;
}

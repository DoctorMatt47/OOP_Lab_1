#pragma once

#include <iostream>

#include "../Dice Files/Dice.h"

/**
 * \brief Set with dices.
 *
 * Set that consists of dices and probability of each faces drop.
 * This class can calculate probability of the each sum.
 */
class Set
{
private:
	ArrayList<Dice> _dice;
	size_t _amountOfDices;

	/**
	 * Finds all sum combinations.
	 * \param array Two dimension array with arrays that represent
	 * numbers of the dice faces.
	 * \param sumsProb Array with probability for sum.
	 * \param sol Array with terms.
	 * \param i Index of two dimension array.
	 * \param n Double amount of dices.
	 */
	void FindCombinations(std::vector<std::vector<size_t>>& array,
	                      std::vector<double>& sumsProb,
	                      std::vector<size_t>& sol, size_t i, int n);
public:

	/**
	 * Default constructor.
	 */
	Set();

	/**
	 * Initializes set of dices using console.
	 */
	void InitializeWithConsole();

	/**
	 * Print all probabilities of dices faces.
	 */
	void Print();

	/**
	 * Find probability of drop for all sums.
	 */
	void FindProbabilityForSums();
};


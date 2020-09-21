#pragma once
#include <exception>

/**
 * \brief Face of the dice.
 *
 * Class that represent face of the dice.
 * Dice consists of instances of this class.
 */
class Face
{
private:
	//Number of dots on face of dice.
	size_t _number;

	//Chance of this dice face being dropped
	double _probability;

public:
	/**
	 * Default constructor.
	 */
	Face();
	
	/**
	 * Constructor that initialize the face of dice.
	 * \param number Number of dots on face of dice.
	 * \param probability Chance of this dice face being dropped.
	 * Must be from zero to one.
	 */
	Face(size_t number, float probability);

	/**
	 * Get the number of dots.
	 * \return Number of dots.
	 */
	size_t GetNumber() const;

	/**
	 * Get probability of this dice face being dropped.
	 * \return Probability.
	 */
	double GetProbability() const;

	/**
	 * Set the number of dots. 
	 * \param number Number of dots. 
	 */
	void SetNumber(size_t number);

	/**
	 * Set probability of this dice face being dropped. 
	 * \param probability Probability.
	 * Must be from zero to one.
	 */
	void SetProbability(float probability);
	
};


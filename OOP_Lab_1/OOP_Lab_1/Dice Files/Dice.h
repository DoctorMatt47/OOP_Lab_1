#pragma once

#include "Face.h"
#include "../Lists Files/ArrayList.h"


/**
 * \brief Represent dice.
 *
 * Set of dice consists of instances of this class.
 */
class Dice
{
private:
	//Collection of faces.
	ArrayList<Face> _faces;

	//Must be even, equals or less than 20, not zero.
	size_t _amountOfFaces;

public:

	/**
	 * Default constructor.
	 */
	Dice();

	/**
	 * Gets size of the faces array.
	 * \return Amount of dice faces.
	 */
	size_t GetAmountOfFaces() const;

	/**
	 * Adds new face to the faces array.
	 * \param face Element of the faces array.
	 */
	void AddFace(Face& face);

	/**
	 * Sets amount of faces
	 * \param amountOfFaces Number of element of the faces array.
	 */
	void SetAmountOfFaces(size_t amountOfFaces);

	/**
	 * Gets probability by number. 
	 * \param num Number of dots on the face.
	 * \return Probability of number.
	 */
	double GetProbabilityByNumber(size_t num);
	
};


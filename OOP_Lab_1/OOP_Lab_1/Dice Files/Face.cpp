#include "Face.h"

size_t Face::GetNumber() const
{
	return _number;
}

double Face::GetProbability() const
{
	return _probability;
}

Face::Face()
{
	_number = 0;
	_probability = 0;
}

Face::Face(const size_t number, const float probability)
{
	if (number == 0)
		throw std::exception("Incorrect number");
	if (probability > 1 || probability < 0)
		throw std::exception("Incorrect probability");
	_number = number;
	_probability = probability;
}

void Face::SetNumber(const size_t number)
{
	if (number == 0)
		return;
	_number = number;
}

void Face::SetProbability(float probability)
{
	if (probability > 1 || probability < 0)
		return;
	_probability = probability;
}

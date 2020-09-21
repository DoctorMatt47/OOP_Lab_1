#include "Dice.h"

Dice::Dice()
{
	_amountOfFaces = 0;
}

size_t Dice::GetAmountOfFaces() const
{
	return _amountOfFaces;
}

void Dice::AddFace(Face& face)
{
	_faces.PushBack(face);
}

void Dice::SetAmountOfFaces(size_t amountOfFaces)
{
	_amountOfFaces = amountOfFaces;
}

double Dice::GetProbabilityByNumber(size_t num)
{
	if (num > _amountOfFaces)
		return 0;
	return _faces[num - 1].GetProbability();
}

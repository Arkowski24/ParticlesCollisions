#include "pVector.h"

pVector::pVector()
{
}


pVector::~pVector()
{
}

pVector& pVector::operator += (const pVector& Summand)
{
	x += Summand.x;
	y += Summand.y;
	return *this;
}

pVector operator + (pVector SummandFirst, pVector SummandSecond)
{
	return SummandFirst += SummandSecond;
}
#pragma once

class pVector
{
public:
	pVector();
	~pVector();

	double x;
	double y;

	pVector& operator += (const pVector&);
};

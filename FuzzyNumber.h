#pragma once
#include "Triad.h"
class FuzzyNumber : public Triad
{
public:
	FuzzyNumber();
	FuzzyNumber(double x, double l, double r) throw(logic_error);
	FuzzyNumber(const FuzzyNumber& v);

	FuzzyNumber& operator --() throw (InheritedException);
	FuzzyNumber& operator ++() throw (Exception);
	FuzzyNumber operator --(int) throw (InheritedException);
	FuzzyNumber operator ++(int) throw (logic_error);

	friend FuzzyNumber operator + (const FuzzyNumber a, const FuzzyNumber b);
	friend FuzzyNumber operator * (const FuzzyNumber a, const FuzzyNumber b);
};


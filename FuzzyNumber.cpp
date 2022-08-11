#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
	:Triad()
{
}

FuzzyNumber::FuzzyNumber(double x, double l, double r) throw(logic_error)
{
	if (!(x > (x - l) && (x + r) > x))
		throw logic_error("Condition is not met");
	//генерув. стандарт. винятку
	this->set_x(x);
	this->set_l(x - l);
	this->set_r(x + r);
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
	:Triad(v)
{
}

FuzzyNumber& FuzzyNumber::operator--() throw(InheritedException)
{
	this->set_l(this->get_l() - 1);
	if (this->get_l() < 0)
		throw new InheritedException();//виняток-нащадок
	return *this;
}

FuzzyNumber& FuzzyNumber::operator++() throw(Exception)
{
	this->set_r(this->get_r() + 1);
	if (this->get_r() > 10)
		throw Exception("Right coordinate bigger than 10");
	//генерув. власного винятку
	return *this;
}

FuzzyNumber FuzzyNumber::operator--(int) throw(InheritedException)
{
	FuzzyNumber a(*this);
	this->set_l(this->get_l() - 1);
	if (this->get_l() < 0)
		throw InheritedException();//виняток-нащадок
	return a;
}

FuzzyNumber FuzzyNumber::operator++(int) throw(logic_error)
{
	FuzzyNumber a(*this);
	this->set_r(this->get_r() + 1);
	if (this->get_r() > 10)
		throw logic_error("Right coordinate bigger than 10");
	//генерув. власного винятку
	return a;
}

FuzzyNumber operator+(const FuzzyNumber a, const FuzzyNumber b)
{
	FuzzyNumber T;
	T.set_x(a.get_x() + b.get_x());
	T.set_l(a.get_x() + b.get_x() - a.get_l() - b.get_l());
	T.set_r(a.get_x() + b.get_x() + a.get_r() + b.get_r());
	return T;
}

FuzzyNumber operator*(const FuzzyNumber a, const FuzzyNumber b)
{
	FuzzyNumber N;
	N.set_x(a.get_x() * b.get_x());
	N.set_l(a.get_x() * b.get_x() - b.get_x() * a.get_l() - a.get_x() * b.get_l() - a.get_l() * b.get_l());
	N.set_r(a.get_x() * b.get_x() + b.get_x() * a.get_r() + a.get_x() * b.get_r() + a.get_r() * b.get_r());
	return N;
}

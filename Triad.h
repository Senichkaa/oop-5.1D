#pragma once
#pragma pack(1)
#include "Exception.h"
#include "InheritedException.h"
class Triad
{
private:
	double x, l, r;
public:
	Triad();
	Triad(double x, double l, double r) throw (out_of_range);
	Triad(const Triad& a);

	double get_x() const { return x; }
	double get_l() const { return l; }
	double get_r() const { return r; }

	void set_x(double value) { x = value; }
	void set_l(double value) { l = value; }
	void set_r(double value) { r = value; }

	Triad& operator =(const Triad& n);
	operator string() const;

	friend bool operator ==(const Triad& l, const Triad& r);
	friend bool operator !=(const Triad& l, const Triad& r);
	friend bool operator >(const Triad& l, const Triad& r);
	friend bool operator <(const Triad& l, const Triad& r);
	friend bool operator >=(const Triad& l, const Triad& r);
	friend bool operator <=(const Triad& l, const Triad& r);

	friend ostream& operator << (ostream& out, const Triad& a);
	friend istream& operator >> (istream& in, Triad& a) throw(Exception);
};


#include "Triad.h"

Triad::Triad()
	:x(0),l(0),r(0)
{
}

Triad::Triad(double x, double l, double r) throw(out_of_range)
{
	if (!((x > -10 && x < 10) || (l > -10 && l < 10) || (r > -10 && r < 10)))
		throw out_of_range("Numbers must belong to [-10;10]");
	//генерув. стандарт. винятку
	this->x = x;
	this->l = l;
	this->r = r;
}

Triad::Triad(const Triad& a)
{
	set_x(a.get_x());
	set_r(a.get_r());
	set_l(a.get_l());
}

Triad& Triad::operator=(const Triad& n)
{
	set_x(n.get_x());
	set_r(n.get_r());
	set_l(n.get_l());
	return *this;
}

Triad::operator string() const
{
	stringstream ss;
	ss << "x = " << x << endl;
	ss << "l = " << l << endl;
	ss << "r = " << r << endl;
	return ss.str();
}

bool operator==(const Triad& l, const Triad& r)
{
	return (l.get_x() == r.get_x() && l.get_l() == r.get_l() && l.get_r() == r.get_r());
}

bool operator!=(const Triad& l, const Triad& r)
{
	return !(l==r);
}

bool operator>(const Triad& l, const Triad& r)
{
	return ((l.get_x() > r.get_x()) || (l.get_x() == r.get_x() && l.get_l() > r.get_l()) ||
		(r.get_x() == l.get_x() && l.get_l() == r.get_l() && l.get_r() > r.get_r()));
}

bool operator<(const Triad& l, const Triad& r)
{
	return ((l.get_x() < r.get_x()) || (l.get_x() == r.get_x() && l.get_l() < r.get_l()) ||
		(r.get_x() == l.get_x() && l.get_l() == r.get_l() && l.get_r() < r.get_r()));
}

bool operator>=(const Triad& l, const Triad& r)
{
	return !(r < l);
}

bool operator<=(const Triad& l, const Triad& r)
{
	return !(l > r);
}

ostream& operator<<(ostream& out, const Triad& a)
{
	out << string(a);
	return out;
}

istream& operator>>(istream& in, Triad& a) throw(Exception)
{
	double x, l, r;
	cout << "x = "; in >> x;
	cout << "l = "; in >> l;
	cout << "r = "; in >> r;

	if (!((x > -10 && x < 10) || (l > -10 && l < 10) || (r > -10 && r < 10)))
		throw Exception("Numbers must belong to [-10;10]");

	a.set_x(x); a.set_l(l); a.set_r(r);
	return in;
}

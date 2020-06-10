#include "Couple.h"

template<class T1, class T2>
bool Couple<T1, T2>::operator==(const Couple<T1, T2>& c) const
{
	return c.first == this->first ? true : false;
}

template<class T1, class T2>
bool Couple<T1, T2>::operator>(const Couple<T1, T2>& c) const
{
	return c.first > this->first ? true : false;
}

template<class T1, class T2>
bool Couple<T1, T2>::operator<(const Couple<T1, T2>& c) const
{
	return c.first < this->first ? true : false;
}

template<class T1, class T2>
std::ostream& operator<<(std::ostream& out, const Couple<T1, T2>& c)
{
	out << c.first << " " << c.second << std::endl;
	return out;
}

template<class T1, class T2>
std::istream& operator>>(std::istream& in, Couple<T1, T2>& c)
{
	in >> c.first >> c.second;
	return in;
}
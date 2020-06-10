#pragma once
#include"BTree.h"
#include"Dictionary.h"

template<class T1, class T2>
struct Couple
{
	T1 first;
	T2 second;

	Couple() = default;

	bool operator==(const Couple<T1, T2>&) const;
	bool operator>(const Couple<T1, T2>&) const;
	bool operator<(const Couple<T1, T2>&) const;

	Couple<T1, T2>& makeCouple(const T1& _t1, const T2& _t2)
	{
		first = _t1;
		second = _t2;
		return *this;
	}

	template<class T1, class T2>
	friend std::ostream& operator<<(std::ostream&, const Couple<T1, T2>&);

	template<class T1, class T2>
	friend std::istream& operator>>(std::istream&, Couple<T1, T2>&);
};
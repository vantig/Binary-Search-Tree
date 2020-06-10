#pragma once
#include<iostream>
#include<string>
using std::string;

struct Dictionary
{
	string english;
	string russian;
	size_t counter = 0;

	friend std::ostream& operator<<(std::ostream&, const Dictionary&);
	friend std::istream& operator>>(std::istream&, Dictionary&);
};
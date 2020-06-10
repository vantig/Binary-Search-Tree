#include "Dictionary.h"

std::ostream& operator<<(std::ostream& out, const Dictionary& word)
{
	out << word.english << " " << word.russian << " " << word.counter << std::endl;
	return out;
}
std::istream& operator>>(std::istream& in, Dictionary& word)
{
	in >> word.english >> word.russian >> word.counter;
	return in;
}
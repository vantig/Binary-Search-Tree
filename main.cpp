#include "BTree.cpp"
#include "Dictionary.h"
#include "Couple.cpp"


int main()
{
	Couple<string, Dictionary> cpl;
	string word = "penguin";
	Dictionary d;

	std::cin >> d;

	cpl.makeCouple(word, d);
	std::cout << cpl << std::endl;
	system("pause");
	return 0;
}

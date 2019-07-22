//testing enum
//ms
//08-06-2019

#include <iostream>
using namespace std;

int main()
{
	cout << "Difficulty Levels\n\n";
	cout << "1 - Easy\n";
	cout << "2- Normal\n";
	cout << "3 - Normal\n";

	enum difficulty {easy = 1, normal, hard}; //enum without class turns the options in integeres
	difficulty myPick = hard;

	switch (myPick) //classless enum = integer is the value
	{
	case 1:
		cout << "You picked Easy.\n";
		break;
	case 2:
		cout << "You picked Normal.\n";
		break;
	case 3:
		cout << "You picked Hard.\n";
		break;
	default:
		cout << "That choice isn't available for now!\n";
		break;
	}
}

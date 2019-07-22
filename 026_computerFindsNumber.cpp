//computer guesses the number TO BE REFACTORED
//by ms
//08-06-2019

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL)); //seeding rng
	int userPick, computerPick, latestNumber, smartAiPick = 100, smartLowerChoice = 1, counter = 0;
	bool numberGuessed = false;

	cout << "Welcome to the computer guesses the number\n!";
	cout << "Pick a number between 1 and 100, and computer will try to guess it in less tries.\n";

	cout << "Pick your number: ";		cin >> userPick;

	do 
	{
		computerPick = rand() % smartAiPick + smartLowerChoice;
		counter++;

		if (computerPick == userPick)
		{
			cout << "Computer pick was " << computerPick << " and he found your number!\n";
			cout << "Number of computer tries: " << counter << " .\n";
			numberGuessed = true;
		}
		else if (computerPick > userPick) //if it's higher than the user pick, the max rng possible is now the latest pick from the pc
		{
			cout << "try number: " << counter << " - higher number: " << computerPick << endl;			
			smartAiPick = computerPick - smartLowerChoice;
			
		}
		else if (computerPick < userPick)
		{
			cout << "try number: " << counter << " - lower number: " << computerPick << endl;
		}
	} 
	while (!numberGuessed);
}

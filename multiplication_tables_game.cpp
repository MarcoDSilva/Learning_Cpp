/* 15-04-2019
by ms
multiplication tables game*/

#include<iostream>
#include <time.h>
using namespace std;

int main()
{
	int x, y, solution, user_guess, number_tries = 0, correct_counter = 0;

	//initialize the PRNG
	srand(time(NULL));

	cout << "You need to get 3 correct answers to win!\n If you get one wrong, you go back 2 steps!!!\n";

	//while correct answers is not 3, keep the game going
	do
	{
		//gen random numbers until 9, +1 to not have a 0 in the generation
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		solution = x * y;

		//asks user for input
		cout << correct_counter << ": " << x << " * " << y << " ? ";
		cin >> user_guess;

		//if user guesses correctly, he gets awarded one point, and number of tries goes up by 1
		if (user_guess == solution)
		{
			number_tries++;
			correct_counter++;
		}
		//if user fails, loses 2 correct answers and number of tries goes up
		else 
		{
			number_tries++;
			correct_counter -= 2;

			//if user answers wrong since the start, we block the counter at 0, to not get a negative int
			if (correct_counter < 0)
			{
				correct_counter = 0;
			}
			
		}

	} while (correct_counter < 3);

	cout << "You won! (" << correct_counter << " correct answers in " << number_tries << " tries)\n";
	
}
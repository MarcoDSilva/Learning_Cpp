//euromillons
//by ms
//27/05/19

#include<iostream>
#include<time.h>

using namespace std;

int main()
{
	srand(time(NULL)); //time to random some seeds
	int numbers[6] = { 0,0,0,0,0,0 }, stars[3] = { 0,0,0 };
	
	//gens random number, if there is any equal between the first 2, rngs it (MAY STILL GET A REPEATED ONE)
	for (int i = 0; i < 5; i++)
	{
		numbers[i] = rand() % 50 + 1;
		if (numbers[i] == numbers[i + 1])
		{
			numbers[i] = rand() % 50 + 1;
		}
	}

	//checks all options available , if bigger than the one ahead, swaps
	for (int i = 0; i < 5; i++)
	{
		if (numbers[0] > numbers[1])
		{
			numbers[5] = numbers[1];
			numbers[1] = numbers[0];
			numbers[0] = numbers[5];
		}
		if (numbers[1] > numbers[2])
		{
			numbers[5] = numbers[2];
			numbers[2] = numbers[1];
			numbers[1] = numbers[5];
		}
		if (numbers[2] > numbers[3])
		{
			numbers[5] = numbers[3];
			numbers[3] = numbers[2];
			numbers[2] = numbers[5];
		}
		if (numbers[3] > numbers[4])
		{
			numbers[5] = numbers[4];
			numbers[4] = numbers[3];
			numbers[3] = numbers[5];
		}
	}

	//rng stars 
	for (int i = 0; i < 2; i++)
	{
		stars[i] = rand() % 12 + 1;
	}

	while (stars[0] == stars[1])
	{
		stars[0] = rand() % 12 + 1;
	}

	if (stars[1] < stars[0])
	{
		stars[2] = stars[1];
		stars[1] = stars[0];
		stars[0] = stars[2];
	}

	//output
	cout << "numbers are: ";
	for (int i = 0; i < 5; i++)
	{
		 cout << numbers[i] << " | ";
	}
	cout << "\nstars are " << stars[0] << " " << stars[1];
}
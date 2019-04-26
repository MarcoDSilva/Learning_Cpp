/* 25/4/2019
by ms
rng array*/

#include<iostream>
#include<locale.h>
#include<time.h>

using namespace std;


int main()
{
	//-- variable --
	int arr[10];

	// --getting rng better --
	srand(time(NULL));
	
	// -- generating 10 random numbers in 50 possible and gives it to the array --
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 50;
	}

	cout << "The array has the following numbers: ";

	// -- loop to show the array after all numbers are RNG'd --
	for (int j = 0; j < 10; j++)
	{
		cout << arr[j] << " | ";
	}

}  
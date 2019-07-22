/* 22/4/2019
by ms
gets X nums, declares the max and min number from those */

#include<iostream>
#include <locale.h>
#include <time.h>
using namespace std;

int main()
{
	//calling pt language for the cmd
	setlocale(LC_ALL, "Portuguese");

	int x, min, max;

	//pseudo RNG
	srand(time(NULL));

	//declaring max and min
	x = rand() % 100;
	max = x;
	min = x;

	//reads 100 numbers and give the min and max
	for (int i = 0; i < 100; i++)
	{
		x = rand() % 1000;

		if (x > max)
		{
			max = x;
		}
		else if (min > x)
		{
			min = x;
		}
	}
	
	cout << "The max number in the series was " << max << " and the min was " << min << "." << endl;
}

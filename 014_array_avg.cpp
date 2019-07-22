/* 25/4/2019
by ms
array playground */

#include<iostream>
#include<locale.h>
using namespace std;


int main()
{
	//getting pt language
	setlocale(LC_ALL, "Portuguese");

	// ---- variables ----
	int arr[10], oddCounter = 0, evenCounter = 0;
	float oddMedia = 0, evenMedia = 0, evenSum = 0, oddSum = 0;

	// ---- initialize array ----
	arr[0] = 1;
	arr[1] = 13;
	arr[2] = 22;
	arr[3] = 98;
	arr[4] = 44;
	arr[5] = 99;
	arr[6] = 19;
	arr[7] = 87;
	arr[8] = 71;
	arr[9] = 39;

	// -- loop to get numbers for calculations --
	for (int i = 0; i < 10; i++)
	{
		// ---- if even number, uploads counter and sums them, else does that for odd ----
		if (arr[i] % 2 == 0)
		{
			evenCounter++;
			evenSum += arr[i];
		}		
		else
		{
			oddCounter++;
			oddSum += arr[i];
		}
	}

	// ---- calculates avg. ----
	oddMedia = oddSum / oddCounter;
	evenMedia = evenSum / evenCounter;

	// ---- outputs ----
	cout << "There are " << oddCounter << " odd numbers , and their average is: " << oddMedia << "\n";
	cout << "There are " << evenCounter << " even numbers, and their average is: " << evenMedia << "\n";
} 

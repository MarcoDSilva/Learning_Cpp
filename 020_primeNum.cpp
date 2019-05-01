/*
01-05-2019
by ms
prime number
*/

#include<iostream>
using namespace std;

int main()
{
	//vars
	int num = 0;
	bool prime = true;

	//input
	cout << "introduce the number to verify if it's a prime one: ";	cin >> num;

	//loop to check if number is prime
	//starts to check the number divided by 2, then goes up 1 by 1 and tries dividing them to see if it's a even number and if isn't
	for (int i = 2; i < num / 2; i++)
	{
		if (num % i == 0)
		{
			prime = false;
			break;
		}
	}

	//return
	if (prime)
	{
		cout << "The number " << num << " is a prime number\n";
	}
	else
	{
		cout << "The number " << num << " is not a prime number\n";
	}
}
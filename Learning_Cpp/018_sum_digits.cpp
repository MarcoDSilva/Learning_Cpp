/* 28/4/2019
by ms
sum of digits */

#include<iostream>
using namespace std;

int main()
{
	// -- variables --
	 long int num, solo_int, sum = 0;
	
	 // -- input --
	 cout << "Please insert number: ";
	 cin >> num;

	 // -- if number is bigger than long int, rejects it --
	if (num > 999999999)
	{
		cout << "Only numbers lower than 999.999.999 are allowed. Thank you!" << endl;
		return 0;
	}

	// -- while number isn't 0, it will take the last digit, and sum it until we loop all possible digits --
	while (num != 0)
	{
		solo_int = num % 10;
		sum = sum + solo_int;

		num = num / 10;
	}

	// -- return the sum --
	cout << "The sum of the digits is: " << sum << endl;
}
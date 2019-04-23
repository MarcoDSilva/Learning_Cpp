/* 23/4/2019
by ms
exponent calculation */

#include<iostream>
using namespace std;

int main()
{
	//vars
	int num, calc, exp;
	
	//inputs 
	cout << "Let's calculate a num with one exponent! Example: 3E10" << endl;
	cout << "Please insert the number you want to multiplicate sucessively: ";	cin >> num;
	cout << "Now insert the exponent: ";	cin >> exp;

	//if exp 0 / if exp and num 0 returns 1
	if (exp == 0)
	{
		cout << "the final number is 1, every number elevated to 0 is 1." << endl;
		return 0;
	}
	else if (num == 0 && exp == 0)
	{
		cout << "the final number is 1, because 0^0 is always 1." << endl;
		return 0;
	}

	//gives calc the same value as num to multiplicate at loop
	calc = num;

	//calculate N times
	for (int i = 1; i < exp; i++)
	{
		calc *= num;
		cout << calc << endl;
	}
	
	//output
	cout << "the result of " << num << "^" << exp << " is " << calc;
		 
}
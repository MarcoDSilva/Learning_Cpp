/* 14-04-2019
by ms
Fahrenheit to Celsius */

#include<iostream>
using namespace std;

int main()
{
	float tempF = 32, celsius;

	cout << "Please insert the temperature in Celsius: ";		cin >> celsius;

	tempF += (9 * celsius) / 5;

	cout << "Temperature in fahrenheit is: " << tempF << endl;
	
}
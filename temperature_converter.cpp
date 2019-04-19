* 19-04-2019
by ms
Celsius x Kelvin x Fahrenheit converter */

#include<iostream>
#include <math.h>
using namespace std;

int main()
{
	string tempActual, tempToConvert;
	double tempF = 32, kelvin = 273.15, total, userTemp;

	//gets input from user, temperature degrees, then what is the conversion the user wants
	cout << "Please insert the temperature number: ";	
	cin >> userTemp;
	cout << "Now insert the temperature you want to pick. 'C' - Celcius, 'K' - Kelvin or 'F' - Fahrenheit\n";
	cin >> tempActual;
	cout << "Now pick the target temperature. C - Celcius, K - Kelvin or F - Fahrenheit\n";	
	cin >> tempToConvert;


	//verifying if the user isn't selecting the same temperature by mistake
	if (tempActual == tempToConvert)
	{
		cout << "You can't convert the temperature " << tempActual << " to the same temperature!\n";
	}

	//celcius to farhenheit formula is | F = 32 + (9 * celcius) / 5
	//celsius to kelvius | one celsius is equal to = 273.15K | formula is celsius = C + 273.15
	if (tempActual == "C" || tempActual == "c")
	{
		if (tempToConvert == "F" || tempToConvert == "f")
		{
			tempF += (9 * userTemp) / 5;
			cout << "Celsius converted to Fahrenheit is: " << tempF;
		}
		else if (tempToConvert == "K" || tempToConvert == "k")
		{
			kelvin += userTemp;
			cout << "Celsius converted to Kelvin is: " << kelvin;
		}
	}

	//farh to celcius | C = f - 32 / 1.8000
	//fahr to kelvin | Kelvin = Fehr + 459.67 * 1.8
	if (tempActual == "F" || tempActual == "f")
	{
		if (tempToConvert == "C" || tempToConvert == "c")
		{
			total = ((userTemp - 32) / 1.8);
			cout << "Fahrenheirt converted to celsius is: " << total;
		}
		else if (tempToConvert == "K" || tempToConvert == "k")
		{
			total = ((userTemp + 459.67) * 5/9);
			cout << "Fahrenheit converted to Kelvin is: " << total;
		}
	}

	//kelvin to celsius is 1 celsius equals -273.15K
	//kelvin to fahrenheit is equal to Kelvin * 9/5 - 459.67
	if (tempActual == "K" || tempActual == "k")
	{
		if (tempToConvert == "C" || tempToConvert == "c")
		{
			total = userTemp - kelvin;
			cout << "Kelvin converted to celsius is: " << total;
		}
		else if (tempToConvert == "F" || tempToConvert == "f")
		{
			total = (userTemp * 9) / 5 - 459.67;
			cout << "Kelvin converted to fahrenheit is: " << total;
		}
	}
	
}
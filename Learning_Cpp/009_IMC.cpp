/* 19-04-2019
IMC calculation*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float weight, height, IMC;

	//asks user for height and weight
	cout << "Please insert your weight: ";	cin >> weight;
	cout << "Please insert your height: ";	cin >> height;

	//calculus
	IMC = (weight / (height * height));

	//checks the value and if the user is between the expected values
	if (IMC <= 18.5)
	{
		cout << "You are underweight and getting a bit more kilos would help. Your IMC value is: " << IMC;
	}
	else if (IMC > 18.5 && IMC <= 25)
	{
		cout << "You have a normal weight. Good job! Your IMC value is: " << IMC;
	}
	else if (IMC > 25 && IMC <= 30)
	{
		cout << "You are above your normal weight. Try to lose some kilos/grams. Your IMC is: " << IMC;
	}
	else
	{
		cout << "You are obese! Go check the doctor right away!! Your IMC is: " << IMC;
	}

}

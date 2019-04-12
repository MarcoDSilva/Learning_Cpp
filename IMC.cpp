//12/04/2019
// IMC calculation

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float weight, height, IMC;

	//asks user for height and weight
	cout << "Please insert your weight: ";		cin >> weight;
	cout << "Please insert your height: ";		cin >> height;

	//calculus
	IMC = (weight / (height * height));

	cout << "Your IMC is: " << IMC << endl;

}
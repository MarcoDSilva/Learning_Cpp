//11-04-19
//made by ms
//comparar

#include <iostream>
using namespace std;

int main()
{
	int x, y, z;

	//ask for the numbers to compare
	cout << "Please insert the first number: ";		cin >> x;
	cout << "Please insert the second number: ";	cin >> y;
	cout << "Please insert the third number: "; 	cin >> z;

	//conditional that compares the numbers between then and returns the biggest or if they are the same value
	if (x > y && x > z)
	{
		cout << x << " is the biggest number between " << x << " and " << y << " and " << z;

	}
	else if (y > z && y > x)
	{
		cout << y << " is the biggest number between " << x << " and " << y << " and " << z;
	}
	else if (z > x && z > y)
	{
		cout << z << " is the biggest number between " << x << " and " << y << " and " << z;
	}
	else
	{
		cout << "All 3 numbers have the same value or 2 are equal and one inferior." << endl;
	}
}

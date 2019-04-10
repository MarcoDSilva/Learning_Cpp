//10-04-2019
//made by ms
// younger or older

#include <iostream>
using namespace std;

int main()
{
	int age;
	cout << "Please insert your age." << endl;
	cin >> age;

	if (age >= 18)
	{
		cout << "You are an adult." << endl;
	}
	else
	{
		cout << "You are a minor." << endl;
	}
}


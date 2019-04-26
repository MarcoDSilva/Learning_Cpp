//date - 10-04-2019
//made by ms
// "graphic representation of the city temperature"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int temp;
	string result;

	//gets degrees from user
	cout << "How many degrees? ";
	cin >> temp;

	cout << temp << endl;


	//while temp is greater than I, checks if it's a odd or even number.
	for (int i = 1; i <= temp; i++)
	{
		
		//if the number mod 2 is even,  adds "#" and if mod 6 is even, adds the space required to groups of 3
		if (i % 2 == 0)
		{
			result = result + "#";
		}
		if (i % 6 == 0)
		{
			result = result + " ";
		}	
	}

	//checks if temperature is odd or even ,if it's odd, it adds the required "+" that means 1.
	if (temp % 2 != 0)
	{
		result = result + "+";
	}

	cout << result << endl;
}

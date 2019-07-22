/* 14-04-2019
by ms
convert hours, mins and secs */

#include<iostream>
using namespace std;

int main()
{
	int seg = 0, min = 0, hour = 0, counter = 0, temporary = 0;

	//gets user input in secs
	cout << "Please insert a number of seconds: ";	cin >> temporary;
	counter = temporary;

	//while temp var is bigger than 0, the loop will happen
	while (temporary > 0)
	{
		if (temporary - 3600 > 0)
		{
			hour += 1;
			temporary -= 3600;
		}
		else if (temporary - 1800 > 0)
		{
			min += 30;
			temporary -= 1800;
		}
		else if (temporary - 900 > 0)
		{
			min += 15;
			temporary -= 900;
		}
		else if (temporary - 300 > 0)
		{
			min += 5;
			temporary -= 300;
		}
		else if (temporary - 120 > 0)
		{
			min += 2;
			temporary -= 120;
		}
		else if (temporary - 60 >= 0)
		{
			min += 1;
			temporary -= 60;
		}
		else
		{
			seg = temporary;
			temporary -= temporary;
		}
	}

	cout << counter << "s = " << hour << "h + " << min << "m + " << seg << "s";
	
}

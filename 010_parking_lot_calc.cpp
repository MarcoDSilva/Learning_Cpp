/* 20/4/2019
ms
parking lot price calc */

#include<iostream>

using namespace std;

int main()
{
	//variaveis
	int hour, min, timeInMins;
	float money = 0;
	bool first, second;

	//input
	cout << "Introduce how much time you have your vehicle parked in hours, then minutes.\n";
	cout << "Hours: ";	cin >> hour;
	cout << "Minutes: "; cin >> min;

	//converts the hour to minutes
	timeInMins = (hour * 60) + min;

	//if user has 2h or 1h, activates the bool for calculation
	if (timeInMins >= 120)
	{
		first = true;
		second = true;
	} else if (timeInMins >= 60)
	{
		first = true;
	}

	//while there is mins remaining it will calculate
	while (timeInMins > 0)
	{
		//if both bools are true, updates money for the first 2 hours (first hour is 2€ and second is 1.5€)
		//if it's only 1h and it's the first , gets 2€ right out of the bat
		//FIX NEEDED: in case the user stays between 1h and 2h, needs to count those
		if (timeInMins >= 120 && first && second)
		{
			money += 3.5;
			timeInMins -= 120;
			first = false;
			second = false;
		} 
		else if (timeInMins >= 60 && first) 
		{
			money += 2;
			timeInMins -= 60;
			first = false;
		}

		//takes the mins remaining and updates money
		if (timeInMins >= 60 && first == false)
		{
			money += 1;
			timeInMins -= 60;
		}

		if (timeInMins >= 30)
		{
			money += 0.50;
			timeInMins -= 30;
		}

		if (timeInMins >= 15)
		{
			money += 0.25;
			timeInMins -= 15;
		}

		if (timeInMins >= 5)
		{
			money += 0.0833;
			timeInMins -= 5;
		}

		if (timeInMins >= 1)
		{
			money += 0.166;
			timeInMins -= 1;
		}
	}

	cout << "\n";
	cout << "You have to pay: " << money << " euros for " << hour << " hours and " << min << " minutes\n";
}

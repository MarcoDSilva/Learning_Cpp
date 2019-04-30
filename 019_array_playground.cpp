/* 30/4/2019
by ms
case_switch*/

#include<iostream>
#include<conio.h>
#include<time.h>

using namespace std;

int main()
{
	// --------------------------------- variables
	char op;
	int array[10], sum, sum_odd, counter_even, counter_odd, max_num, min_num, x;
	float avg, avg_even, avg_odd;

	//------------------------------------------- COMMAND LIST --------------
	cout << "\n\t\t\tPROGRAM THAT MANIPULATES ARRAYS\n";
	cout << "\n\t\t\tCOMMANDS: \n\n\t\t\ti: Starts the array. \n\t\t\tl: Lists the values of the array. \n\t\t\ta: Sum of the elements of the array. \n\t\t\tb: Shows the num of even numbers in an array";
	cout << "\n\t\t\tc: Gives the array elements avg. \n\t\t\td: avg of even numbers \n\t\t\te: compares even and odd numbers avg to check the biggest one\n\t\t\tf: shows the difference between the max and min number";
	cout << "\n\t\t\tg: Generates new values for the array \n\t\t\ts: EXIT\n";


	// --loop while s is not pressed to terminate--
	do
	{

		op = _getch();
		cout << "\n";

		switch (op)
		{

			//----------------------- Starts the array
			case 'i':
					array[0] = 1; 	array[1] = 13;	array[2] = 22;	array[3] = 98;	array[4] = 44;
					array[5] = 99;	array[6] = 19;	array[7] = 87;	array[8] = 71;	array[9] = 39;

					cout << "The array was generated. Press l to check the actual values.\n";
			break;

			//---------------------------  Lists the values of the array
			case 'l':
					for (int i = 0; i < 10; i++)
					{
						cout << array[i] << " | ";
					}
					cout << endl;
			break;

			// ----------------------------- Sum of the elements of the array
			case 'a':
					sum = 0;
					for (int i = 0; i < 10; i++)
					{
						sum += array[i];
					}
					cout << "the sum is: " << sum << endl;
			break;

			//-------------------------------- num of even numbers in an array
			case 'b':
					counter_even = 0;
					for (int i = 0; i < 10; i++)
					{
						if (array[i] % 2 == 0)
						{
							counter_even++;
						}
					}
					cout << "there are " << counter_even << " even nummbers\n";
			break;

			//--------------------------------------- returns the array elements avg
			case 'c':
					avg = 0;
					sum = 0;
					for (int i = 0; i < 10; i++)
					{
						sum += array[i];
					}
					avg = sum / 10;
					cout << "the average is " << avg << "\n";
			break;

			//------------------------------------------ even numbers average
			case 'd':
					counter_even = 0;
					avg_even = 0;
					for (int i = 0; i < 10; i++)
					{
						if (array[i] % 2 == 0)
						{
							avg_even += array[i];
							counter_even++;
						}
					}
					avg_even /= counter_even;
					cout << "the even numbers average is " << avg_even << "\n";
			break;

			//-------------------------- even avg > odd avg?
			case 'e':
					avg_even = 0;
					avg_odd = 0;
					counter_odd = 0;
					counter_even = 0;

					// loops
					for (int i = 0; i < 10; i++)
					{
						if (array[i] % 2 == 0)
						{
							avg_even += array[i];
							counter_even++;
						}
						if (array[i] % 2 != 0)
						{
							avg_odd += array[i];
							counter_odd++;
						}
					}

					//----- gets the avg
					avg_even = avg_even / counter_even;
					avg_odd = avg_odd / counter_odd;

					//checks which of averages is the biggest
					if (avg_even > avg_odd)
					{
						cout << "the avg of even numbers is bigger with " << avg_even << " vs the odd avg with " << avg_odd << endl;
					}
					else
					{
						cout << "the odd avg is bigger with " << avg_odd << " vs the even avg with " << avg_even << endl;
					}
			break;

			//--------------------------------------------- difference between max and min
			case 'f':
					max_num = array[0];
					min_num = array[0];

					for (int i = 0; i < 10; i++)
					{
						if (max_num < array[i])
						{
							max_num = array[i];
						}

						if (min_num > array[i])
						{
							min_num = array[i];
						}
					}
					cout << "the difference between the number " << max_num << " and the number " << min_num << " is " << max_num - min_num << endl;
			break;

				// ----------------------------------------------- generates new values for the array
			case 'g':
					x = 0;
					srand(time(NULL));

					//generates a number between 0 and 100 and applies it to the elements of the array
					for (int i = 0; i < 10; i++)
					{
						x = rand() % 101;

						array[i] = x;
					}

					cout << "A new array was generated, please verify the new values with the key l\n";
			break;

			default:
					if (op != 's')
					{
						cout << "That option is not valid!\n";
					}
			break;
		}

	} while (op != 's');

}

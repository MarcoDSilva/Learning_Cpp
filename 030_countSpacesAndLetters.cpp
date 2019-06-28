//count spaces, uppercase and lowercase letters
//by ms
//28-06-2019

#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

int main()
{
	char s[200];
	int space_counter = 0, lower_case = 0, upper_case = 0;
	cout << "insert: ";
	cin.getline(s,200);
	

	for (int i = 0; i < 199; i++)
	{
		if (s[i] == 32)
		{
			space_counter++;
		}
		if (s[i] > 64 && s[i] < 91)
		{
			upper_case++;
		}
		if (s[i] > 96 && s[i] < 123)
		{
			lower_case++;
		}
		
	}
	cout << "letras pequenas: " << lower_case << "\nletras grandes: " << upper_case << "\nEspacos: " << space_counter << endl;
}

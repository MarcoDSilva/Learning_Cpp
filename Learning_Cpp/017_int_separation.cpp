/* 26/4/2019
by ms
separate an int into it's digits*/

#include<iostream>
#include<string>
using namespace std;


int main()
{
	// -- variables --
	int num;
	
	//-- user input --
	cout << "Insert a number to separate it: ";		cin >> num;

	// -- converting int to string --
	string converted = to_string(num);

	// -- separating the nums --
	for (int i = 0; i < converted.length(); i++)
	{
		cout << converted[i] << " ";
	}
}  

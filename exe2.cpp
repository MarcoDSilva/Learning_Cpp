//program where you pick 2 numbers and show them to the user

#include <iostream>
using namespace std;

int main()
{
	int x, y;
	
	//ask the user for the numbers
	cout << "Please pick the first number: " << endl;
	cin >> x;
	cout << "Please pick the second number: " << endl;
	cin >> y;
	cout << "Your first picked number was " << x << " and your second picked number was " << y << "." << endl;
}
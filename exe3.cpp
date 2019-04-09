//read 2 numbers, sum them, and return to the user

#include <iostream> 
using namespace std;

int main()
{
	int x, y, sum;

	//asking for both nums
	cout << "Please pick the first number to sum" << endl;
	cin >> x;

	cout << "Please pick the second number to finish the sum" << endl;
	cin >> y;

	//sum both nums and return
	sum = x + y;
	cout << "The sum of both numbers is: " << sum << "!" << endl;

}
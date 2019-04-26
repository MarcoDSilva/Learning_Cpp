#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int x, y, hypotenuse;

	//gets user input for both legs and atributes both vars
	cout << "Please insert the values of both triangle legs, where both have to be positive: "; 
	cin >> x;
	cin >> y;

	//theorem is both legs squared equal the hypotenuse
	hypotenuse = pow(x, 2) + pow(y, 2);

	cout << "The hypotenuse is: " << hypotenuse;
	

}

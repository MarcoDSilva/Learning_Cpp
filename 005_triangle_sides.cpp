/* 17-04-2019
by ms
checking triangles sides*/

#include<iostream>
using namespace std;

int main()
{
	int side1, side2, side3;

	//get 3 side inputs
	cout << "Please insert 3 sizes for the sides of the triangle;\n";
	cout << "side1: ";	cin >> side1;
	cout << "side2: ";	cin >> side2;
	cout << "side3: ";	cin >> side3;

	//if all sides are equal it's equilateral, if they are all different it's scalene
	//if A and B are equal (or B and C, or A and C) it's isosceles

	if (side1 == side2 && side2 == side3)
	{
		cout << "equilateral";
	}
	else if (side1 == side2 || side2 == side3 || side1 == side3)
	{
		cout << "isosceles\n";
	}
	else
	{
		cout << "scalene";
	}
}

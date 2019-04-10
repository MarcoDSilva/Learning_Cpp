//10-04-2019
// made by MS
// Calculo Raio

using namespace std;
#include <iostream>
const float pi = 3.1416;

int main()
{
	
	float raio, area;

	cout << "Por favor introduza o raio para o calculo" << endl;
	cin >> raio;

	//calculo raio
	area = raio * raio * pi;

	cout << "A area do raio e: " << area << endl;

}

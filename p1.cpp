/*data: 18-04-2019
feito por Marco Silva
produção 01
*/

#include<iostream>
#include<locale.h>
using namespace std;

int main()
{
	//extras for language
	setlocale(LC_ALL, "Portuguese");

	//variables
	string name1, name2, name3;
	int age1, age2, age3, ageCounter = 0, adultAge = 18;

	//gets user input 
	cout << "Introduza o nome da primeira pessoa: ";	cin >> name1;
	cout << "Introduza a idade da primeira pessoa: ";	cin >> age1;
	cout << "Introduza o nome da segunda pessoa: ";		cin >> name2;
	cout << "Introduza a idade da segunda pessoa: ";	cin >> age2;
	cout << "Introduza o nome da terceira pessoa: ";	cin >> name3;
	cout << "Introduza a idade da terceira pessoa: ";	cin >> age3;

	//checks for the oldest user or users
	if (age1 > age2 && age1 > age3) { 
		cout << "Mais velho: " << name1 << endl; 
	}
	else if (age2 > age3 && age2 > age1) { 
		cout << "Mais velho: " << name2 << endl; 
	}
	else if (age3 > age2 && age3 > age1) { 
		cout << "Mais velho: " << name3 << endl; 
	}
	else if (age1 == age2 && age1 > age3) { 
		cout << "Mais velhos são: " << name1 << " e " << name2 << endl; 
	}
	else if (age2 == age3 && age3 > age1) { 
		cout << "Mais velhos são: " << name2 << " e " << name3 << endl; 
	}
	else if (age1 == age3 && age1 > age2) { 
		cout << "Mais velhos são: " << name1 << " e " << name3 << endl; 
	}
	else {
		cout << "São todos da mesma idade." << endl; 
	}

	//compares if ages are older or equal to 18, and if they are, counter levels up
	if (age1 >= adultAge) { ageCounter++; }
	if (age2 >= adultAge) { ageCounter++; }
	if (age3 >= adultAge) { ageCounter++; }

	//prints the number of people that are of adult age
	cout << "Maioridade: " << ageCounter;
}
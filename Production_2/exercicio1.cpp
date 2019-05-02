/*
Produção 2.
Data: 02-05-2019
Feito por Marco Silva
*/

#include<iostream>
#include<locale.h>
using namespace std;

int main()
{
	//-- lingua portuguesa --
	setlocale(LC_ALL, "Portuguese");

	// -- variables --
	string name = "";
	int bday_year = 0, age = 0;

	// -- inputs --
	cout << "Por favor, introduza o seu nome: ";	cin >> name;
	cout << "Por favor, introduza o seu ano de nascimento: ";	cin >> bday_year;

	// -- logic for age --
	age = 2019 - bday_year;

	// -- outputs --
	cout << "Olá " << name << ", tens " << age << " anos.\n";

}
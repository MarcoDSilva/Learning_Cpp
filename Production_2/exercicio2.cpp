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
	// ---- consola lingua pt ----
	setlocale(LC_ALL, "Portuguese");
	
	// ---- variables ----
	string name;
	int age = 0, payment = 0;
	float tax = 0;

	// ---- inputs -----
	cout << "Insira o seu nome: ";		cin >> name;
	cout << "Insira a sua idade: ";		cin >> age;
	cout << "Insira o valor a pagar: ";		cin >> payment;

	//if < 18, taxa desconto é 10%
	if (age < 18)
	{
		tax = payment * 0.10;
		payment -= tax;

		cout << "Olá " << name << ", tens a pagar " << payment << " euros.\n";
	}
	else if (age > 65)
	{
		tax = payment * 0.20;
		payment -= tax;

		cout << "Olá " << name << ", tens a pagar " << payment << " euros.\n";
	}
	else
	{
		cout << "Olá " << name << ", tens a pagar " << payment << " euros.\n";
	}
}
/* 16-04-2019
made by marco silva
project 0
*/

#include<iostream>
using namespace std;

int main()
{
	int age1, age2;
	string name1, name2;

	//obtém os dados dos utilizadores
	cout << "Insira o nome da primeira pessoa: ";	cin >> name1;

	cout << "Insira a idade da primeira pessoa: ";	cin >> age1;

	cout << "Insira o nome da segunda pessoa: ";	cin >> name2;

	cout << "Insira a idade da primeira pessoa: ";	cin >> age2;

	   
	//compara as idades dos utilizadores
	if (age1 == age2)
	{
		cout << "Mais Velho: Nenhum, pois sao da mesma idade.\n";	
	}
	else if (age1 > age2)
	{
		cout << "Mais velho: " << name1 << endl;
	}
	else
	{
		cout << "Mais velho: " << name2 << endl;
	}

	//verifica se é maior ou menor de idade
	if (age1 >= 18 && age2 >= 18)
	{
		cout << "Maioridade: Ambos\n";
	}
	else if (age1 < 18 && age2 < 18)
	{
		cout << "Maioridade: Nenhum\n";
	}
	else if (age1 >= 18) {
		cout << "Maioridade: " << name1 << endl;
	}
	else
	{
		cout << "Maioridade: " << name2 << endl;
	}
}
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
	int array[5] = { 0,0,0,0,0 }, pares = 0, impares = 0, maiores = 0, menores = 0, primeiro = 0;
	float media = 0;

	// ----------- loop para obter pares, impares e media --------

	cout << "Insira 5 números.\n";
	
	for (int i = 0; i < 5; i++)
	{
		cout << "Insira um número: ";
		cin >> array[i];
		
		// ---- obter pares e impares ----
		if (array[i] % 2 == 0)
		{
			pares++;
			
		}

		if (array[i] % 2 != 0)
		{
			impares++;
		}

		// ---- soma para a media ----
		media += array[i];

	}

	// ---- primeiro para comparar com os restantes e media ----
	primeiro = array[0];
	media /= 5;

	// ---- media e maiores que primeiro
	for (int i = 0; i < 5; i++)
	{
		if (array[i] > primeiro)
		{
			maiores++;
		}

		if (array[i] < media)
		{
			menores++;
		}
	}

	// ----- output ------
	cout << "Existem " << pares << " pares, " << impares << " impares, " << maiores << " maiores que o primeiro, e " << menores << " abaixo da média.\n";

}
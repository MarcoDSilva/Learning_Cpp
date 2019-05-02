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
	
	// ---- variaveis ----
	int contador = 0, positivos[5] = { 0,0,0,0,0 };
	float media = 0;

	// ---- input 5 numeros para array ----

	cout << "Insira 5 números, irá lhe ser retornada a média dos números positivos.\n";

	for (int i = 0; i < 5; i++)
	{
		cout << "Insira um número: ";
		cin >> positivos[i];
	}

	// ---- soma positivos e aumenta contador para calcular media ----
	for (int i = 0; i < 5; i++)
	{
		if (positivos[i] > 0)
		{
			media += positivos[i];
			contador++;
		}
	}

	// ---- calcular a media dos positivos e retorna a mesma ao utilizador ----
	if (contador >= 1)
	{
		media /= contador;
		cout << "A média dos números positivos inseridos é: " << media << "\n";
	}
	else
	{
		cout << "Nenhum número positivo foi inserido.\n";
	}
}
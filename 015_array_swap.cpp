/* 25/4/2019
by ms
array swap */

#include<iostream>
#include<locale.h>
using namespace std;

int main()
{
	//getting pt language
	setlocale(LC_ALL, "Portuguese");

	// ---- variables ----
	int arr[10], temp1, temp2, swapper;

	// ---- initialize array ----
	arr[0] = 1;
	arr[1] = 13;
	arr[2] = 22;
	arr[3] = 98;
	arr[4] = 44;
	arr[5] = 99;
	arr[6] = 19;
	arr[7] = 87;
	arr[8] = 71;
	arr[9] = 39;

	//---- ler 2 posições ----
	cout << "Por favor insira 2 números para verificar e efectuar a troca na array. \n";
	cin >> temp1 >> temp2;

	cout << "Na posição " << temp1 << " temos o número " << arr[temp1] << " e na posição " << temp2 << " o digito " << arr[temp2] << endl;

	//---- trocar o conteudo das mesmas na array ----
	// - swapper guarda o número original arr[pos1] dada pelo user, para a pos1 ficar com o número da array 2
	// e no final, a arr2 vai buscar o número da pos1 , que está a ser guardada pela variavel swapper -
	swapper = arr[temp1];
	arr[temp1] = arr[temp2];
	arr[temp2] = swapper;

	//mostrar array para confirmar a troca
	cout << "Abaixo segue a array com os valores actualizados. \n";

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
} 

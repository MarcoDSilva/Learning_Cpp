// swaping arrays of chars
// ms
//28-06-2019

#include <iostream>
using namespace std;
int main()

{
	int conta_chars = 0;
	char frase[21] = "Curso de programacao";
	char frase2[21];
	int tamanho = 19;
	bool finished = false;


	while (conta_chars < 3)
	{
		frase2[conta_chars] = frase[conta_chars];
		conta_chars += 1;
	}

	while (tamanho > 2)
	{
		frase2[conta_chars] = frase[tamanho];
		conta_chars += 1;
		tamanho -=1 ;
	}
	frase2[20] = '\0';
	cout << frase2;
}


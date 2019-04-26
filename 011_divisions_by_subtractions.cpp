/* 22/4/2019
by ms
divisão através de subtracções sucessivas */

#include<iostream>
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Portuguese");

	//variaveis 2 ints para dividir, contador, temp
	int divisor, dividendo, resultado, holder_divisor = 0;
	bool calculo = true;

	//inputs
	cout << "Subtrações sucessivas entre inteiros (Divisor/Dividendo)" << endl;
	cout << "Por favor insira o dividendo: ";	cin >> dividendo;
	cout << "Por favor insira o divisor: ";		cin >> divisor;

	//se o dividendo for 0, é indefinido
	if (dividendo <= 0)
	{
		cout << "Operação matemática indefinida, escolha um dividendo maior que 0 da próxima vez";
		return 0;
	}


	//enquanto o resultado é maior ao dividendo, subtrai os numeros entre si.
	do 
	{
		if (!calculo)
		{
			holder_divisor = resultado;
			resultado = resultado - dividendo;
			cout << holder_divisor << " - " << dividendo << " = " << resultado << endl;
		}
		else
		{
			resultado = divisor - dividendo;
			cout << divisor << " - " << dividendo << " = " << resultado << endl;
			calculo = false;
		}

	} while (resultado >= dividendo);

}

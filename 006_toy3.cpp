//18-04-19
//by ms
//toy 3 - 

#include<iostream>
#include<time.h>
#include<locale.h>

using namespace std;

int main()
{
	//language extras
	setlocale(LC_ALL, "Portuguese");

	int x, answer, counter = 0;

	//pseudo RNG
	srand(time(NULL));

	//generating until 100
	x = rand() % 100 + 1; 

	//input
	cout << "Tentar adivinhar número (entre 0 e 100)" << endl;

	
	//while the answer isn't correct, keeps prompting the user and giving hints about the result
	do {
		cout << "Número?" << endl;
		cin >> answer;

		//warns the user only numbers between 1 and 100 are accepted
		if (answer > 100 || answer < 1) cout << "Apenas números entre 1 e 100 são validos.\n";

		if (answer == x)
		{
			cout << "Acertou em " << counter << " tentativas.\n";

		}
		else if (answer > x)
		{
			cout << "Tentar para baixo...\n";
			counter++;
		}
		else
		{
			cout << "Tentar para cima...\n";
			counter++;
		}

	} while (answer != x);

	cout << "\nNOTA: o número gerado pelo sistema foi o " << x << ".\n";
}

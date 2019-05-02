#include<iostream>
#include<string>
using namespace std;

int main()
{
	string board[3][3];

	//do while enquanto a boolen vitoria não for true
	//pedir input ao user e devolver onde foi posta a opção
	// 3 por 3, onde as coordenadas são A0, A1, A2, B0, B1, B2, C0, C1, C2
	// opção X e O, 1x por utilizador (turno par vs turno impar)
	//caso uma das opções preencha uma linha ou uma coluna, passar a boolean da vitoria para true

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			if (j % 2 == 0)
			{
				board[i][j] = "x";
			}
			else
			{
				board[i][j] = "O";
			}
			
		}
	}

	for (int i = 0; i < 3; i++)
	{
		
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << "|";
		}
		cout << "\n";
	}
	
}
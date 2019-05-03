#include<iostream>
#include<string>
using namespace std;

int main()
{
	//---- variables ----
	string board[3][3], player1 = "", player2 = "", playerOption1 = "", playerOption2 = "";
	bool victory = false, draw = false;
	int turn = 0;


	//nomes jogadores
	cout << "Insira nome do jogador 1: ";	cin >> player1;
	cout << "Insira nome do jogador 2: ";	cin >> player2;

	//do while enquanto a boolen vitoria não for true
	//pedir input ao user e devolver onde foi posta a opção
	// 3 por 3, onde as coordenadas são A0, A1, A2, B0, B1, B2, C0, C1, C2
	// opção X e O, 1x por utilizador (turno par vs turno impar)
	//caso uma das opções preencha uma linha ou uma coluna, passar a boolean da vitoria para true


	//cria a board em 3 x 3 e passa a coordenada de Y
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0)
			{
				board[i][j] = "A";
			}
			else if (i == 1)
			{
				board[i][j] = "B";
			}
			else if (i == 2)
			{
				board[i][j] = "C";
			}



		}
	}

	//desenha a tabela e mostra a coordenada de X
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << j << " |";
		}
		cout << "\n";
	}



}

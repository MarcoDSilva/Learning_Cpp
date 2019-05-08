#include<iostream>
#include<string>
#include<time.h>
using namespace std;

// ---------------------- functions ----------------
int primeiroTurno();

int main()
{
	//---- variables ----
	string board[3][3] = { "1","2","3","4","5","6","7","8","9"};
	string x = "X", o = "O", player1 = "", player2 = "";
	bool victory = false, draw = false, jogadorX = false;
	int turn = primeiroTurno(), playerChoice = 0;
	

	//-------------------------------- nomes jogadores
	cout << "Insira nome do jogador 1: ";	cin >> player1;
	cout << "\nBem vindo jogador/a " << player1 << ".\n";
	cout << "Insira nome do jogador 2: "; cin >> player2;
	cout << "\nBem vindo jogador/a " << player2 << ".\n";
	cout << "Jogador/a " << player1 << " vai utilizar " << x << " e jogador/a " << player2 << " vai utilizar " << o << "\n\n";
	cout << "Exemplo da tabela de jogo em baixo. \nCada jogador escolhe um número por turno, de 1 a 9, e a respectiva marca irá aparecer. \nBoa sorte jogadores!\n\n\n";

	//--------------------------------- desenha a tabela
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			
			cout << board[i][j] << "|";
		}

		cout << "\n";
	}

	//do while enquanto a boolen vitoria não for true
	do
	{
		//verificação de turno para chamar o jogador correspondente
		if (turn % 2 == 0)
		{
			cout << player1 << " escolha a jogada que quer efectuar.";
			cin >> playerChoice;
			jogadorX = true;
		}
		else
		{
			cout << player2 << " escolha a jogada que quer efectuar.";
			cin >> playerChoice;
			jogadorX = false;
		}

		//logica para receber jogada
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (playerChoice == 1 || playerChoice == 2 || playerChoice == 3)
				{
					if (jogadorX)
					{
						board[0][playerChoice - 1] = x;
					}
					else
					{
						board[0][playerChoice - 1] = o;
					}
				}
				else if (playerChoice == 4 || playerChoice == 5 || playerChoice == 6)
				{
					if (jogadorX)
					{
						board[1][playerChoice - 4] = x;
					}
					else
					{
						board[1][playerChoice - 4] = o;
					}
				}
				else if (playerChoice == 7 || playerChoice == 8 || playerChoice == 9)
				{
					if (jogadorX)
					{
						board[2][playerChoice - 7] = x;
					}
					else
					{
						board[2][playerChoice - 7] = o;
					}
				}
			}
			turn++; //actualizar turno
		}
		// update tabela
		for (int i = 0; i < 3; i++)
		{
			cout << "|";
			for (int j = 0; j < 3; j++)
			{

				cout << board[i][j] << "|";
			}

			cout << "\n";
		}

	} while (!victory || turn < 9);
	


	//pedir input ao user e devolver onde foi posta a opção

	// opção X e O, 1x por utilizador (turno par vs turno impar)
	//caso uma das opções preencha uma linha ou uma coluna, passar a boolean da vitoria para true

	
}

// ----------------------- rng para escolher o primeiro jogador a actuar -----------------
int primeiroTurno()
{
	int turn;
	srand(time(NULL));

	turn = rand() % 2;

	return turn;
}
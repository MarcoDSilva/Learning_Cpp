#include<iostream>
#include<string>
#include<time.h>
using namespace std;

const int MAX_SIZE = 3;

// ---------------------- functions ----------------
int primeiroTurno();
bool finder(bool victory);

int main()
{
	//---- variables ----
	char board[MAX_SIZE][MAX_SIZE] = { '1','2','3','4','5','6','7','8','9' }, x = 'X', o = 'O';
	string player1 = "", player2 = "";
	bool victory = false, draw = false, jogadorX = false;
	int turn = 1, playerChoice = 0;

	//-------------------------------- nomes jogadores
	cout << "Insira nome do jogador 1: ";	cin >> player1;
	cout << "Bem vindo jogador/a " << player1 << ".\n";
	cout << "Insira nome do jogador 2: "; cin >> player2;
	cout << "Bem vindo jogador/a " << player2 << ".\n";
	cout << "Jogador/a " << player1 << " vai utilizar " << x << " e jogador/a " << player2 << " vai utilizar " << o << "\n\n";
	cout << "Exemplo da tabela de jogo em baixo. \nCada jogador escolhe um número por turno, de 1 a 9, e a respectiva marca irá aparecer. \nBoa sorte jogadores!\n\n\n";

	//--------------------------------- desenha a tabela
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << "|";
		for (int j = 0; j < MAX_SIZE; j++)
		{

			cout << board[i][j] << "|";
		}
		cout << "\n";
	}

	//do while enquanto a boolen vitoria/empate não for verdadeira
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

		//impedir jogador de jogar no mesmo spot

		//logica para receber jogada
		for (int i = 0; i < MAX_SIZE; i++)
		{
			for (int j = 0; j < MAX_SIZE; j++)
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
				if (playerChoice == 4 || playerChoice == 5 || playerChoice == 6)
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
				if (playerChoice == 7 || playerChoice == 8 || playerChoice == 9)
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
		}

		// ----------------------------- update tabela para utilizador após jogada
		for (int i = 0; i < MAX_SIZE; i++)
		{
			cout << "|";
			for (int j = 0; j < MAX_SIZE; j++)
			{

				cout << board[i][j] << "|";
			}

			cout << "\n";
		}

		turn = turn + 1; //actualizar turno

		//caso uma das opções preencha uma linha ou uma coluna, passar a boolean da vitoria para true
		if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && (board[0][0] != '1'))
		{
			victory = finder(victory);
		}
		else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && (board[1][0] != '4'))
		{
			victory = finder(victory);
		}
		else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && (board[2][0] != '7'))
		{
			victory = finder(victory);
		}
		else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && (board[0][0] != '1'))
		{
			victory = finder(victory);
		}
		else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && (board[0][1] != '2'))
		{
			victory = finder(victory);
		}
		else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && (board[0][2] != '3'))
		{
			victory = finder(victory);
		}
		else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[0][0] != '1'))
		{
			victory = finder(victory);
		}
		else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[0][2] != '3'))
		{
			victory = finder(victory);
		}

		//-------------------------------------- checking moves and win condition
		if (turn > 9 && !victory)
		{
			draw = true;
		}

	} while (!victory && !draw);
}

// ----------------------- rng para escolher o primeiro jogador a actuar -----------------
int primeiroTurno()
{
	int turn;
	srand(time(NULL));

	turn = rand() % 2;

	return turn;
}

bool finder(bool victory)
{
	victory = true;
	cout << "Vencedor encontrado!\n\n";
	return victory;
}
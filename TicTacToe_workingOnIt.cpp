//TIC TAC TOE - NEEDS TO BE REFACTORED AFTER FINISH IT

#include<iostream>
#include<string>
#include<time.h>
using namespace std;

const int MAX_SIZE = 3;

// ---------------------- functions ----------------
int primeiroTurno();
bool finder(bool victory);
void winCheck();
char playerPick(bool player, char play);
void crossOrO(int play, char move);
void boardUpdated();

//------ global vars for test ----
char board[MAX_SIZE][MAX_SIZE] = { '1','2','3','4','5','6','7','8','9' };
bool victory = false, draw = false;

int main()
{
	//---- variables ----
	string player1 = "", player2 = "";
	char play = ' ';
	bool jogadorX = false;
	int turn = 1, playerChoice = 0;

	//-------------------------------- nomes jogadores
	cout << "Insira nome do jogador 1: ";	cin >> player1;
	cout << "Bem vindo jogador/a " << player1 << ".\n";
	cout << "Insira nome do jogador 2: "; cin >> player2;
	cout << "Bem vindo jogador/a " << player2 << ".\n";
	cout << "Jogador/a " << player1 << " vai utilizar X e jogador/a " << player2 << " vai utilizar O \n\n";
	cout << "Exemplo da tabela de jogo em baixo. \nCada jogador escolhe um número por turno, de 1 a 9, e a respectiva marca irá aparecer. \nBoa sorte jogadores!\n\n\n";

	//brings the board
	boardUpdated();

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

		//pickingPlay
		play = playerPick(jogadorX, play);

		//logica para receber jogada
		for (int i = 0; i < MAX_SIZE; i++)
		{
			for (int j = 0; j < MAX_SIZE; j++)
			{
				crossOrO(playerChoice, play);
			}
		}

		// shows updated board and checks the winning condition after the user move
		boardUpdated();
		winCheck();
		turn = turn + 1;

		//checks turns and draw
		if (turn > 9 && !victory)
		{
			draw = true;
			cout << "it's a draw!!!\n";
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

//shows board
void boardUpdated()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << "|";
		for (int j = 0; j < MAX_SIZE; j++)
		{

			cout << board[i][j] << "|";
		}

		cout << "\n";
	}
}

//returns that a winner was found
bool finder(bool victory)
{
	victory = true;
	cout << "Vencedor encontrado!\n\n";
	return victory;
}

//checks winning condition
void winCheck()
{
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
}

//picks the player correct corresponding character
char playerPick(bool playerX, char play)
{
	bool px = playerX;
	char pC = play;
	if (px)
	{
		pC = 'X';
	}
	else
	{
		pC = 'O';
	}
	return pC;
}


//puts the option in the right position
void crossOrO(int play, char move)
{
	int playerChoice = play;
	char mo = move;

	if (playerChoice >= 1 && playerChoice <= 3)
	{
		board[0][playerChoice - 1] = mo;
	}
	if (playerChoice >= 4 && playerChoice <= 6)
	{
		board[1][playerChoice - 4] = mo;
	}
	if (playerChoice >= 7 && playerChoice <= 9)
	{
		board[2][playerChoice - 7] = mo;
	}
}

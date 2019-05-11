//TIC TAC TOE - NEEDS TO BE REFACTORED AFTER FINISH IT

#include<iostream>
#include<string>
#include<time.h>
using namespace std;

//constant for board max size in both axis
const int MAX_SIZE = 3;

// ---------------------- functions ----------------
bool finder(bool victory);
void winCheck();
char playerPick(bool player);
void crossOrO(int play, char move);
void boardUpdated();
int turnChecker(int turn, bool playerTurn, string firstPlayer, string secondPlayer);
void placementVerification(int pick);


//------ global vars for test ----
char board[MAX_SIZE][MAX_SIZE] = { '-','-','-','-','-','-','-','-','-' };
bool victory = false, draw = false, playerXcross = false;

int main()
{
	//---- variables ----
	string player1 = "", player2 = "";
	char play = ' ';
	int turn = 1, playerChoice = 0;

	//-------------------------------- player names
	cout << "Insert name - player 1: ";	cin >> player1;
	cout << "Welcome player " << player1 << ".\n";
	cout << "Insert name - player 2: "; cin >> player2;
	cout << "Welcome player " << player2 << ".\n";
	cout << "Player " << player1 << " will be the one with the X plays and player " << player2 << " will use the O play.\n\n";
	cout << "Board example below. \nEach player picks his coordinate from 1 to 9 and the respective play will be marked. (X or O) \nGood luck players!\n\n\n";

	//brings the board
	boardUpdated();

	//until no winner/draw is reached, the game will continue (9 turns max)
	do
	{
		//verifies which turn is and calls the corresponding user
		playerChoice = turnChecker(turn, playerXcross, player1, player2);

		//pickings the play from user
		play = playerPick(playerXcross);

		//loop the matrix and makes the play
		for (int i = 0; i < MAX_SIZE; i++)
		{
			for (int j = 0; j < MAX_SIZE; j++)
			{
				crossOrO(playerChoice, play);
			}
		}

		// shows the updated board and verifies if the winning condition after the user move was reached
		boardUpdated();
		winCheck();
		turn = turn + 1;

		//checks if enough turns were played and the winning condition , to finish the game in case a draw happened
		if (turn > 9 && !victory)
		{
			draw = true;
			cout << "it's a draw!!!\n";
		}
	} while (!victory && !draw);
}

//shows board
void boardUpdated()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << "\t|";
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
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
			{
				victory = finder(victory);
				break;
			}
		}
	}

	//caso uma das opções preencha uma linha ou uma coluna, passar a boolean da vitoria para true
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && (board[0][0] != '-'))
	{
		victory = finder(victory);
	}
	else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && (board[0][1] != '-'))
	{
		victory = finder(victory);
	}
	else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && (board[0][2] != '-'))
	{
		victory = finder(victory);
	}
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[0][0] != '-'))
	{
		victory = finder(victory);
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[0][2] != '-'))
	{
		victory = finder(victory);
	}
}

//returns the mark after the user picks his move. 
char playerPick(bool playerX)
{
	bool playerIsXorO = playerX;
	char playMark = ' ';
	if (playerIsXorO)
	{
		playMark = 'X';
	}
	else
	{
		playMark = 'O';
	}
	return playMark;
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

//verifies which turn is and calls the right user to make his move
int turnChecker(int turn, bool playerTurn, string firstPlayer, string secondPlayer)
{
	int turnCheck = turn, playerChoice = 0;
	string player1 = firstPlayer, player2 = secondPlayer;

	if (turn % 2 == 0)
	{
		cout << player1 << " pick the move you want to make.";
		cin >> playerChoice;
		playerXcross = true;
	}
	else
	{
		cout << player2 << " pick the move you want to make.";
		cin >> playerChoice;
		playerXcross = false;
	}
	return playerChoice;
}

// verifies if the user choice is available
void placementVerification(int pick)
{

}
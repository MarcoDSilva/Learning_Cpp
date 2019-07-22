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
void playPlacement(int play, char move);
void boardUpdated();
int playerTurn(bool playerTurn);
void placementVerification(int pick);


//------ global vars for test ----
char board[MAX_SIZE][MAX_SIZE] = { '-','-','-','-','-','-','-','-','-' };
bool victory = false, draw = false, firstPlayer = false;
string player1 = "", player2 = "";
int turn = 1;

int main()
{
	//---- variables ----
	char play = ' ';
	int playerChoice = 0;

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
		//verifies which turn is and calls the corresponding user | verifies if the play is available | gets the correct mark from that user
		playerChoice = playerTurn(firstPlayer);
		play = playerPick(firstPlayer);

		//UPDATES THE BOARD WITH THE PLAY MADE BY THE USER
		for (int i = 0; i < MAX_SIZE; i++)
		{
			for (int j = 0; j < MAX_SIZE; j++)
			{
				playPlacement(playerChoice, play);
			}
		}

		// shows the updated board and verifies if the winning condition after the user move was reached
		boardUpdated();
		winCheck();
		turn++;

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
	if (firstPlayer)
	{
		cout << player1 << " wins!\n\n";
	}
	else
	{
		cout << player2 << " wins!\n\n";
	}
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

	//if columns or diagonals are all the same mark, returns true to the win condition
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
	char playMark = ' ';
	if (playerX)
	{
		playMark = 'X';
	}
	else
	{
		playMark = 'O';
	}
	return playMark;
}

//places the mark X or O in the position defined by the user
void playPlacement(int play, char move)
{
	if (play >= 1 && play <= 3)
	{
		board[0][play - 1] = move;
	}
	if (play >= 4 && play <= 6)
	{
		board[1][play - 4] = move;
	}
	if (play >= 7 && play <= 9)
	{
		board[2][play - 7] = move;
	}
}

//verifies which turn is and calls the right user to make his move
int playerTurn(bool playerTurn)
{
	int playerChoice = 0;

	if (turn % 2 == 0)
	{
		cout << player1 << " make your move: ";
		cin >> playerChoice;
		firstPlayer = true;
	}
	else
	{
		cout << player2 << " make your move: ";
		cin >> playerChoice;
		firstPlayer = false;
	}
	placementVerification(playerChoice);
	return playerChoice;
}

// verifies if the user choice is available
void placementVerification(int pick)
{
	if (pick >= 1 && pick <= 3)
	{
		if (board[0][pick - 1] != '-')
		{
			cout << "Option already in use, please pick another option!\n";
			playerTurn(turn);
		}
	}
	else if(pick >= 4 && pick <= 6)
	{
		if (board[1][pick - 4] != '-')
		{
			cout << "Option already in use, please pick another option!\n";
			playerTurn(turn);
		}
	}
	else if (pick >= 7&& pick <= 9)
	{
		if (board[2][pick - 7] != '-')
		{
			cout << "Option already in use, please pick another option!\n";
			playerTurn(turn);
		}
	}
}

// tic tac toe
// made by ms
// 09-05-19

#include<iostream>
#include<conio.h>
using namespace std;

const int MAX_SIZE = 3;

//functions
void menu();
void draw();
void exampleCoordinates();
void checker(char picked, bool playerO);
void winCheck();
bool finder(bool victory);
string name (string name1);
string name2(string name2);

//global var for board
char board[MAX_SIZE][MAX_SIZE] = {'1','2','3','4','5','6','7','8','9'};

int main()
{
	char key_press;
	string player1= "", player2 = "";
	int turn = 1, playerChoice = 0;
	bool playerO = false, victory = false, tied = false;
	
	//---- name inputs ---
	player1 = name(player1);
	player2 = name2(player2);
	cout << "welcome player " << player1 << " and player " << player2 << "\n\n";
	cout << player1 << " uses X and player " << player2 << " uses O. When asked, pick the coordinate belonging to the place in the board\n";

	menu();

	do
	{
		key_press = _getch();

		switch (key_press)
		{
		// ---- show coordinates ---
		case 'c':
		case 'C':
			exampleCoordinates();
			break;

			
		// ---- starts game ----
		case 'p':
		case 'P':
			
			do
			{
				if (turn % 2 == 0)
				{
					cout << player2 << " it's your turn to pick!";
					cin >> playerChoice;
					playerO = true;
				}
				else
				{
					cout << player1 << "it's your turn to pick!";
					cin >> playerChoice;
					playerO = false;
				}

				checker(playerChoice, playerO);

			} while (!victory && !tied);

			break;

		// --- shows board ----
		case 's':
		case 'S':
			draw();
			break;

		// ---- starts new game ---
		case 'n':
		case 'N':
			cout << "N is here\n";
			break;

		// ----- Menu here ----
		case 'm':
		case 'M':
			menu();
			break;

		// --- if anything else fails ---
		default:
			if (key_press != 27) 
			{
				cout << "wrong keys are being pressed, calm down! Press M to check menu options!\n";
			}
		}
	} while (key_press != 27);
}

//------------- MENU ---------
void menu()
{
	cout << "\nWelcome to the tic tac toe game!\n";
	cout << "C - Shows Coordinates\n";
	cout << "P - Play Game\n";
	cout << "S - Show board\n";
	cout << "N - New Game\n";
	cout << "ESC - Terminate the program\n";
	cout << "\n\n";
}
//---- draws board ----
void draw()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << board[i][j] << "|";
		}
		cout << "\n";
	}
}

void exampleCoordinates()
{
	char example[3][3] = { '1','2','3','4','5','6','7','8','9'};
	cout << "\n";

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << example[i][j] << "|";
		}
		cout << "\n";
	}
}

// ----------- names -----------
string name (string name1)
{
	cout << "Jogador 1 insira o seu nome: ";
	cin >> name1;
	return name1;
}

string name2(string name2)
{
	cout << "Jogador 2 insira o seu nome: ";
	cin >> name2;
	return name2;
}

//array checker
void checker(char picked, bool playerO)
{
	char play = ' ';

	if (playerO == false)
	{
		play = 'X';
	}
	else
	{
		play = 'O';
	}
	switch (picked)
	{
	case 1:
		if (board[0][0] != 'X' && board[0][0] != 'O')
		{
			board[0][0] = play;
		}
		break;
	case 2:
		if (board[0][1] != 'X' && board[0][1] != 'O')
		{
			board[0][1] = play;
		}
		break;
	case 3:
		if (board[0][2] != 'X' && board[0][2] != 'O')
		{
			board[0][2] = play;
		}
		break;
	case 4:
		if (board[1][0] != 'X' && board[1][0] != 'O')
		{
			board[1][0] = play;
		}
		break;
	case 5:
		if (board[1][1] != 'X' && board[1][1] != 'O')
		{
			board[1][1] = play;
		}
		break;
	case 6:
		if (board[1][2] != 'X' && board[1][2] != 'O')
		{
			board[1][2] = play;
		}
		break;
	case 7:
		if (board[2][0] != 'X' && board[2][0] != 'O')
		{
			board[2][0] = play;
		}
		break;
	case 8:
		if (board[2][1] != 'X' && board[2][1] != 'O')
		{
			board[2][1] = play;
		}
		break;
	case 9:
		if (board[2][2] != 'X' && board[2][2] != 'O')
		{
			board[2][2] = play;
		}
		break;
	default:
		cout << "only numbers 1 to 9!!!\n";
		break;
	}
}

//winning checker
void winCheck()
{
	bool victory = false;

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

bool finder(bool victory)
{
	victory = true;
	cout << "Vencedor encontrado!\n\n";
	return victory;
}
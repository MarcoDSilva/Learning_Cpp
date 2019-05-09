//produção 3
//09-05-2019
//caça ao tesouro

#include<iostream>
#include<conio.h>
#include<time.h>
#include<locale.h>
using namespace std;

const int MAX_SIZE = 5;

// ------ functions ----
void new_bomb();
void new_treasure();
void menu();
void show_board();
void clear_board();
void searcher(char x);

// ----- global matrix ---
char board[MAX_SIZE][MAX_SIZE] = {};

int main()
{
	//---consola lingua portuguesa ----
	setlocale(LC_ALL, "Portuguese");

	srand(time(NULL)); //pseudo random

	//-----variaveis ---------
	char key;

	menu();

	// ------------------------------- PROGRAMA MAIN ------------------------
	do 
	{
		key = _getch();
		switch (key)
		{
		//------------------ listar --------------
		case 'l':
		case 'L':
			show_board();
			break;

		// -------------- nova bomba -------------
		case 'b':
		case 'B':
			new_bomb();
			break;

		// --------------- limpa a matriz --------
		case 'c':
		case 'C':
			clear_board();
			break;

		// -------------- jogar -----------------
		case 'j':
		case 'J':
			cout << "\nfunção ainda em construção\n";
			break;

		//------------- novo tesouro -----------
		case 't':
		case 'T':
			new_treasure();
			break;

		// ---------------- invoca o menu
		case 'm':
		case 'M':
			menu();
			break;
		// ---------------- reservadas
		case 'x':
		case 'X':
			cout << "RESERVADO\n";
			break;

		// ---------------- reservadas
		case 'y':
		case 'Y':
			cout << "RESERVADO\n";
			break;

		// ---------------- reservadas
		case 'z':
		case 'Z':
			cout << "RESERVADO\n";
			break;

		//--- if all else fails ---
		default:
			if (key != 27)
			{
				cout << "\nopção não reconhecida! Pressione M para ver as opções.\n";
			}
		}
	} while (key != 27);

}

// ------- menu -------
void menu()
{
	cout << "\nBem vindo à busca do tesouro explosivo!\n";
	cout << "-------------------------------------------\n";
	cout << "Opção L - lista o mapa.\n";
	cout << "Opção J - iniciar o jogo.\n";
	cout << "Opção C - limpa a matriz\n";
	cout << "Opção T - move o tesouro para uma nova posição.\n";
	cout << "Opção B - move a bomba para uma nova posição.\n";
	cout << "Opção M - mostra o menu das opções\n";
	cout << "Opção X - reservado\n";
	cout << "Opção Y - reservado\n";
	cout << "Opção Z - reservado\n";
	cout << "Opção ESC - termina o jogo.\n";
	cout << "-------------------------------------------\n";
}

// ------ cria uma bomba nova ------
void new_bomb()
{
	int x, y;
	x = rand() % 5;
	y = rand() % 5;

	//looks for the bomb in the matrix, if finds one, removes it
	searcher('B');

	//condição caso a board tenha um T ou um B no sitio, caso contrário, a função chama-se as si própria para inserir a bomba
	if ((board[x][y] != 'T') && (board[x][y] != 'B'))
	{
		board[x][y] = 'B';
	}
	else
	{
		new_bomb();
	}
	cout << "A bomba mudou de sítio. Alah esteja consigo!\n";
}

// ------ cria um tesouro novo -------
void new_treasure()
{
	int x, y;
	x = rand() % 5;
	y = rand() % 5;

	//looks for the treasure in the matrix, if finds one, removes it
	searcher('T');

	//condição caso a board tenha um T ou um B no sitio, caso contrário, a função chama-se a si própria para inserir o tesouro
	if ((board[x][y] != 'B') && (board[x][y] != 'T'))
	{
		board[x][y] = 'T';
	}
	else
	{
		new_treasure();
	}
	cout << "O tesouro foi alterado de sítio. Boa procura!\n";
}

// ----- mostra o tabuleiro de jogo ao utilizador ------
void show_board()
{
	cout << "  0 1 2 3 4\n";

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << i << "|";
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << board[i][j] << "|";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

// ----- percorre a matriz e limpa os valores das jogadas para os valores iniciais -----
void clear_board()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			board[i][j] = ' ';
		}
	}
	cout << "O tabuleiro de jogo foi limpo. Pode inserir novo tesouro/bomba e boa sorte!\n";
}

// ----- procura na matriz um caractér e remove-o (caso seja bomba/tesouro/outro) -----
void searcher(char x)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (board[i][j] == x)
			{
				board[i][j] = ' ';
			}
		}
	}
}

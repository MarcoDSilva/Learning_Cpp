// by Marco Silva
//09-05-2019 e 14-05-2019
//caça ao tesouro - produção 3

#include<iostream>
#include<conio.h>
#include<time.h>
#include<locale.h>
#include<stdlib.h>
using namespace std;

// ---- maximo da matriz, podendo assim ser alterado à vontade do freguês para conforto máximo
const int MAX_SIZE = 5;

// ------ functions ----
void new_bomb();
void new_treasure();
void menu();
void show_board();
void clear_board();
void searcher(char x);
void umaTentativa();
void tresTentativas();
void pesquisa_board(int x, int y);
void ultimate_survival();

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

		// ------------ limpa a consola
		case 'n':
		case 'N':
			system("CLS");
			menu();
			break;

		// ---------------- Da uma tentativa ao utilizador para acertar na bomba/tesouro/em nada
		case 'x':
		case 'X':
			umaTentativa();
			break;

		// ---------------- O utilizador tem tres tentativas, apos a terceira, retorna onde o utilizador acertou/falhou
		case 'y':
		case 'Y':
			tresTentativas();
			break;

		// ---------------- jogar até acertar no tesouro ou bomba.
		case 'z':
		case 'Z':
			ultimate_survival();
			break;

		//--- if all else fails ---
		default:
			if (key != 27)
			{
				cout << "\nopção inválida! Pressione M para ver as opções ou N para limpar o ecrã e trazer o Menu.\n";
			}
		}
	} while (key != 27);

}

// ------- menu -------
void menu()
{
	cout << "\nBem vindo à busca do tesouro explosivo!\n";
	cout << "-------------------------------------------\n";
	cout << "Opção L - Lista o mapa.\n";
	cout << "Opção C - Limpa a matriz\n";
	cout << "Opção T - Move o tesouro para uma nova posição.\n";
	cout << "Opção B - Move a bomba para uma nova posição.\n";
	cout << "Opção M - Mostra o menu das opções\n";
	cout << "Opção N - Limpa a consola\n";
	cout << "Opção X - Ler uma tentativa de jogo.\n";
	cout << "Opção Y - Ler 3 tentativas de jogo.\n";
	cout << "Opção Z - Modo sobrevivencia. Ou ganha ou perde.\n";
	cout << "Opção ESC - Termina o jogo.\n";
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
	cout << "  1 2 3 4 5\n";

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << i + 1 << "|";
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

// ------- dá uma tentativa ao utilizador para acertar no prémio, ou falhar redondamente
void umaTentativa()
{
	int coordenada_linha = 0, coordenada_coluna = 0;
	cout << "Tem direito a uma tentativa de jogo. Irá ser informado do resultado da jogada\n";
	do 
	{
		cout << "Insira a coordenada da coluna, de 1 a 5: "; cin >> coordenada_coluna;
		cout << "Insira a coordenada da linha, de 1 a 5: ";	cin >> coordenada_linha;

		//limpa o cin para impedir o uso indevido do utilizador, como por exemplo, caratéres em vez de números
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while ((coordenada_coluna > 5 || coordenada_coluna < 1) || (coordenada_linha > 5 || coordenada_linha < 1));
	

	// ------ actualizar as coordenadas do input do utilizador, devido a matriz ser de 0 a 4, mas ser pedido 1 a 5 ao user
	coordenada_coluna--;
	coordenada_linha--;

	pesquisa_board(coordenada_linha, coordenada_coluna);
}

void pesquisa_board(int x, int y)
{
	// ----- condicional para verificar se o utilizador acertou na bomba/tesouro ou em nada.
	if (board[x][y] == 'T')
	{
		cout << "\nAcertou no Tesouro e ganhou o quem quer ser milionário! Parabéns.\n";
	}
	else if (board[x][y] == 'B')
	{
		cout << "\nBOOM! Acertar numa bomba é o mesmo que acertar no tesouro, mas infelizmente perdeu o jogo.\n";
	}
	else
	{
		cout << "\nParabéns, acertou em.... NADA\n";
	}
}

void tresTentativas()
{
	int coordenada_linha = 0, coordenada_coluna = 0, contador_bombas = 0, contador_tesouros = 0, contador_falhas = 0;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "Tem direito três tentativas de jogo. Irá ser informado do resultado da mesmas no final. Boa sorte!\n";
		cout << "Insira a coordenada da coluna: "; cin >> coordenada_coluna;
		cout << "Insira a coordenada da linha: ";	cin >> coordenada_linha;

		// ------ actualizar as coordenadas do input do utilizador, devido a matriz ser de 0 a 4, mas ser pedido 1 a 5 ao user
		coordenada_coluna--;
		coordenada_linha--;

		// ----- condicional para verificar se o utilizador acertou na bomba/tesouro ou em nada e actualizar o contador correto
		if (board[coordenada_linha][coordenada_coluna] == 'T')
		{
			contador_tesouros++;
		}
		else if (board[coordenada_linha][coordenada_coluna] == 'B')
		{
			contador_bombas++;
		}
		else
		{
			contador_falhas++;
		}
	}
	cout << "\nNestas 3 tentativas acertou:\n\nNo tesouro " << contador_tesouros << " vezes.\n";
	cout << "Na bomba " << contador_bombas << " vezes.\n";
	cout << "E falhou " << contador_falhas << " vezes.\n";
}

// ---------------- jogar até acertar no tesouro ou bomba
void ultimate_survival()
{
	int coordenada_linha = 0, coordenada_coluna = 0, contador = 0;
	bool win = false;
	bool lose = false;

	cout << "Bem vindo ao modo sobrevivência. Jogue até acertar no tesouro ou rebentar com a bomba. Boa sorte!\n";

	do
	{
		cout << "Insira a coordenada da coluna: "; cin >> coordenada_coluna;
		cout << "Insira a coordenada da linha: ";	cin >> coordenada_linha;

		// ------ actualizar as coordenadas do input do utilizador, devido a matriz ser de 0 a 4, mas ser pedido 1 a 5 ao user
		coordenada_coluna--;
		coordenada_linha--;


		// ----- condicionar para verificar se o utilizador acertou na bomba/tesouro ou em nada.
		if (board[coordenada_linha][coordenada_coluna] == 'X')
		{
			cout << "\nEssa opção já foi utilizada anteriormente. Por favor escolha uma opção nova.\n";
		}
		else if (board[coordenada_linha][coordenada_coluna] == 'T')
		{
			cout << "\nAcertou no Tesouro e ganhou o quem quer ser milionário! Parabéns.\n";
			contador++;
			win = true;
		}
		else if (board[coordenada_linha][coordenada_coluna] == 'B')
		{
			cout << "\nBOOM! Acertar numa bomba é o mesmo que acertar no tesouro, mas infelizmente perdeu o jogo.\n";
			contador++;
			lose = true;
		}
		else
		{
			cout << "\nParabéns, acertou em.... NADA. Tente outra vez.\n";
			board[coordenada_linha][coordenada_coluna] = 'X';
			contador++;
		}
	} while (!win && !lose);

	cout << "Numero de tentativas utilizadas: " << contador << endl;
}

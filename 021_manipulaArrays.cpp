//04-05-2019
//feito por marco silva
// manipula arrays

#include<iostream>
#include<conio.h>
#include<string>
#include<locale.h>
#include<ctype.h>

using namespace std;
const int ARRAY_SIZE = 21;

//-------------------------- função lista inicial -------------------------
void slash()
{
	cout << "--------------------------------------\n";
}

void menu()
{
	slash();
	cout << "MANIPULAR ARRAY COM NOMES.\n\n";
	cout << "\t 1 = Listar todos os nomes\n";
	cout << "\t 2 = Lê 1 nome para uma posição.\n";
	cout << "\t 3 = Lista número, nome e comprimento em letras.\n";
	cout << "\t 4 = Qual o nome maior.\n";
	cout << "\t 5 = Procurar nome na lista.\n";
	cout << "\t 6 = Todos os nomes para letras maiusculas\n";
	cout << "\t 7 = Todos os nomes para letras minusculas\n\n";
	cout << "Pressione ESC para terminar o programa.\n";
	slash();
}

int main()
{
	//--------------- consola pt ---------------------
	setlocale(LC_ALL, "Portuguese");
	
	//--------------------------- variables ----------------------
	string nomes[21] = { "", "Mellissa", "Anibal", "Celsa", "Jerold", "Blaine", "Shauna", "Youlanda", 
		"Raymon", "Hugo", "Muriel", "Sherice", "Ginny", "Hertha", "Creola",	"Lorena", 
		"Julieta" , "Kizzie", "Mirian", "Michiko", "Cheri"}, longest_name = " ", nome_pesquisa = "", temp_name = "", novo_nome = "";

	int procura_position = 0, biggest_name = 0;
	bool found = false;
	char key_press;

	menu();

	//--------------------------MAIN PROG -------------------------
	do
	{
		key_press = _getch();

		switch (key_press)
		{
		//----------------------------- lista nomes -----------------
		case 49:
			for (int i = 1; i < ARRAY_SIZE; i++)
			{
				cout << i << " - " << nomes[i] << endl;
			}
			slash();
			break;

		//---------------------------- user escolhe a posição, dá um novo nome, e dá update na lista
		case 50:
			procura_position = 0;

			//input de posição e nome para update
			cout << "Para que posição (entre 1 e 20) quer inserir o novo nome? ";
			cin >> procura_position;
			
			//se o utilizador usar texto ou outro número, pede outra vez. O cin.clear() limpa o buffer e o cin.ignore vai ignorar os carateres maximos inseridos(?)
			while (procura_position > 20 || procura_position < 1)
			{
					cout << "Insira um NÚMERO entre 1 e 20!!!: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> procura_position;
			}
			cout << "Qual o nome que pretende dar? ";	
			cin >> novo_nome;

			//update no nome
			nomes[procura_position] = novo_nome;
			slash();
			break;

		//---------------------------- lista número, nome, comprimento em letras
		case 51:
			for (int i = 1; i < ARRAY_SIZE; i++)
			{
				cout << "Nome " << i << " " << nomes[i] << "\t\t" << nomes[i].size() << endl;
			}
			slash();
			break;

		//--------------------------- qual o maior nome
		case 52:
			for (int i = 1; i < ARRAY_SIZE; i++)
			{
				if (nomes[i].size() > biggest_name)
				{
					biggest_name = nomes[i].size();
					longest_name = nomes[i];
				}
			}
			cout << "O maior nome da lista é " << longest_name << " com " << biggest_name << " letras!\n";
			slash();
			break;

		//--------------------------le nome, e procura a existencia dele na lista
		case 53:
			found = false;
			cout << "Insira nome para pesquisar na lista: ";
			cin >> nome_pesquisa;

			for (int i = 1; i < ARRAY_SIZE; i++)
			{
				if (nome_pesquisa == nomes[i])
				{
					cout << "O nome " << nome_pesquisa << " existe e está na posição " << i << endl;
					found = true;
				}
			}

			//se o nome não foi encontrado, a boolean continua false logo temos de dar retorno ao user
			if (!found)
			{
				cout << "O nome não existe na lista\n\n";
			}
			slash();
			break;
		//------------------------ todos os nomes para uppercase
		case 54:
			for (int i = 1; i < ARRAY_SIZE; i++)
			{
				temp_name = "";
				for (int j = 0; j < nomes[i].size(); j++) 
				{
					temp_name += toupper(nomes[i][j]);
					
				}
				cout << temp_name << "\n";
			}
			slash();
			break;

		//------------------------- todos os nomes para lowercase
		case 55:
			for (int i = 1; i < ARRAY_SIZE; i++)
			{
				temp_name = "";
				for (int j = 0; j < nomes[i].size(); j++)
				{
					temp_name += tolower(nomes[i][j]);

				}
				cout << temp_name << "\n";
			}
			slash();
			break;
		//---------------------- default
		default:
			if (key_press != 27)
			{
				menu();
				break;
			}
		}
	} while (key_press != 27); //escape isn't pressed
	
}
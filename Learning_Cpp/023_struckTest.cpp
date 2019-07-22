//struct playground
//made by ms
//23-09-19

#include<iostream>
using namespace std;

struct carro
{
	string marca;
	string nome_dono;
	int ano_matricula;
	char categoria;
};

int main()
{
	/*carro info;

	cout << "Insira a marca, nome do dono, ano da matricula e categoria do seu carro. \n";
	cout << "Marca: ";	cin >> info.marca;
	cout << "Nome do dono: ";	cin >> info.nome_dono;
	cout << "Ano da matricula: ";	cin >> info.ano_matricula;
	cout << "categoria numa letra, L para ligeiro, P pesados: ";	cin >> info.categoria;

	cout << "\nCarro com a marca  " << info.marca << " pertence a " << info.nome_dono << " com a matricula do ano " << info.ano_matricula << " e categoria " << info.categoria << "\n";

	cout << "Teste array na struct.\n";*/

	carro v[10];

	for (int i = 0; i < 3; i++)
	{
		cout << "Carro " << i + 1 << endl;
		cout << "Marca:";	cin >> v[i].marca;
		cout << "Nome do dono: "; cin >> v[i].nome_dono;
		cout << "Ano da matricula: "; cin >> v[i].ano_matricula;
		cout << "categoria numa letra, L para ligeiro, P pesados: "; cin >> v[i].categoria;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "\nCarro com a marca  " << v[i].marca << " pertence a " << v[i].nome_dono << " com a matricula do ano " << v[i].ano_matricula << " e categoria " << v[i].categoria << "\n";
	}
}

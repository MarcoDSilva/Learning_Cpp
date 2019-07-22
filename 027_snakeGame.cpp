//snake game
//by ms
//27-05-19 || 12-06-19 || 18 e 19 /06/19

#include<iostream>
#include<conio.h>	
#include<time.h>
#include<Windows.h>
using namespace std;

//constantes para tamanho, para ser refactored com matrix(?)
const int WIDTH = 20;
const int HEIGHT = 20;

//struck snake e struck fruta
struct snakeObj{
	int x, y;
	int tail = 0;
	int tailX[100], tailY[100];
};

struct fruitObj {
	int x;
	int y;
};

struct tailObj {
	int PrevX, PrevY, tempX, tempY;
};

snakeObj snake;
fruitObj fruit;
tailObj tail;

int score = 0;

//tornar em numeros os inputs para condicional
enum Directions { STOP = 0, RIGHT, LEFT, DOWN, UP };
Directions keyPress;

// funções
void setup();
void draw();
void input();
void logic();

//global
bool gameOver;

//main chama só as funções necessárias para o jogo
int main()
{
	setup();
	while (!gameOver)
	{
		draw();
		input();
		logic();
		Sleep(1);
	}
}

//inicializa os valores da posição da cobra/fruta, do estado do jogo, movimento e score.
void setup()
{
	gameOver = false;
	keyPress = STOP;
	snake.x = WIDTH / 2;
	snake.y = WIDTH / 2;
	fruit.x= rand() % 20;
	fruit.y = rand() % 20;
	score = 0;
}
//desenha o tabuleiro e os elementos
void draw()
{
	system("cls");
	for (int i = 0; i < HEIGHT + 1; i++) { cout << "#"; }
	cout << "\n";

	//TENTAR REFACTOR COM UMA MATRIX
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			//desenhar os cantos
			if (j == 0 || j == WIDTH - 1) { cout << "#"; }

			//obtem a posição da cobra e desenha
			if (snake.x == j && snake.y == i)	{
				cout << "O";
			} 
			//obtem a posição da fruta e desenha
			else  if (fruit.x == j && fruit.y == i) {
				cout << "F";
			} 
			//obtem a posição da cauda da cobra , e dos espaços em branco
			else {
				bool printer = false;
				for (int coord = 0; coord < snake.tail; coord++) {
						
					if (snake.tailX[coord] == j && snake.tailY[coord] == i)
					{
						cout << "x";
						printer = true;
					}
				}
				if (!printer) { cout << " "; }
			}
		}
		cout << "\n";
	}

	//borda de baixo do tabuleiro
	for (int i = 0; i < HEIGHT + 1; i++) { cout << "#"; }
	cout <<  "\n";
	cout << "Score: " << score << "\n";
}

//recebe os comandos do jogo, UP DOWN LEFT RIGHT
void input()
{	
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
		case 'A':
			keyPress = LEFT;
			break;

		case 's':
		case 'S':
			keyPress = DOWN;
			break;

		case 'd':
		case 'D':
			keyPress = RIGHT;
			break;

		case 'W':
		case 'w':
			keyPress = UP;
			break;

		case 27:
			gameOver = true;
			break;
		}
	}	
}

void logic()
{

	//se a a cobra estiver na mesma posição da fruta, come-a
	if (snake.x == fruit.x && snake.y == fruit.y) {
		score += 5;
		snake.tail++;
		fruit.x = rand() % 20;
		fruit.y = rand() % 20;
	}

	// o prev fica com a ultima posição da cobra
	tail.PrevX = snake.x; 
	tail.PrevY = snake.y;

	//loop para aumentar a cobra e actualizar a array com a informação da mesma
	//tailTemp fica com o valor actual do iterador, o iterador escreve a posição anterior da cabeça da cobra, e o prev fica 
	//com o valor actual da tailx[i]
	for (int i = 0; i < snake.tail; i++)
	{
		tail.tempX = snake.tailX[i]; 
		tail.tempY = snake.tailY[i];
		snake.tailX[i] = tail.PrevX;
		snake.tailY[i] = tail.PrevY;
		tail.PrevX = tail.tempX; 
		tail.PrevY = tail.tempY;
	}

	switch (keyPress)
	{
		case UP:
		snake.y--;
		break;

		case LEFT:
		snake.x--;
		break;

		case RIGHT:
		snake.x++;
		break;

		case DOWN:
		snake.y++;
		break;

		default:
		break;
	}
}

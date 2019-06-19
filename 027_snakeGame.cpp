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

//coordenadas e scores
int snakeX, snakeY, fruitX, fruitY, snakeTail = 0, score = 0;
int tailX[100], tailY[100];

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
	snakeX = WIDTH / 2;
	snakeY = WIDTH / 2;
	fruitX = rand() % 20;
	fruitY = rand() % 20;
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
			if (snakeX == j && snakeY == i)	{
				cout << "O";
			} 
			//obtem a posição da fruta e desenha
			else  if (fruitX == j && fruitY == i) {
				cout << "F";
			} 
			//obtem a posição da cauda da cobra , e dos espaços em branco
			else {
				bool printer = false;
				for (int coord = 0; coord < snakeTail; coord++) {
						
					if (tailX[coord] == j && tailY[coord] == i)
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
	int tailPrevX, tailPrevY, tailPrev2X, tailPrev2Y; //variaveis para a cauda, a posição depois da cabeça e o temp que actualiza o valor

	//se a a cobra estiver na mesma posição da fruta, come-a
	if (snakeX == fruitX && snakeY == fruitY) {
		score += 5;
		snakeTail++;
		fruitX = rand() % 20;
		fruitY = rand() % 20;
	}

	// o prev fica com a ultima posição da cobra
	tailPrevX = snakeX; 
	tailPrevY = snakeY;

	//loop para aumentar a cobra e actualizar a array com a informação da mesma
	//prev2X fica com o valor actual do iterador, o iterador escreve a posição anterior da cabeça da cobra, e o prev fica 
	//com o valor actual da tailx[i]
	for (int i = 0; i < snakeTail; i++)
	{
		tailPrev2X = tailX[i]; 
		tailPrev2Y = tailY[i];
		tailX[i] = tailPrevX;
		tailY[i] = tailPrevY;
		tailPrevX = tailPrev2X; 
		tailPrevY = tailPrev2Y;
	}

	switch (keyPress)
	{
		case UP:
		snakeY--;
		break;

		case LEFT:
		snakeX--;
		break;

		case RIGHT:
		snakeX++;
		break;

		case DOWN:
		snakeY++;
		break;

		default:
		break;
	}
}

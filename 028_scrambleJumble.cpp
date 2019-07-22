//testing arrays
//book example

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL)); //pseudo random seed

	enum fields {WORD, HINT, NUM_FIELDS}; //enumerador para as palavras, dicas e o numero de campos

	const int NUM_WORDS = 5; //constante com o numero de palavras

	//array bidimensional com palavras e as dicas correspondentes. 
	//enum é usado para poder aceder à array

	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"friend", "speak ----- and enter!"},
		{"voldemort", "the one whose name shall not be mentioned"},
		{"money", "everyone needs to spend it right?"},
		{"winner", "the one that doesn't lose"},
		{"pig", "also known as spider something in simpsons movie"}
	};

	//random pra escolher a palavra a ser utilizada
	int choice = rand() % NUM_WORDS;

	string theWord = WORDS[choice][WORD]; //word to guess
	string theHint = WORDS[choice][HINT]; // hint for word

	//randomiza a palavra N vezes
	string jumble = theWord;
	int lenght = jumble.size();

	for (int i = 0; i < lenght; i++)
	{
		int index1 = rand() % lenght;
		int index2 = rand() % lenght;
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	//apresentação do jogo ao jogador e pede a jogada
	cout << "Welcome to the Word Jumble!\n\n";
	cout << "Unscramble the letters and guess the word.\n";
	cout << "Enter 'hint' for a hint or 'quit' to quit the game.\n";
	cout << "The jumbled word is the follow: " << jumble;

	//jogada inicial
	string guess;
	cout << "\nYour guess: ";		cin >> guess;
	
	//loop para jogada
	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint") { cout << theHint; }
			else { cout << "Sorry, you failed. Please retry."; }

		cout << "\nYour guess: ";		cin >> guess;
	}
	
	//word found
	if (guess == theWord) { cout << "Correct! You guessed it!\n"; }
	return 0;
}
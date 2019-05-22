//brinquedo 4 
// made by ms
// 19-05-2019

#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

// functions
void menu();
void inicializeArray();
void listArray();
void newFile();
void verifyOldest();

//global matrix
string people[20][5] = {};

int main()
{
	char key_press = ' ';
	menu();

	do
	{
		//gets the correspondent option
		key_press = _getch();

		switch (key_press)
		{
		case '1':
			inicializeArray();
			break;

		case '2':
			listArray();
			break;

		case 'i':
		case 'I':
			newFile();
			break;

		case '3':
			verifyOldest();
			break;

		default:
			if (key_press != 27)
			{

			}
			break;
		}
	} while (key_press != 27);
}

void menu()
{
	cout << "MANIPULATE MATRIX OF STRINGS\n\n";
	cout << "1 - Inicialize the matrix\n";
	cout << "2 - List the matrix\n";
	cout << "I - Insert new user file, replacing an old one\n";
	cout << "3 - Which user is the oldest?\n";
}

void inicializeArray()
{
	//first value of matrix belongs to names
	people[0][0] = "Even Bennets";
	people[1][0] = "Cinderella Plantz";
	people[2][0] = "Brenton Alper";
	people[3][0] = "Christeen Canada";
	people[4][0] = "Elsa Champney";
	people[5][0] = "Eartha Walraven";
	people[6][0] = "Janelle Wilmoth";
	people[7][0] = "Leonel Welsch";
	people[8][0] = "Lura Andrus";
	people[9][0] = "Adaline Lightner";
	people[10][0] = "Melony Brenes";
	people[11][0] = "Evelina Thill";
	people[12][0] = "Karol Mathena";
	people[13][0] = "Broderick Nida";
	people[14][0] = "Esmeralda Mallet";
	people[15][0] = "Coral Toenjes";
	people[16][0] = "Genia Jackman";
	people[17][0] = "Kiara Hoggatt";
	people[18][0] = "Augustina Hernandes";
	people[19][0] = "Sidney Swain";

	//second value of matrix belongs to country
	people[0][1] = "Sweden";
	people[1][1] = "SK and Nevis";
	people[2][1] = "Swaziland";
	people[3][1] = "Oman";
	people[4][1] = "Honduras";
	people[5][1] = "Andorra";
	people[6][1] = "Cyprus";
	people[7][1] = "US of America";
	people[8][1] = "Morocco";
	people[9][1] = "Faroe Islands";
	people[10][1] = "Chile";
	people[11][1] = "Hungary";
	people[12][1] = "Iran";
	people[13][1] = "Saint Vincent";
	people[14][1] = "Brunei Darussalam";
	people[15][1] = "Bosnia and Herzegovia";
	people[16][1] = "Kyrgyztan";
	people[17][1] = "Israel";
	people[18][1] = "New Caledonia";
	people[19][1] = "Liberia";

	//third value is for sex 
	people[0][2] = "Female";
	people[1][2] = "Female";
	people[2][2] = "Male";
	people[3][2] = "Female";
	people[4][2] = "Female";
	people[5][2] = "Female";
	people[6][2] = "Female";
	people[7][2] = "Male";
	people[8][2] = "Female";
	people[9][2] = "Female";
	people[10][2] = "Female";
	people[11][2] = "Female";
	people[12][2] = "Female";
	people[13][2] = "Female";
	people[14][2] = "Female";
	people[15][2] = "Female";
	people[16][2] = "Female";
	people[17][2] = "Female";
	people[18][2] = "Female";
	people[19][2] = "Male";

	//forth for age
	people[0][3] = "1987";
	people[1][3] = "2010";
	people[2][3] = "1937";
	people[3][3] = "2014";
	people[4][3] = "1993";
	people[5][3] = "1948";
	people[6][3] = "1953";
	people[7][3] = "1933";
	people[8][3] = "2018";
	people[9][3] = "1974";
	people[10][3] = "1977";
	people[11][3] = "1925";
	people[12][3] = "1941";
	people[13][3] = "2018";
	people[14][3] = "1931";
	people[15][3] = "1967";
	people[16][3] = "2003";
	people[17][3] = "1992";
	people[18][3] = "1980";
	people[19][3] = "1994";

	cout << "The array was initialized. You can press 2 to see the values.\n\n";
}

void listArray()
{
	cout << "-----------------------------------------------------------------------\n";
	cout << "N.   NAME\t\t\t  COUNTRY\t\tSEX\t   YEAR\n";
	for (int i = 0; i < 20; i++)
	{
		cout << left << setw(2) << setfill(' ') << i + 1 << ": "
			<< setw(25) << setfill('.') << people[i][0] << left
			<< setw(25) << setfill(' ') << people[i][1] << left
			<< setw(15) << setfill(' ') << people[i][2] << right
			<< setw(2) << setfill(' ') << people[i][3] << endl;
	}
	cout << "-----------------------------------------------------------------------\n";
}

void newFile()
{

}

void verifyOldest()
{
	int maior = 0;
	
}

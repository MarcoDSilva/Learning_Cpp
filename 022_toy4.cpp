//toy 4 
// made by ms
// 19-05-2019 and 26/05/2019

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

//struct for data manipulation
struct people {
	string name;
	string country;
	string sex;
	int year;
};
people map[20];

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
				cout << "wrong key was pressed!\n";
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

//initializes the empty array with pre-defined values
void inicializeArray()
{
	//struct names 
	map[0].name = "Even Bennets";
	map[1].name = "Cinderella Plantz";
	map[2].name = "Brenton Alper";
	map[3].name = "Christeen Canada";
	map[4].name = "Elsa Champney";
	map[5].name = "Eartha Walraven";
	map[6].name = "Janelle Wilmoth";
	map[7].name = "Leonel Welsch";
	map[8].name = "Lura Andrus";
	map[9].name = "Adaline Lightner";
	map[10].name = "Melony Brenes";
	map[11].name = "Evelina Thill";
	map[12].name = "Karol Mathena";
	map[13].name = "Broderick Nida";
	map[14].name = "Esmeralda Mallet";
	map[15].name = "Coral Toenjes";
	map[16].name = "Genia Jackman";
	map[17].name = "Kiara Hoggatt";
	map[18].name = "Augustina Hernandes";
	map[19].name = "Sidney Swain";

	//struct contries
	map[0].country = "Sweden";
	map[1].country = "SK and Nevis";
	map[2].country = "Swaziland";
	map[3].country = "Oman";
	map[4].country = "Honduras";
	map[5].country = "Andorra";
	map[6].country = "Cyprus";
	map[7].country = "US of America";
	map[8].country = "Morocco";
	map[9].country = "Faroe Islands";
	map[10].country = "Chile";
	map[11].country = "Hungary";
	map[12].country = "Iran";
	map[13].country = "Saint Vincent";
	map[14].country = "Brunei Darussalam";
	map[15].country = "Bosnia and Herzegovia";
	map[16].country = "Kyrgyztan";
	map[17].country = "Israel";
	map[18].country = "New Caledonia";
	map[19].country = "Liberia";

	//sex
	map[0].sex = "Female";
	map[1].sex = "Female";
	map[2].sex = "Male";
	map[3].sex = "Female";
	map[4].sex = "Female";
	map[5].sex = "Female";
	map[6].sex = "Female";
	map[7].sex = "Male";
	map[8].sex = "Female";
	map[9].sex = "Female";
	map[10].sex = "Female";
	map[11].sex = "Female";
	map[12].sex = "Female";
	map[13].sex = "Female";
	map[14].sex = "Female";
	map[15].sex = "Female";
	map[16].sex = "Female";
	map[17].sex = "Female";
	map[18].sex = "Female";
	map[19].sex = "Male";

	//b-day year
	map[0].year = 1987;
	map[1].year = 2010;
	map[2].year = 1937;
	map[3].year = 2014;
	map[4].year = 1993;
	map[5].year = 1948;
	map[6].year = 1953;
	map[7].year = 1933;
	map[8].year = 2018;
	map[9].year = 1974;
	map[10].year = 1977;
	map[11].year = 1925;
	map[12].year = 1941;
	map[13].year = 2018;
	map[14].year = 1931;
	map[15].year = 1967;
	map[16].year = 2003;
	map[17].year = 1992;
	map[18].year = 1980;
	map[19].year = 1994;

	cout << "The array was initialized. You can press 2 to see the values.\n\n";
}

//Lists the array correctly and with a specific design
void listArray()
{
	cout << "-----------------------------------------------------------------------\n";
	cout << "N.   NAME\t\t\t  COUNTRY\t\tSEX\t   YEAR\n";
	for (int i = 0; i < 20; i++)
	{
		cout << left << setw(2) << setfill(' ') << i + 1 << ": "
			<< setw(25) << setfill('.') << map[i].name << left
			<< setw(25) << setfill(' ') << map[i].country << left
			<< setw(15) << setfill(' ') << map[i].sex << right
			<< setw(2) << setfill(' ') << map[i].year << endl;
	}
	cout << "-----------------------------------------------------------------------\n";
}

//gets the user info in temp values, gets the position to update , then updates the info where the user wants
void newFile()
{
	int pick = 0, temp_year = 0;
	string temp_name, temp_country, temp_sex;

	cout << "NEW USER:\n";
	cout << "Name: ";	cin >> temp_name;
	cout << "Country: ";	cin >> temp_country;
	cout << "Sex ";	cin >> temp_sex;
	cout << "Year of Birth: ";	cin >> temp_year;
	cout << "In which line you want to update this new user (1 to 20): ";	cin >> pick;

	pick--;  // we are asking the user from input 1 to 20, but our object starts at 0

	map[pick].name = temp_name;
	map[pick].country = temp_country;
	map[pick].sex = temp_sex;
	map[pick].year = temp_year;

	cout << "The user was updated. Pick 2 to see the updated user list.\n";
}

// to verify the oldest member , loops through all 20 people
// returns the age, the name and the year of birth
void verifyOldest()
{
	int year = 2019, oldest = -1, biggest_age = -1, actual_year = 2019;
	string oldest_person = "";

	for (int i = 0; i < 20; i++)
	{
		if (actual_year - map[i].year > oldest)
		{
			oldest = actual_year - map[i].year;
			biggest_age = map[i].year;
			oldest_person = map[i].name;
		}
	}

	cout << "The highest age is: " << biggest_age;
	cout << "\n( " << oldest_person << " / " << oldest << " )\n";
}

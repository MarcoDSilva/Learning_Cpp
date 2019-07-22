//experimenting vectors
//hero's inventory exercise

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//vector of strings instead of an array
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	//returns the number of elements inside the vector
	cout << "You have " << inventory.size() << " items.\n";
		
	//returns the elements inside the vector
	cout << "Your items are the follow: \n";
	for (int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}

	//swapping entire inventory and returning it to the user
	cout << "\nYou traded all your inventory for magical items.\n";
	inventory[0] = "magical staff";
	inventory[1] = "magical robe";
	inventory[2] = "mana dagger";

	cout << "Your new items are:\n";
	for (int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}

	cout << "\nThe item name '" << inventory[0] << "' has  " << inventory[0].size() << " letters.\n\n";

	//removes the last element with pop_back
	cout << "While facing a powerful foe, your mana dagger was destroyed!\n";
	inventory.pop_back();

	cout << "Your items now are: \n";
	for (int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i] << endl;
	}

	//clearing all inventory (vector)
	cout << "\nWhile you were taking a bath, a troll stole all your possessions!\n";
	inventory.clear();

	//in case the inventory(vector) has nothing inside
	if (inventory.empty())
	{
		cout << "Your backpack is empty!\n";
	}
	else
	{
		cout << "You have something inside your backpack.\n";
	}
	   
	return 0;
}
// Kathleen Fillingim
// CIS 1202.501
// Final Project
// 05/10/2025

#include<iostream>
#include<string>
#include<cctype>
#include<fstream>

#include "Snake.h"
#include "Dog.h"

using namespace std;

// Function prototypes:

int showMenu();
void getSnakeInfo();
void getDogInfo();
void printToFile(string, string, double, double, bool); // Snake
void printToFile(string, string, double, string, string); // Dog


int main()
{
	
	cout << "Welcome to your Pet Dashboard" << endl;
	cout << "-----------------------------------" << endl;

	int choice;
	
	do     // Loop through menu of choices until exit is chosen
	{
		choice = showMenu();

		cin.ignore(); // Flush newline characters

		switch (choice)
		{
			case 1:
				getSnakeInfo();
				break;
			case 2: 
				getDogInfo();
				break;
			case 3:
				cout << "\nExiting program." << endl;
				break;
		}
	} while (choice != 3);

	cout << endl << endl;

	return 0;
}

// showMenu() function definition:
//
// Shows a menu of choices to the user and prompts user for
// an int value that corresponds to a numbered choice. 
// Validates user input then returns it to main()

int showMenu()
{
	int input;

	cout << "\nPlease review the following choices:" << endl;
	cout << "\t1. Add a pet snake's info." << endl;
	cout << "\t2. Add a pet dog's info." << endl;
	cout << "\t3. Exit." << endl;
	cout << "Enter the number for your choice: ";

	cin >> input;
	while (input < 1 || input > 3)
	{
		cout << "Invalid entry. Please enter a number 1-3: ";
		cin >> input;
	}

	return input;
}


// getSnakeInfo() function definition:
//
// Prompts user for input for a snake
// Creates a Snake instance
// Calls the Snake class' displayInfo() function to pass
//		the inputted variables and print to console.
// Gives the user the option to write the snake info
//		to an external file.

void getSnakeInfo()
{
	// Get user input
	
	string name, breed;
	double weight, length;
	char venom;
	bool isVenom;

	cout << "\nSnake Entry:" << endl;
	cout << "\tEnter the pet's name: ";
	getline(cin, name);

	cout << "\tEnter the pet's breed: ";
	getline(cin, breed);

	cout << "\tEnter the pet's weight (in lbs): ";
	cin >> weight;

	cout << "\tEnter the snake length (in inches): ";
	cin >> length;

	cout << "\tIs this snake venomous? Enter Y for yes or N for no: ";
	cin >> venom;
	while (tolower(venom) != 'y' && tolower(venom) != 'n') // tolower() accommodates for both upper and lowercase entries
	{
		cout << "Invalid entry. Please enter either Y or N: ";
		cin >> venom;
	}
	if (tolower(venom) == 'y')
		isVenom = true;
	else
		isVenom = false;

	// Create Snake instance and print info to console

	Snake slither(name, breed, weight, length, isVenom);

	slither.displayInfo(name, breed, weight, length, isVenom);
	slither.weightMessage(weight);

	// Print to File?

	char input;
	cout << "\nDo you want to print this info to an external file? Enter Y for yes or N for no: ";
	cin >> input;

	while (tolower(input) != 'y' && tolower(input) != 'n')
	{
		cout << "Invalid entry. Please enter either Y or N: ";
		cin >> input;
	}

	if (tolower(input) == 'y')
	{
		printToFile(name, breed, weight, length, isVenom);
	}
	else if (tolower(input) == 'n')
		cout << "Exiting Snake Entry." << endl;
}


// getDogInfo() function definition:
//
// Prompts user for input for a dog
// Creates a Dog instance
// Calls the Dog class' displayInfo() function to pass
//		the inputted variables and print to console.
// Gives the user the option to write the dog info
//		to an external file.

void getDogInfo()
{
	// Get user input
	
	string name, breed, color, energy;
	double weight;

	cout << "\nDog Entry:" << endl;
	cout << "\tEnter the pet's name: ";
	getline(cin, name);
	cout << "\tEnter the pet's breed: ";
	getline(cin, breed);

	cout << "\tEnter the pet's weight (in lbs): ";
	cin >> weight;

	cin.ignore(); // Flush the newline character
	cout << "\tEnter the dog's coat color: ";
	getline(cin, color);

	//cin.ignore(); // Flush the newline character
	cout << "\tEnter the dog's energy level (low, mid, high): ";
	getline(cin, energy);

	// Create Dog instance and print info to console

	Dog doggo(name, breed, weight, color, energy);

	doggo.displayInfo(name, breed, weight, color, energy);
	doggo.energyMessage(energy);

	// Print to File?

	char input;
	cout << "\nDo you want to print this info to an external file? Enter Y for yes or N for no: ";
	cin >> input;

	while (tolower(input) != 'y' && tolower(input) != 'n')
	{
		cout << "Invalid entry. Please enter either Y or N: ";
		cin >> input;
	}

	if (tolower(input) == 'y')
	{
		printToFile(name, breed, weight, color, energy);
	}
	else if (tolower(input) == 'n')
		cout << "Exiting Dog Entry." << endl;


}

void printToFile(string name, string breed, double weight, double length, bool venomStatus) // Snake
{
	// Convert the venom bool value to a string
	
	string status;
	
	if (venomStatus)
		status = "Venomous";
	else
		status = "Not venomous";

	// Create and open the file 

	fstream snakeFile;
	snakeFile.open("SnakeEntry.dat", ios::out | ios::binary);

	// Write the contents to the file

	if (snakeFile.is_open())
	{
		snakeFile.write(reinterpret_cast<char*>(&name), sizeof(name));
		snakeFile.write(reinterpret_cast<char*>(&breed), sizeof(breed));
		snakeFile.write(reinterpret_cast<char*>(&weight), sizeof(weight));
		snakeFile.write(reinterpret_cast<char*>(&length), sizeof(length));
		snakeFile.write(reinterpret_cast<char*>(&status), sizeof(status));
		snakeFile.close();
		cout << "File Created." << endl;
	}
	else
	{
		cerr << "Error opening file." << endl;
	}

	// unhide driver to test that the file wrote the correct info:

	/*snakeFile.open("SnakeEntry.dat", ios::in | ios::binary);

	string name1, breed1, status1;
	double weight1, length1;

	snakeFile.read(reinterpret_cast<char*>(&name1), sizeof(name1));
	snakeFile.read(reinterpret_cast<char*>(&breed1), sizeof(breed1));
	snakeFile.read(reinterpret_cast<char*>(&weight1), sizeof(weight1));
	snakeFile.read(reinterpret_cast<char*>(&length1), sizeof(length1));
	snakeFile.read(reinterpret_cast<char*>(&status1), sizeof(status1));


	cout << name1 << endl;
	cout << breed1 << endl;
	cout << weight1 << endl;
	cout << length1 << endl;
	cout << status1 << endl;

	snakeFile.close();*/
}

void printToFile(string name, string breed, double weight, string color, string energy) // Dog
{
	// Create and open the file 

	fstream dogFile;
	dogFile.open("DogEntry.dat", ios::out | ios::binary);

	// Write the contents to the file

	if (dogFile.is_open())
	{
		dogFile.write(reinterpret_cast<char*>(&name), sizeof(name));
		dogFile.write(reinterpret_cast<char*>(&breed), sizeof(breed));
		dogFile.write(reinterpret_cast<char*>(&weight), sizeof(weight));
		dogFile.write(reinterpret_cast<char*>(&color), sizeof(color));
		dogFile.write(reinterpret_cast<char*>(&energy), sizeof(energy));
		dogFile.close();
		cout << "File Created." << endl;
	}
	else
	{
		cerr << "Error opening file." << endl;
	}

	// unhide driver to test that the file wrote the correct info:

	/*dogFile.open("DogEntry.dat", ios::in | ios::binary);

	string name1, breed1, color1, energy1;
	double weight1;

	dogFile.read(reinterpret_cast<char*>(&name1), sizeof(name1));
	dogFile.read(reinterpret_cast<char*>(&breed1), sizeof(breed1));
	dogFile.read(reinterpret_cast<char*>(&weight1), sizeof(weight1));
	dogFile.read(reinterpret_cast<char*>(&color1), sizeof(color1));
	dogFile.read(reinterpret_cast<char*>(&energy1), sizeof(energy1));

	
	cout << name1 << endl;
	cout << breed1 << endl;
	cout << weight1 << endl;
	cout << color1 << endl;
	cout << energy1 << endl;
	
	dogFile.close();*/
}
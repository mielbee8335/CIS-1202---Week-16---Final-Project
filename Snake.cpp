#include "Snake.h"
#include<string>
#include<cmath>

using namespace std;

// Snake class member function definitions:

Snake::Snake() // Default constructor
{
	Pet();
	snakeLength = 0.0;
	isVenomous = false;
}

Snake::Snake(string& name, string& breed, double weight, double length, bool venom) // Constructor
{
	Pet(name, breed, weight);
	snakeLength = length;
	isVenomous = venom;
}

// Setters and Getters:

void Snake::setSnakeLength(double length)
{
	snakeLength = length;
}

double Snake::getSnakeLength()
{
	return snakeLength;
}

void Snake::setIsVenomous(bool venom)
{
	isVenomous = venom;
}

string Snake::getIsVenomous()
{
	string status;
	
	if (isVenomous)
		status = "Yes";
	else
		status = "No";

	return status;
}

// Etc.

void Snake::displayInfo(string& name, string& breed, double weight, double length, bool venom)
{
	Pet::displayInfo(name, breed, weight);

	setSnakeLength(length);
	cout << "\tSnake Length: " << getSnakeLength() << " in";

	setIsVenomous(isVenomous);
	cout << "\tVenomous Snake? : " << getIsVenomous();
	
	cout << endl;
}

void Snake::weightMessage(double weight)
{
	if (ceil(weight) > 15)
		cout << "\n** Warning! Your snake may be overweight, check-in with a vet. **" << endl;
}
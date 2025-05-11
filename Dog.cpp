#include "Dog.h"
#include<string>
#include<fstream>

using namespace std;

// Dog class member function definitions:

Dog::Dog() // Default constructor
{
	Pet();
	coatColor = "";
	energyLevel = "";
}

Dog::Dog(string& name, string& breed, double weight, string& color, string& energy) // Constructor
{
	Pet(name, breed, weight);
	coatColor = color;
	energyLevel = energy;
}

// Setters and Getters:

void Dog::setCoatColor(string& color)
{
	coatColor = color;
}

string Dog::getCoatColor()
{
	return coatColor;
}

void Dog::setEnergyLevel(string& energy)
{
	energyLevel = energy;
}

string Dog::getEnergyLevel()
{
	return energyLevel;
}

// Etc.

void Dog::displayInfo(string& name, string& breed, double weight, string& color, string& energy)
{
	Pet::displayInfo(name, breed, weight);

	setCoatColor(color);
	cout << "\tCoat Color: " << getCoatColor();

	setEnergyLevel(energy);
	cout << "\tEnergy Level: " << getEnergyLevel();

	cout << endl;
}

void Dog::energyMessage(string& energy)
{
	if (energy == "low")
		cout << "\n** If your dog's energy level remains low for several days, check-in with a vet. **" << endl;
}
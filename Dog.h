#ifndef DOG_H
#define DOG_H
#include "Pet.h"
#include<string>

using namespace std;

// Dog class declaration:

class Dog : public Pet
{
private:
	string coatColor;
	string energyLevel;
public:
	// Constructors:

	Dog();
	Dog(string&, string&, double, string&, string&);

	// Setters & Getters:

	void setCoatColor(string&);
	string getCoatColor();

	void setEnergyLevel(string&);
	string getEnergyLevel();

	// Etc.

	void displayInfo(string&, string&, double, string&, string&);

};

#endif 

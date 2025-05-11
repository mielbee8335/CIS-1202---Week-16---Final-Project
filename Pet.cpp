#include "Pet.h"
#include<string>

using namespace std;

// Pet class member function definitions:

Pet::Pet() // Default constructor
{
	petName = "";
	petBreed = "";
	petWeight = 0.0;
}

Pet::Pet(string& name, string& breed, double weight) // Constructor
{
	petName = name;
	petBreed = breed;
	petWeight = weight;
}

// Setters and Getters:

void Pet::setPetName(string& name)
{
	petName = name;
}

string Pet::getPetName()
{
	return petName;
}

void Pet::setPetBreed(string& breed)
{
	petBreed = breed;
}

string Pet::getPetBreed()
{
	return petBreed;
}

void Pet::setPetWeight(double weight)
{
	petWeight = weight;
}

double Pet::getPetWeight()
{
	return petWeight;
}

void Pet::displayInfo(string& name, string& breed, double weight)
{
	cout << "Pet information:" << endl;

	setPetName(name);
	cout << "\tPet Name: " << getPetName();

	setPetBreed(breed);
	cout << "\tPet Breed: " << getPetBreed();

	setPetWeight(weight);
	cout << "\tPet Weight: " << getPetWeight() << " lbs" << endl;
}
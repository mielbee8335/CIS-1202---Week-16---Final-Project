#ifndef PET_H
#define PET_H

#include<string>
#include<iostream>
using namespace std;

// Pet class declaration

class Pet
{
protected:
	string petName;
	string petBreed;
	double petWeight;

public:
	// Constructors:

	Pet(); // Default constructor
	Pet(string&, string&, double);

	// Setters and Getters:

	void setPetName(string&);
	string getPetName();

	void setPetBreed(string&);
	string getPetBreed();

	void setPetWeight(double);
	double getPetWeight();

};


#endif

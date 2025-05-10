#ifndef SNAKE_H
#define SNAKE_H
#include "Pet.h"
#include<string>

using namespace std;

// Snake class declaration:

class Snake : public Pet
{
private:
	double snakeLength;
	bool isVenomous;
public:
	// Constructors:

	Snake();
	Snake(string&, string&, double, double, bool);

	// Setters & Getters:

	void setSnakeLength(double);
	double getSnakeLength();

	void setIsVenomous(bool);
	string getIsVenomous();

	// Etc.

	void displayInfo(string&, string&, double, double, bool);

};

#endif 

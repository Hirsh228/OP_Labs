#ifndef CLASSES
#define CLASSES

#include <cmath>
#include <iostream>

#define M_PI 3.14159265358979323846

class ComplexNum {
	double x{0},
		   y{0},
           p{0},
		   f{0};
public:
	double getX();
	double getY();
	double getP();
	double getF();

	// Calculation of p
	void makeP();
	// Calculation of f
	void makeF();
	// Constructor
	ComplexNum(double cP, double cF);
	// Constructor
	ComplexNum();
	// Increase Re
	ComplexNum operator++();
	// Increase Im
	ComplexNum operator++([[maybe_unused]] int notused);
	// Add complex numbers
	ComplexNum operator+(ComplexNum obj);
	// Prints an algebraic form
	void printAlgForm();
	// Prints an power form
	void printPowForm();
};

 
#endif // !CLASS


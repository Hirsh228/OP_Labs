#include "classes.h"

// Getters block
#if 1
double ComplexNum::getX() 
{
	return x;
}

double ComplexNum::getY() 
{
	return y;
}

double ComplexNum::getP() 
{
	return p;
}

double ComplexNum::getF()
{
	return f;
}
#endif


// Calculation of f
void ComplexNum::makeF()
{
	if (x > 0 && y > 0 || x > 0 && y < 0) // I Iv
	{
		f = atan(y / x);
	}
	else if (x < 0 && y > 0) // II
	{
		f = M_PI + atan(y / x);
	}
	else if (x < 0 && y < 0) // III
	{
		f = -M_PI + atan(y / x);
	}
	else
	{
		f = 0;
	}
}

// Calculation of p
void ComplexNum::makeP() 
{
	p = sqrt(pow(x, 2) + pow(y, 2));
}

// Constuctor
ComplexNum::ComplexNum(double cP, double cF) : p{ cP }, f{ cF }
{
	x = p * cos(f);
	y = p * sin(f);

}

// Constuctor
ComplexNum::ComplexNum()
{
	p = 0;
	f = 0;
	x = p * cos(f);
	y = p * sin(f);
}

// Increase Re
ComplexNum ComplexNum::operator++() 
{
	x++;
	makeP();
	makeF();
	return *this;
}
// Increase Im
ComplexNum ComplexNum::operator++([[maybe_unused]] int notised)
{
	y++;
	makeP();
	makeF();
	return *this;
}
// Add complex numbers
ComplexNum ComplexNum::operator+(ComplexNum obj)
{
	ComplexNum tmp;
	tmp.y = y + obj.y;
	tmp.x = x + obj.x;
	tmp.makeF();
	tmp.makeP();
	return tmp;
}
// Prints an algebraic form
void ComplexNum::printAlgForm()
{
	std::cout << "[Alg] z = " << x << " + " << y << " * i\n";
}
// Prints a power form
void ComplexNum::printPowForm()
{
	std::cout << "[Pow] z = " << p << " * e ^ ( i * " << f << " )\n";
}

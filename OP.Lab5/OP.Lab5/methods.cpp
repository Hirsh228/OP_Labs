#include "methods.h"

//Getters
#if 1

long long TIntNumber::getBin() 
{
	long long binNum = 0;
	int	remainder;
	int decNum = decValue;

	for (int i = 1; decNum != 0; i = i * 10)
	{
		remainder = decNum % 2;
		decNum = decNum / 2;
		binNum = binNum + remainder * i;
	}
	return binNum;
}

int TIntNumber::getDec() {
	return decValue;
}

std::string TIntNumber::getHex() {
	int reminder;
	std::string hex{};
	int temp{ decValue };
	for (int i = 0; temp != 0; i++)
	{
		reminder = temp % 16;
		if (reminder < 10)
		{
			hex += (static_cast<char>(reminder + 48));
		}
		else
		{
			hex += (static_cast<char>(reminder + 55));
		}
		temp = temp / 16;
	}
	std::reverse(hex.begin(), hex.end());
	return hex;
}

#endif 

//Setters
#if 1
void TIntNumber::setDec(int num) {
	decValue = num;
}


#endif 

//Constructors
#if 1
TIntNumber::TIntNumber(int decNum) : decValue{ decNum }
{	}
// TIntNumber2 constructor
TIntNumber2::TIntNumber2(int binNum) : TIntNumber(binToDec(binNum))
{
	binValue = binNum;
}

// TIntNumber16 constructor dec - hex
TIntNumber16::TIntNumber16(std::string hexNum) : TIntNumber(hexToDec(hexNum))
{
	hexValue = hexNum;
}
// TIntNumber16 constructor hex - hex


#endif 

//Operators
#if 1
TIntNumber TIntNumber::operator+ (TIntNumber obj)
{
	TIntNumber tmp;
	tmp.decValue = decValue + obj.decValue;
	return tmp;
}

bool TIntNumber::operator<(TIntNumber obj)
{
	if (decValue < obj.decValue)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TIntNumber::operator>(TIntNumber obj)
{
	if (decValue > obj.decValue)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TIntNumber::operator==(TIntNumber obj)
{
	if (decValue == obj.decValue)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif 

void TIntNumber::print(std::string str)
{
	std::cout	<< str << '\n'
				<< "Dec: " << getDec() << '\n'
				<< "Bin: " << getBin() << '\n'
				<< "Hex: " << getHex() << '\n';
}



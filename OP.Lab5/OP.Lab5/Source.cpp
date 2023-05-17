#include <iostream>
#include "methods.h"
#include "code.h"

int main()
{
	int				m{},
					n{};
	TIntNumber		sum2,
					sum16;
	TIntNumber2		num2;
	TIntNumber16	num16;

	std::cout <<	"Enter the number of numbers"
					"you want to enter.\n"
					"m - binary\n"
					"n - hexadecimal\n"
					"In the format(m n): ";

	std::cin >> m >> n;

	std::cout << "\n***Binary sum***\n";
	int bin{};
	for (int i = 0; i < m; i++) 
	{
		std::cout << "Bin " << i + 1 << ": ";
		std::cin >> bin;
		new(&num2) TIntNumber2(bin);
		sum2 = sum2 + num2;
	}

	std::cout << "\n***Hexadecimal sum***\n";
	std::string hex{};
	for (int i = 0; i < m; i++)
	{
		std::cout << "Hex " << i + 1 << ": ";
		std::cin >> hex;
		new(&num16) TIntNumber16(hex);
		sum16 = sum16 + num16;
	}

	sum2.print("\n***Bin Sum***");
	sum16.print("\n***Hex Sum***");

	if (sum2 > sum16) {
		std::cout << "\nBinary sum is grater!\n";
	}
	else if(sum2 == sum16)
	{
		std::cout << "\nThey are equal!\n";
	}
	else
	{
		std::cout << "\nHexadecimal sum is grater!\n";
	}

	return EXIT_SUCCESS;
	
}

#if 0
Створити клас TIntNumber, який представляє ціле число у будь - якій системі счислення
і містить методи для додавання іншшого числа, порівняння чисел та передавання числа
у вказану систему числення(із заданого переліку).На основі цього класу створити класи нашадки
TIntNumber2  та TIntNumber16, що представляють двійкові та шіснадцяткові числа.
Створити m  двійкових та n шістнадцяткових чисел.
Знайти суму двійкових і суму шіснадцяткових чисел.
Перевести отримане значення суми шістнадцяткових чисел у двійковий формат.
Визначити, сума яких чисел більша(двійкових чи шістандцяткових).
#endif
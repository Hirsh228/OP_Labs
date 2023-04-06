#include <iostream>
#include "classes.h"
#include "code.h"

int main()
{
	int n{};
	std::cout << "Enter how many arithmetic progressions will there be: ";
	std::cin >> n;
	[[maybe_unused]] ArithmeticProgression* apArray = new ArithmeticProgression[n];
	fillArray(apArray, n);
	printSums(apArray, n);
	ArithmeticProgression tempMax = findMaxSum(apArray, n);
	double maxSum = tempMax.getSum();
	std::cout << "\nMaximal sum = " << maxSum << '\n';
	new(&tempMax) ArithmeticProgression(tempMax.getA(), tempMax.getD(), tempMax.getN());
	tempMax.showProg();
	delete[] apArray;
	return EXIT_SUCCESS;
}
#if 0
Розробити клас "арифметична прогресія", який задається першим
членом a, різницею d та кількістю членів n.Створити масив
об''єктів даного класу. Визначити прогресію (її номер), що 
має найбільшу суму елементів.
#endif // 0

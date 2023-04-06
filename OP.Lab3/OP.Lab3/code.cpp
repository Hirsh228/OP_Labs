#include "classes.h"
#include "Colors.h"
#include "code.h"

void getNum(int& num, std::string var) {
	std::string nums{};
	do {
		std::cout << "Enter " << var << ':';
		std::cin >> nums;
		if (asciiCheck(nums)) {
			redColor();
			std::cout << "It is not number!\n";
			resetColor();
		}
		else
		{
			num = std::stoi(nums);
		}
	} while (asciiCheck(nums));
}

void getNum(double& num, std::string var) {
	std::string nums{};
	do {
		std::cout << "Enter " << var << ':';
		std::cin >> nums;
		if (asciiCheck(nums)) {
			redColor();
			std::cout << "It is not number!\n";
			resetColor();
		}
		else
		{
			num = std::stod(nums);
		}
	} while (asciiCheck(nums));
}

bool asciiCheck(std::string_view nums){
	int dot = 0,
		neg = 0;
	bool check{};
	for (int i = 0; i < nums.length(); i++) {
		if (nums[i] != 45 && nums[i] != 46) {
			if (!isdigit(nums[i])) {
				check = true;
			}
		}
		(nums[i] == 45) ? neg++ : 0;
		(nums[i] == 46) ? dot++ : 0;

		(dot == 2 || neg == 2) ? check = true : false;
	}
	return(check);
}

void fillArray(ArithmeticProgression* arr, int size)
{
	std::cout << "Now fill array.\n\n";
	double	a{},
		    d{};
	int		n{};
	for (int i = 0; i < size; i++) {
		std::cout << "Progresion №" << i+1 << ":\n";
		getNum(a, "a");
		getNum(d, "d");
		getNum(n, "n");
		std::cout << '\n';
		arr[i].putA(a);
		arr[i].putD(d);
		arr[i].putN(n);
		new(&arr[i]) ArithmeticProgression(a, d, n);
	}
}

void printSums(ArithmeticProgression* arr, int size)
{
	for (int i = 0; i < size; i++) {
		std::cout << "Sum " << i+1 << ": " << arr[i].getSum() << '\n';
	}
}

ArithmeticProgression findMaxSum(ArithmeticProgression* arr, int size)
{
	ArithmeticProgression max{};
	for (int i = 0; i < size; i++) {
		if (max.getSum() < arr[i].getSum()) {
			max = arr[i];
		}
	}
	return max;
}

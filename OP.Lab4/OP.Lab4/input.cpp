#include "input.h"


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

bool asciiCheck(std::string_view nums) {
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
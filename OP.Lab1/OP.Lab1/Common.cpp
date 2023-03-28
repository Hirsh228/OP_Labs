#include "Common.h"

// Створює на основі аргументів вибір
int make_choice(int argc, char** argv, int& choice) {

	std::string mode{ argv[2] };
	std::string flag{ argv[1] };

	if (argc != 3) {
		redColor();
		std::cout << "Not correct amount of arguments!!!" << std::endl;
		resetColor();
		return EXIT_FAILURE;
	}

	if (flag != ("-mode")) {
		redColor();
		std::cout << "Write \"-mode\" before the mode" << std::endl;
		resetColor();
		return EXIT_FAILURE;
	}


	if (mode == "FileStream") {
		choice = 0;
	}
	else if (mode == "FilePointer") {
		choice = 1;
	}
	else if (mode == "rules") {
		choice = 2;
	}
	else {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

// Присвоює параметру значення із вводу
int getK(int& k) {
	blueColor();
	std::cout << "Enter k: ";
	std::cin >> k;
	std::cin.ignore();
	resetColor();
	return EXIT_SUCCESS;
}

// Кольоровий друк
void printMagenta(std::string_view mes) {
	magentaColor();
	std::cout << mes << '\n';
	resetColor();
}

// Перевірка expr із повідомленням при true
int checkWithMessage(bool expr, std::string_view message) {
	if (expr) {
		redColor();
		std::cout << static_cast<std::string>(message) << std::endl;
		resetColor();
		return EXIT_FAILURE;
	}
	else {
		return EXIT_SUCCESS;
	}
}
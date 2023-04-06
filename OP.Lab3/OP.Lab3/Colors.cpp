#include "Colors.h"
#include <iostream>

#define RESET		"\033[0m"
#define BLACK		"\033[30m"				/* Black */
#define RED			"\033[31m"				/* Red */
#define GREEN		"\033[32m"				/* Green */
#define YELLOW		"\033[33m"				/* Yellow */
#define BLUE		"\033[34m"				/* Blue */
#define MAGENTA		"\033[35m"				/* Magenta */
#define CYAN		"\033[36m"				/* Cyan */
#define WHITE		"\033[37m"				/* White */


// Reset to standart color
void resetColor() {
	std::cout << RESET;
}

// Simple colors
void blackColor() {
	std::cout << BLACK;
}
void redColor() {
	std::cout << RED;
}
void greenColor() {
	std::cout << GREEN;
}
void yellowColor() {
	std::cout << YELLOW;
}
void blueColor() {
	std::cout << BLUE;
}
void magentaColor() {
	std::cout << MAGENTA;
}
void cyanColor() {
	std::cout << CYAN;
}
void whiteColor() {
	std::cout << WHITE;
}
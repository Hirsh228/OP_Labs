#ifndef COMMON
#define COMMON
#define _CRT_SECURE_NO_WARNINGS
#define IN_NAME "input.txt"
#define OUT_NAME "output.txt"
#define NEW_NAME "other.txt"
#define STRING_SIZE 256

#include "colors.h"
#include <string_view>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

// Присвоює параметру к значення
int getK(int& k);
// Вибирає режим роботи програми
int make_choice(int argc, char** argv, int& choice);
// Звичайний кольоровий друк
void printMagenta(std::string_view mes);
// Перевірка expr із повідомленням при true
int checkWithMessage(bool expr, std::string_view message);


#endif // !COMMON
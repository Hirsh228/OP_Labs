#ifndef CODE
#define CODE

#include <string_view>
#include <string>
#include <iostream>
#include "classes.h"


void fillArray(ArithmeticProgression* arr, int size);    // Заповнення масиву прогресій
void printSums(ArithmeticProgression* arr, int size);    // Виведення всіх сум
ArithmeticProgression findMaxSum(ArithmeticProgression* arr, int size);    // Повертає прогресію із найбільшою сумою
bool asciiCheck(std::string_view nums);                      // Перевірка вводу
void getNum(int& num, std::string var = "int number");       // Ввід
void getNum(double& num, std::string var = "double number"); // Ввід

#endif // !CODE

#ifndef CODE
#define CODE

#include "Colors.h"
#include "Classes.h"
#include <iostream>
#include <iomanip>
#include <string_view>
#include <fstream>
#include <string>

void task();
void menu(WorkDayTerm t);
int getChoice();
std::string getName();
int printFile(std::string_view fileName);
int createFile(WorkDayTerm t);
int fillFile(std::string_view fileName);
int fileValidation(std::string_view name, WorkDayTerm t);
int appendFile(std::string_view fileName);
bool exists_test(std::string name);
int openAndMake(WorkDayTerm t);


#endif // !CODE

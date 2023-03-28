#ifndef FILE_STREAM_FUNCTIONS
#define FILE_STREAM_FUNCTIONS
#include "Common.h"
#include <fstream>

// Функції для потокового файлу.
// Заповнити файл  
int fillFile(std::string_view fName);
// Вивести файл
int printFile(std::string_view fName);
// Порахувати лінії
int countLines(std::string_view fName);
// Функція виймає із файлу lnum рядок у змінну sVar 
int lineFromFileToVar(std::string_view fName, int lNum, std::string& sVar);
// Рахує слова в рядку
int countWords(std::string_view fName, int lNum);
// Шифрує файл як це поставлено в задачі
int encrypt(std::string_view fName, int k);
// Переміщує не парні рядки до нового файлу
int notEvMoveToNewFile(std::string_view fName, std::string_view nfName);
// Переміщує передостаннє слово кожного рядка на початок рядку
int btlWordAtTheBegin(std::string_view fName);
// Функція поміщає код передостанньої літери                          
//						другого слова                                  
//						останнього рядка                               
//						в його кінець виділивши ":"          
int lineWithCodeToFile(std::string_view fName);


#endif // !FILE_STREAM_FUNCTIONS

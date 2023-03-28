#ifndef FPF
#define FPF

#include "colors.h"
#include "Common.h"
#include <stdio.h>
#include <iostream>
#include <cstring>

// Функції для вказівникового файлу. 
// Заповнити файл  
int pFillFile(FILE* file, const char* fName);
// Вивести файл
int pPrintFile(FILE* file, const char* fName);
// Порахувати лінії
int pCountLines(FILE* file, const char* fName);
// Функція виймає із файлу lnum рядок у змінну sVar 
int pLineFromFileToVar(FILE* file, const char* fName, int lNum, char* sVar);
// Рахує слова в рядку
int pCountWords(FILE* file, const char* fName, int lNum);
// Шифрує файл як це поставлено в задачі
int pEncrypt(FILE* file, const char* fName, int k);
// Переміщує не парні рядки до нового файлу
int pNotEvMoveToNewFile(FILE* file, const char* fName, const char* nFName);

// Не готові функції
//int pNtlWordAtTheBegin(FILE* file, const char* fName);
//int pLineWithCodeToFile(FILE* file, const char* fName);

#endif // !FPF


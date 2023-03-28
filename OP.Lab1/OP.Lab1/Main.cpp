#include "FileStreamFunctions.h"
#include "FilePointerFunctions.h"
#include "colors.h"
#include "Common.h"

// Вхід у програму
int main(int argc, char** argv)
{
    setlocale(LC_ALL, ".UTF8");

    int choice{};
    if (make_choice(argc, argv, choice)) {
        redColor();
        std::cout << "Wrong mode! Visit -more rules." << std::endl;
        resetColor();
        return EXIT_FAILURE;
    }
    FILE* file = NULL;
    int k{};
    switch (choice) {
    // Режим Stream
    case 0:
        cyanColor();
        std::cout << "!Stream Mode!\n";
        resetColor();
        fillFile(IN_NAME);
        getK(k);

        printMagenta("***Вхідний файл***");
        printFile(IN_NAME);

        printMagenta("***Шифрування***");
        encrypt(IN_NAME, k);
        printFile(IN_NAME);

        printMagenta("***Не парні рядки в новому файлі***");
        notEvMoveToNewFile(IN_NAME, NEW_NAME);
        printFile(NEW_NAME);

        printMagenta("***Передостаннє слово переміщене на початок***");
        btlWordAtTheBegin(NEW_NAME);
        printFile(NEW_NAME);

        printMagenta("***Код передостанньої літери, другого слова, останнього рядка між двома :***");
        lineWithCodeToFile(NEW_NAME);
        printFile(NEW_NAME);
        break;
    // Режим поінтерів
    case 1:
        cyanColor();
        std::cout << "!Pointer Mode!\n";
        resetColor();


        pFillFile(file, IN_NAME);
        getK(k);

        printMagenta("***Вхідний файл***");
        pPrintFile(file, IN_NAME);

        printMagenta("***Шифрування***");
        pEncrypt(file, IN_NAME, k);
        pPrintFile(file, IN_NAME);

        printMagenta("***Не парні рядки в новому файлі***");
        pNotEvMoveToNewFile(file, IN_NAME, NEW_NAME);
        pPrintFile(file, NEW_NAME);
        /*
        printMagenta("***Передостаннє слово переміщене на початок***");
        pBtlWordAtTheBegin(file, NEW_NAME);
        pPrintFile(file, NEW_NAME);
        printMagenta("***Код передостанньої літери, другого слова, останнього рядка між двома :***");
        pLineWithCodeToFile(file, NEW_NAME);
        pPrintFile(file, NEW_NAME);
        */

        break;
    // Показ правил
    case 2:
        cyanColor();
        std::cout << "!Rules!\n";
        blueColor();
        std::cout << "Program has 2 modes: Straem and Pointer\n"
            "1) -mode FileStream \n"
            "2) -mode FilePointer\n";
        resetColor();
        break;

    default:
        redColor();
        std::cout << "No choice." << std::endl;
        resetColor();
        return 0;
    }
}

// Задача
#if 0
Створити текстовий файл.Слова у  тексті відділяються  пробілами, комами,
крапками.Зашифруйте даний текст, виконавши у кожному його рядку циклічну
заміну кожної літери на літеру того ж регістру, розташовану  в  алфавіті
на k - й позиції після літери, що  шифрується(k - вводиться із клавіатури).

Наприклад, для англ алфавіту і k = 2 "A" перейде в "C", "a" - в "с",
"b" - в "d", "z" - в "b".

Розділові знаки і пробіли не змінювати.Кожен непарний рядок заміненого
файлу переписати в новий текстовий файл, переставивши передостаннє слово
рядка на його початок.Визанчити код передостанньої літери другого слова
останнього рядка нового тексту і дописати його в кінець даного рядка,
відділивши  символом ":".Вивести вміст вхідного і створеного файлів.
#endif


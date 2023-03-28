#include"code.h"

int main()
{
	WorkDayTerm term;
	bool flag{true};
	std::string fileName;
	task();
	term.setDayTerm();
	do {
		menu(term);
		int choice{getChoice()};
		std::cin.ignore();
		switch (choice){
		case 1:
			system("cls");
			std::cout << "***Open file and make task***\n";
			cyanColor();
			openAndMake(term);
			resetColor();
			system("pause");
			break;
		case 2:
			system("cls");
			std::cout << "***Create file***\n";
			cyanColor();
			createFile(term);
			resetColor();
			system("pause");
			break;
		case 3:
			system("cls");
			std::cout << "***File appending***\n";
			cyanColor();
			fileName = getName();
			printFile(fileName);
			appendFile(fileName);
			resetColor();
			system("pause");
			break;
		case 4:
			system("cls");
			std::cout << "***File reading***\n";
			cyanColor();
			fileName = getName();
			printFile(fileName);
			resetColor();
			system("pause");
			break;
		case 5:
			system("cls");
			std::cout << "***Work day term changing***\n";
			term.setDayTerm();
			break;
		case 6:
			system("cls");
			cyanColor();
			std::cout << "Exit\n";
			flag = false;
			resetColor();
			break;

		default:
			redColor();
			std::cout << "Wrong choice! Try again\n";
			choice = -1;
			resetColor();
			system("pause");
			break;
		}

	} while (flag);
}

#if 0
Створити файд із переліком технічних перерв у роботі каси:
час початку та час кінця перерви. При введенні даних перевіряти,
чи не накладається нова перерва на вже наявну. Визначити, чи
встигне касир обслужити N клієнтів (N ввести з клавіатури), які
стоять у черзі, якщо на одного клієнта в середеьому витрачається
15 хв.
/*
* Вивід інформації про програму (Що робить)
* Введення початку та кінця дня
* Вибір:
* 1. Відкрити файл та виконати завдання
* 2. Cтворити файл
* 3. Доповнити файл
* 4. Прочитати файл
* 5. Змінити початок та кінець дня
* 6. Вийти із програми
*/
#endif


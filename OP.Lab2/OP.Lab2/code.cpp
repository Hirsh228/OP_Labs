#include "code.h"

//Prints our task
void task(){
	system("cls");
	setlocale(LC_ALL, "UTF_8");
	std::cout << "***Наше завдання***\n";
	cyanColor();
	std::cout << 
		"Створити файд із переліком технічних перерв у роботі каси: час \n"
		"початку та час кінця перерви.При введенні даних перевіряти, чи \n"
		"не накладається нова перерва на вже наявну.Визначити, чи встигне \n"
		"касир обслужити N клієнтів(N ввести з клавіатури), які стоять \n"
		"у черзі, якщо на одного клієнта в середеьому витрачається 15 хв.\n\n";
	resetColor();
}
//Prints menu
void menu(WorkDayTerm t) {
	system("cls");
	t.getDayBegin().showTime();
	std::cout << " - ";
	t.getDayEnd().showTime();
	std::cout << "\n";
	std::cout << "***MENU***\n";
	cyanColor();
	std::cout << "1. Open file and make task\n"
				 "2. Create file\n"
				 "3. Append file\n"
				 "4. Read file\n"
				 "5. Change work day term\n"
				 "6. Exit\n";
	resetColor();
}
//Returns int that will use for choice
int getChoice() {
	int c{};
	std::cout << "Enter your choice: ";
	std::cin >> c;
	return c;
}
//Asks for name and returns string 
std::string getName() {
	std::string fName{};
	std::cout << "Enter file name: ";
	std::cin >> fName;
	return fName;
}
//Prints the file
int printFile(std::string_view fileName) {
	system("cls");
	int brBegH, brBegM,
		brEndH, brEndM;
	std::cout.fill('0');
	std::ifstream wrtFromFile(static_cast<std::string>(fileName), std::ios::binary);
	if (!wrtFromFile) {
		std::cerr << "OPEN ERROR!\n";
		wrtFromFile.close();
		return EXIT_FAILURE;
	}
	for (int i = 1; !wrtFromFile.eof(); i++)
	{
		wrtFromFile >> brBegH >> brBegM >> brEndH >> brEndM;
		std::cout << "Break №" << i << ": " << std::setw(2) << brBegH << std::setw(1) << ':' << std::setw(2) << brBegM <<
			" - " << brEndH << std::setw(1) << ':' << std::setw(2) << brEndM << '\n';
	}
	wrtFromFile.close();
	return EXIT_SUCCESS;
}
//Fills the file with data about breaks
int fillFile(std::string_view fileName) {
	system("cls");
	Break break1;
	char ch{};
	
	std::ofstream wrtToFile(static_cast<std::string>(fileName), std::ios::binary);
	if (!wrtToFile) {
		std::cerr << "OPEN ERROR!\n";
		wrtToFile.close();
		return EXIT_FAILURE;
	}
	do {
		break1.setBreakBegin();
		break1.setBreakEnd();

		wrtToFile << ' ' << break1.getBreakBegin().getHour() << ' ' << break1.getBreakBegin().getMinute() << ' '
		<< break1.getBreakEnd().getHour() << ' ' << break1.getBreakEnd().getMinute();

		std::cout << "Nore?(y/n) ";
		std::cin >> ch;
		std::cin.ignore();
		if (ch == 'n' || ch == 'N') {
			break;
		}
	} while (true);
	wrtToFile.close();
	return EXIT_SUCCESS;
}
//Checks file for time overlay
int fileValidation(std::string_view name, WorkDayTerm t) {
	bool isOverlap(Time start1, Time end1, Time start2, Time end2);
	bool termOverlap(Time start1, Time end1, Time start2, Time end2, WorkDayTerm t);
	int tBrBegH, tBrBegM,
		tBrEndH, tBrEndM;
	int curBegH, curBegM,
		curEndH, curEndM;
	Break br1, br2;
	int errorCounter{ 0 };
	int elemsNum{ 0 };
	std::ifstream wrtToFile(static_cast<std::string>(name), std::ios::binary);
	while (!wrtToFile.eof())
	{
		wrtToFile >> curBegH >> curBegM >> curEndH >> curEndM;
		br1.setBreakBegin(curBegH, curBegM);
		br1.setBreakEnd(curEndH, curEndM);
		std::ifstream out(static_cast<std::string>(name), std::ios::binary);
		while (!out.eof()) {
			out >> tBrBegH >> tBrBegM >> tBrEndH >> tBrEndM;
			br2.setBreakBegin(tBrBegH, tBrBegM);
			br2.setBreakEnd(tBrEndH, tBrEndM);
			if (isOverlap(br1.getBreakBegin(), br1.getBreakEnd(), br2.getBreakBegin(), br2.getBreakEnd()))
			{
				errorCounter++;
			}
			if (termOverlap(br1.getBreakBegin(), br1.getBreakEnd(), br2.getBreakBegin(), br2.getBreakEnd(), t))
			{
				errorCounter++;
			}
		}
		elemsNum += 1;
	}

	if (errorCounter > elemsNum) {
		redColor();
		std::cout << "A time overlap occurred!\n";
		resetColor();
		wrtToFile.close();
		return EXIT_FAILURE;
	}
	else
	{
		greenColor();
		std::cout << "File is good!\n";
		resetColor();
		wrtToFile.close();
		return EXIT_SUCCESS;
	}
}
//Appends file
int appendFile(std::string_view fileName){
	
	Break break1;
	char ch{};
	
	if (exists_test(static_cast<std::string>(fileName))) {
		greenColor();
		std::cout << "File exist\n";
		resetColor();
	}
	else {
		redColor();
		std::cout << "File don't exist\n";
		resetColor();
		return EXIT_FAILURE;
	}
	std::ofstream wrtToFile(static_cast<std::string>(fileName), std::ios::binary|std::ios::app);
	if (!wrtToFile) {
		std::cerr << "OPEN ERROR!\n";
		wrtToFile.close();
		return EXIT_FAILURE;
	}
	do {
		break1.setBreakBegin();
		break1.setBreakEnd();

		wrtToFile << ' ' << break1.getBreakBegin().getHour() << ' ' << break1.getBreakBegin().getMinute() << ' '
			<< break1.getBreakEnd().getHour() << ' ' << break1.getBreakEnd().getMinute();

		std::cout << "Nore?(y/n) ";
		std::cin >> ch;
		std::cin.ignore();
		if (ch == 'n' || ch == 'N') {
			break;
		}
	} while (true);
	wrtToFile.close();
	return EXIT_SUCCESS;
}
//Check for duplicate
bool exists_test(std::string name) {
	std::ifstream f(name.c_str());
	return f.good();
}
//Creates file and fill it, but if fill is not correct, it deletes file
int createFile(WorkDayTerm t) {
	std::string fileName = getName();
	if (exists_test(fileName)) {
		std::cout << "Such file already exist\n";
		return EXIT_FAILURE;
	}
	else
	{
		fillFile(fileName);
		if (fileValidation(fileName, t)) {
			redColor();
			std::cout << "Time problems in file!!!\nFile not created.\n";
			resetColor();
			remove(fileName.c_str());
			return EXIT_FAILURE;
		};
		return EXIT_SUCCESS;
	}
}
//Makes main task
int openAndMake(WorkDayTerm t) {
	int n{}, val{};
	std::string fileName = getName();
	std::ifstream wrtFromFile(fileName, std::ios::binary);
	if (!wrtFromFile) {
		redColor();
		std::cerr << "OPEN ERROR\n";
		resetColor();
		return EXIT_FAILURE;
	}
	if (fileValidation(fileName, t)) {
		return EXIT_FAILURE;
	};
	int begH, begM,
		endH, endM,
		sum = 0;
	sum += (t.getDayEnd().timeToMin() - t.getDayBegin().timeToMin());
	while (!wrtFromFile.eof()) {
		wrtFromFile >> begH >> begM >> endH >> endM;
		sum -= (60 * endH + endM) - (60 * begH + begM);

	}
	wrtFromFile.close();
	std::cout << "Enter number of customers: ";
	std::cin >> n;
	std::cin.ignore();
	val = n * 15;
	if (sum > val) {
		greenColor();
		std::cout << "The casier will have time to serve " << n << " customers!\n";
		resetColor();
	}
	else {
		redColor();
		std::cout << "The casier will NOT have time to serve " << n << " customers!\n";
		resetColor();
	}
	return EXIT_SUCCESS;
}
//Checks for time overlay
bool isOverlap(Time start1, Time end1, Time start2, Time end2) {
	if (end2.timeToMin() < start1.timeToMin()) {
		return false;
	}
	if (end1.timeToMin() < start2.timeToMin()) {
		return false;
	}
	return true;
}
//Checks for term overlay 
bool termOverlap(Time start1, Time end1, Time start2, Time end2, WorkDayTerm t) {
	if (t.getDayEnd().timeToMin() > end1.timeToMin() && t.getDayEnd().timeToMin() > end2.timeToMin() &&
		t.getDayBegin().timeToMin() < start1.timeToMin() && t.getDayBegin().timeToMin() < start2.timeToMin()) {
		return false;
	}
	return true;
}


#include "FileStreamFunctions.h"

// Заповнення файлу
int fillFile(std::string_view fName) {
	blueColor();
	std::cout << "!Fill file!\n\n";

	greenColor();

	std::ofstream outFile(static_cast<std::string>(fName));

	if (checkWithMessage(!outFile.is_open(),
		"OPEN ERROR!!!")) {
		outFile.close();
		return EXIT_FAILURE;
	}

	int flag{ 1 };
	std::string sentence{};
	do {
		getline(std::cin >> std::ws, sentence);
		outFile << sentence << '\n';
		std::cout << "More?(No - 0)(Yes - 1): ";
		std::cin >> flag;
		std::cin.ignore();

	} while (flag);

	outFile.close();
	resetColor();
	return EXIT_SUCCESS;
}


// Вивід файлу
int printFile(std::string_view fName) {
	yellowColor();
	std::ifstream inFile(static_cast<std::string>(fName));
	if (checkWithMessage(!inFile.is_open(),
		"OPEN ERROR!!!")) {
		inFile.close();
		return EXIT_FAILURE;
	}

	std::string sentence{};

	while (getline(inFile, sentence) && !sentence.empty())
	{
		std::cout << sentence << "\n";
	}

	inFile.close();
	std::cout << std::endl;
	resetColor();
	return EXIT_SUCCESS;
}


// Рахувати рядки (Повертає к-сть)
int countLines(std::string_view fName) {
	std::ifstream inFile(static_cast<std::string>(fName));
	if (checkWithMessage(!inFile.is_open(),
		"OPEN ERROR!!!")) {
		inFile.close();
		return EXIT_FAILURE;
	}

	int counter{};
	std::string line{};
	while (std::getline(inFile, line)) {
		counter++;
	}

	inFile.close();
	return counter;
}


// Виймає з файлу lNum рядок у змінну sVar
int lineFromFileToVar(std::string_view fName, int lNum, std::string& sVar) {
	std::ifstream inFile(static_cast<std::string>(fName));
	if (checkWithMessage(!inFile.is_open(),
		"OPEN ERROR!!!")) {
		inFile.close();
		return EXIT_FAILURE;
	}

	for (int i = 0; i != lNum; i++) {
		getline(inFile, sVar);
	}

	inFile.close();
	return EXIT_SUCCESS;
}


// Рахує слова в lNUm рядку
int countWords(std::string_view fName, int lNum) {
	std::ifstream inFile(static_cast<std::string>(fName));
	if (checkWithMessage(!inFile.is_open(),
		"OPEN ERROR!!!")) {
		inFile.close();
		return EXIT_FAILURE;
	}

	int linesNum = { countLines(static_cast<std::string>(fName)) };

	if (checkWithMessage(lNum > linesNum,
		"In that file not enough lines!")) {
		inFile.close();
		return EXIT_FAILURE;
	}


	std::string line;

	lineFromFileToVar(static_cast<std::string>(fName), lNum, line);

	std::stringstream buf(line);
	std::string word;
	int words_counter{ 0 };

	while (buf >> word) {
		words_counter++;
	}

	inFile.close();
	return words_counter;

}


// Шифрування за k
int encrypt(std::string_view fName, int k) {
	blueColor();
	std::ifstream inFile(static_cast<std::string>(fName));
	if (checkWithMessage(!inFile.is_open(),
		"OPEN ERROR!!!")) {
		inFile.close();
		return EXIT_FAILURE;
	}

	std::ofstream outFile(static_cast<std::string>(OUT_NAME));
	if (checkWithMessage(!outFile.is_open(),
		"OPEN ERROR!!!")) {
		outFile.close();
		return EXIT_FAILURE;
	}

	std::string sentence{};
	int lineCounter{ 0 };
	while (!inFile.eof()) {
		getline(inFile, sentence);
		lineCounter++;
		for (int j = 0; j < static_cast<int>(sentence.length()); j++) {
			int temp{ static_cast<int>(sentence[j]) };
			if (temp != 32 &&	// Space
				temp != 44 &&	// Coma
				temp != 46 &&	// Dot
				temp != 59		// Semicolon
				) {
				for (int i{ 0 }; i < (k % 26); i++) {
					temp++;
					if (temp == 123 || temp == 91) {
						temp -= 26;
					}
				}
			}
			sentence[j] = static_cast<char>(temp);
			// in sentence
		}

		outFile << sentence;

		if (countLines(fName) != lineCounter) {
			outFile << '\n';
		}
	}

	inFile.close();
	outFile.close();

	std::remove(IN_NAME);	//inName.c_str()
	checkWithMessage(std::rename(OUT_NAME, IN_NAME), "Rename error\n");

	resetColor();
	return EXIT_SUCCESS;
}


// Не парні рядки одного файлу переходять у новий файл
int notEvMoveToNewFile(std::string_view fName, std::string_view nfName) {
	std::ifstream inFile(static_cast<std::string>(fName));
	if (checkWithMessage(!inFile.is_open(),
		"OPEN ERROR!!!")) {
		inFile.close();
		return EXIT_FAILURE;
	}

	std::ofstream outFile(static_cast<std::string>(nfName));
	if (checkWithMessage(!outFile.is_open(),
		"OPEN ERROR!!!")) {
		outFile.close();
		return EXIT_FAILURE;
	}

	int linesNum{ countLines(fName) };
	std::string sentence{};
	for (int i = 0; linesNum > i; i++) {
		getline(inFile, sentence);
		if (((i + 1) % 2) == 1) {
			outFile << sentence;
			if (linesNum != i) {
				outFile << '\n';
			}
		}
	}

	outFile.close();
	inFile.close();

	return EXIT_SUCCESS;
}


// Переставляє передостаннє слово рядка на початоК
int btlWordAtTheBegin(std::string_view fName) {
	std::ifstream inFile(static_cast<std::string>(fName));
	if (checkWithMessage(!inFile.is_open(),
		"OPEN ERROR!!!")) {
		inFile.close();
		return EXIT_FAILURE;
	}
	std::ofstream outFile(OUT_NAME);
	if (checkWithMessage(!outFile.is_open(),
		"OPEN ERROR!!!")) {
		outFile.close();
		return EXIT_FAILURE;
	}

	int lines{ countLines(fName) };
	std::string line{};
	std::string slw{};
	bool flag{};
	for (int i = 0; i < lines; i++) {

		flag = static_cast<bool>(getline(inFile, line));

		size_t wEnd = line.find_last_of(' ');
		size_t wBeg = line.find_last_of(' ', wEnd - 1);

		if (wEnd != -1 &&
			wBeg != -1 &&
			wEnd != wBeg) {
			slw = line.substr(wBeg + 1, wEnd - wBeg - 1);
			line.erase(wBeg + 1, wEnd - wBeg);
		}
		if (wEnd == wBeg &&
			flag == 1) {
			outFile << line;
			if (lines != i) {
				outFile << '\n';
			}
			continue;

		}

		line.insert(0, slw + ' ');
		outFile << line;

		if (lines != i) {
			outFile << '\n';
		}

	}

	inFile.close();
	outFile.close();

	std::remove(static_cast<std::string>(fName).c_str());	//inName.c_str()
	checkWithMessage(std::rename(OUT_NAME, static_cast<std::string>(fName).c_str()), "Rename error\n");

	return EXIT_SUCCESS;
}



// Помістити код передостанньої літери                          
//               другого слова                                  
//               останнього рядка                               
//               в його кінець виділивши ":"          

int lineWithCodeToFile(std::string_view fName) {
	int takeCode(std::string line);
	int insertCode(std::string & line, int code);


	std::ifstream inFile(static_cast<std::string>(fName));
	if (checkWithMessage(!inFile.is_open(),
		"OPEN ERROR!!!")) {
		inFile.close();
		return EXIT_FAILURE;
	}

	std::ofstream outFile(static_cast<std::string>(OUT_NAME));
	if (checkWithMessage(!outFile.is_open(),
		"OPEN ERROR!!!")) {
		outFile.close();
		return EXIT_FAILURE;
	}

	int lines{ countLines(fName) };
	std::string line{};
	int code{};

	for (int i = 0; i < lines; i++) {
		getline(inFile, line);
		if (i == lines - 1) {
			code = takeCode(line);
			insertCode(line, code);
		}
		outFile << line;
		if (lines != i) {
			outFile << '\n';
		}

	}
	inFile.close();
	outFile.close();

	std::remove(static_cast<std::string>(fName).c_str());	//inName.c_str()
	checkWithMessage(std::rename(OUT_NAME, static_cast<std::string>(fName).c_str()), "Rename error\n");

	return EXIT_SUCCESS;
}

// Отримує код передостанньої літери
int takeCode(std::string line) {
	int takeSecWord(std::string_view line, std::string & word);
	std::string word{};
	takeSecWord(line, word);
	int code{};
	int wordLength{ static_cast<int>(word.length()) };
	const int num{ wordLength - 2 };
	if (wordLength <= 1) {
		code = 0;
	}
	else {
		code = static_cast<int>(word[num]);
	}

	return code;
}

// Виймає друге слово рядка
int takeSecWord(std::string_view line, std::string& word) {
	size_t wBeg = line.find(" ");
	size_t wEnd = line.find(" ", wBeg + 1);

	word = line.substr(wBeg + 1, wEnd - wBeg - 1);
	return EXIT_SUCCESS;
}


// Вставляє код у кінець файлу виділивши двома :
int insertCode(std::string& line, int code) {

	std::string insert{ ":" + std::to_string(code) + ":" };
	line.append(insert);

	return EXIT_SUCCESS;
}
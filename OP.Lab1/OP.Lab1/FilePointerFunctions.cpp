#include "FilePointerFunctions.h" 

// Функції для вказівникового файлу. 
// Заповнити файл  
int pFillFile(FILE* file, const char* fName) {
	blueColor();
	std::cout << "!Fill file!\n\n";
	greenColor();
	char error_buffer[STRING_SIZE * 4];

	file = fopen(fName, "w");

	if (file == NULL) {
		strerror_s(error_buffer, errno);
		std::cout << "WARNING!!!" << error_buffer << std::endl;
		fclose(file);
		return EXIT_FAILURE;
	}

	int flag{ 1 };
	char line[STRING_SIZE];

	do {
		std::cin.getline(line, STRING_SIZE - 1);
		fprintf(file, "%s\n", line);
		std::cout << "More?(No - 0)(Yes - 1): ";
		std::cin >> flag;
		std::cin.ignore();
	} while (flag);


	fclose(file);
	resetColor();
	return EXIT_SUCCESS;
}
// Вивести файл
int pPrintFile(FILE* file, const char* fName) {
	char error_buffer[STRING_SIZE * 4];
	yellowColor();
	file = fopen(fName, "r");
	if (file == NULL) {
		strerror_s(error_buffer, errno);
		std::cout << "WARNING!!!" << error_buffer << std::endl;
		fclose(file);
		return EXIT_FAILURE;
	}

	char c;
	while ((c = static_cast<char>(getc(file))) != EOF) {
		putchar(c);
	}
	fclose(file);
	resetColor();
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
// Порахувати лінії
int pCountLines(FILE* file, const char* fName) {
	file = fopen(fName, "r");
	char error_buffer[STRING_SIZE * 4];
	if (file == NULL) {
		strerror_s(error_buffer, errno);
		std::cout << "WARNING!!!" << error_buffer << std::endl;
		fclose(file);
		return EXIT_FAILURE;
	}
	char line[STRING_SIZE];
	int counter{ 0 };
	while (fgets(line, STRING_SIZE, file)) {
		counter++;
	}
	fclose(file);

	return counter;
}
// Функція виймає із файлу lnum рядок у змінну sVar 
int pLineFromFileToVar(FILE* file, const char* fName, int lNum, char* line) {
	file = fopen(fName, "r");
	char error_buffer[STRING_SIZE * 4];
	if (file == NULL) {
		strerror_s(error_buffer, errno);
		std::cout << "WARNING!!!" << error_buffer << std::endl;
		fclose(file);
		return EXIT_FAILURE;
	}
	for (int i = 0; i != lNum; i++) {
		std::fgets(line, STRING_SIZE, file);
	}

	fclose(file);
	return EXIT_SUCCESS;
}
// Рахує слова в рядку
int pCountWords(FILE* file, const char* fName, int lNum) {
	file = fopen(fName, "r");
	char error_buffer[STRING_SIZE * 4];
	if (file == NULL) {
		strerror_s(error_buffer, errno);
		std::cout << "WARNING!!!" << error_buffer << std::endl;
		fclose(file);
		return EXIT_FAILURE;
	}

	int linesNum = { pCountLines(file, fName) };

	if (lNum > linesNum) {
		redColor();
		std::cout << "In that file not enough lines!" << std::endl;
		resetColor();
		fclose(file);
		;		return EXIT_FAILURE;
	}

	char line[STRING_SIZE];

	pLineFromFileToVar(file, fName, lNum, line);
	int word{ 0 },
		words_counter{ 0 };

	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] != ' ' && line[i] != '\n') {
			if (!word) {
				words_counter++;
				word = 1;
			}
		}
		else {
			word = 0;
		}
	}

	fclose(file);
	return words_counter;
}
// Шифрує файл як це поставлено в задачі
int pEncrypt(FILE* file, const char* fName, int k) {
	blueColor();
	file = fopen(fName, "r");
	char error_buffer[STRING_SIZE * 4];
	if (file == NULL) {
		strerror_s(error_buffer, errno);
		std::cout << "WARNING!!!" << error_buffer << std::endl;
		fclose(file);
		return EXIT_FAILURE;
	}
	FILE* outFile;
	outFile = fopen(OUT_NAME, "w");
	if (file == NULL) {
		strerror_s(error_buffer, errno);
		std::cout << "WARNING!!!" << error_buffer << std::endl;
		fclose(outFile);
		return EXIT_FAILURE;
	}

	char sentence[STRING_SIZE];
	int lineCounter{ pCountLines(file, fName) };

	for (int i = 0; i < lineCounter; i++) {
		std::fgets(sentence, STRING_SIZE, file);
		for (int j = 0; j < static_cast<int>(strlen(sentence)); j++) {
			int temp{ static_cast<int>(sentence[j]) };
			if (temp != 32 &&	// Space
				temp != 44 &&	// Coma
				temp != 46 &&	// Dot
				temp != 59 &&	// Semicolon
				temp != 10		// New line
				) {
				for (int l{ 0 }; l < (k % 26); l++) {
					temp++;
					if (temp == 123 || temp == 91) {
						temp -= 26;
					}
				}
			}
			sentence[j] = static_cast<char>(temp);
			// in sentence
		}

		fprintf(outFile, "%s", sentence);

	}

	fclose(file);
	fclose(outFile);

	std::remove(fName);	//inName.c_str()
	checkWithMessage(std::rename(OUT_NAME, fName), "Rename error\n");

	resetColor();
	return EXIT_SUCCESS;
}
// Переміщує не парні рядки до нового файлу
int pNotEvMoveToNewFile(FILE* file, const char* fName, const char* nfName) {
	file = fopen(fName, "r");
	char error_buffer[STRING_SIZE * 4];
	if (file == NULL) {
		strerror_s(error_buffer, errno);
		std::cout << "WARNING!!!" << error_buffer << std::endl;
		fclose(file);
		return EXIT_FAILURE;
	}
	FILE* outFile;
	outFile = fopen(nfName, "w");
	if (file == NULL) {
		strerror_s(error_buffer, errno);
		std::cout << "WARNING!!!" << error_buffer << std::endl;
		fclose(outFile);
		return EXIT_FAILURE;
	}

	int linesNum{ pCountLines(file, fName) };
	char sentence[STRING_SIZE];

	for (int i = 0; linesNum > i; i++) {
		std::fgets(sentence, STRING_SIZE, file);
		if (((i + 1) % 2) == 1) {
			fprintf(outFile, "%s", sentence);
		}
	}

	fclose(outFile);
	fclose(file);

	return EXIT_SUCCESS;
}

// Не готові функції
//int pNtlWordAtTheBegin(FILE* file, const char* fName);
//int pLineWithCodeToFile(FILE* file, const char* fName);
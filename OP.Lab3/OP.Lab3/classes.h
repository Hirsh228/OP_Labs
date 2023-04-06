#ifndef CLASSES
#define CLASSES

#include <iostream>

class ArithmeticProgression {
	double	a{ 0 },	    // Перший член
            d{ 0 },     // Різниця прогресії
            * prog{ nullptr }, // Прогресія
            sum{ 0 };   // Сума	
	int     n{ 0 };	    // К-сть елементів
public:
	ArithmeticProgression(double na = 0, double nd = 0, int nn = 0);    // Конструктор
	~ArithmeticProgression();                                           // Деструктор
	ArithmeticProgression(const ArithmeticProgression& ap);             // Конструктор копіювання
	
	double getA();
	double getD();
	int getN();
	double getSum();
	double* getProg();

	void putA(double A);
	void putD(double D);
	void putN(int N);

	void showProg();    // Показ прогресії
};
#endif // !CLASSES


#include "classes.h"

ArithmeticProgression::ArithmeticProgression(double na, double nd, int nn) : a{ na }, d{ nd }, n{ nn } {
	prog = new double[n];
	prog[0] = na;
	for (int i = 1; i < n; i++) {
		prog[i] = prog[i-1] + d;
	}
	sum = n * (2 * a + d * (n - 1)) / (2);
}

ArithmeticProgression::~ArithmeticProgression(){
	if (prog) {
		delete[] prog;
	}
}

ArithmeticProgression::ArithmeticProgression(const ArithmeticProgression &ap) {
	delete[] prog;
	prog = new double[n];
	*prog = *ap.prog;
	for (int i = 0; i < n; i++) {
		prog[i] = ap.prog[i];
	}
	a = ap.a;
	d = ap.d;
	n = ap.n;
}

void ArithmeticProgression::showProg() {
	for (int i = 0; i < n; i++) {
		std::cout << "Prog " << i + 1 << ": " << prog[i] << '\n';
	}
}


// getters
#if 1
double ArithmeticProgression::getA(){
	return a;
}
double ArithmeticProgression::getD() {
	return d;
}
int ArithmeticProgression::getN() {
	return n;
}
double* ArithmeticProgression::getProg() {
	return prog;
}
double ArithmeticProgression::getSum() {
	//sum = n * (2 * a + d * (n - 1)) / (2);
	return sum;
}
#endif

// Putters
#if 1
void ArithmeticProgression::putA(double A) {
	a = A;
}
void ArithmeticProgression::putD(double D) {
	d = D;
}
void ArithmeticProgression::putN(int N) {
	n = N;
}
#endif


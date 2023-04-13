#include <iostream>

#include "classes.h"
#include "input.h"

int main()
{
    double tP,
           tF;

    magentaColor();
      std::cout << "Enter K1 ( z = p * e ^ (i * f) )\n";
    yellowColor();
    getNum(tP, "p");
    getNum(tF, "f");
      ComplexNum K1(tP, tF);
    greenColor();
      K1.printPowForm();
      K1.printAlgForm();
    
    magentaColor();
      std::cout << "Enter K2 ( z = p * e ^ (i * f) )\n";
    yellowColor();
      getNum(tP, "p");
      getNum(tF, "f");
      ComplexNum K2(tP, tF);
    greenColor();
      K2.printPowForm();
      K2.printAlgForm();

    magentaColor();
      std::cout << "++K1 (Increace Re)\n";
      ++K1;
    greenColor();
      K1.printAlgForm();
      K1.printPowForm();

    magentaColor();
      std::cout << "K2++ (Increace Im)\n";
      K2++;
    greenColor();
      K2.printAlgForm();
      K2.printPowForm();

      ComplexNum K3;
    magentaColor();
      std::cout << "K3 = K1 + K2 \n";
      K3 = K1 + K2;
    greenColor();
      K3.printAlgForm();
      K3.printPowForm();
    resetColor();

    return EXIT_SUCCESS;
}

#if 0
Визначити клас "Комплексне число",який задає комплексні числа в показниковій
формі p = e^(i*f).Членами класу є модуль р та аргумент ф комплексного числа.
Реалізувати для нього декілька конструкторів, геттери, метод переведення числа у
алгебраїчну форму.Перевантажити оператори : префіксний "++" / постфіксний
"++" - для інкрементування дійсної і уявної частини числа відповідно, "+" — ДЛЯ
обчислення суми двох комплексних чисел.Створити три комплексні числа(К1, К2, КЗ),
використовуючи різні конструктори.Інкрементувати дійсну частину числа К1 і уявну 
частину числа К2.Знайти суму змінених чисел К1 і К2 та зберегти її в КЗ.Перевести
число КЗ у алгебраїчну форму.
#endif

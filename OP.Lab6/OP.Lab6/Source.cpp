#include "HashSet.h"

int main() {

    std::string type;
    std::cout << "Enter type: ";
    std::cin >> type;
    if (type == "int") {
        HashSet<int> set1;
        HashSet<int> set2;

        set1.put(1);
        set1.put(2);
        set1.put(5);
        set1.put(3);
        set1.put(3);
        set2.put(2);
        set2.put(3);
        set2.put(8);

        std::cout << "Print set1 using iterator: ";
        for (auto element : set1) {
            std::cout << element << " ";
        }
        std::cout << std::endl;

        std::cout << "Print set2 using iterator: ";
        for (auto element : set2) {
            std::cout << element << " ";
        }

        std::cout << std::endl;

        std::cout << "Merge: " << merge(set1, set2) << std::endl;
        set1.clear();
        std::cout << "Clear set1: " << set1 << std::endl;
        std::cout << std::boolalpha << "Has element 3 set2?: " << set2.has(3) << std::endl;
    }
    else if (type == "double") {
        HashSet<double> set1;
        HashSet<double> set2;
        set1.put(2.1);
        set1.put(7.5);
        set1.put(5.2);
        set1.put(3.3);
        set1.put(3.3);
        set2.put(2.1);
        set2.put(3.3);
        set2.put(7.5);
        set2.put(12.5);

        std::cout << "Print set1 using iterator: ";
        for (auto element : set1) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
        std::cout << "Print set2 using iterator: ";
        for (auto element : set2) {
            std::cout << element << " ";
        }
        std::cout << std::endl;

        std::cout << "Merge: " << merge(set1, set2) << std::endl;
        set1.clear();
        std::cout << "Clear set1: " << set1 << std::endl;
        std::cout << std::boolalpha << "Has element 3.3 set2?: " << set2.has(3.3) << std::endl;
    }
    else if (type == "string") {
        HashSet<std::string> set1;
        HashSet<std::string> set2;
        set1.put("one");
        set1.put("two123");
        set1.put("boo321");
        set2.put("too");
        set2.put("two123");
        set2.put("goo");


        std::cout << "Print set1 using iterator: ";
        for (auto element : set1) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
        std::cout << "Print set2 using iterator: ";
        for (auto element : set2) {
            std::cout << element << " ";
        }
        std::cout << std::endl;

        std::cout << "Merge: " << merge(set1, set2) << std::endl;
        set1.clear();
        std::cout << "Clear set1: " << set1 << std::endl;
        std::cout << std::boolalpha << "Has element koo set2?: " << set2.has("koo") << std::endl;
    }
    else {
        std::cout << "Wrong type!!!" << std::endl;
    }
    return 0;
}
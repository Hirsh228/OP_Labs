#ifndef HASH_SET
#define HASH_SET


#include<iostream>
#include<cmath>
#define TABLE_SIZE 500


// Вузол зв'язного списку
template<typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node(T data) : data(data) {}
};

// Ітератор для переміщення між елементами множини.
template<typename T>
class Iterator {
private:
    Node<T>** table;
    int currentIndex;
    Node<T>* currentNode;

public:
    Iterator(Node<T>** table, int size) : table(table), currentIndex(0), currentNode(nullptr) {
        // Шукаємо непусту клітинку у таблиці
        for (int i = 0; i < size; ++i) {
            if (table[i] != nullptr) {
                currentIndex = i;
                currentNode = table[i];
                break;
            }
        }
    }

    T operator*() const {
        return currentNode->data;
    }

    Iterator<T>& operator++() {
        currentNode = currentNode->next;
        if (currentNode == nullptr) {
            for (int i = currentIndex + 1; i < TABLE_SIZE; ++i) {
                if (table[i] != nullptr) {
                    currentIndex = i;
                    currentNode = table[i];
                    break;
                }
            }
        }
        return *this;
    }

    bool operator!=(const Iterator<T>& other) const {
        return currentNode != other.currentNode;
    }
};

// Хеш таблиця
template<typename T>
class HashSet {
private:
    Node<T>* table[TABLE_SIZE];

    // Функція, яка потребує спеціалізації.
    int hash(T value) const {
        return std::abs(value % TABLE_SIZE);
    }

public:
    HashSet() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    HashSet(const HashSet<T>& set) {
        Node<T>* current = nullptr;
        for (int i = 0; i < TABLE_SIZE; i++) {
            current = set.table[i];
            while (current != nullptr) {
                put(current->data);
                current = current->next;
            }
        }
    }

    HashSet<T>& operator=(const HashSet<T>& set) {
        Node<T>* current = nullptr;
        for (int i = 0; i < TABLE_SIZE; i++) {
            current = set.table[i];
            while (current != nullptr) {
                put(current->data);
                current = current->next;
            }
        }

        return *this;
    }
    // Вставка у список
    void put(T value) {
        int index = hash(value);
        Node<T>* newNode = new Node<T>(value);
        if (table[index] == nullptr) {
            table[index] = newNode;
            return;
        }

        Node<T>* current = table[index];
        if (current->data == value) return;
        while (current->next != nullptr) {
            if (current->data == value) return;
            current = current->next;
        }

        current->next = newNode;
    }
    // Очистка списка
    void clear() {
        Node<T>* current;
        Node<T>* temp;

        // Очищуємо пам'ять
        for (int i = 0; i < TABLE_SIZE; i++) {
            current = table[i];
            while (current != nullptr) {
                temp = current;
                current = current->next;
            }
        }

        // Анулюємо покажчики
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }
    
    // Перевірка чи є елемент у списку
    bool has(T value) const {
        int index = hash(value);
        Node<T>* current = table[index];

        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }

        return false;
    }
    // Видалення елемента
    void remove(T value) {
        int index = hash(value);
        Node<T>* current = table[index];
        Node<T>* prev = nullptr;


        while (current != nullptr) {
            if (current->data == value) {
                if (prev == nullptr) {
                    table[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Ітератор на початок
    Iterator<T> begin() { return Iterator<T>(table, TABLE_SIZE); }

    // Ітератор на кінець
    Iterator<T> end() { return Iterator<T>(nullptr, 0); }

    // Дружня функція для з'єднання
    template<typename U>
    friend HashSet<U> merge(HashSet<U>& set1, HashSet<U>& set2);


    // Оператор виведення.
    friend std::ostream& operator<<(std::ostream& out, const HashSet<T>& set) {
        Node<T>* current;
        for (int i = 0; i < TABLE_SIZE; i++) {
            current = set.table[i];
            while (current != nullptr) {
                out << current->data << " ";
                current = current->next;
            }
        }

        return out;
    }


    // Деструктор
    ~HashSet()
    {
        Node<T>* current = nullptr;
        Node<T>* temp = nullptr;
        for (int i = 0; i < TABLE_SIZE; i++) {
            current = table[i];
            while (current != nullptr) {
                temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

template<typename T>
HashSet<T> merge(HashSet<T>& set1, HashSet<T>& set2) {

    HashSet<T> result;
    Node<T>* current = nullptr;
    for (int i = 0; i < TABLE_SIZE; i++) {
        current = set1.table[i];
        while (current != nullptr) {
            result.put(current->data);
            current = current->next;
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        current = set2.table[i];
        while (current != nullptr) {
            result.put(current->data);
            current = current->next;
        }
    }

    return result;
}


// Спеціалізація хеш-функції для рядків типу std::string
template<>
int HashSet<std::string>::hash(std::string value) const {
    int chars = 0;
    for (int i = 0; i < value.length(); i++) {
        chars += value[i];
    }

    return chars % TABLE_SIZE;
}

// Спеціалізація хеш-функції для рядків типу const char*
template<>
int HashSet<const char*>::hash(const char* value) const {
    int chars = 0;
    for (int i = 0; i < strlen(value); i++) {
        chars += value[i];
    }

    return chars % TABLE_SIZE;
}

// Спеціалізація хеш-функції для типу double
template<>
int HashSet<double>::hash(double value) const {
    return (int)value % TABLE_SIZE;
}

#endif // !HASH_SET

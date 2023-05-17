// methods.h
#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include <string>
#include "code.h"

class TIntNumber {
private:
    int decValue{};
public:
    TIntNumber(int decNum = 0);
    void setDec(int num);
    TIntNumber operator+(TIntNumber obj);
    bool operator<(TIntNumber obj);
    bool operator>(TIntNumber obj);
    bool operator==(TIntNumber obj);
    long long getBin();
    int getDec();
    std::string getHex();
    void print(std::string str);
};

class TIntNumber2 : public TIntNumber {
private:
    int binValue{};
public:
    TIntNumber2(int decNum = 0);
};

class TIntNumber16 : public TIntNumber {
private:
    std::string hexValue{};
public:
    TIntNumber16(std::string hexNum = "0000");
};

#endif


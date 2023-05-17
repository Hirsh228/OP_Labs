#include "code.h"

// get bin -  return dec
int binToDec(long binNum)
{
    int decNum{ 0 },
        rem{};
    for (int i = 0; binNum != 0; i++) {
        rem = binNum % 10;
        binNum /= 10;
        decNum += static_cast<int>(rem * pow(2, i));
    }
    return decNum;
}

// get hex - return dec
int hexToDec(std::string hexNum)
{
    int hexLen = static_cast<int>(hexNum.length()),
        r{},
        decNum{};
    for (int i = 0; hexNum[i] != '\0'; i++)
    {
        hexLen--;
        if (hexNum[i] >= '0' && hexNum[i] <= '9')
        {
            r = hexNum[i] - 48; // static_cast in int
        }
        else if (hexNum[i] >= 'a' && hexNum[i] <= 'f')
        {
            r = hexNum[i] - 87;
        }
        else if (hexNum[i] >= 'A' && hexNum[i] <= 'F')
        {
            r = hexNum[i] - 55;
        }
        decNum += static_cast<int>(r * pow(16, hexLen));
    }

    return decNum;
}
// Format output
//void printTable(const TIntNumber& bin, const TIntNumber& hex){
//    std::cout << "__________________________________________________\n"
//              << "|\t Bin Sum \t |\t Hex sum \t | "
//              << "| Dec: " << bin.getDec() << "\t\t| Dec: " << hex.getDec() << "\t\t| ";   
//                       
//}
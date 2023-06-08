#ifndef TEXTFILE_H
#define TEXTFILE_H
#include<string>
#include<string.h>
#include<fstream>
#include<iostream>

class TextFile
{
private:
    std::string _path;
public:
    TextFile(const char* path);
    std::string read();
    void write(const std::string& data) const;
};

#endif // TEXTFILE_H

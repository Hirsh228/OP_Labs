#include "textfile.h"

TextFile::TextFile(const char* path) : _path(path) {}

std::string TextFile::read() {

    std::string data = "";
    std::ifstream in(_path);
    if (!in.is_open()) {
        std::string error;
        char buffer[255];
        strerror_s(buffer, 255, errno);
        error = buffer;
        in.close();
        throw std::runtime_error("Cannot open the file in read mode!\nDetails: " + error);
    }

    std::string line;
    while(std::getline(in, line)) {
        data += line + '\n';
    }

    in.close();
    return data;
}

void TextFile::write(const std::string& data) const {
    std::ofstream out(_path);
    if (!out.is_open()) {
        std::string error;
        char buffer[255];
        strerror_s(buffer, 255, errno);
        error = buffer;
        out.close();
        throw std::runtime_error("Cannot open the file in write mode!\nDetails: " + error);
    }

    out << data;
    out.close();
}

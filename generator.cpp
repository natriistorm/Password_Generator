#include <iostream>
#include <fstream>
#include "PasswordGenerator.h"

void workingWithUser(int& number, int& length, std::string& filename) {
    std::cout << "Enter number of passwords" << "\n";
    std::cin >> number;
    std::cout << "Enter length of password (lesser than 32)" << "\n";
    std::cin >> length;
    if (number <= 0 or length <= 0 or number > 32) {
        throw std::length_error("Incorrect length of password");
    }
    std::cout << "Enter name of file to write generated passwords" << "\n";
    std::cin >> filename;
}


int main() {
    int number, length;
    std::string filename;
    try {
        workingWithUser(number, length, filename);
    } catch(std::exception& ex) {
        std::cout << ex.what();
        return 1;
    }
    std::ofstream outputFile(filename);
    PasswordGenerator passwords = PasswordGenerator(number, length, outputFile);
    std::cout << "Passwords are generated" << "\n";
    return 0;
}

//
// Created by Анастасия on 02.07.2021.
//
#include <vector>
#include <algorithm>
#include <random>
#include <vector>
#include <fstream>
#ifndef GENERATING_PASSWORDS_PASSWORDGENERATOR_H
#define GENERATING_PASSWORDS_PASSWORDGENERATOR_H
class PasswordGenerator{
private:
    int numberOfPasswords;
    int lengthOfPassword;
    std::vector<char> password;
public:

    PasswordGenerator(const int& number, const int& length, std::ofstream& outputFile) :
        numberOfPasswords(number), lengthOfPassword(length) {
        password.resize(lengthOfPassword);
        for (int i = 0; i < numberOfPasswords; ++i) {
            assign();
            for (int j = 0; j < lengthOfPassword; ++j) {
                outputFile << password[j];
            }
            outputFile << "\n";
        }
        outputFile.close();
    }

    void assign() {
        std::mt19937 gen(time(0));
        std::uniform_int_distribution<> uid(0, lengthOfPassword);
        int numbers = uid(gen);
        std::uniform_int_distribution<> smallLettersUid(0, lengthOfPassword - numbers);
        int smallLetters = smallLettersUid(gen);
        std::uniform_int_distribution<> bigLettersUid(0, lengthOfPassword - numbers - smallLetters);
        for (int i = 0; i < numbers; ++i) {
            password[i] = static_cast<char>(uid(gen) % 10 + 48);
        }
        for (int j = numbers; j < numbers + smallLetters; ++j) {
            password[j] = static_cast<char>(smallLettersUid(gen) % 26 + 97);
        }
        for (int j = numbers + smallLetters; j < lengthOfPassword - 2; ++j) {
            password[j] = static_cast<char>(bigLettersUid(gen) % 26 + 65);
        }
        password[lengthOfPassword - 2] = '_';
        password[lengthOfPassword - 1] = '!';
        std::shuffle(password.begin(), password.end(), std::mt19937(std::random_device()()));
    }
};
#endif //GENERATING_PASSWORDS_PASSWORDGENERATOR_H

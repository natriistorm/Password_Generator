#include "passwordgenerator.h"
#include <QTextStream>
#include <QFile>
#include <random>

PasswordGenerator::PasswordGenerator(const int& number, const int& length,
                                     QFile& outputFile) :
    numberOfPasswords(number), lengthOfPassword(length) {
    password.resize(lengthOfPassword);
    if (outputFile.open(QIODevice::WriteOnly)) {
        QTextStream out(&outputFile);
        for (int i = 0; i < numberOfPasswords; ++i) {
            assign();
            for (int j = 0; j < lengthOfPassword; ++j) {
                out << password[j];
            }
            out << "\n";
        }
    }
    outputFile.close();
}

void PasswordGenerator::assign() {
    std::mt19937 gen(time(0));
    int numbers = gen() % lengthOfPassword;
    int smallLetters = gen() % (lengthOfPassword - numbers);
    for (int i = 0; i < numbers; ++i) {
        password[i] = static_cast<char>(gen() % 10 + 48);
    }
    for (int j = numbers; j < numbers + smallLetters; ++j) {
        password[j] = static_cast<char>(gen() % 26 + 97);
    }
    for (int j = numbers + smallLetters; j < lengthOfPassword - 2; ++j) {
        password[j] = static_cast<char>(gen() % 26 + 65);
    }
    password[lengthOfPassword - 2] = '_';
    password[lengthOfPassword - 1] = '!';
    std::shuffle(password.begin(), password.end(), std::mt19937(std::random_device()()));
}

#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <vector>
#include <QFile>
class PasswordGenerator
{
public:
    PasswordGenerator(const int& number, const int& length, QFile& outputFile);
    int numberOfPasswords;
    int lengthOfPassword;
    std::vector<char> password;
    void assign();
};

#endif // PASSWORDGENERATOR_H

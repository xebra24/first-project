#include <string>

#include "Header.h"
#include "Person.h"

// Declared as externs, header.h
const std::string welcome_txt = "assets/welcome.txt";
const std::string choice_txt = "assets/initialUserChoice.txt";

int main() {
    fileOut(welcome_txt);   // mainFuncs.cpp
    choose();               // mainFuncs.cpp
    return 0;
}
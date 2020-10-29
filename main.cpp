#include <string>

#include "Header.h"
#include "Person.h"

using std::string;

// Declared as externs, header.h
const string welcome_txt = "assets/welcome.txt";
const string choice_txt = "assets/initialUserChoice.txt";

int main() {
    fileOut(welcome_txt);   // mainFuncs.cpp
    choose();               // mainFuncs.cpp
    return 0;
}
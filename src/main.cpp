#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

#include "ui.h"
#include "logic.h"
#include "Person.h"
#include "file_management.h"
#include "header.h"

using std::string;
using std::vector;
namespace fs = std::filesystem;

// Declared as externs, header.h
const string welcome_txt = "assets/welcome.txt";
const string choice_txt = "assets/initialUserChoice.txt";
vector<Person> people;

int main()
{
    printFileContents(welcome_txt);
    choose();
    return 0;
}
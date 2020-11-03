#include <string>
#include <vector>
#include <filesystem>

#include "ui.h"
#include "logic.h"
#include "Person.h"
#include "file_manage.h"
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
    fileOut(welcome_txt);   
    choose();               
    return 0;
}
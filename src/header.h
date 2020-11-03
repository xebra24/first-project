#pragma once

#include <vector>
#include <filesystem>

#include "Person.h"

using std::vector;
using std::string;
namespace fs = std::filesystem;

extern vector<Person> people;       // Defined main.cpp
extern const string welcome_txt;    // Defined main.cpp    
extern const string choice_txt;     // Defined main.cpp 
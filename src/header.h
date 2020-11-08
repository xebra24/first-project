#pragma once

#include <vector>
#include <filesystem>

#include "Person.h"

using std::string;
using std::vector;
namespace fs = std::filesystem;

extern vector<Person> people;    // Defined main.cpp
extern const string welcome_txt; // Defined main.cpp
extern const string choice_txt;  // Defined main.cpp
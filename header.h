#pragma once

#include <vector>

#include "Person.h"

extern std::vector<Person> people;      // Defined mainFuncs.cpp
extern const std::string welcome_txt;    // Defined main.cpp    
extern const std::string choice_txt;     // Defined main.cpp 

// All defined in mainFuncs.cpp
void getPeople();
void check();
std::vector<Person> order(std::vector<Person>& p);
bool sortPancakes(const Person& lhs, const Person& rhs);
bool sortPNum(const Person& lhs, const Person& rhs);
void sortPeople();
void waitToExit();
void fileOut(std::string file_loc);
void choose();
void saveInput();
void viewOldData();
std::vector<Person> editEntries(std::vector<Person>& vec);
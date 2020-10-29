#pragma once

#include <vector>

#include "Person.h"

extern vector<Person> people;      // Defined mainFuncs.cpp
extern const string welcome_txt;    // Defined main.cpp    
extern const string choice_txt;     // Defined main.cpp 

// All defined in mainFuncs.cpp
void getPeople();
void check();
vector<Person> order(vector<Person>& p);
bool sortPancakes(const Person& lhs, const Person& rhs);
bool sortPNum(const Person& lhs, const Person& rhs);
void sortPeople();
void waitToExit();
void fileOut(string file_loc);
void choose();
void saveInput();
void viewOldData();
vector<Person> editEntries(vector<Person>& vec);
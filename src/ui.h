#pragma once

#include <vector>
#include <string>

#include "header.h"

using std::vector;
using std::string;

vector<Person> editEntries(vector<Person>& vec);
void viewOldData();
void getPeople();
void waitToExit();
void fileOut(string file_loc);
void saveInput();
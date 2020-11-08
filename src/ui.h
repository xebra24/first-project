#pragma once

#include <vector>
#include <string>

#include "header.h"

using std::string;
using std::vector;

vector<Person> editEntries();
void viewOldData();
void getPeople();
void waitToExit();
void fileOut(string file_loc);
void saveInput();
void check();
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>

#include "header.h"
#include "Person.h"

using std::vector; using std::cout;
using std::cin; using std::string;

vector<Person> people;     // Declared extern, header.h

// Add user-specified number of people to vector<Person> people;
void getPeople() {
    int numPeople;
    cout << "\nHow many people are there? ";
    cin >> numPeople;
    cout << std::endl;

    for (int i = 1; i <= numPeople; ++i) {
        Person person(i, 0);
        people.push_back(person);
    }

    for (auto& element : people) {
        element.getPancakesConsumed(element);                           // Person.cpp
    }
}

// Allow user to check their entries
void check() {
    vector<char> yes_or_no (1);
    cout << "\nDo you want to check your entries? y/n: ";
    cin >> yes_or_no[0];
    cout << std::endl;

    if (yes_or_no[0] == 'y' || yes_or_no[0] == 'Y') {
        for (auto const& element : people) {
            element.printPancakesEaten(cout, element);             // Person.cpp
        }
        cout << std::endl;

        vector<char> yes_or_no2 (1);
        cout << "Is this correct? y/n: ";
        cin >> yes_or_no2[0];

        if (yes_or_no2[0] == 'N' || yes_or_no2[0] == 'n') {
            editEntries(people);
        }

        else if (yes_or_no2[0] == 'Y' || yes_or_no2[0] == 'y') {
            return;
        }

        else { // TODO: Add function to go back to beginning of if statement
            cout << "Your entry is invalid, please try again.";
        }
    }

    else if (yes_or_no[0] == 'n' || yes_or_no[0] == 'N') {
        return;
    }
    
    else {
        std::cerr << "Your entry is invalid, please try again.\n";
        check();
    }
}

// For use in std::sort(); used instead of operator<
bool sortPancakes(const Person& lhs, const Person& rhs) {
    return lhs.returnPancakesConsumed() < rhs.returnPancakesConsumed(); //Person.cpp
}

// For use in std::sort(); used instead of operator<
bool sortPNum(const Person& lhs, const Person& rhs) {
    return lhs.returnPersonNumber() < rhs.returnPersonNumber();         //Person.cpp
}

// Check if user wants ordered list, if yes returns sorted
// vector<People> people, low to high, otherwise exits program.
void sortPeople() {
    vector<char> yes_or_no (1);
    cout << "Would you like an ordered list? y/n: ";
    cin >> yes_or_no[0];

    if (yes_or_no[0] == 'y' || yes_or_no[0] == 'Y') {
        cout << std::endl;
        std::sort(people.begin(), people.end(), sortPancakes);
        for (auto& element : people) {
            element.printPancakesEaten(cout, element);             // Person.cpp
        }
    }
    
    else if (yes_or_no[0] == 'n' || yes_or_no[0] == 'N') {
        return;
    }
    
    else {
        cout << "Your entry is invalid, please try again.\n";
        sortPeople();
    }
    std::sort(people.begin(), people.end(), sortPNum); // Reset ordering of people
}

// Don't immediately exit
void waitToExit() {
    string input;
    cout << "\nType anything, then press enter to exit program." << std::endl;
    cin >> input;
}

// Output contents of specified file
void fileOut(string file_loc) {
    string message;
    std::ifstream out;
    out.open(file_loc);

    if (out.is_open()) {
        // Print welcome message in welcome.txt
        while (std::getline (out, message)) {
            cout << message << std::endl;
        }
    }
}

// Allow user choice of creating new data or reviewing old data
void choose() {
    fileOut(choice_txt);

    vector<char> choice (1);
    cin >> choice[0];

    // If creating new data
    if (choice[0] == '1') {
            getPeople();    // mainFuncs.cpp
            check();        // mainFuncs.cpp
            sortPeople();   // mainFuncs.cpp
            saveInput();    // mainFuncs.cpp
            waitToExit();   // mainFuncs.cpp
    }

    // Otherwise we review old .txt output file (NOT FUNCTIONAL)
    else if (choice[0] == '2') {
        viewOldData();  // mainFuncs.cpp
        waitToExit();
    }
    
    else if (choice[0] == '3') {
        return;
    }

    else {
        std::cerr << "Your entry is invalid, please try again.\n" << std::endl;
        choose();
    }
}

// Save user input to file (only one file at a time, for now)
void saveInput() {
    vector<char> yes_or_no (1);
    cout << "\nWould you like to save your input? y/n: ";
    cin >> yes_or_no[0];

    if (yes_or_no[0] == 'y' || yes_or_no[0] == 'Y') {
        // Get current time to name file
        time_t t = time(0);
        struct tm * now = localtime( & t );

        char buffer [80];
        strftime (buffer, 80, "outFiles/%Y-%m-%d-%H%M.txt", now);
        
        // Create file [time].txt
        std::ofstream outFile;
        outFile.open(buffer);

        if (outFile.is_open()) {
            for (auto const element : people) {
                // Store pancakes eaten in outFile.txt
                element.printPancakesEaten(outFile, element);
            }

            outFile << std::endl;

            // Ordered list in outFile.txt
            outFile << "\nOrdered list:\n" << std::endl;
            std::sort(people.begin(), people.end(), sortPancakes);

            for (auto const& element : people) {
                element.printPancakesEaten(outFile, element);
            }

            std::sort(people.begin(), people.end(), sortPNum); // Reset ordering of people
            cout << "Done." << std::endl;
        }

        else {
            std::cerr << "Error opening file!" << std::endl;
        }

        outFile.close();
    }
    
    else if (yes_or_no[0] == 'n' || yes_or_no[0] == 'N') {
        cout << "Goodbye!" << std::endl;
        return;
    }
    
    else {
        std::cerr << "Your entry is invalid, please try again." << std::endl;
        saveInput();
    }
}

void viewOldData() {
    std::ifstream out ("outFiles/2020-10-25-1153.txt");
    string line;
    if (out.is_open()) {
        while (std::getline(out, line)) {
            cout << line << '\n';
        }
        out.close();
    }
    
    else {
        std::cerr << "Error opening file!" << std::endl;
    }
}

vector<Person> editEntries(vector<Person>& vec) {
    int personToEdit;
    cout << "Please type the number of the person to edit: ";
    cin >> personToEdit;
    cout << std::endl;

    people[personToEdit].getPancakesConsumed(people[personToEdit - 1]);

    return people;
}
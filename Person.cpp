#include <iostream>

#include "Person.h"

using std::cout;
using std::cin;

// Get how many pancakes eaten
void Person::getPancakesConsumed(Person& p) {
    cout << "How many pancakes did person " << 
    p.returnPersonNumber() << " consume? ";
    cin >> p.pancakesConsumed;
}

// How many pancakes eaten
int Person::returnPancakesConsumed() const {
    return pancakesConsumed;
}

// Return person num
int Person::returnPersonNumber() const {
    return personNum;
}

// Print how many pancakes person [x] ate
void Person::printPancakesEaten(std::ostream& out, const Person& p) const {
    int pNumber = p.returnPersonNumber();

    if (p.returnPancakesConsumed() == 1) {
        out << "Person " << pNumber << " ate " << p.returnPancakesConsumed() << " pancake." << std::endl;
    }

    else {
        out << "Person " << pNumber << " ate " << p.returnPancakesConsumed() << " pancakes." << std::endl;
    }
}

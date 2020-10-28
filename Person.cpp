#include <iostream>

#include "Person.h"

// Get how many pancakes eaten
void Person::getPancakesConsumed(Person& p) {
    std::cout << "How many pancakes did person " << 
    p.returnPersonNumber() << " consume? ";
    std::cin >> p.pancakesConsumed;
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

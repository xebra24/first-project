#pragma once

class Person
{
    // DATA MEMBERS
    unsigned int personNum;
    unsigned int pancakesConsumed;

public:
    // CONSTRUCTORS
    Person() = default;
    Person(int n) : personNum(n) {}

    // METHODS
    // Setting member values
    void getPancakesConsumed(Person &p);

    // Returning member values
    int returnPancakesConsumed() const;
    int returnPersonNumber() const;
    void printPancakesEaten(std::ostream &out, const Person &p) const;
};
#include <iostream>
#include <string>
#include <vector>
#include "header.h"

void get_nums_of_pancakes() {
    //Get the no. of pancakes eaten by person 1, 2, etc. up to person 10.
    for (int i = 0; i < 10; i++) {
        person[i] = i + 1;
        std::cout << "Input the number of pancakes entered by person " << person[i] << ": ";
        std::cin >> num_eaten_pancakes[i];
    }
}

//Who ate the most pancakes
int who_ate_most() {
    for (int i = 0; i < 10; i++) {
        if (num_eaten_pancakes[i] > most_pancakes) {
            most_pancakes = num_eaten_pancakes[i];
            person_who_ate_most = person[i];
        }
    }
    return person_who_ate_most;
}

//Who ate the least pancakes
int who_ate_least() {
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            least_pancakes = num_eaten_pancakes[i];
        }

        if (num_eaten_pancakes[i] <= least_pancakes) {
            least_pancakes = num_eaten_pancakes[i];
            person_who_ate_least = person[i];
        }
    }
    return person_who_ate_least;
}

void review_entries() {
    //Ask user if they want to review entries
    std::string yes_or_no = "";
    std::cout << "Would you like to review your entries? Y/n: ";
    std::cin >> yes_or_no;

    //If answer is yes, we output all the entries, then check if it is correct.
    if (yes_or_no == "y" || yes_or_no == "Y") {
        for (int i = 0; i < 10; i++) {
            std::cout << "Person " << person[i] << " ate " << num_eaten_pancakes[i] << "\n";
        }
        std::cout << "\n" << "Is this correct? Y/n: ";
        std::cin >> yes_or_no;
        
        //If it is correct, we finish the program.
        if (yes_or_no == "Y" || yes_or_no == "y") {
            std::cout << "Goodbye!";
        }

        //If it is not correct, we do the whole thing again.
        else
            get_nums_of_pancakes();
            display_person_who_ate_most();
            display_person_who_ate_least();
            review_entries();
    }

    else
        return;
}

void display_person_who_ate_most() {
    person_who_ate_most = who_ate_most();
    std::cout << "Person " << who_ate_most() << " ate the most pancakes with " 
        << num_eaten_pancakes[(__int64)person_who_ate_most - 1] << " eaten." << std::endl;
}

void display_person_who_ate_least() {
    person_who_ate_least = who_ate_least();
    std::cout << "Person " << who_ate_least() << " ate the least pancakes with " 
        << num_eaten_pancakes[(__int64)person_who_ate_least - 1] << " eaten." << std::endl;
}

void wait_to_exit() {
    std::string input;
    std::cout << "Press any letter key to end the program. . . \n";
    std::cin >> input;
}

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

#include <iostream>
#include <string>
#include <vector>
#include "header.h"

std::vector<int> person = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
std::vector<int> pancakes(10);

int most_pancakes = 0;
int person_who_ate_most = 0;

int main() {
    get_nums_of_pancakes();
    person_who_ate_most = who_ate_most();
    std::cout << "Person " << who_ate_most() << " ate the most pancakes " << "with " 
        << pancakes[person_who_ate_most - 1] << " eaten.";
    return 0;
}

/*TO FIX:
 - Clunky variable names
 - Which person eats the least
 - Ask user to review inputs, then allow them to edit it
 - Ordered list of who at most
 */
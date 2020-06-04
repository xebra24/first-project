#include <iostream>
#include <string>
#include <vector>
#include "header.h"

std::vector<int> person = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
std::vector<int> num_eaten_pancakes(10);

int most_pancakes = 0;
int least_pancakes = 0;
int person_who_ate_most = 0;
int person_who_ate_least = 0;

int main() {
    get_nums_of_pancakes();
    display_person_who_ate_most();
    display_person_who_ate_least();
    review_entries();
    return 0;
}

#include <vector>
#include <string>

//VARIABLES
//Vectors for 10 people, pancakes
extern std::vector<int> person;
extern std::vector<int> num_eaten_pancakes;

extern int most_pancakes;
extern int least_pancakes;
extern int person_who_ate_most;
extern int person_who_ate_least;

//FUNCTIONS
void get_nums_of_pancakes();
int who_ate_most();
int who_ate_least();

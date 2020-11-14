#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <map>
#include <ctime>

#include "header.h"
#include "logic.h"
#include "ui.h"
#include "Person.h"

namespace fs = std::filesystem;

using std::cin;
using std::cout;
using std::string;
using std::vector;

// Output contents of specified file
void printFileContents(string file_loc)
{
    string line;
    std::ifstream out;
    out.open(file_loc);

    if (out.is_open())
    {
        while (std::getline(out, line))
        {
            cout << line << '\n';
        }
    }

    else
    {
        cout << "Error opening file!";
    }
}

void printFileContents(fs::path path)
{
    string line;
    std::ifstream out;
    out.open(path);

    if (out.is_open())
    {
        while (std::getline(out, line))
        {
            cout << line << '\n';
        }
    }

    else
    {
        cout << "Error opening file!";
    }
}

void writeToFile(string file_name)
{
    file_name.c_str();
    std::ofstream out_file(file_name);

    if (out_file.is_open())
    {
        for (auto const &element : people)
        {
            // Store pancakes eaten in output file
            element.printPancakesEaten(out_file, element);
        }

        out_file << std::endl;

        // Ordered list in the output file
        out_file << "Ordered list:\n";
        std::sort(people.begin(), people.end(), sortPancakes);

        for (auto const &element : people)
        {
            element.printPancakesEaten(out_file, element);
        }

        std::sort(people.begin(), people.end(), sortPNum); // Reset ordering of people
        cout << "Done." << std::endl;

        //Basic statistics in the output file
        std::sort(people.begin(), people.end(), sortPancakes);

        int sum = 0, num_people = 0;
        double average = 0, median_person = 0, median = 0;

        for (auto &element : people)
        {
            sum += element.returnPancakesConsumed();
            ++num_people;
        }

        if (num_people % 2)
        {
            median = (people.at(people.size() / 2).returnPancakesConsumed() + people.at((people.size() / 2) + 1).returnPancakesConsumed()) / 2;
        }

        else
        {
            median = people.at(people.size() / 2).returnPancakesConsumed();
        }

        average = sum / num_people;

        out_file << "\nThe average number of pancakes consumed is "
                 << average << ".\n";

        out_file << "\nThe median number of pancakes consumed is "
                 << median << ".\n";
    }

    else
    {
        std::cerr << "Error opening file!" << std::endl;
    }
}

// Save user input to file
void saveInput()
{
    string yes_or_no;
    cout << "\nWould you like to save your input? y/n: ";
    cin >> yes_or_no;

    if (yes_or_no == "y" || yes_or_no == "Y")
    {
        string yes_or_no2;
        cout << "\nWould you like a custom name for the file? y/n (if n, the time will be used): ";
        cin >> yes_or_no2;

        if (yes_or_no2 == "y" || yes_or_no2 == "Y")
        {
            string file_name = "./out_files/";
            string temp;
            cout << "Enter a name: ";
            cin >> temp;
            file_name += temp;
            file_name += ".txt";
            
            writeToFile(file_name);
        }

        else if (yes_or_no2 == "n" || yes_or_no2 == "N")
        {
            // Get current time to name file
            time_t t = time(0);
            struct tm *now = localtime(&t);

            char buffer[80];
            strftime(buffer, 80, "./out_files/%Y-%m-%d-%H%M.txt", now);

            string file_name(buffer);

            writeToFile(file_name);
        }

        else
        {
            std::cerr << "Your entry is invalid, please try again." << std::endl;
            saveInput();
        }
    }
}

void showOutFiles()
{
    fs::path path = "./out_files";
    fs::directory_iterator it(path);
    int counter = 1;
    std::map<int, fs::path> files; // Map files to an int to print user choice

    for (auto &element : it)
    {
        fs::path temp_path = *it;
        std::cout << counter << ": " << temp_path.filename() << '\n';

        files.insert(std::pair<int, fs::path>(counter, temp_path.relative_path()));

        ++counter;
    }

    counter = 1; // Prepare to choose file to output

    int choice;
    cin >> choice;

    for (auto element : files)
    {
        if (!(element.first == choice))
        {
            ++counter;
        }

        else
        {
            printFileContents(element.second);
        }
    }
}
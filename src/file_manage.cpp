#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "header.h"
#include "logic.h"
#include "ui.h"
#include "Person.h"

namespace fs = std::filesystem;

using std::cout;
using std::cin;
using std::string;
using std::vector;

// Output contents of specified file
void fileOut(string file_loc)
{
    string message;
    std::ifstream out;
    out.open(file_loc);

    if (out.is_open()) 
    {
        // Print welcome message in welcome.txt
        while (std::getline (out, message)) 
        {
            cout << message << '\n';
        }
    }
}

// Save user input to file
void saveInput()
{
    vector<char> yes_or_no (1);
    cout << "\nWould you like to save your input? y/n: ";
    cin >> yes_or_no[0];

    if (yes_or_no[0] == 'y' || yes_or_no[0] == 'Y') 
    {

        vector<char> yes_or_no2 (1);
        cout << "\nWould you like a custom name for the file? y/n (if n, the time will be used): ";
        cin >> yes_or_no2[0];

        if (yes_or_no2[0] == 'y' || yes_or_no2[0] == 'Y')
        {
            std::string file_name;
            std::cout << "Enter a file name: ";
            std::cin >> file_name;

            fs::path folder = "./outFiles/";
            folder /= file_name + ".txt";
            std::filesystem::create_directory(folder.parent_path());

            std::ofstream out_file(folder);

            if (out_file.is_open()) 
            {
                for (auto const element : people) 
                {
                    // Store pancakes eaten in output file
                    element.printPancakesEaten(out_file, element);
                }

                out_file << std::endl;

                // Ordered list in the output file

                out_file << "\nOrdered list:\n\n";
                std::sort(people.begin(), people.end(), sortPancakes);

                for (auto const& element : people) 
                {
                    element.printPancakesEaten(out_file, element);
                }

                std::sort(people.begin(), people.end(), sortPNum); // Reset ordering of people
                cout << "Done." << std::endl;

                //Basic statistics in the output file

                std::sort(people.begin(), people.end(), sortPancakes);
        
                int sum = 0, num_people = 0;
                double average = 0, median_person = 0, median = 0;

                for (auto& element : people) 
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

            out_file.close();
        }

        else if (yes_or_no2[0] == 'n' || yes_or_no2[0] == 'N')
        {
            // Get current time to name file
            time_t t = time(0);
            struct tm * now = localtime( &t );

            char buffer [80];
            strftime (buffer, 80, "outFiles/%Y-%m-%d-%H%M.txt", now);
            
            // Create file [time].txt
            std::ofstream out_file;
            out_file.open(buffer);

            if (out_file.is_open()) 
            {
                for (auto const element : people) 
                {
                    // Store pancakes eaten in outFile.txt
                    element.printPancakesEaten(out_file, element);
                }

                out_file << std::endl;

                // Ordered list in outFile.txt
                out_file << "\nOrdered list:\n\n";
                std::sort(people.begin(), people.end(), sortPancakes);

                for (auto const& element : people) 
                {
                    element.printPancakesEaten(out_file, element);
                }

                std::sort(people.begin(), people.end(), sortPNum); // Reset ordering of people
                cout << "Done." << std::endl;
            }

            else 
            {
                std::cerr << "Error opening file!" << std::endl;
            }

            out_file.close();
        }
    }
    
    else if (yes_or_no[0] == 'n' || yes_or_no[0] == 'N') 
    {
        cout << "\nGoodbye!" << std::endl;
        return;
    }
    
    else 
    {
        std::cerr << "Your entry is invalid, please try again." << std::endl;
        saveInput();
    }
}
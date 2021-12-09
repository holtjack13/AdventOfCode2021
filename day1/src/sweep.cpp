#include <iostream>
#include <fstream>
#include <cstdlib>

#include "sweep.h"

void display_total(const int total)
{
    std::cout << "The number of measurement increases is: " << total << "\n";
}

int main(int argc, char *argv[])
{
    if (argc != 2) { usage(); return EXIT_FAILURE; }

    // Open file stream
    std::ifstream sonar_file { argv[1], std::ios::in };

    // Check file opened properly
    if (!sonar_file.good()) { open_error(); return EXIT_FAILURE; }

    // Initialise variables to capture sonar readings
    int prev_reading { 0 };
    int current_reading { 0 };
    int increased_total { 0 };

    // Read file, comparing values as we go...
    while (!sonar_file.eof())
    {
        sonar_file >> current_reading;

        // Check that we read the value from the file successfully.
        if (sonar_file.fail() && !sonar_file.eof())
        {
            read_error();
            return EXIT_FAILURE;
        }

        // In this case, there isn't a previous measurement to compare
        // against, so we skip the rest of the loop.
        if (prev_reading == 0)
        {
            prev_reading = current_reading;
            continue;
        }

        if (current_reading > prev_reading) { increased_total++; }

        prev_reading = current_reading;
    }

    display_total(increased_total);

    return EXIT_SUCCESS;
}


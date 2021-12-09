#include <array>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <cstdlib>

#include "sweep.h"

int main(int argc, char *argv[])
{
    if (argc != 2) { usage(); return EXIT_FAILURE; }

    // Open file streams
    std::ifstream sonar_file { argv[1], std::ios::in };
    std::ofstream sonar_sums { "data/sonar_sums", std::ios::out };

    // Check file opened properly
    if (!sonar_file.good()) { open_error(); return EXIT_FAILURE; }
    if (!sonar_sums.good()) { open_error(); return EXIT_FAILURE; }

    // Initialise our sliding window
    std::array<int, 3> window;
    sonar_file >> window[0] >> window[1] >> window[2];

    while (!sonar_file.eof())
    {
        // Check that we read the value from the file successfully.
        if (sonar_file.fail() && !sonar_file.eof())
        {
            read_error();
            return EXIT_FAILURE;
        }

        // Write sum of window values to file
        sonar_sums << std::accumulate(window.begin(), window.end(), 0) << "\n";

        // Slide the window
        std::rotate(window.begin(), window.begin() + 1, window.end());
        sonar_file >> window[2];
    }

    std::cout << "Successfully written sum values to file...\n";
    return EXIT_SUCCESS;
}


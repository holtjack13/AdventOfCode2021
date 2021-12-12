#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "dive.h"

int main(int argc, char *argv[])
{
    // Check argument has been provided
    if (argc != 2) { usage(); return EXIT_FAILURE; }

    std::ifstream cmd_file { argv[1], std::ios::in };

    // Check file stream opened successfully
    if (!cmd_file.good()) { open_error(); return EXIT_FAILURE; }

    // Initialise working variables
    position_t pos_without_aim;
    position_t pos_with_aim;

    // Load first instruction
    instruction_t instruction;
    cmd_file >> instruction;

        while (!cmd_file.eof())
        {
            if (cmd_file.fail() && !cmd_file.eof()) { read_error(); return EXIT_FAILURE; }

            pos_without_aim.move(instruction, false);
            pos_with_aim.move(instruction, true);

            cmd_file >> instruction;
        }

        std::cout << "Final answer is: \n" 
                  << "\tposition (without aim) = " << pos_without_aim.product()<< "\n"
                  << "\tposition (with aim) = " << pos_with_aim.product()<< "\n";
}

#ifndef __SWEEP__
#define __SWEEP__

#include <iostream>

void usage()
{
    std::cout << "Usage: sweep sonar_file\n"
              << "\tsonar_file: file containing sonar data points\n";
}

void open_error()
{
    std::cout << "sweep: file failed to open: check file and try "
              << "again...\n";
}

void read_error()
{
    std::cout << "sweep: file read error: please check file "
              << "integrity\n";
}

#endif

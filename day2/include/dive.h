#ifndef __DIVE__
#define __DIVE__

#include <iostream>
#include <fstream>
#include <string>

enum class direction { forward, up, down };

struct instruction_t
{
    direction m_direct;
    int m_units;

    instruction_t(): m_direct(direction::forward), m_units(0) {}
    instruction_t(direction d, int units): m_direct(d), m_units(units) {}

    friend std::istream& operator>>(std::istream& os, instruction_t& i)
    {
        // Read string from input stream
        std::string d;
        os >> d;

        // Convert string into enum (easier to work with)
        if (d == "forward") { i.m_direct = direction::forward; }
        else if (d == "up") { i.m_direct = direction::up; }
        else if (d == "down") { i.m_direct = direction::down; }
        else { os.setstate(std::ios_base::failbit); }

        // Read unit value
        os >> i.m_units;
        return os;
    }
};

struct position_t
{
    int m_horizontal;
    int m_depth;
    int m_aim;

    position_t(): m_horizontal(0), m_depth(0), m_aim(0) {}

    void forward(const int units, bool with_aim) 
    { 
        if (with_aim) { m_depth += m_aim * units; }
        m_horizontal += units; 
    }

    void down(const int units, bool with_aim) 
    { 
        with_aim ? m_aim += units : m_depth += units; 
    }

    void up(const int units, bool with_aim) 
    { 
        with_aim ? m_aim -= units : m_depth -= units; 
    }

    void move(const instruction_t i, bool with_aim)
    {
        switch (i.m_direct)
        {
            case direction::forward: forward(i.m_units, with_aim); break;
            case direction::up:      up(i.m_units, with_aim); break;
            case direction::down:    down(i.m_units, with_aim); break;
        }
    }

    int product() { return m_horizontal * m_depth; }
};

void usage()
{
    std::cout << "Usage: dive cmd_file\n"
              << "\t cmd_file: text file containing movement instructions";
}

void open_error()
{
    std::cout << "dive: file failed to open: check file and try again...\n";
}

void read_error()
{
    std::cout << "dive: failed to read instruction: check file and try "
              << "again...\n";
}

#endif

#!/bin/sh 

# Make build directory
echo "Creating build directory..."
mkdir -p build/debug/
mkdir -p build/release

# Build programs
echo "Building programs..."
make

# Part 1 Solution
echo "Running Part 1..."
build/release/sweep data/sonar_file

# Part 2 Solution
echo "Running Part 2..."
build/release/sweepw data/sonar_file
build/release/sweep data/sonar_sums

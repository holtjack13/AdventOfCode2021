#!/bin/sh

# Make build directory
echo "Creating build directory..."
mkdir -p build/debug/
mkdir -p build/release

# Build programs
echo "Building programs..."
make

# Part 1 Solution
build/release/dive data/dive_data

BUILD_DEBUG = ./build/debug
BUILD_RELEASE = ./build/release
SRC_DIR = ./src
INCLUDE_DIR = ./include

CXX = g++

all: debug release

debug: dive_debug 

release: dive_release 

dive_debug:
	$(CXX) $(SRC_DIR)/dive.cpp -o $(BUILD_DEBUG)/dive -I $(INCLUDE_DIR) -g

dive_release:
	$(CXX) $(SRC_DIR)/dive.cpp -o $(BUILD_RELEASE)/dive -I $(INCLUDE_DIR) -O3

clean: 
	rm $(BUILD_DEBUG)/dive $(BUILD_RELEASE)/dive 

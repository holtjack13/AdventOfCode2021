BUILD_DEBUG = ./build/debug
BUILD_RELEASE = ./build/release
SRC_DIR = ./src
INCLUDE_DIR = ./include

CXX = g++

all: debug release

debug: sweep_debug sweep_window_debug

release: sweep_release sweep_window_release

sweep_debug:
	$(CXX) $(SRC_DIR)/sweep.cpp -o $(BUILD_DEBUG)/sweep -I $(INCLUDE_DIR) -g

sweep_window_debug:
	$(CXX) $(SRC_DIR)/sweep_window.cpp -o $(BUILD_DEBUG)/sweepw -I $(INCLUDE_DIR) -g

sweep_release:
	$(CXX) $(SRC_DIR)/sweep.cpp -o $(BUILD_RELEASE)/sweep -I $(INCLUDE_DIR) -O3

sweep_window_release:
	$(CXX) $(SRC_DIR)/sweep_window.cpp -o $(BUILD_RELEASE)/sweepw -I $(INCLUDE_DIR) -O3

clean: 
	rm $(BUILD_DEBUG)/sweep $(BUILD_DEBUG)/sweepw $(BUILD_RELEASE)/sweep $(BUILD_RELEASE)/sweepw

CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Werror

BUILD_DIR := ./build
SRC_DIR := ./problemset

TARGET := ./main

.PHONY: build clean


$(shell mkdir -p $(BUILD_DIR))

build:
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/0001.cpp -o $(BUILD_DIR)/main 

test:
	@$(BUILD_DIR)/main

clean:
	@rm -rf $(BUILD_DIR) 
	@echo "Removed $(BUILD_DIR)"

CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Werror
MAKEFLAGS := --no-print-directory

BUILD_DIR 	:= ./build
SRC_DIR 	:= ./problemset
TARGET 		:= ./main

.PHONY: build test run clean

# makes the build directory
$(shell mkdir -p $(BUILD_DIR))

# Get all arguments after the target and reprocess to rjustify
FAKE_TARGET = $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
# need to use %04g over $04d (decimal vs digit for whatever reason once you go past 8)
ARGS := $(shell printf %04g $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)))

# Prevent make from treating arguments as targets
$(eval $(FAKE_TARGET):;@:)

build:
	@$(CXX) $(CXXFLAGS) $(SRC_DIR)/$(ARGS).cpp $(SRC_DIR)/euler.cpp -o $(BUILD_DIR)/$(ARGS)

test:
	@$(BUILD_DIR)/$(ARGS)

run:
	@echo "Arguments: $(ARGS) $(ARGS2)"
	@make build $(ARGS)
	@make test $(ARGS)

clean:
	@rm -rf $(BUILD_DIR)
	@echo "Removed $(BUILD_DIR)"

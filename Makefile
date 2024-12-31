CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Werror

BUILD_DIR 	:= ./build
SRC_DIR 	:= ./problemset
TARGET 		:= ./main

.PHONY: build clean

# makes the build directory
$(shell mkdir -p $(BUILD_DIR))


# Get all arguments after the target and reprocess to rjustify
FAKE_TARGET = $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
ARGS := $(shell echo $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)) | xargs printf %04d)

# Prevent make from treating arguments as targets
$(eval $(FAKE_TARGET):;@:)

build:
	@echo "Arguments: $(ARGS)"
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/$(ARGS).cpp -o $(BUILD_DIR)/$(ARGS) 

test:
	@echo "Arguments: $(ARGS)"
	@$(BUILD_DIR)/$(ARGS)

clean:
	@rm -rf $(BUILD_DIR) 
	@echo "Removed $(BUILD_DIR)"

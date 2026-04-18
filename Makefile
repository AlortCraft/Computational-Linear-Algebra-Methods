# Makefile for Computational Linear Algebra Methods

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -g
INCLUDE := -Iinclude

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
INCLUDE_DIR := include

# Output executable
TARGET := $(BIN_DIR)/ALC.exe

# Source files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
DEPS := $(OBJECTS:.o=.d)

# Default target
.PHONY: all
all: $(TARGET)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Link the executable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files and generate dependencies
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

# Include dependency files
-include $(DEPS)

# Run the executable
.PHONY: run
run: $(TARGET)
	./$(TARGET)

# Clean build files
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Clean and rebuild
.PHONY: rebuild
rebuild: clean all

# Show help
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  run      - Build and run the executable"
	@echo "  clean    - Remove build and bin directories"
	@echo "  rebuild  - Clean and build again"
	@echo "  help     - Show this help message"

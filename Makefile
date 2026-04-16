.PHONY: all run clean rebuild debug release help

CXX ?= g++
CXXFLAGS ?= -std=c++23 -O2 -Wall -Wextra -Wpedantic -Iinclude
LDFLAGS ?=

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/cla_methods

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

ifeq ($(OS),Windows_NT)
	TARGET := $(TARGET).exe
	RM = cmd /c del /Q
	RM_DIR = cmd /c rmdir /S /Q
	RUN_CMD = .\$(TARGET)
else
	RM = rm -f
	RM_DIR = rm -rf
	RUN_CMD = ./$(TARGET)
endif

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $@

$(BIN_DIR):
	@mkdir -p $@

-include $(DEPS)

run: $(TARGET)
	$(RUN_CMD)

clean:
	$(RM_DIR) $(BUILD_DIR) $(BIN_DIR)

rebuild: clean all

debug: CXXFLAGS := -std=c++23 -g -O0 -Wall -Wextra -Wpedantic -Iinclude
debug: rebuild

release: CXXFLAGS := -std=c++23 -O3 -DNDEBUG -Wall -Wextra -Wpedantic -Iinclude
release: rebuild

help:
	@echo "Targets:"
	@echo "  all      - Build the project"
	@echo "  run      - Build and run executable"
	@echo "  clean    - Remove build artifacts"
	@echo "  rebuild  - Clean and build"
	@echo "  debug    - Build with debug flags"
	@echo "  release  - Build with release flags"
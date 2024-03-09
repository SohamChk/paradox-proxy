# Makefile for the project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Executable
TARGET = $(BIN_DIR)/my_program

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $^ -o $@

# Clean up generated files
clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*


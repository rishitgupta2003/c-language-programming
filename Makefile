# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Directories
SRC_DIR = Practice
OBJ_DIR = build
BIN = run

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files (replace Practice/main.c -> build/main.o)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(BIN)

# Link object files into final executable
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c to .o in build/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create build/ directory if not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build artifacts
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN)
	rmdir $(OBJ_DIR) 2>/dev/null || true

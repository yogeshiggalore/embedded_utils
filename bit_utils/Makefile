# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Iinclude

# Source files
SOURCES = src/bit_util.c src/bit_util_test.c

# Debug flags (add -g for debugging)
DEBUG_FLAGS = -g

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Executable
TARGET = util_out

# Default target
all: $(TARGET)

# Compile C files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(OBJECTS) -o $@

# Clean
clean:
	rm -f $(OBJECTS) $(TARGET)
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDFLAGS = -lgdi32

# Output binary name
TARGET = build/Snake

# Add .exe extension on Windows
ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
endif

# Source and object directories
SRCDIR = src
OBJDIR = build/obj

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Default target
all: $(TARGET)

# Ensure build and obj directories exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Build rule
$(TARGET): $(OBJDIR) $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Rule for object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean rule
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)
	rm -rf $(OBJDIR)
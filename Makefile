# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11  # Ensure standard C11 is used
LDFLAGS = -lgdi32  # Linker flags for Windows GDI library

# Output binary name
TARGET = build/Snake

# Source and object directories
SRCDIR = src
OBJDIR = build/repository

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)

# Object files (replace .c with .o in SRCS, but in OBJDIR)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Default target
all: $(TARGET)

# Build rule
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Rule for object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)  # Create the object directory if it doesn't exist
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean rule
clean:
	$(RM) -f $(OBJDIR)/*.o $(TARGET)
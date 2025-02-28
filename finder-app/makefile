#****************************************************************************
# Author Marco Bettini
# Assignment 2
#*****************************************************************************
#
#------------------------------------------------------------------------------
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# 	default target which builds the “writer” application
#	clean target which removes the “writer” application and all .o files
#
# Platform Overrides:
#	CROSS_COMPILE=aarch64-none-linux-gnu-
#
#------------------------------------------------------------------------------

#PATH = ./finder-app
#SOURCES = finder-app/writer.c
TARGET = writer

# Platform Overrides
#CROSS_COMPILE = 

#COMMON_FLAGS =-Wall \
#			-Werror \
#			-O0 \
#			-g \
#			-std=c99

# Architectures Specific Flags
ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
	# Compiler
	CC = aarch64-none-linux-gnu-gcc
else
	# Host Platform
	CC = gcc
endif

# Build executable
.PHONY: all
all: $(TARGET)
#	@echo "Build completed!"
	
$(TARGET): $(TARGET).c
	$(CC) $(TARGET).c -o $@
	
# Clean target
.PHONY: clean
clean:
	rm -f $(TARGET)



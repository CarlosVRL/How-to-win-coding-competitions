## Source Files ##
SOURCES = AplusBsquared.cpp

## Object Files ##
OBJECTS = $(SOURCES:.cpp=.o)

## Target ##
EXECUTABLE = a

## Compiler Options ##
CC = g++
CFLAGS = -c -Wall
LDFLAGS =

## Goals ##
all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) *o $(EXECUTABLE)

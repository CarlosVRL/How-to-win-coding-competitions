## Source Files ##
SOURCES = PrepareYourselfToCompetition.cpp

## Object Files ##
OBJECTS = $(SOURCES:.cpp=.o)

## Target ##
EXECUTABLE = a

## Compiler Options ##
CC = g++
CFLAGS = -c -Wall -std=c++11
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

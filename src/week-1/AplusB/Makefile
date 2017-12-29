## Target ##
EXECUTABLE = AplusB
OUTPUT_PATH = ./target
	
## Source Files ##
SOURCES = AplusB.cpp
OBJECTS = $(SOURCES:.cpp=.o)

## Compiler Options ##
CC = g++
CFLAGS = -c -Wall
LDFLAGS =

## Goals ##
all: $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUTPUT_PATH)/$@
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) *o $(OUTPUT_PATH)/$(EXECUTABLE)
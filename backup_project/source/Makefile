CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c bp_main_tools.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=backup_manager

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean: 
	rm $(OBJECTS) $(EXECUTABLE)

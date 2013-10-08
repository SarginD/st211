CC=gcc
CFLAGS=-c -Wall -pthread
LDFLAGS=-pthread
SOURCES=task3.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=task3

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean: 
	rm $(OBJECTS) $(EXECUTABLE)
test:	$(EXECUTABLE)
	./$(EXECUTABLE)

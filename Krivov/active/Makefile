CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=task2.c csv.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=useless

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean: 
	rm $(OBJECTS) $(EXECUTABLE)
test:	$(EXECUTABLE)
	./$(EXECUTABLE)

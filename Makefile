CC=gcc
LDFLAGS=-c -g -std=c11 -Wall -Wextra -Werror
EXECUTABLE=a.out
SOURCES=srcs/main.c
OBJECTS=$(SOURCES:.c=.o)
HEADERS=-I./includes

all: build

.c.o:
	@echo "Compiling"
	$(CC) $(LDFLAGS) $(HEADERS) -D _SD_SOURCE  $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(EXECUTABLE_TEST) $(OBJECTS_TEST)


rebuild: clean build test


build: $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE) : $(OBJECTS)
	@echo "Linking"
	$(CC) $(OBJECTS) -o $@

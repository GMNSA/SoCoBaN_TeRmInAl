CC=gcc
CFLAGS=-c -g -std=gnu11 -Wall -Wextra -Werror
EXECUTABLE=a.out
SOURCES=srcs/f_input.c srcs/f_string.c tests/main.c
OBJECTS=$(SOURCES:.c=.o)
HEADERS=-I./includes

LD_NAME_INPUT=libinput.a
LD_NAME_STRING=libstring.a

all: build

.c.o:
	@echo "Compiling $< <--> $@"
	$(CC) $(CFLAGS) $(HEADERS)  $< -o $@

clean:
	rm -f  $(OBJECTS) $(EXECUTABLE) $(LD_NAME_INPUT) $(LD_NAME_STRING)


rebuild: clean build 

build:  $(OBJECTS) $(LD_NAME_INPUT) $(LD_NAME_STRING) 


$(LD_NAME_INPUT):
	@echo "create libs $@"
	ar -rc $(LD_NAME_INPUT) srcs/f_input.o

$(LD_NAME_STRING):
	@echo "create libs $@"
	ar -rc $(LD_NAME_STRING) srcs/f_string.o

test: $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE) : $(OBJECTS) $(LD_NAME_INPUT) $(LD_NAME_STRING)
	$(CC)  $(LD_NAME_INPUT) $(LD_NAME_STRING) tests/main.o -o $@

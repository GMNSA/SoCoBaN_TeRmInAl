CC=gcc
CFLAGS=-c -g -std=gnu11 -Wall -Wextra -Werror

EXECUTABLE=a.out
SOURCES=srcs/main.c srcs/socoban_game.c srcs/socoban_game_menu.c srcs/socoban_log_file.c srcs/f_work_with_file.c
OBJECTS=$(SOURCES:.c=.o)

EXECUTABLE_TEST=test.out
SOURCES_TEST=tests/main.c srcs/socoban_game.c srcs/socoban_game_menu.c srcs/socoban_log_file.c srcs/f_work_with_file.c
OBJECTS_TEST=$(SOURCES_TEST:.c=.o)

HEADERS=-I./includes -I./libs/includes
LDFLAGS=./libs/libinput.a ./libs/libstring.a
LDSHAREDFLAGS=-L/usr/lib64/ -lexpat

all: build

.c.o:
	@echo "Compiling"
	$(CC)  $(CFLAGS) $(HEADERS)   $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(EXECUTABLE_TEST) $(OBJECTS_TEST)


rebuild: clean build


build: $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE) : $(OBJECTS)
	@echo "Linking"
	make -C libs
	$(CC) $(OBJECTS) $(LDFLAGS) $(LDSHAREDFLAGS) -o $@


test: $(EXECUTABLE_TEST) $(OBJECTS_TEST)

$(EXECUTABLE_TEST) : $(OBJECTS_TEST)
	@echo "Linking"
	make -C libs
	$(CC) $(OBJECTS_TEST) $(LDFLAGS) $(LDSHAREDFLAGS) -o $@

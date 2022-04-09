CC=gcc
CFLAGS=-c -g -std=gnu11 -Wall -Wextra -Werror
EXECUTABLE=a.out
SOURCES=srcs/main.c srcs/socoban_game.c srcs/socoban_game_menu.c
OBJECTS=$(SOURCES:.c=.o)
HEADERS=-I./includes -I./libs/includes
LDFLAGS=./libs/libinput.a ./libs/libstring.a

all: build

.c.o:
	@echo "Compiling"
	$(CC) $(CFLAGS) $(HEADERS) -D _SD_SOURCE  $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(EXECUTABLE_TEST) $(OBJECTS_TEST)


rebuild: clean build


build: $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE) : $(OBJECTS)
	@echo "Linking"
	make -C libs
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@



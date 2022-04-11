/* socoban_game.c */

#include "socoban_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "f_input.h"
#include "socoban_game_menu.h"
#include "socoban_game_options.h"

e_game_state convert_to_game_state(e_socoban_menu menu_);

// -------------------------------------------------------

e_game_state G_GAME_STATE = GAME_STATE_INIT;

void game() {
	int is_run = 1;

	while (is_run) {
		switch (G_GAME_STATE) {
			case GAME_STATE_INIT:
				game_init();
				G_GAME_STATE = GAME_STATE_MENU;
				break;
			case GAME_STATE_MENU:
				game_menu();
				G_GAME_STATE = convert_to_game_state(socoban_menu_state());
				break;
			case GAME_STATE_PROCESS:
				game_process();
				break;
			case GAME_STATE_LEVEL:
				game_level();
				break;
			case GAME_STATE_SCORES:
				game_scores();
				break;
			case GAME_STATE_ABOUT:
				game_about();
				break;
			case GAME_STATE_EXIT:
				game_exit();
				is_run = 0;
				break;
			default:
				break;
		}
		usleep(GAME_SPEED);
	}
}

// -------------------------------------------------------

void game_init() {
	printf("INIT\n");
}

void game_menu() {
	printf("MENU\n");
	socoban_menu();
}

// -------------------------------------------------------

void game_process() {
	printf("PROCESS\n");

	if (key_input() == KEY_ESCAPE) {
		G_GAME_STATE = GAME_STATE_INIT;
	}
}

void game_level() {
	printf("LEVEL\n");

	if (key_input() == KEY_ESCAPE) {
		G_GAME_STATE = GAME_STATE_INIT;
	}
}

void game_scores() {
	printf("SCORES\n");

	if (key_input() == KEY_ESCAPE) {
		G_GAME_STATE = GAME_STATE_MENU;
	}
}

void game_about() {
	printf("ABOUT\n");

	if (key_input() == KEY_ESCAPE) {
		G_GAME_STATE = GAME_STATE_MENU;
	}
}

void game_exit() {
	system("clear");
	printf("EXIT\n");
}

// -------------------------------------------------------

e_game_state convert_to_game_state(e_socoban_menu menu_) {
	e_game_state result = GAME_STATE_MENU;
	if (menu_ == MENU_STATE_START) {
		result = GAME_STATE_PROCESS;
	} else if (menu_ == MENU_STATE_LEVEL) {
		result = GAME_STATE_LEVEL;
	} else if (menu_ == MENU_STATE_SCORES) {
		result = GAME_STATE_SCORES;
	} else if (menu_ == MENU_STATE_ABOUT) {
		result = GAME_STATE_ABOUT;
	} else if (menu_ == MENU_STATE_EXIT) {
		result = GAME_STATE_EXIT;
	} else {
		result = GAME_STATE_MENU;
	}
	return (result);
}

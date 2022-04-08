/* socoban_game.c */

#include "socoban_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "socoban_game_menu.h"

#include "socoban_game_options.h"

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
				G_GAME_STATE = GAME_STATE_MENU;
				break;
			case GAME_STATE_PROCESS:
				game_process();
				G_GAME_STATE = GAME_STATE_PROCESS;
				break;
			case GAME_STATE_LEVEL:
				game_level();
				G_GAME_STATE = GAME_STATE_LEVEL;
				break;
			case GAME_STATE_SCORES:
				game_scores();
				G_GAME_STATE = GAME_STATE_SCORES;
				break;
			case GAME_STATE_ABOUT:
				game_about();
				G_GAME_STATE = GAME_STATE_ABOUT;
				break;
			case GAME_STATE_EXIT:
				game_exit();
				G_GAME_STATE = GAME_STATE_EXIT;
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
}

void game_level() {
	printf("LEVEL\n");
}

void game_scores() {
	printf("SCORES\n");
}

void game_about() {
	printf("ABOUT\n");
}

void game_exit() {
	printf("EXIT\n");
}

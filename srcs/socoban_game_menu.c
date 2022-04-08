/* socoban_game_menu.c */

#include "socoban_game_menu.h"
#include "f_input.h"
#include "socoban_game_options.h"
#include <unistd.h>
#include <stdlib.h>

char const *G_SOCOBAN_MENU[MENU_SOCOBAN_END] = {
	"Start",
	"Level",
	"Scores",
	"About",
	"Exit"
};

int G_SOCOBAN_MENU_CURRENT_STATE = MENU_STATE_START;
void draw_highlighted_element_menu(char const *elemnt_, int is_shift_);

void socoban_menu_move();

// -------------------------------------------------------

void socoban_menu() {
	int is_run = 1;

	while (is_run) {
		system("clear");
		for (int i = 0; i < MENU_SOCOBAN_END; ++i) {
			if (G_SOCOBAN_MENU_CURRENT_STATE == i) {
				draw_highlighted_element_menu(G_SOCOBAN_MENU[i], i % 2);
			} else {
				printf("%s\n", G_SOCOBAN_MENU[i]);
			}
		}
		socoban_menu_move();
		usleep(SOCOBAN_DEFAULT_SPEED_MENU);
	}
}

void socoban_menu_move() {
	e_key_code key = key_input();
	if (key == KEY_UP) {
		if (G_SOCOBAN_MENU_CURRENT_STATE > MENU_STATE_START) {
			--G_SOCOBAN_MENU_CURRENT_STATE;
		} else {
			G_SOCOBAN_MENU_CURRENT_STATE = MENU_STATE_EXIT;
		}
	} else if (key == KEY_DOWN) {
		if (G_SOCOBAN_MENU_CURRENT_STATE < MENU_STATE_EXIT) {
			++G_SOCOBAN_MENU_CURRENT_STATE;
		} else {
			G_SOCOBAN_MENU_CURRENT_STATE = MENU_STATE_START;
		}

	} else if (key == KEY_ENTER) {

	}
}

void draw_highlighted_element_menu(char const *elemnt_, int is_shift_) {
	ft_unuased(elemnt_);
	ft_unuased(is_shift_);

	// int n_element = strlen(elemnt_);
	// if (is_shift_) {
	// 	printf("[%s]\n", elemnt_);
	// } else {
	// 	printf(" [%s]\n", elemnt_);
	// }
}

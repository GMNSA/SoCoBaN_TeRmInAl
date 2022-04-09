/* socoban_game_menu.c */

#include "socoban_game_menu.h"
#include <unistd.h>
#include <stdlib.h>
#include "f_input.h"
#include "f_string.h"
#include "socoban_game_options.h"

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
char to_up_letter(char ch_);
char to_down_letter(char ch_);

// -------------------------------------------------------

void socoban_menu() {
	int is_run = 1;

	while (is_run) {
		system("clear");
		for (int i = 0; i < MENU_SOCOBAN_END; ++i) {
			if (G_SOCOBAN_MENU_CURRENT_STATE == i) {
				draw_highlighted_element_menu(G_SOCOBAN_MENU[i], i % 2);
			} else {
				if (i % 2 == 0) {
					printf(" %s\n", G_SOCOBAN_MENU[i]);
				} else {
					printf("%s\n", G_SOCOBAN_MENU[i]);
				}
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
	int n_element = f_strlen(elemnt_);
	if (is_shift_) {
		 printf("* ");
		for (int i = 0; i < n_element; ++i) {
			if (i % 2 == 0) {
				printf("%c", to_up_letter(elemnt_[i]));
			} else {
				printf("%c", to_down_letter(elemnt_[i]));
			}
		}
		printf(" *\n");
	} else {
		printf("  * ");
		for (int i = 0; i < n_element; ++i) {
			if (i % 2 == 0) {
				printf("%c", to_up_letter(elemnt_[i]));
			} else {
				printf("%c", to_down_letter(elemnt_[i]));
			}
		}
		printf(" *\n");
	}
}

char to_up_letter(char ch_) {
	if (ch_ >= 'a' && ch_ <= 'z') {
		ch_ -= 32;
	}
	return (ch_);
}

char to_down_letter(char ch_) {
	if (ch_ >= 'A' && ch_ <= 'Z') {
		ch_ += 32;
	}
	return (ch_);
}

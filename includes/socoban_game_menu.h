/* socoban_game_menu.h */

#ifndef SRC_SOCOBAN_GAME_MENU_H_
#define SRC_SOCOBAN_GAME_MENU_H_

typedef enum e_socoban_menu {
	MENU_STATE_START,
	MENU_STATE_LEVEL,
	MENU_STATE_SCORES,
	MENU_STATE_ABOUT,
	MENU_STATE_EXIT,
	MENU_SOCOBAN_END
} e_socoban_menu;

extern int G_SOCOBAN_MENU_CURRENT_STATE;
extern e_socoban_menu G_SOCOBAN_MENU_STATE;

// -------------------------------------------------------

void socoban_menu();
e_socoban_menu socoban_menu_state();

#endif  // SRC_SOCOBAN_GAME_MENU_H_

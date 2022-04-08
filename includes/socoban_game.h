/* socoban_game.h */

#ifndef SRC_SOCOBAN_GAME_H_
#define SRC_SOCOBAN_GAME_H_

typedef enum e_game_state {
	GAME_STATE_INIT,
	GAME_STATE_MENU,
	GAME_STATE_PROCESS,
	GAME_STATE_LEVEL,
	GAME_STATE_SCORES,
	GAME_STATE_ABOUT,
	GAME_STATE_EXIT

} e_game_state;

extern e_game_state G_GAME_STATE;

// -------------------------------------------------------

void game();

void game_init();
void game_menu();

void game_process();
void game_level();
void game_scores();
void game_about();
void game_exit();

#endif  // SRC_SOCOBAN_GAME_H_

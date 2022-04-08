#include "f_input.h"


#define ARROW_KEY_PRESSED 0xE0

e_key_code get_key(char ch);


int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

e_key_code key_input() {
	char ch = '\0';
	e_key_code result = KEY_UNKNOWN;
	while (kbhit()) {
		ch = getchar();
		 result = get_key(ch);
	}
	return (result);
}

e_key_code get_key(char ch) {
	e_key_code result = KEY_UNKNOWN;
	switch (ch)	{
		case 'w':
			result = KEY_UP;
			break;
		case 's':
			result = KEY_DOWN;
			break;
		case 'a':
			result = KEY_LEFT;
			break;
		case 'd':
			result = KEY_RIGHT;
			break;
		case ' ':
			result = KEY_SPACE;
			break;
		case 10:
			result = KEY_ENTER;
			break;
		case 27:
			result = KEY_ESCAPE;
			break;
		default:
			result = KEY_UNKNOWN;
	}
	// printf("KEY %d\n", ch);
	return (result);
}

e_key_code it_key_input() {
	int key = getchar();
	e_key_code result = KEY_UNKNOWN;
	switch (key) {
		case 'w':
			return KEY_UP;
		case 'a':
			return KEY_RIGHT;
		case 's':
			return KEY_DOWN;
		case 'd':
			return KEY_LEFT;
		case 10:
			return KEY_ENTER;
		case 32:
			return KEY_SPACE;
		case 27:
			return KEY_ESCAPE;
	}
	return (result);
}

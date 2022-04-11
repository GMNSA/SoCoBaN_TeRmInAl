/* socoban_log_file.c */

#include "socoban_log_file.h"
#include <stdio.h>
#include <time.h>
#include "socoban_game_options.h"
#include <stdlib.h>

e_socoban_log_file G_LOG_ERROR = ERROR_LOG_OK;

// -------------------------------------------------------
void close_app();

void create_log(char const *text_, char const *text2_,  char const *filename_) {
	FILE *fin = NULL;
	unsigned is_close = 0;

	long ttime = time(0);
	char const *current_time = ctime(&ttime);

	if (filename_ == NULL) {
		filename_ = "log_file.txt";
	}

	if (text_ == NULL) {
		switch (G_LOG_ERROR) {
			case ERROR_LOG_OK:
				text_ = "OK <----->";
				break;
			case ERROR_LOG_XML:
				text_ = "XML ERROR <----->";
				break;
			case ERROR_CREATE_DYNAMIC_MEMORY:
				text_ = "Create dynamic memory ERROR!!! <----->";
				break;
			default:
				break;
		}
	}

	if (text2_ == NULL) {
		text2_ = "";
	}

	fin = fopen(filename_, "a");

	if (fin) {
		fprintf(fin, "%s %s %s", text_, text2_, current_time);
		fclose(fin);
		if (G_LOG_ERROR != ERROR_LOG_OK) {
			is_close = 1;
		}
	} else {
		fprintf(stderr, "ERROR LOG FILE !!!!");
			is_close = 1;
	}

	if (is_close) {
		close_app();
	}
}

void close_app() {
	exit(-1);
}

/* socoban_log_file.h */

#ifndef SRC_SOCOBAN_LOG_FILE_H_
#define SRC_SOCOBAN_LOG_FILE_H_

typedef enum e_socoban_log_file {
	ERROR_LOG_OK,
	ERROR_LOG_XML,
	ERROR_CREATE_DYNAMIC_MEMORY,
} e_socoban_log_file;

extern e_socoban_log_file G_LOG_ERROR;

void create_log(char const *text_, char const *text2_,  char const *filename_);

#endif  // SRC_SOCOBAN_LOG_FILE_H_

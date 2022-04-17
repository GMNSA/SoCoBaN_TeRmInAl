#include "f_string.h"
#include <stdlib.h>

int is_letter(char ch_);
int is_number(char ch_);

unsigned f_strlen(const char *s_) {
	unsigned i = 0;
	for (i = 0; s_[i] != '\0'; ++i) {
	}
	return (i);
}

// -------------------------------------------------------

char *f_strdup(const char *s_) {
	char *str = NULL;
	unsigned n_s = f_strlen(s_);
	unsigned i;
	if (!(str = (char *)calloc(n_s + 1, sizeof(char)))) {
		exit(-1);
	}

	for (i = 0; i < n_s && s_[i] != '\0'; ++i) {
		str[i] = s_[i];
	}
	str[i] = '\0';
	return (str);
}

// -------------------------------------------------------

int f_strcmp(const char *s1_, const char *s2_) {
	int result = 0;
	for (unsigned i = 0; s1_[i] != '\0' || s2_[i] != '\0'; ++i ) {
		if (s1_[i] != s2_[i]) {
			result = s1_[i] - s2_[i];
			break;
		}
	}
	return (result);
}

// -------------------------------------------------------

int f_atoi(const char *nptr_) {
	int result = 0;
	int is_negative = 1;
	while ((*nptr_ == ' ' || *nptr_ == '\t') && *nptr_ != '\0') {
		++nptr_;
	}
	if (*nptr_ == '+') {
		is_negative = 1; 
		++nptr_;
	} else if (*nptr_ == '-') {
		is_negative = -1;
		++nptr_;
	}
	while (is_number(*nptr_) && *nptr_ != '\0') {
		result = (result * 10) + ((*nptr_) - 48);

		++nptr_;
	}
	return (result * is_negative);
}

// -------------------------------------------------------

int is_letter(char ch_) {
	int result = 0;
	if (ch_ >= 97 && ch_ <= 122) {
		result = 1;
	} else if (ch_ >= 65 && ch_ <= 90) {
		result = 1;
	}
	return (result);
}

// -------------------------------------------------------

int is_number(char ch_) {
	int result = 0;
	if (ch_ >= 48 && ch_ <= 57) {
		result = 1;
	} 
	return (result);
}

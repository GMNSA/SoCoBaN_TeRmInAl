#include "f_string.h"
#include <stdlib.h>

unsigned f_strlen(const char *s_) {
	unsigned i = 0;
	for (i = 0; s_[i] != '\0'; ++i) {
	}
	return (i);
}

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

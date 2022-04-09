#include <stdio.h>
#include "f_string.h"

void test_strlen();

int main(void)
{
#ifdef _TEST_1
	test_strlen();
#endif
	return 0;
}

void test_strlen() {
	if (f_strlen("  ") != 2) {
		printf("n/a\n");
	} else {
		printf("OK\n");
	}

	if (f_strlen("There") == 5) {
		printf("OK\n");
	} else {
		printf("n/a\n");
	}

	if (f_strlen("There is no spoon.") == 18) {
		printf("OK\n");
	} else {
		printf("n/a\n");
	}

	if (f_strlen("T") == 1) {
		printf("OK\n");
	} else {
		printf("n/a\n");
	}

	if (f_strlen("") == 0) {
		printf("OK\n");
	} else {
		printf("n/a\n");
	}
	printf("TEST strlen OK\n");
}

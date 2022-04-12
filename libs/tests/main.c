#include <stdio.h>
#include "f_string.h"
#include <stdlib.h>

void test_strlen();
void test_strdup();
void test_strcmp();

int main(void)
{
#ifdef _TEST_1
	test_strlen();
#endif	// _TEST_1

#ifdef _TEST_2
	test_strcmp();
#endif	// _TEST_2

#ifdef _TEST_2
	test_strdup();
#endif	// _TEST_2

#ifdef _TEST_
	test_strlen();
	test_strcmp();
	test_strdup();
#endif 	//_TEST_
	return 0;
}

// -------------------------------------------------------

void test_strlen() {
	printf("\n=============> f_strlen\n");
	int is_ok = 1;
	if (f_strlen("  ") != 2) {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	} else {
		printf("OK\n");
	}

	if (f_strlen("There") == 5) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}

	if (f_strlen("There is no spoon.") == 18) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}

	if (f_strlen("T") == 1) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}

	if (f_strlen("") == 0) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}

	if (f_strlen("\0") == 0) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}

	if (is_ok) {
		printf("TEST f_strlen OK ===========>\n");
	} else {
		printf("TEST f_strlen FAIL ===========>\n");
	}
}

// -------------------------------------------------------

void test_strdup() {
	char const *res = "there is no spoon";
	char *out = f_strdup(res);
	int is_ok = 1;

	printf("\n=============> f_strdup\n");

	if (f_strcmp(res, out) == 0) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}
	if (out) {
		free (out);
	}

	res = "\0";
	out = f_strdup(res);

	if (f_strcmp(res, out) == 0) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}
	if (out) {
		free (out);
	}

	res = "";
	out = f_strdup(res);

	if (f_strcmp(res, out) == 0) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}
	if (out) {
		free (out);
	}

	res = "th\nkdk\tkdlb009###\0kde!!???";
	out = f_strdup(res);

	if (f_strcmp(res, out) == 0) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}
	if (out) {
		free (out);
	}

	if (is_ok) {
		printf("TEST f_strlen OK ===========>\n");
	} else {
		printf("TEST f_strlen FAIL ===========>\n");
	}
}

// -------------------------------------------------------

void test_strcmp() {
	char *one = "there ";
	char *two = "there ";
	int is_ok = 1;

	printf("\n=============> f_strcmp\n");

	if (f_strcmp(one, two) == 0) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}

	one = "there ";
	two = "there 7";

	if (f_strcmp(one, two) == -55) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}

	one = "Phere ";
	two = "there 7";

	if (f_strcmp(one, two) == -36) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}

	one = "";
	two = "there 7";

	if (f_strcmp(one, two) == -116) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}

	one = "\n";
	two = "there 7";

	if (f_strcmp(one, two) == -106) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}
	one = "There";
	two = "\0";

	if (f_strcmp(one, two) == 84) {
		printf("OK\n");
	} else {
		printf("FAIL [line] - %d\n", __LINE__);
		is_ok = 0;
	}

	if (is_ok) {
		printf("TEST f_strcmp OK ===========>\n");
	} else {
		printf("TEST f_strcmp FAIL ===========>\n");
	}
}

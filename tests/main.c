#include <stdio.h>
#include "socoban_log_file.h"
#include <expat.h>
#include "f_work_with_file.h"

void test_xml();

int main(void)
{
	test_xml();
	return 0;
}

void test_xml() {
	s_xml_document doc;
	if (xml_document_load(&doc, "data/test.xml")) {
		// printf("%s\n", doc.root);
		xml_document_free(&doc);
	}
	printf("TEST xml OK\n");
}

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
		while (doc.root) {
			output_xml_node(doc.root);
			doc.root = doc.root->parent;
		}
		xml_document_free(&doc);
	}
	printf("\n------------\n");
	printf("TEST xml OK\n");

}
// 1. size file text
// 2. create buff data form file
// 3. 

/* f_work_with_file.c */

#include "f_work_with_file.h"
#include "socoban_game_options.h"
#include "socoban_log_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHARS 1000000

int G_DEPTH;

s_level_game *read_level(unsigned num_) {
	ft_unuased(num_);

	printf("SUCCESS\n");

	return (NULL);
}

int xml_document_load(s_xml_document *document_,
		char const *path_) {
	ft_unuased(document_);
	ft_unuased(path_);
	int result = 1;
	FILE *fio = fopen(path_, "r");
	unsigned size = 0;
	char *buff = NULL;

	if (!fio) {
		G_LOG_ERROR = ERROR_LOG_XML;
		create_log("Could'n read file from ", path_, NULL);
		result = 0;
	}
	fseek(fio, 0, SEEK_END);
	size = ftell(fio);
	fseek(fio, 0, SEEK_SET);

	if (!(buff = (char *)calloc(size + 1, sizeof(char)))) {
		create_log("Error craete dynamic memory \
				[buff] FILE - f_work_with_file.c ",
				NULL, NULL);
	}
	fread(buff, 1, size, fio);
	fclose(fio);

	return (result);
}

void xml_document_free(s_xml_document *document_)  {
	if(document_) {
		xml_node_free(document_->root);
	}
}

s_xml_node *xml_node_new(s_xml_node *parent_) {
	ft_unuased(parent_);
	s_xml_node *node = NULL;
	if ((!(node = (s_xml_node *)calloc(1, sizeof(s_xml_node))))) {
		G_LOG_ERROR = ERROR_CREATE_DYNAMIC_MEMORY;
		create_log("Error create dynamic memory \
				[node] FILE - f_work_with_file",
				NULL,
				NULL);
	}
	node->parent = parent_;
	node->tag = NULL;
	node->innter_text = NULL;
	return (node);
}

void xml_node_free(s_xml_node *parent_) {
	ft_unuased(parent_);
}

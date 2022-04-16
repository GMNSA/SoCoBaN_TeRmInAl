/* f_work_with_file.c */

#include "f_work_with_file.h"
#include <stdio.h>
#include <stdlib.h>
#include "f_string.h"
#include "socoban_game_options.h"
#include "socoban_log_file.h"

#define MAXCHARS 1000000

#define ft_debug(str) printf("[debug] %s: %s\n", #str, str)

int G_DEPTH;

s_level_game *read_level(unsigned num_) {
	ft_unuased(num_);

	printf("SUCCESS\n");

	return (NULL);
}

// -------------------------------------------------------

void resize_lex(char *lex_, int *size_);

// -------------------------------------------------------

int xml_document_load(s_xml_document *document_,
		char const *path_) {
	int result = 1;
	FILE *fio = fopen(path_, "r");
	unsigned size = 0;
	char *buff = NULL;

	if (!fio) {
		G_LOG_ERROR = ERROR_LOG_XML;
		create_log("Could'n read file from ", path_, NULL);
		result = 0;
	}
	// get size
	fseek(fio, 0, SEEK_END);
	size = ftell(fio);
	fseek(fio, 0, SEEK_SET);
	if (!(buff = (char *)calloc(size + 1, sizeof(char)))) {
		create_log("Error craete dynamic memory \
				[buff] FILE - f_work_with_file.c ",
				NULL, NULL);
	}
	// write data from file to buff
	fread(buff, 1, size, fio);
	fclose(fio);
	buff[size] = '\0';
	// document_->root = xml_node_new(NULL);


	s_xml_node *curr_node = NULL;
	s_xml_node *root_node = NULL;
	ft_unuased(curr_node);
	ft_unuased(root_node);
	ft_unuased(result);
	int i = 0;
	char lex[512] = {"\0"};
	int lexi = 0;
	int is_end_tag = 0;
	int is_text_doc = 0;

	ft_unuased(lex);
	ft_unuased(lexi);

	while (buff[i] != '\0') {
		if (curr_node == NULL) {
			curr_node = xml_node_new(NULL);
		}

		// Close tag
		if (i < (int)size 
				&& buff[i] == '<' 
				&& buff[i + 1] == '/'
				&& is_end_tag) {
			i += 2;
			resize_lex(lex, &lexi);
			is_end_tag = 0;
			while (buff[i] != '>') {
				lex[lexi++] = buff[i++];
			}
			if (f_strcmp(lex, curr_node->tag) != 0) {
				fprintf(stderr, "ERROR tag\n");
				result = 0;
				break;
			}
			if (buff[i + 1] == '\n' && buff[i + 2] != '\0') {
				printf("create curr_node\n");
				curr_node = xml_node_new(curr_node);
			}
			continue;
		}

		// Begin tag
		if (buff[i] == '<' && is_end_tag == 0) {
			is_end_tag = 1;
			is_text_doc = 1;
			resize_lex(lex, &lexi);
			++i;
			while (buff[i] != '>') {
				lex[lexi++] = buff[i++];
			}
			curr_node->tag = f_strdup(lex);
			resize_lex(lex, &lexi);
			++i;
		} 

		// Inner text
		if (is_text_doc) {
			is_text_doc = 0;
			resize_lex(lex, &lexi);
			while (buff[i] != '<' && i < (int)size) {
				lex[lexi++] = buff[i++];
			}
			curr_node->inner_text = f_strdup(lex);
			continue;
		} 
		++i;
	}
	document_->root = curr_node;

	return (result);
}

// -------------------------------------------------------

void xml_document_free(s_xml_document *document_)  {
	if(document_) {
		xml_node_free(document_->root);
	}
}

// -------------------------------------------------------

s_xml_node *xml_node_new(s_xml_node *parent_) {
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
	node->inner_text = NULL;
	return (node);
}

// -------------------------------------------------------

void xml_node_free(s_xml_node *node_) {
	if (node_) {
		if (node_->tag) {
			free(node_->tag);
		}
		if (node_->inner_text) {
			free(node_->inner_text);
		}
		free (node_);
	}
}

void resize_lex(char *lex_, int *size_) {
	unsigned n_lex = f_strlen(lex_);
	*size_ = 0;

	for (unsigned i = 0; i < n_lex; ++i) {
		lex_[i] = '\0';
	}
}

// -------------------------------------------------------

void output_xml_node(s_xml_node *document_) {
	if (document_) {
		if (document_->inner_text) {
			printf("inner_text: %s\n", document_->inner_text);
		} else {
			printf("inner_text: %s\n", "NONE");
		}

		if (document_->tag) {
			printf("tag: %s\n", document_->tag);
		} else {
			printf("tag: %s\n", "NONE");
		}
	}
}

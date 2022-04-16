/* f_work_with_file.h */

#ifndef SRC_F_WORK_WITH_FILE_H_
#define SRC_F_WORK_WITH_FILE_H_

#define MAX_LEVEL_NAME 30

typedef struct 	s_level_game {
	char 		id[30];
	unsigned 	width;
	unsigned 	height;
	char 	  **field;
} 				s_level_game;

typedef struct s_xml_node {
	char       *tag;
	char 	   *inner_text;
	struct 		s_xml_node *parent;
} 				s_xml_node;

typedef struct s_xml_document {
	s_xml_node *root;
} s_xml_document;

// -------------------------------------------------------

s_xml_node *xml_node_new(s_xml_node *parent_);
void xml_node_free(s_xml_node *node_);

int xml_document_load(s_xml_document *document_,
		char const *path_);

void xml_document_free(s_xml_document *document_);

void output_xml_node(s_xml_node *document_); 

#endif  // SRC_F_WORK_WITH_FILE_H_

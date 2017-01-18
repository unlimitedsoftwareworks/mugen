#include "mugen.h"
#include "datatypes.h"
#include "memory.h"

Node* createNode(unsigned int line, unsigned int pos, utf8String source) {
	Node* node = dmt_calloc(1, sizeof(Node));
	node->source = source;
	node->line = line;
	node->pos = pos;

	return node;
}

Program* createProgram(Node* parentNode) {
	Program *program = dmt_calloc(1, sizeof(Program));
	program->parent = parentNode;
	vec_init(&program->imports);
	vec_init(&program->externMethods);
	vec_init(&program->variables);
	vec_init(&program->datatypes);
	vec_init(&program->functions);

	return program;
}
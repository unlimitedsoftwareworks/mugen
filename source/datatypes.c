#include "datatypes.h"
#include "memory.h"

Program* createProgram() {
	Program *program = dmt_calloc(1, sizeof(Program));
	vec_init(&program->imports);
	vec_init(&program->externMethods);
	vec_init(&program->variables);
	vec_init(&program->datatypes);
	vec_init(&program->functions);

	return program;
}
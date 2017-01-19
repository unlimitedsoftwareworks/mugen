#include "mugen.h"
#include "datatypes.h"
#include "memory.h"

Program* createProgram(unsigned int line, unsigned int pos, utf8String source) {
	Program *program = dmt_calloc(1, sizeof(Program));
	
	program->parent.ReturnValue = NULL;
	program->parent.source = source;
	program->parent.line = line;
	program->parent.pos = pos;
	program->parent.Debug = 1;
	
	vec_init(&program->imports);
	vec_init(&program->externMethods);
	vec_init(&program->variables);
	vec_init(&program->datatypes);
	vec_init(&program->functions);

	return program;
}

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "mugen.h"
#include "engine.h"
#include "datatypes.h"
#include "memory.h"
#include "defines.h"

Program* createProgram(struct TokenStruct *token) {
	Program *program = dmt_calloc(1, sizeof(Program));
	
	program->node.ReturnValue = NULL;
	program->node.token = token;
	program->node.Debug = 0;
	program->node.nodeType = PS_PROGRAM;
	program->node.parent = NULL;
	
	vec_init(&program->imports);
	vec_init(&program->externMethods);
	vec_init(&program->variables);
	vec_init(&program->datatypes);
	vec_init(&program->functions);

	return program;
}

ImportPackage* createImportPackage(Node* parent, struct TokenStruct *token) {
	ImportPackage *import = dmt_calloc(1, sizeof(ImportPackage));
	import->node.parent = parent;
	import->node.nodeType = PS_IMPORTPATH;
    import->node.token = token;
	
	vec_init(&import->pkg);
	
	return import;
}

void dumpImportPackage(ImportPackage* import) {
	unsigned int i = 0;
	for(; i < import->pkg.length; i++) {
		printf("%ls", import->pkg.data[i]);
		if(i+1 < import->pkg.length)
			printf(".");
		else
			printf("\n");
	}
}

/* Datatypes */
//DataType* createDataType(Node* parent, 

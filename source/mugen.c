#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "memory.h"
#include "mugen.h"
#include "utilities.h"
#include "engine.h"
#include "parser.h"
#include "datatypes.h"

int compile(char *fname)
{
	wchar_t *InputBuf;
	struct TokenStruct *Token;
	int Result;

	/* Load the inputfile into memory. */
	InputBuf = LoadInputFile(fname);
	if (InputBuf == NULL) exit(1);

	int debugg = 0;
	int err = 0;
	/* Run the Parser. */
	Result = Parse(InputBuf, wcslen(InputBuf), 0, debugg, &Token);
	/* Interpret the results. */
	if (Result != PARSEACCEPT) {
		ShowErrorMessage(Token, Result);
		printf("\nSyntax Error\n");
		return 255;
	}
	else {
		printf("Input accepted\n");
	}

	Program *program = dmt_calloc(1, sizeof(Program));
	vec_init(&program->imports);
	vec_init(&program->externMethods);
	vec_init(&program->variables);
	vec_init(&program->datatypes);
	vec_init(&program->functions);
	

	//printTree(Token,0);

	//semanticAnalyse(parentExpr);

	/* Cleanup. */
	DeleteTokens(Token);
	dmt_free(InputBuf);
	return 0;
}


void displayHelp()
{
    printf(MUGEN_HELP, MUGEN_VERSION);
}

void parseCmdLine(int argc, char* argv[])
{
}


#ifndef MUGEN_PARSER_H
#define MUGEN_PARSER_H

#include <stdlib.h>
#include "vec.h"
#include "mugen.h"
#include "engine.h"
#include "datatypes.h"


struct ContextStruct {
	wchar_t *ReturnValue;             /* In this template all rules return a string. */
	int Indent;                       /* For printing debug messages. */
	int Debug;                        /* 0=off, 1=on */
	struct TokenStruct *token;
	struct ContextStruct *parent;
}ContextStruct;




void ReadableString(wchar_t *Input, wchar_t *Output, long Width);

#endif

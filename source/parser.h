#ifndef MUGEN_PARSER_H
#define MUGEN_PARSER_H

#include <stdlib.h>
#include "utf8.h"
#include "containers/vec.h"
#include "mugen.h"
#include "engine.h"
#include "types.h"


struct ContextStruct {
	wchar_t *ReturnValue;             /* In this template all rules return a string. */
	int Indent;                       /* For printing debug messages. */
	int Debug;                        /* 0=off, 1=on */
	struct TokenStruct *token;
	struct ContextStruct *parent;
}ContextStruct;













































#endif

#ifndef AI_PARSER_H
#define AI_PARSER_H

#include <stdlib.h>
#include "utf8.h"
#include "containers/vec.h"
#include "mugen.h"
#include "engine.h"

struct ContextStruct {
	wchar_t *ReturnValue;             /* In this template all rules return a string. */
	int Indent;                       /* For printing debug messages. */
	int Debug;                        /* 0=off, 1=on */
	struct TokenStruct *token;
	struct ContextStruct *parent;
}ContextStruct;

typedef struct Program {
    vec_t(struct ImportExpr*) imports;
    
    vec_t(struct TypeDecl*) typeDecls;
    vec_t(struct VariableDecl*) varDecls;
    vec_t(struct FunctionDecl*) funcDecls;
}Program;

typedef struct ImportExpr{
    vec_t(wchar_t*) path;
}ImportExpr;

typedef struct TypeDecl{
    wchar_t* name;
    struct TypeExpr* type;
}TypeDecl;

//void parseAst(struct TokenStruct *Token, struct ContextStruct *context);

#endif

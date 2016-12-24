#ifndef AI_PARSER_H
#define AI_PARSER_H

#include <stdlib.h>
#include "utf8.h"
#include "containers/vec.h"
#include "mugen.h"
#include "engine.h"

#define NEW(type) type* new_##type(){ return (type*)dmt_calloc(1, sizeof(type)); }

typedef enum FunctionBodyType{
    FBT_EXPR = 0,
    FBT_BODY = 1
}FunctionBodyType;

typedef enum TypeExprType{
    TET_BASE,
    TET_FN,
    TET_TEMPLATE,
    TET_ARRAY,
    TET_TUPLE;
    TET_INTERFACE,
}TypeExprType;

struct ContextStruct {
	wchar_t *ReturnValue;             /* In this template all rules return a string. */
	int Indent;                       /* For printing debug messages. */
	int Debug;                        /* 0=off, 1=on */
	struct TokenStruct *token;
	struct ContextStruct *parent;
}ContextStruct;

typedef struct Program {
    vec_t(struct ImportExpr*) imports;
    
    vec_t(struct GlobalTypeDecl*) typeDecls;
    vec_t(struct GlobalVariableDecl*) varDecls;
    vec_t(struct GlobalFunctionDecl*) funcDecls;
    vec_t(struct GlobalEnumDecl*) enumDecls;
    vec_t(struct InterfaceDecl*) interfaceDecls;
    vec_t(struct ClassDecl*) classDecls;
}Program;

typedef struct ImportExpr{
    vec_t(wchar_t*) path;
}ImportExpr;

typedef struct GlobalTypeDecl{
    wchar_t* name;
    struct TypeExpr* type;
}GlobalTypeDecl;

typedef struct GlobalVariableDecl{
    wchar_t* name;
    struct TypeExpr* type;
    int isLocal;
    int isMutable;
}GlobalVariableDecl;

typedef struct GlobalFunctionDecl{
    wchar_t* name;
    vec_t(struct VariableDecl*) params;
    
    struct TypeExpr* returnType;
    enum FunctionBodyType bodyType;
}GlobalFunctionDecl;

typedef struct InterfaceDecl{
    struct InterfaceHeader* header;
    
    vec_t(struct OperatorDecl) operators;
    vec_t(struct InterfaceMethod*) methods;
}InterfaceDecl;

typedef struct ClassDecl{
    struct ClassHeader* header;
    
    int isImmutable;
    
    vec_t(struct ClassMethod*) methods;
    vec_t(struct OperatorDecl) operators;
    vec_t(struct ClassAttributes*) attributes;
}ClassDecl;


typedef struct TypeExpr{
    TypeExprType type;
    union{
        struct TypeBaseExpr* base;
        struct TypeFnExpr* fn;
        struct TypeArrayExpr* array;
        struct TypeTupleExpr* tuple
    };
}TypeExpr;



//void parseAst(struct TokenStruct *Token, struct ContextStruct *context);

#endif

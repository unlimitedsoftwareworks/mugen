#ifndef AI_PARSER_H
#define AI_PARSER_H

#include <stdlib.h>
#include "utf8.h"
#include "containers/vec.h"
#include "mugen.h"
#include "engine.h"

/*
 * Helper macros,
 * Write once use, use everywhere.
 */

/* used to allocate all kind of structures */
#define NEW(type) type* new_##type(){ return (type*)dmt_calloc(1, sizeof(type)); }

/* is(object, type) checks if object.typeField == type */
#define IS(o, t) (o.typeField == ENUM_##t)

/* all enums has the same structures */
#define ENUM(t) ENUM_##t

typedef enum FunctionBodyType{
    ENUM(Expr) = 0,
    ENUM(Block) = 1
}FunctionBodyType;

typedef enum TypeExprType{
    ENUM(TypeBaseExpr),
    ENUM(TypeFnExpr),
    ENUM(TypeTemplateExpr),
    ENUM(TypeArrayExpr),
    ENUM(TypeTupleExpr),
    ENUM(TypeInterfaceExpr),
}TypeExprType;

typedef enum TypeBaseType{
    TBT_BYTE,
    TBT_CHAR,
    TBT_BOOL,
    TBT_INT_8,
    TBT_UINT_8,
    TBT_INT_16,
    TBT_UINT_16,
    TBT_INT_32,
    TBT_UINT_32,
    TBT_INT_64,
    TBT_UINT_64,
    TBT_FLOAT,
    TBT_DOUBLE,
}TypeBaseType

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
    enum FunctionBodyType typeField;
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

typedef struct TypeBaseExpr{
    enum TypeBaseType type;
}TypeBaseExpr;

typedef struct TypeFnExpr{
    vec_t(struct TypeExpr*) params;
    vec_t(struct TypeExpr*) returns;
}TypeFnExpr;

typedef struct TypeArrayExpr{
    struct TypeExpr* type;
}TypeArrayExpr;

typedef struct TypeTupleExpr{
    
};

//void parseAst(struct TokenStruct *Token, struct ContextStruct *context);

#endif

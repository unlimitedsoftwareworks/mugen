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
    ENUM(TypePkgExpr),
    ENUM(TypeTemplatePkgExpr),
    ENUM(TypeArrayExpr),
    ENUM(TypeTupleExpr),
    ENUM(TypeInterfaceExpr),
}TypeExprType;

typedef enum TypeBaseType{
    ENUM(ByteValue),
    ENUM(CharValue),
    ENUM(BoolValue),
    ENUM(Int8Value),
    ENUM(UInt8Value),
    ENUM(Int16Value),
    ENUM(UInt16Value),
    ENUM(Int32Value),
    ENUM(UInt32Value),
    ENUM(Int64Value),
    ENUM(UInt64Value),
    ENUM(FloatValue),
    ENUM(DoubleValue),
}TypeBaseType;

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
    TypeExprType typeField;
    union{
        struct TypeBaseExpr* base;
        struct TypeFnExpr* fn;
        struct TypePkgExpr pkg;
        struct TypePkgTemplateExpr pkgTemplate;
        struct TypeArrayExpr* array;
        struct TypeTupleExpr* tuple;
        struct TypeInterfaceExpr interfaceList;
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
    vec_t(TypeExpr*) params;
};

//void parseAst(struct TokenStruct *Token, struct ContextStruct *context);

#endif

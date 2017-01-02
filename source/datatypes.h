#ifndef MUGEN_TYPES_H
#define MUGEN_TYPES_H

#include <stdlib.h>
#include "vec.h"
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

/* used in enum fields */
#define ENUM(t) ENUM_##t

/* Used inside unions */
#define FIELD(t) struct t##DataType* field##t
#define FIELD_(t) struct t* field##t

/* used in structure headers */
#define TYPE(t) t##DataType

/*
 * ******************************************
 *        DataTypes Representations
 * *******************************************
 */

typedef enum EnumTypes {
    ENUM(Basic),
    ENUM(Array),
    ENUM(Tuple),
    ENUM(Reference),
    ENUM(Fn),
    ENUM(Behavior),
    ENUM(Interface),
    ENUM(Class),
    ENUM(Enum),
    ENUM(GenericInterface),
    ENUM(GenericClass),
    ENUM(Dummy),
}EnumTypes;

typedef enum EnumBasicDataType {
    ENUM(Byte),
    ENUM(Char),
    ENUM(Int8),
    ENUM(UInt8),
    ENUM(Int16),
    ENUM(UInt16),
    ENUM(Int32),
    ENUM(UInt32),
    ENUM(Int64),
    ENUM(UInt64),
    ENUM(Float),
    ENUM(Double),
    ENUM(Boolean),
}EnumBaseType;


typedef struct DataType {
    enum EnumTypes typeField;
    union{
        FIELD(Basic);
        FIELD(Array);
        FIELD(Tuple);
        FIELD(Reference);
        FIELD(Fn);
        FIELD(Behavior);
        FIELD(Interface);
        FIELD(Class);
        FIELD(Enum);
        FIELD(GenericInterface);
        FIELD(GenericClass);
        FIELD(Dummy);
    };
}DataType;

typedef struct TYPE(Basic) {
    enum EnumBasicDataType typeField;
}TYPE(Basic);

typedef struct TYPE(Array) {
    struct DataType* arrayOf;
}TYPE(Array);

typedef struct TYPE(Tuple) {
    vec_t(struct DataType*) elements;
}TYPE(Tuple);

typedef struct TYPE(Reference)
{
    struct DataType* referenceTo;
}TYPE(Reference);

typedef struct TYPE(Fn) {
    vec_t(struct DataType*) params;
    vec_t(struct DataType*) returnTypes;
}TYPE(Fn);

typedef struct TYPE(Behavior) {
    /* can be only interfaces and generic interface */
    vec_t(struct DataType*) behaviours;
}TYPE(Behavior);

typedef struct TYPE(Interface) {
    wchar_t* name;
    
    vec_t(struct FunctionMethodHeader*) methodHeaders;
    vec_t(struct OperatorMethodHeader*) operatorHeaders;
}TYPE(Interface);

typedef struct TYPE(Class) {
    wchar_t* name;
    int isImmutable;
    
    vec_t(struct TYPE(Interface)*) implements;
    vec_t(struct FunctionMethod*) methods;
    vec_t(struct OperatorMethod*) operators;
    vec_t(struct Attribute*) attributes;
}TYPE(Class);

typedef struct TYPE(Enum) {
    wchar_t* name;
    vec_t(wchar_t*) enums;
}TYPE(Enum);

typedef struct TYPE(GenericInterface) {
    wchar_t* name;
    
    vec_t(struct TYPE(Dummy)) generics;
    vec_t(struct FunctionMethodHeader*) methodHeaders;
    vec_t(struct OperatorMethodHeader*) operatorHeaders;
}TYPE(GenericInterface);


typedef struct TYPE(GenericClass) {
    wchar_t* name;
    
    vec_t(struct TYPE(Dummy)) generics;
    vec_t(struct TYPE(Interface)*) implements;
    vec_t(struct FunctionMethod*) methods;
    vec_t(struct OperatorMethod*) operators;
    vec_t(struct Attribute*) attributes;
}TYPE(GenericClass);

typedef struct TYPE(Dummy) {
    wchar_t* name;
}TYPE(Dummy);

/*
 * ***********************************************************
 *    Method/Functions Attribute/Variables Representations
 * ***********************************************************
 */

typedef enum EnumFunctionBodyType{
    ENUM(Expr),
    ENUM(Block)
}EnumFunctionBodyType;

typedef struct FunctionMethodHeader {
    wchar_t name;
    struct TYPE(Fn) fnType;
}FunctionMethodHeader;

typedef struct OperatorMethodHeader {
    /* operator ID as in defines.h */
    unsigned int opId;
    struct TYPE(Fn) fnType;
}OperatorMethodHeader;

typedef struct FunctionMethod {
    struct FunctionMethodHeader* header;
    EnumFunctionBodyType typeField;
    union{
        FIELD_(Expr);
        FIELD_(Block);
    };
    int isSynchronized;
}FunctionMethod;

typedef struct OperatorMethod {
    struct FunctionMethodHeader* header;
    EnumFunctionBodyType typeField;
    union{
        FIELD_(Expr);
        FIELD_(Block);
    };
    int isSynchronized;
}OperatorMethod;

/*
 * Used for method attributes and global variables *
 */
typedef struct Attribute {
    wchar_t name;
    struct DataType* type;
    int isLocal;
    int isMutable;
}Attribute;

/*
 * ***********************************************************
 *                      Program Tree
 * ***********************************************************
 */

typedef struct Program{
    wchar_t* name;
    
    vec_t(struct ImportPackage*) imports;
    vec_t(struct ExternMethod*) externMethods;
    vec_t(struct Attribute*) variables;
    vec_t(struct DataType*) datatypes;
    vec_t(struct Function*) functions;    
}Program;

/* 
 * Single Import Expression
 */
typedef struct ImportPackage{
    vec_t(wchar_t*) pkg;
}ImportPackage;

/* 
 * Global functions
 */
typedef struct Function{
    struct FunctionMethodHeader* header;
    EnumFunctionBodyType typeField;
    union{
        FIELD_(Expr);
        FIELD_(Block);
    };
}Function;

typedef struct ExternMethod{
    struct FunctionMethodHeader* header;
    int isPure;
}ExternMethod;

/*
 * Used inside functions
 * where it does not have local visibility
 */
typedef struct Variable{
    wchar_t* name;
    struct DataType* type;
    int isMutable;
}Variable;

/* Statements */

typedef enum EnumStatements{
    ENUM(StmtBlock),
    ENUM(Repeat),
    ENUM(While),
    ENUM(For),
    ENUM(Foreach),
    ENUM(Return),
    ENUM(Break),
    ENUM(Continue),
    ENUM(If),
    ENUM(Match),
    ENUM(Expression),
}EnumStatements;


typedef struct Block {
    vec_t(struct Statement*) statements;
    vec_t(struct Variable*) variables;
    int isSynchronized;
}Block;

typedef struct Repeat{
    struct Block* block;
    struct Expr* condition;
}Repeat;

typedef struct While{
    struct Block* block;
    struct Expr* condition;
}While;

typedef struct For{
    vec_t(struct Expr*) initExprList;
    struct Expr* condition;
    vec_t(struct Expr*) incExprList;
    struct Block* block;
}For;

typedef struct Foreach{
    struct Variable* looper;
    struct Expr* container;
    struct Block* block;
}Foreach;

typedef struct Return{
    vec_t(struct Expr*) returnedExprs;
}Return;

typedef struct If{
    struct Expr* condition;
    struct Block* block;
    vec_t(struct If*) elseifs;
    struct Else* else_;
}If;

typedef struct Else {
    struct Block* block;
}Else;

typedef struct Match{
    vec_t(struct Expr*) tomatch;
    vec_t(struct MatchElement*) elements;
    struct Block* else_;
}Match;

typedef struct MatchElement {
    vec_t(struct Expr*) matches;
    struct Block* block;
}MatchElement;

/*
 * Expressions
 */

typedef enum EnumExpressions{
    ENUM(VarDeclExpr),
    ENUM(MatchExpr),
    ENUM(BinaryOperator),
    ENUM(UnaryOperator),
    ENUM(ValueExpr),
    ENUM(ListCompExpr),
    ENUM(LabmdaExpr),
    ENUM(NewExpr),
}EnumExpressions;

typedef enum EnumValues{
    ENUM(OctValue),
    ENUM(HexValue),
    ENUM(DecValue),
    ENUM(BinValue),
    ENUM(StringValue),
    ENUM(StringCharValue),
    ENUM(NullValue),
    ENUM(BooleanValue),
}EnumValues;

typedef struct VarDeclExpr{
    vec_t(struct Variable*) variables;
};

typedef struct MatchExpr{
    vec_t(struct MatchExprElement*) elements;
    struct Expr* else_;
}MatchExpr;

typedef struct MatchExprElement{
    vec_t(struct Expr*) matches;
    struct Expr* expr;
}MatchExprElement;

typedef struct BinaryOperator{
    unsigned int operator;
    struct Expr* left;
    struct Expr* right;
}BinaryOperator;

typedef struct UnaryOperator{
    unsigned int operator;
    struct Expr* unary;
}UnaryOperator;

typedef struct Value{
    wchar_t* value;
}Value;

typedef struct ListCompExpr{
    struct Variable* variable;
    struct Expr* in;
    struct Expr* condition;
    struct Expr* expr;
}ListCompExpr;

typedef struct LabmdaExpr{
    struct FunctionMethodHeader* header;
    EnumFunctionBodyType typeField;
    union{
        FIELD_(Expr);
        FIELD_(Block);
    };
}LabmdaExpr;

typedef enum EnumNew{
    ENUM(NewPkgTemplate),
    ENUM(NewPkg),
    ENUM(NewArray)
}EnumNew;

typedef struct NewExpr{
    EnumNew typeField;
    union{
        struct NewPkgTemplate* newPkgTemplate;
        struct NewPkg* newPkg;
        struct NewArray* newArray;
    };
}NewExpr;

typedef struct NewPkgTemplate{
    vec_t(wchar_t *) pkg;
}NewPkgTemplate;

#endif


























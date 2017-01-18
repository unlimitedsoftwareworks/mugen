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
//#define PARENT_EXPR struct Node* parent;
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

typedef struct Node {
	unsigned int line;
	unsigned int pos;
	utf8String source;
}Node;

typedef struct TYPE(Basic) {
	struct Node* parent;
    enum EnumBasicDataType typeField;
}TYPE(Basic);

typedef struct TYPE(Array) {
	struct Node* parent;
    struct DataType* arrayOf;
}TYPE(Array);

typedef struct TYPE(Tuple) {
	struct Node* parent;
    vec_t(struct DataType*) elements;
}TYPE(Tuple);

typedef struct TYPE(Reference) {
	struct Node* parent;
    struct DataType* referenceTo;
}TYPE(Reference);

typedef struct TYPE(Fn) {
	struct Node* parent;
    vec_t(struct DataType*) params;
    vec_t(struct DataType*) returnTypes;
}TYPE(Fn);

typedef struct TYPE(Behavior) {
	struct Node* parent;
    /* can be only interfaces and generic interface */
    vec_t(struct DataType*) behaviours;
}TYPE(Behavior);

typedef struct TYPE(Interface) {
	struct Node* parent;
    utf8String name;
    
    vec_t(struct FunctionMethodHeader*) methodHeaders;
    vec_t(struct OperatorMethodHeader*) operatorHeaders;
}TYPE(Interface);

typedef struct TYPE(Class) {
	struct Node* parent;
	utf8String name;
    int isImmutable;
    
    vec_t(struct TYPE(Interface)*) implements;
    vec_t(struct FunctionMethod*) methods;
    vec_t(struct OperatorMethod*) operators;
    vec_t(struct Attribute*) attributes;
}TYPE(Class);

typedef struct TYPE(Enum) {
	utf8String name;
    vec_t(utf8String) enums;
}TYPE(Enum);

typedef struct TYPE(GenericInterface) {
	struct Node* parent;
    utf8String name;
    
    vec_t(struct TYPE(Dummy)) generics;
    vec_t(struct FunctionMethodHeader*) methodHeaders;
    vec_t(struct OperatorMethodHeader*) operatorHeaders;
}TYPE(GenericInterface);


typedef struct TYPE(GenericClass) {
	struct Node* parent;
    utf8String name;
    
    vec_t(struct TYPE(Dummy)) generics;
    vec_t(struct TYPE(Interface)*) implements;
    vec_t(struct FunctionMethod*) methods;
    vec_t(struct OperatorMethod*) operators;
    vec_t(struct Attribute*) attributes;
}TYPE(GenericClass);

typedef struct TYPE(Dummy) {
	struct Node* parent;
    utf8String name;
}TYPE(Dummy);

/*
 * ***********************************************************
 *    Method/Functions Attribute/Variables Representations
 * ***********************************************************
 */

typedef enum EnumFunctionBodyType{
    ENUM(Node),
    ENUM(Block)
}EnumFunctionBodyType;

typedef struct FunctionMethodHeader {
	struct Node* parent;
	utf8String name;
    struct TYPE(Fn) fnType;
}FunctionMethodHeader;

typedef struct OperatorMethodHeader {
	struct Node* parent;
    /* operator ID as in defines.h */
    unsigned int opId;
    struct TYPE(Fn) fnType;
}OperatorMethodHeader;

typedef struct FunctionMethod {
	struct Node* parent;
    struct FunctionMethodHeader* header;
    EnumFunctionBodyType typeField;
    union{
        FIELD_(Node);
        FIELD_(Block);
    };
    int isSynchronized;
}FunctionMethod;

typedef struct OperatorMethod {
	struct Node* parent;
    struct FunctionMethodHeader* header;
    EnumFunctionBodyType typeField;
    union{
        FIELD_(Node);
        FIELD_(Block);
    };
    int isSynchronized;
}OperatorMethod;

/*
 * Used for method attributes and global variables *
 */
typedef struct Attribute {
	struct Node* parent;
	utf8String name;
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
	struct Node* parent;
    utf8String name;
    
    vec_t(struct ImportPackage*) imports;
    vec_t(struct ExternMethod*) externMethods;
    vec_t(struct Attribute*) variables;
    vec_t(struct DataType*) datatypes;
    vec_t(struct Function*) functions;    
}Program;

/* 
 * Single Import Nodeession
 */
typedef struct ImportPackage{
	struct Node* parent;
    vec_t(utf8String) pkg;
}ImportPackage;

/* 
 * Global functions
 */
typedef struct Function{
	struct Node* parent;
    struct FunctionMethodHeader* header;
    EnumFunctionBodyType typeField;
    union{
        FIELD_(Node);
        FIELD_(Block);
    };
}Function;

typedef struct ExternMethod{
	struct Node* parent;
    struct FunctionMethodHeader* header;
    int isPure;
}ExternMethod;

/*
 * Used inside functions
 * where it does not have local visibility
 */
typedef struct Variable{
	struct Node* parent;
    utf8String name;
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
    ENUM(Nodeession),
}EnumStatements;


typedef struct Block {
	struct Node* parent;
    vec_t(struct Statement*) statements;
    vec_t(struct Variable*) variables;
    int isSynchronized;
}Block;

typedef struct Repeat{
	struct Node* parent;
    struct Block* block;
    struct Node* condition;
}Repeat;

typedef struct While{
	struct Node* parent;
    struct Block* block;
    struct Node* condition;
}While;

typedef struct For{
	struct Node* parent;
    vec_t(struct Node*) initNodeList;
    struct Node* condition;
    vec_t(struct Node*) incNodeList;
    struct Block* block;
}For;

typedef struct Foreach{
	struct Node* parent;
    struct Variable* looper;
    struct Node* container;
    struct Block* block;
}Foreach;

typedef struct Return{
	struct Node* parent;
    vec_t(struct Node*) returnedNodes;
}Return;

typedef struct If{
	struct Node* parent;
    struct Node* condition;
    struct Block* block;
    vec_t(struct If*) elseifs;
    struct Else* else_;
}If;

typedef struct Else {
	struct Node* parent;
    struct Block* block;
}Else;

typedef struct Match{
	struct Node* parent;
    vec_t(struct Node*) tomatch;
    vec_t(struct MatchElement*) elements;
    struct Block* else_;
}Match;

typedef struct MatchElement {
	struct Node* parent;
    vec_t(struct Node*) matches;
    struct Block* block;
}MatchElement;

/*
 * Nodeessions
 */

typedef enum EnumNodeessions{
    ENUM(VarDeclNode),
    ENUM(MatchNode),
    ENUM(BinaryOperator),
    ENUM(UnaryOperator),
    ENUM(ValueNode),
    ENUM(ListCompNode),
    ENUM(LabmdaNode),
    ENUM(NewNode),
}EnumNodeessions;

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

typedef struct VarDeclNode{
	struct Node* parent;
    vec_t(struct Variable*) variables;
};

typedef struct MatchNode{
	struct Node* parent;
    vec_t(struct MatchNodeElement*) elements;
    struct Node* else_;
}MatchNode;

typedef struct MatchNodeElement{
	struct Node* parent;
    vec_t(struct Node*) matches;
    struct Node* expr;
}MatchNodeElement;

typedef struct BinaryOperator{
	struct Node* parent;
    unsigned int operator;
    struct Node* left;
    struct Node* right;
}BinaryOperator;

typedef struct UnaryOperator{
	struct Node* parent;
    unsigned int operator;
    struct Node* unary;
}UnaryOperator;

typedef struct Value{
	struct Node* parent;
    utf8String value;
}Value;

typedef struct ListCompNode{
	struct Node* parent;
    struct Variable* variable;
    struct Node* in;
    struct Node* condition;
    struct Node* expr;
}ListCompNode;

typedef struct LabmdaNode{
	struct Node* parent;
    struct FunctionMethodHeader* header;
    EnumFunctionBodyType typeField;
    union{
        FIELD_(Node);
        FIELD_(Block);
    };
}LabmdaNode;

typedef enum EnumNew{
    ENUM(NewPkgTemplate),
    ENUM(NewPkg),
    ENUM(NewArray)
}EnumNew;

typedef struct NewNode{
	struct Node* parent;
    EnumNew typeField;
    union{
        struct NewPkgTemplate* newPkgTemplate;
        struct NewPkg* newPkg;
        struct NewArray* newArray;
    };
}NewNode;

typedef struct NewPkgTemplate{
	struct Node* parent;
    vec_t(utf8String) pkg;
}NewPkgTemplate;

#endif


























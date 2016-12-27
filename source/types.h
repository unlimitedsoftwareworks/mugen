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
}FunctionMethod;

typedef struct OperatorMethod {
    struct FunctionMethodHeader* header;
    EnumFunctionBodyType typeField;
    union{
        FIELD_(Expr);
        FIELD_(Block);
    };
}OperatorMethod;

typedef struct Attribute {
    wchar_t name;
    struct DataType* type;
    int isLocal;
    int isMutable;
}Attribute;




#endif

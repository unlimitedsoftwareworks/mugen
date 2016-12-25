#ifndef MUGEN_EXPR_H
#define MUGEN_EXPR_H

#include "types.h"

typedef enum EnumExpr{
    ENUM(VarDeclExpr),
    ENUM(MatchExpr),
    ENUM(BinaryOperator),
    ENUM(UnaryOperator),
    ENUM(NewExpr),
    ENUM(ValueExpr),
    ENUM(LambdaExpr),
    ENUM(ListCompExpr),
}EnumExpr;
/*
typedef struct Expr{
    
}Expr;
*/

#endif

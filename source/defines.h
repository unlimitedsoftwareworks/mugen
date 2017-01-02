#ifndef MUGEN_DEFINES_H
#define MUGEN_DEFINES_H

#define PS_EOF 0 // (EOF)
#define PS_ERROR 1 // (Error)
#define PS_COMMENT 2 // Comment
#define PS_NEWLINE 3 // NewLine
#define PS_WHITESPACE 4 // Whitespace
#define PS_TIMESDIV 5 // '*/'
#define PS_DIVTIMES 6 // '/*'
#define PS_DIVDIV 7 // '//'
#define PS_MINUS 8 // '-'
#define PS_MINUSMINUS 9 // '--'
#define PS_EXCLAM 10 // '!'
#define PS_EXCLAMEQ 11 // '!='
#define PS_PERCENT 12 // '%'
#define PS_PERCENTEQ 13 // '%='
#define PS_AMP 14 // '&'
#define PS_AMPAMP 15 // '&&'
#define PS_AMPEQ 16 // '&='
#define PS_LPAREN 17 // '('
#define PS_RPAREN 18 // ')'
#define PS_TIMES 19 // '*'
#define PS_TIMESEQ 20 // '*='
#define PS_COMMA 21 // ','
#define PS_DOT 22 // '.'
#define PS_DIV 23 // '/'
#define PS_DIVEQ 24 // '/='
#define PS_COLON 25 // ':'
#define PS_SEMI 26 // ';'
#define PS_LBRACKET 27 // '['
#define PS_RBRACKET 28 // ']'
#define PS_CARET 29 // '^'
#define PS_CARETEQ 30 // '^='
#define PS_LBRACE 31 // '{'
#define PS_PIPE 32 // '|'
#define PS_PIPEPIPE 33 // '||'
#define PS_PIPEEQ 34 // '|='
#define PS_RBRACE 35 // '}'
#define PS_TILDE 36 // '~'
#define PS_PLUS 37 // '+'
#define PS_PLUSPLUS 38 // '++'
#define PS_PLUSEQ 39 // '+='
#define PS_LT 40 // '<'
#define PS_LTLT 41 // '<<'
#define PS_LTLTEQ 42 // '<<='
#define PS_LTEQ 43 // '<='
#define PS_EQ 44 // '='
#define PS_MINUSEQ 45 // '-='
#define PS_EQEQ 46 // '=='
#define PS_EQGT 47 // '=>'
#define PS_GT 48 // '>'
#define PS_MINUSGT 49 // '->'
#define PS_GTEQ 50 // '>='
#define PS_GTGT 51 // '>>'
#define PS_GTGTEQ 52 // '>>='
#define PS_AS 53 // as
#define PS_BINLITERAL 54 // BinLiteral
#define PS_BOOL 55 // Bool
#define PS_BREAK 56 // break
#define PS_BYTE 57 // Byte
#define PS_CASE 58 // case
#define PS_CHAR 59 // Char
#define PS_CHARLITERAL 60 // CharLiteral
#define PS_CLASS 61 // class
#define PS_CONTINUE 62 // continue
#define PS_DECLITERAL 63 // DecLiteral
#define PS_DELETE 64 // delete
#define PS_DOUBLE 65 // Double
#define PS_ELSE 66 // else
#define PS_ENUM 67 // enum
#define PS_FALSE 68 // false
#define PS_FLOAT 69 // Float
#define PS_FLOATLITERAL 70 // FloatLiteral
#define PS_FN 71 // fn
#define PS_FOR 72 // for
#define PS_FOREACH 73 // foreach
#define PS_FROM 74 // from
#define PS_FUNCTION 75 // function
#define PS_HEXLITERAL 76 // HexLiteral
#define PS_IDENTIFIER 77 // Identifier
#define PS_IF 78 // if
#define PS_IMMUTABLE 79 // immutable
#define PS_IMPLEMENTS 80 // implements
#define PS_IMPORT 81 // import
#define PS_IN 82 // in
#define PS_INT16 83 // 'Int16'
#define PS_INT32 84 // 'Int32'
#define PS_INT64 85 // 'Int64'
#define PS_INT8 86 // 'Int8'
#define PS_INTERFACE 87 // interface
#define PS_IS 88 // is
#define PS_LAMBDA 89 // lambda
#define PS_LET 90 // let
#define PS_LOCAL 91 // local
#define PS_MATCH 92 // match
#define PS_MUT 93 // mut
#define PS_NEW 94 // new
#define PS_NULL 95 // null
#define PS_OCTLITERAL 96 // OctLiteral
#define PS_REPEAT 97 // repeat
#define PS_RETURN 98 // return
#define PS_SIZEOF 99 // sizeof
#define PS_STRINGLITERAL 100 // StringLiteral
#define PS_SYNCHRONIZED 101 // synchronized
#define PS_TRUE 102 // true
#define PS_TYPE 103 // type
#define PS_UINT16 104 // 'UInt16'
#define PS_UINT32 105 // 'UInt32'
#define PS_UINT64 106 // 'UInt64'
#define PS_UINT8 107 // 'UInt8'
#define PS_WHEN 108 // when
#define PS_WHILE 109 // while
#define PS_BASE 110 // <Base>
#define PS_BLOCK 111 // <Block>
#define PS_BREAKSTMT 112 // <Break Stmt>
#define PS_CASEEXPRS 113 // <Case Exprs>
#define PS_CLASSDECL 114 // <Class Decl>
#define PS_CLASSDECLS 115 // <Class Decls>
#define PS_CLASSDEF 116 // <Class Def>
#define PS_CLASSMETHOD 117 // <Class Method>
#define PS_CLASSMETHODDECL 118 // <Class Method Decl>
#define PS_CLASSVARIABLEDECL 119 // <Class Variable Decl>
#define PS_CONTINUESTMT 120 // <Continue Stmt>
#define PS_DECL 121 // <Decl>
#define PS_DECLARATIONS 122 // <Declarations>
#define PS_ELSEELEMENT 123 // <Else Element>
#define PS_ELSEIFSTMT 124 // <Else If Stmt>
#define PS_ELSESTMT 125 // <Else Stmt>
#define PS_ENUMDECL 126 // <Enum Decl>
#define PS_ENUMVALUE 127 // <Enum Value>
#define PS_ENUMVALUES 128 // <Enum Values>
#define PS_EXPR 129 // <Expr>
#define PS_EXPRLIST 130 // <Expr List>
#define PS_FNTYPE 131 // <Fn Type>
#define PS_FORSTMT 132 // <For Stmt>
#define PS_FOREACHSTMT 133 // <Foreach Stmt>
#define PS_FUNCNAME 134 // <Func Name>
#define PS_IDLIST 135 // <Id List>
#define PS_IFSTMT 136 // <If Stmt>
#define PS_IMPORTEXPRLIST 137 // <Import Expr List>
#define PS_IMPORTPATH 138 // <Import Path>
#define PS_IMPORTSECTION 139 // <Import Section>
#define PS_INTERFACEDEF 140 // <Interface Def>
#define PS_INTERFACEMETHOD 141 // <Interface Method>
#define PS_INTERFACEMETHODS 142 // <Interface Methods>
#define PS_LAMBDAEXPR 143 // <Lambda Expr>
#define PS_LFUNCTIONDECL 144 // <LFunction Decl>
#define PS_LTYPEDECL 145 // <LType Decl>
#define PS_LVARDECL 146 // <LVar Decl>
#define PS_MATCHELEMENT 147 // <Match Element>
#define PS_MATCHLIST 148 // <Match List>
#define PS_MATCHSTMT 149 // <Match Stmt>
#define PS_NEWEXPR 150 // <New Expr>
#define PS_OPADD 151 // <Op Add>
#define PS_OPAND 152 // <Op And>
#define PS_OPASSIGN 153 // <Op Assign>
#define PS_OPBINAND 154 // <Op BinAND>
#define PS_OPBINOR 155 // <Op BinOR>
#define PS_OPBINXOR 156 // <Op BinXOR>
#define PS_OPCOMPARE 157 // <Op Compare>
#define PS_OPEQUATE 158 // <Op Equate>
#define PS_OPMULT 159 // <Op Mult>
#define PS_OPOR 160 // <Op Or>
#define PS_OPPOINTER 161 // <Op Pointer>
#define PS_OPSHIFT 162 // <Op Shift>
#define PS_OPUNARY 163 // <Op Unary>
#define PS_OVERRIDEABLEOPERATOR 164 // <Overrideable Operator>
#define PS_PARAM 165 // <Param>
#define PS_PARAMS 166 // <Params>
#define PS_PKG 167 // <Pkg>
#define PS_PKGTEMPLATE 168 // <Pkg Template>
#define PS_PKGTEMPLATELIST 169 // <Pkg Template List>
#define PS_PROGRAM 170 // <Program>
#define PS_REPEATSTMT 171 // <Repeat Stmt>
#define PS_RETURNSTMT 172 // <Return Stmt>
#define PS_STATEMENTS 173 // <Statements>
#define PS_STMT 174 // <Stmt>
#define PS_TYPE2 175 // <Type>
#define PS_TYPEDECL 176 // <Type Decl>
#define PS_TYPEDEF 177 // <Type Def>
#define PS_TYPES 178 // <Types>
#define PS_VALUE 179 // <Value>
#define PS_VARDECLSTMT 180 // <Var Decl Stmt>
#define PS_WHILESTMT 181 // <While Stmt>


#endif

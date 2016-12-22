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
#define PS__ 31 // '_'
#define PS_LBRACE 32 // '{'
#define PS_PIPE 33 // '|'
#define PS_PIPEPIPE 34 // '||'
#define PS_PIPEEQ 35 // '|='
#define PS_RBRACE 36 // '}'
#define PS_TILDE 37 // '~'
#define PS_PLUS 38 // '+'
#define PS_PLUSPLUS 39 // '++'
#define PS_PLUSEQ 40 // '+='
#define PS_LT 41 // '<'
#define PS_LTLT 42 // '<<'
#define PS_LTLTEQ 43 // '<<='
#define PS_LTEQ 44 // '<='
#define PS_EQ 45 // '='
#define PS_MINUSEQ 46 // '-='
#define PS_EQEQ 47 // '=='
#define PS_EQGT 48 // '=>'
#define PS_GT 49 // '>'
#define PS_MINUSGT 50 // '->'
#define PS_GTEQ 51 // '>='
#define PS_GTGT 52 // '>>'
#define PS_GTGTEQ 53 // '>>='
#define PS_AS 54 // as
#define PS_BINLITERAL 55 // BinLiteral
#define PS_BOOL 56 // Bool
#define PS_BREAK 57 // break
#define PS_BYTE 58 // Byte
#define PS_CASE 59 // case
#define PS_CHAR 60 // Char
#define PS_CHARLITERAL 61 // CharLiteral
#define PS_CLASS 62 // class
#define PS_CONTINUE 63 // continue
#define PS_DECLITERAL 64 // DecLiteral
#define PS_DELETE 65 // delete
#define PS_DOUBLE 66 // Double
#define PS_ELSE 67 // else
#define PS_ENUM 68 // enum
#define PS_FALSE 69 // false
#define PS_FLOAT 70 // Float
#define PS_FLOATLITERAL 71 // FloatLiteral
#define PS_FN 72 // fn
#define PS_FOR 73 // for
#define PS_FOREACH 74 // foreach
#define PS_FREE 75 // free
#define PS_FUNCTION 76 // function
#define PS_HEXLITERAL 77 // HexLiteral
#define PS_IDENTIFIER 78 // Identifier
#define PS_IF 79 // if
#define PS_IMMUTABLE 80 // immutable
#define PS_IMPLEMENTS 81 // implements
#define PS_IMPORT 82 // import
#define PS_IN 83 // in
#define PS_INT16 84 // 'Int16'
#define PS_INT32 85 // 'Int32'
#define PS_INT64 86 // 'Int64'
#define PS_INT8 87 // 'Int8'
#define PS_INTERFACE 88 // interface
#define PS_IS 89 // is
#define PS_LAMBDA 90 // lambda
#define PS_LET 91 // let
#define PS_LOCAL 92 // local
#define PS_MATCH 93 // match
#define PS_MUT 94 // mut
#define PS_NEW 95 // new
#define PS_NULL 96 // null
#define PS_OCTLITERAL 97 // OctLiteral
#define PS_REPEAT 98 // repeat
#define PS_RETURN 99 // return
#define PS_SIZEOF 100 // sizeof
#define PS_STRINGLITERAL 101 // StringLiteral
#define PS_SYNCHRONIZED 102 // synchronized
#define PS_TRUE 103 // true
#define PS_TYPE 104 // type
#define PS_UINT16 105 // 'UInt16'
#define PS_UINT32 106 // 'UInt32'
#define PS_UINT64 107 // 'UInt64'
#define PS_UINT8 108 // 'UInt8'
#define PS_WHEN 109 // when
#define PS_WHILE 110 // while
#define PS_BASE 111 // <Base>
#define PS_BLOCK 112 // <Block>
#define PS_BREAKSTMT 113 // <Break Stmt>
#define PS_CASEEXPRS 114 // <Case Exprs>
#define PS_CLASSDECL 115 // <Class Decl>
#define PS_CLASSDECLS 116 // <Class Decls>
#define PS_CLASSDEF 117 // <Class Def>
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

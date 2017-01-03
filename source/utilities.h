#ifndef MUGEN_COMPILER_H
#define MUGEN_COMPILER_H

#include <sys/stat.h>
#include "parser.h"
#include "engine.h"
#include "mugen.h"

wchar_t *LoadInputFile(char *FileName);
int fileExists(char* name);
void ShowErrorMessage(struct TokenStruct *Token, int Result);
const char* basename(const char *name);

#endif


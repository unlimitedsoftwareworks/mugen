/* not again .. */
#include "no_sillywarnings_please.h"

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#include "memory/memory.h"
#include "parser.h"
#include "engine.h"
#include "mugen.h"
#include "defines.h"
#include "utilities.h"


  /* Load input file from disk into memory. */
  wchar_t *LoadInputFile(char *FileName) {
	  FILE *Fin;
	  char *Buf1;
	  wchar_t *Buf2;
	  struct stat statbuf;
	  size_t BytesRead;
	  unsigned long i;

	  /* Sanity check. */
	  if ((FileName == NULL) || (*FileName == '\0')) return(NULL);

	  /* Open the file. */
	  Fin = fopen(FileName, "rb");
	  if (Fin == NULL) {
		  fprintf(stdout, "Could not open input file: %s\n", FileName);
		  return(NULL);
	  }

	  /* Get the size of the file. */
	  if (fstat(fileno(Fin), &statbuf) != 0) {
		  fprintf(stdout, "Could not stat() the input file: %s\n", FileName);
		  fclose(Fin);
		  return(NULL);
	  }

	  /* Allocate memory for the input. */
	  Buf1 = (char *)dmt_malloc(statbuf.st_size + 1);
	  Buf2 = (wchar_t *)dmt_malloc(sizeof(wchar_t) * (statbuf.st_size + 1));
	  if ((Buf1 == NULL) || (Buf2 == NULL)) {
		  fprintf(stdout, "Not enough memory to load the file: %s\n", FileName);
		  fclose(Fin);
		  if (Buf1 != NULL) dmt_free(Buf1);
		  if (Buf2 != NULL) dmt_free(Buf2);
		  return(NULL);
	  }

	  /* Load the file into memory. */
	  BytesRead = fread(Buf1, 1, statbuf.st_size, Fin);
	  Buf1[BytesRead] = '\0';

	  /* Close the file. */
	  fclose(Fin);

	  /* Exit if there was an error while reading the file. */
	  if (BytesRead != statbuf.st_size) {
		  fprintf(stdout, "Error while reading input file: %s\n", FileName);
		  dmt_free(Buf1);
		  dmt_free(Buf2);
		  return(NULL);
	  }

	  /* Convert from ASCII to Unicode. */
	  for (i = 0; i <= BytesRead; i++) Buf2[i] = Buf1[i];
	  dmt_free(Buf1);

	  return(Buf2);
  }




  void ShowErrorMessage(struct TokenStruct *Token, int Result) {
	  int Symbol;
	  int i;
	  wchar_t s1[BUFSIZ];

	  switch (Result) {
	  case PARSELEXICALERROR:
		  fprintf(stdout, "Lexical error");
		  break;
	  case PARSECOMMENTERROR:
		  fprintf(stdout, "Comment error");
		  break;
	  case PARSETOKENERROR:
		  fprintf(stdout, "Tokenizer error");
		  break;
	  case PARSESYNTAXERROR:
		  fprintf(stdout, "Syntax error");
		  break;
	  case PARSEMEMORYERROR:
		  fprintf(stdout, "Out of memory");
		  break;
	  }
	  if (Token != NULL) fprintf(stdout, " at line %ld column %ld", Token->Line, Token->Column);
	  fprintf(stdout, ".\n");

	  if (Result == PARSELEXICALERROR) {
		  if (Token->Data != NULL) {
			  ReadableString(Token->Data, s1, BUFSIZ);
			  fprintf(stdout, "The grammar does not specify what to do with '%S'.\n", s1);
		  }
		  else {
			  fprintf(stdout, "The grammar does not specify what to do.\n");
		  }
	  }
	  if (Result == PARSETOKENERROR) {
		  fprintf(stdout, "The tokenizer returned a non-terminal.\n");
	  }
	  if (Result == PARSECOMMENTERROR) {
		  fprintf(stdout, "The comment has no end, it was started but not finished.\n");
	  }
	  if (Result == PARSESYNTAXERROR) {
		  if (Token->Data != NULL) {
			  ReadableString(Token->Data, s1, BUFSIZ);
			  fprintf(stdout, "Encountered '%S', but expected ", s1);
		  }
		  else {
			  fprintf(stdout, "Expected ");
		  }
		  for (i = 0; i < Grammar.LalrArray[Token->Symbol].ActionCount; i++) {
			  Symbol = Grammar.LalrArray[Token->Symbol].Actions[i].Entry;
			  if (Grammar.SymbolArray[Symbol].Kind == SYMBOLTERMINAL) {
				  if (i > 0) {
					  fprintf(stdout, ", ");
					  if (i >= Grammar.LalrArray[Token->Symbol].ActionCount - 2) fprintf(stdout, "or ");
				  }
				  fprintf(stdout, "'%S'", Grammar.SymbolArray[Symbol].Name);
			  }
		  }
		  fprintf(stdout, ".\n");
	  }
  }

  
int fileExists(char* name)
{
    FILE *file;
    if ((file = fopen(name, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}


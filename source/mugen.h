#ifndef MUGEN_H
#define MUGEN_H

#include <stdio.h>

/*
 * Version naming: X.Y.z
 * 
 * Where: X major version: new features
 *        Y minor version: bug fixes
 *        z release version: [a, b, s]
 *                a: alpha
 *                b: beta
 *                s: stable  
 * 
 */

#define MUGEN_VERSION "0.1.a"

#define MUGEN_HELP "\
   _   _   _   _   _  \n\
  / \\ / \\ / \\ / \\ / \\ \n\
 ( M | U | G | E | N ) v. %s\n\
  \\_/ \\_/ \\_/ \\_/ \\_/ \n\n\
Written by Soulaymen Chouri [doit@praisethemoon.org]\n\n\
> Usage: mugen -c input.mu (compiles an input source file)\n\n"


int compile(char *fname);
void displayHelp();
void parseCmdLine();

#endif

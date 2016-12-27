/* please */
#include "no_sillywarnings_please.h"

#include <stdlib.h>
#include "utf8.h"
#include "memory.h"
#include "mugen.h"

int main(int argc, char *argv[]) {
    if (argc < 2)
    {
        displayHelp();
    }
    else
    {
        parseCmdLine();
    }
    
    int err = compile("tests/sample01.mu");
    
    printf("\n[NOTICE] Ending with memory of [%zu]Bytes\n", dmt_usage());
    printf("\n[NOTICE] Memory DUMP:\n");
    dmt_dump(stdout);
    return err;
}

/**
 * Main file for the compiler.
 * Author: Oscar C. S.
 */

#include "error.h"
#include "parse.h"
#include "backend.h"

int main(void) {
    ast_node_t* icode;
    if (!parse_program(&icode))
        compiler_error("No top-level expression");
    
    process(icode);
    return 0;
}

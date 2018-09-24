/**
 * The compiler backend.
 * Author: Oscar C. S.
 */

#include <stdio.h>
#include "parse.h"
#include "backend.h"

static void code_gen_expression(expression_t* expr) {
    switch (expr->type) {
        case 'D':
            printf("PUSH %d\n", expr->value);
            break;
        case 'P':
            code_gen_expression(expr->left);
            code_gen_expression(expr->right);
            switch (expr->oper) {
                case '+': 
                    printf("ADD\n");
                    break;
                case '*':
                    printf("MUL\n");
                    break;
            }
            break;
    }
}

void process(ast_node_t* icode) {
    code_gen_expression(icode);
    printf("PRINT\n");
}
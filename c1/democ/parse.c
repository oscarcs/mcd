/**
 * Parser.
 * Author: Oscar C. S.
 */

#include <stdlib.h>
#include "lex.h"
#include "error.h"
#include "parse.h"

// Internal functions
static expression_t* new_expression();
static void free_expression(expression_t*);
static int parse_operator(operator_t*);
static int parse_expression(expression_t**);

static expression_t* new_expression() {
    return (expression_t*) malloc(sizeof(expression_t));
}

static void free_expression(expression_t* expr) {
    free((void*) expr);
}

static int parse_operator(operator_t* oper) {
    if (token.type == '+') {
        *oper = '+';
        get_next_token();
        return 1;
    }

    if (token.type == '*') {
        *oper = '*';
        get_next_token();
        return 1;
    }

    return 0;
}

static int parse_expression(expression_t** expr_p) {
    expression_t* expr = *expr_p = new_expression();

    // Try to parse a digit:
    if (token.type == TOKEN_DIGIT) {
        expr->type = 'D';
        expr->value = token.repr - '0';
        get_next_token();
        return 1;
    }

    // Try to parse a parenthesized expression:
    if (token.type == '(') {
        expr->type = 'P';
        get_next_token();
        
        if (!parse_expression(&expr->left)) {
            compiler_error("Missing left expression.");
        }
        if (!parse_operator(&expr->oper)) {
            compiler_error("Missing operator."); 
        }
        if (!parse_expression(&expr->right)) {
            compiler_error("Missing right expression.");
        }
        if (token.type != ')') {
            compiler_error("Missing ).");
        }
        get_next_token();
        return 1;
    }

    // We've failed, so free the memory for expr.
    free_expression(expr);
    return 0;
}

int parse_program(ast_node_t** icode_p) {
    expression_t *expr;

    // Start the lexer:
    get_next_token();

    if (parse_expression(&expr)) {
        if (token.type != TOKEN_EOF) {
            compiler_error("Garbage at the end of the program.");
        }
        *icode_p = expr;
        return 1;
    }
    return 0;
}
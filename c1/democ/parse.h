/**
 * Parser header file.
 * Author: Oscar C. S.
 */

#ifndef PARSE_H
#define PARSE_H

typedef int operator_t;
typedef struct expression {
    char type;
    int value;
    struct expression* left;
    struct expression* right;
    operator_t oper;
} expression_t;

typedef expression_t ast_node_t;

extern int parse_program(ast_node_t**);

#endif
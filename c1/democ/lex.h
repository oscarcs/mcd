/**
 * Header file for the lexer.
 * Author: Oscar C. S.
 */

#ifndef LEX_H
#define LEX_H

#define TOKEN_EOF 256
#define TOKEN_DIGIT 257

typedef struct {
    int type;
    char repr;
} token_type_t;

extern token_type_t token;
extern void get_next_token();

#endif
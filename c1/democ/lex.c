/**
 * Lexical analyzer for the compiler.
 * Author: Oscar C. S.
 */

#include <stdio.h>
#include "lex.h"

/**
 * Check whether a character is a 'layout character'.
 */
static int layout_char(int ch) {
    switch (ch) {
        case ' ':
        case '\t':
            return 1;
        default:
            return 0;
    }
}

token_type_t token;

/**
 * Get the next token.
 */
void get_next_token() {
    int ch;

    // Get the next valid non-whitespace character.
    do {
        ch = getchar();
        if (ch == '\n') {
            token.type = TOKEN_EOF;
            token.repr = '#';
            return;
        }
    } while (layout_char(ch));

    // Classify the token
    if ('0' <= ch && ch <= '9') {
        token.type = TOKEN_DIGIT;
    }
    else {
        token.type = ch;
    }
    token.repr = ch;
}
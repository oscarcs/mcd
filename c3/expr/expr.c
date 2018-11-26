////
// Demo of some expression parsing routines. 
////

#include <stdlib.h>
#include <stdio.h>

#define ERROR  -1
#define NUMBER  0
#define OPER    1
#define LPAREN  2
#define RPAREN  3

typedef struct {
    int type;
    char repr;
} token_t;

char* infix_to_reverse_polish(token_t*, int);
char* infix_to_polish(token_t*, int);

int main(void) {

    int n = 1024;
    char* expr = malloc(n);
    getline(&expr, &n, stdin);

    printf("Run which expression parser? Enter a selection:\n");
    printf("\t1 - infix to Polish\n");
    printf("\t2 - Polish to infix\n");
    printf("Run which expression parser?\n");

    char* result;

    ////
    // Infix:                   1 + 2 * 3
    // Polish (prefix):         + 1 * 2 3
    // Rev. Polish (postfix)    1 2 3 * +
    ////

    char option = getchar(); 
    switch (option) {
        case '1':
            result = infix_to_polish(expr, n);
            break;
        default:
            result = "Invalid option selected.";
    }

    printf("%s\n", result);
}

// Convert a list of 
token_t* tokenize(char* expr, int len) {
    
    int cur_type;
    char* cur_repr;

    for (int i = 0; i < len; i++) {
        char cur = expr[i];
        if (cur >= '0' && cur <= '9') {
            
            // If we're already tokenizing a number, append.
            if (cur_type == NUMBER) {

            }
            cur_type = NUMBER;
        }
        else if (cur == '+' || cur == '-' || cur == '/' || cur == '*') {

            if (cur_type == OPER) {
                // Two operators in sequence is an error.
                break;
            }

            cur_type = OPER;
        }
    }
}

// Use the shunting yard algorithm to convert infix to reverse polish.
char* infix_to_reverse_polish(token_t* expr, int len) {
    char* result = malloc(len);

    for (int i = 0; i < len; i++) {

    }
    
    return result;
}

// Use a reverse shunting yard algorithm to convert infix to polish.
char* infix_to_polish(token_t* expr, int len) {
    char* result = malloc(len);

    result = "lol";

    return result;
}
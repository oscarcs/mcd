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
#define ISNUMBER(x) (x >= '0' && x <= '9')
#define ISOPER(x) (x == '+' || x == '-' || x == '/' || x == '*')
#define ISLPAREN(x) (x == '(')
#define ISRPAREN(x) (x == ')')

typedef struct {
    int type;
    char* repr;
} token_t;

token_t* tokenize(char*, int);
char* infix_to_reverse_polish(token_t*, int);
char* infix_to_polish(token_t*, int);

int main(void) {

    size_t n = 1024;
    char* expr = malloc(n);
    int len = getline(&expr, &n, stdin);
    printf("%i\n", len);

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

    tokenize(expr, len);

    switch (option) {
        case '1':
            // result = infix_to_polish(expr, n);
            break;
        default:
            result = "Invalid option selected.";
    }

    printf("%s\n", expr);
}

// Convert a list of 
token_t* tokenize(char* expr, int len) {

    token_t* tokens = malloc(sizeof(token_t) * 1024); 
    int cur_token = 0;

    for (int i = 0; i < len; ) {
        printf("%i: i\n", i);
        if (expr[i] == ' ') {
            while (expr[i] == ' ') {
                i++;
            }
        }
        else if (ISNUMBER(expr[i])) {
            int start = i;
            while (ISNUMBER(expr[i])) {
                i++;
            }

            int len = i - start;
            char* repr = malloc((len + 1) * sizeof(char));
            sprintf(repr, "%.*s", len, expr + start);
            tokens[cur_token].repr = repr;
            tokens[cur_token].type = NUMBER;
            cur_token++;

            printf("Added number token.\n");
        }
        else if (expr[i] == '-' && ISNUMBER(expr[i + 1])) {
            int start = i;
            i++;
            while (ISNUMBER(expr[i])) {
                i++;
            }

            int len = i - start;
            char* repr = malloc((len + 1) * sizeof(char));
            sprintf(repr, "%.*s", len, expr + start);
            tokens[cur_token].repr = repr;
            tokens[cur_token].type = NUMBER;
            cur_token++;

            printf("Added number token.\n");
        }
        else if (ISOPER(expr[i])) {
            int loc = i;
            i++;

            char* repr = malloc(sizeof(char));
            sprintf(repr, "%.*s", 1, expr + loc);
            tokens[cur_token].repr = repr;
            tokens[cur_token].type = OPER;
            cur_token++;

            printf("Added operator token.\n");
        }
        else if (ISLPAREN(expr[i])) {
            int loc = i;
            i++;

            char* repr = malloc(sizeof(char));
            sprintf(repr, "%.*s", 1, expr + loc);
            tokens[cur_token].repr = repr;
            tokens[cur_token].type = LPAREN;
            cur_token++;

            printf("Added lparen token.\n");
        }
        else if (ISRPAREN(expr[i])) {
            int loc = i;
            i++;

            char* repr = malloc(sizeof(char));
            sprintf(repr, "%.*s", 1, expr + loc);
            tokens[cur_token].repr = repr;
            tokens[cur_token].type = RPAREN;
            cur_token++;

            printf("Added rparen token.\n");
        }
        else {
            // @@TODO: error.
            break;
        }
    }

    for (int j = 0; j < cur_token; j++) {
        printf("|%s|\n", tokens[j].repr);
    }

    return tokens;
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
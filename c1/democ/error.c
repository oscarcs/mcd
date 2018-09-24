
#include <stdio.h>
#include <stdlib.h>

void compiler_error(char* msg) {
    printf("Error: %s\n", msg);
    exit(1);
}
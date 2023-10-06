#include <stdlib.h>
#include <stdio.h>

typedef struct inner_string {
    int pointeur;
    char content;
} inner_string;

inner_string convert(char* var);

int inner_len(inner_string base);


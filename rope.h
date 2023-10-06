#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inner_string.h"

typedef struct Rope{
    inner_string content;
    struct Rope* left;
    struct Rope* right;
    int size;
    unsigned pointer;
    } Rope;

size_t rope_len(Rope* rope);

void rope_insert_at();

char* substring(int pos, int len, int c, char* base);

char research(Rope* rope, long int i);

void recursive(char* base, Rope* rope);

Rope* rope_new(char* base);

void rope_delete(Rope* rope);
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inner_string.h"

typedef struct Rope{
    inner_string* node_content;
    struct Rope* left;
    struct Rope* right;
    int size;
    int weight;
    } Rope;

size_t rope_len(Rope* rope);

void rope_insert_at(Rope* rope, char *base, size_t pos);

char* substring(int pos, int len, int c, char* base);

Rope* research(Rope* rope, long int i);

void recursive(char* base, Rope* rope);

Rope* rope_new(char* base);

void rope_delete(Rope* rope);
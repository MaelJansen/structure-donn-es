#include <stdlib.h>
#include <stdio.h>
#include "inner_string.h"

inner_string* convert(char* var, int pointeur){
    inner_string* res = malloc(sizeof(inner_string));
    res->content = *var;
    res->pointeur = pointeur;
    return res;
}
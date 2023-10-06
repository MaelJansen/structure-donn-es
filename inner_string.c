#include <stdlib.h>
#include <stdio.h>
#include "inner_string.h"

inner_string convert(char* var){
    inner_string* res = malloc(sizeof(inner_string));
    res->content = "Test";
    return res;
}

int inner_len(inner_string base){
    return 0;
}
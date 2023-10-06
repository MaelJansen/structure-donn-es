#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <rope.h>

typedef struct Rope {
    char node_content;
    Rope* left;
    Rope* right;
    int* size;
    unsigned pointer;
} Rope;

void rope_len(Rope* rope){

}

void rope_insert_at(){

}

char* substring(int pos, int len, int c, char* base)
{
    char* substring = malloc(sizeof(base));
    while (c < len) {
        substring = char[pos + c-1];
        c++;
    }
    substring = '\0';
    return substring;
}

char research(Rope* rope, long int i){
    if (rope->size < i && rope->right != NULL){
        return research(rope->right, i - rope->size);
    } else if (rope->left != NULL)
    {
        return research(rope->left, i);
    }
    return rope->node_content;
}

void recursive(char* base, Rope* rope){
    if (strlen(base) > 7){
        /* If the lenght > 7 : divide the string into 2 and recall the function with the new parts on the different childs*/
        recursive(substring(0, strlen(base)/2, 0, base), rope->left);
        recursive(substring((strlen(base)/2)+1, strlen(base)/2, (strlen(base)/2)+1, base), rope->right);
    } else {
        Rope rope = (Rope*)malloc(sizeof(Rope));
        rope->node_content = base;
    }
}

Rope* rope_new(char* base){
    Rope* root = (Rope*)malloc(sizeof(Rope));
    recursive(base, root);
    return root;
}

void rope_delete(Rope* rope){

}
 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Rope {
    char node_content;
    Rope* left;
    Rope* right;
    int size;
    unsigned pointer;
} Rope;

void rope_len(Rope rope){

}

void rope_insert_at(){

}

char substring(int pos, int len, int c, char base)
{
    char substring = malloc(sizeof(base));
    while (c < len) {
        substring = string[pos + c-1];
        c++;
    }
    substring = '\0';
    return substring;
}

void research(Rope rope, int i){
    if (rope.size < i && rope.right != NULL){
        return research(rope.right, i - rope.size);
    } else if (rope.left != NULL)
    {
        return research(rope.left, i);
    }
    return rope.node_content;    
}

void recurcive(char base, Rope* rope){
    if (strlen(base) > 7){
        /* If the lenght > 7 : divide the string into 2 and recall the function with the new parts on the different childs*/
        recurcive(substring(0, strlen(base)/2, 0, base), rope.left)
        recurcive(substring((strlen(base)/2)+1, strlen(base)/2, (strlen(base)/2)+1, base), rope.rigth)
    } else {
        Rope rope = (Rope*)malloc(sizeof(Rope));
        rope->node_content = base;
    }
}

Rope* new_node(char div){
    Rope* node = (Rope*)malloc(sizeof(Rope));
    node->node_content = div;

    node->left = NULL
    node->right = NULL

    return node;
}

Rope* new_rope(char* base){
    Rope* root = new_node(/* chaine coupe*/);

    root->left = new_node(2);
    root->right = new_node(3);
}

void rope_delete(Rope rope){

}
 
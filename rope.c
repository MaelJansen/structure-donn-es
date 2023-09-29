#include <stdlib.h>
#include <stdio.h>

struct Rope {
    char node_content;
    struct rope* left;
    struct rope* right;
    int size;
}

void rope_len(Rope rope){

}

void rope_insert_at(){

}

struct Rope* new_node(char div){
    struct rope* node = (struct rope*)malloc(sizeof(struct rope));
    node->node_content = div;

    node->left = NULL
    node->right = NULL

    return (node);
}

struct Rope* new_rope(char base){
    int max_char = 5;
    struct node* root = new_node(/* chaine coupe*/);

    root->left = new_node(2);
    root->right = new_node(3);
}

void rope_delete(Rope rope){

}
 
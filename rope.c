#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rope.h"

char* substring(int pos, int len, int c, char* base){
    /* Renvoie un partie du string*/
    char* substring = malloc(sizeof(len +1));
    for (int i = 0; i < len; i++){
        substring[i] = base[pos + i];
    }
    substring[len] = '\0';
    return substring;
}

void insert_new_string(Rope* rope, char *base, int pos){
        int insert = pos - rope->node_content->pointeur;
        char* partOne = substring(0, insert, 0, rope->node_content->content);
        char* partTwo = substring(insert +1, strlen(rope->node_content->content) - insert, insert +1, rope->node_content->content);
        char* final = malloc(strlen(partOne) + strlen(base) + strlen(partTwo) + 1);
        strcpy(final, partOne);
        strcat(final, base);
        strcat(final, partTwo);
        rope->node_content->content = final;
}

Rope* recursive(char* base){
    /* Permet de créer tout les fils d'une rope */
    Rope* rope = malloc(sizeof(Rope));
    rope = &(Rope) {
        .left = NULL,
        .right = NULL,
        .node_content = NULL,
        .weight = 0,
        .size = 0
        };
    if (strlen(base) > 7){
        rope->left = recursive(substring(0, strlen(base)/2, 0, base));
        rope->right = recursive(substring((strlen(base)/2)+1, strlen(base)/2, (strlen(base)/2)+1, base));
    } 
    printf("*%s\n", base);
    //a voir si il faut laisser rope_new ou utilisé rope
    rope->node_content = convert(base, 1);
    rope->weight = 0;
    return rope;
}

int check_left(Rope* rope){
    if (rope->left != NULL){
        return rope->left->weight;
    }
    return rope->weight;
}

int check_right(Rope* rope){
    int res = 0;
    if (rope->right != NULL){
        res += check_right(rope->right);
    }
    if (res != 0){
        return res;
    }
    return rope->weight;
}

size_t rope_len(Rope* rope){
    /* Renvoie la taille de la chaine de caractère stockée*/
    return (size_t)(check_left(rope) + check_right(rope));
}

void assign_weight(Rope* rope){
    int weight = 0;
    if(rope->left == NULL){
        rope->weight = strlen(rope->node_content->content);
    } else {
        if (rope->left != NULL && rope->left->weight != 0){
            assign_weight(rope->left);
        } else if (rope->right != NULL && rope->right->weight != 0){
            assign_weight(rope->right);
        }
        weight += check_left(rope);
        weight += check_right(rope);
        rope->weight = weight;
    }
}

Rope* rope_new(char* base){
    /* Permet de créer une rope à partir d'une chaine de caractères */
    Rope* root = malloc(sizeof(Rope));
    root = &(Rope) {
        .left = NULL,
        .right = NULL,
        .node_content = NULL,
        .weight = 0,
        .size = 0
    };
    if(strlen(base) >= 1){
        if (root != NULL && strlen(base) > 7){
            root->left = recursive(substring(0, strlen(base)/2, 0, base));
            root->right = recursive(substring((strlen(base)/2)+1, strlen(base)/2, (strlen(base)/2)+1, base));
            assign_weight(root);
            return root;
        } else if (root != NULL){
            root->left = recursive(base);
            assign_weight(root);
            return root;
        }
    }
    return NULL;
}

void rope_delete(Rope* rope){
    /* Permet de supprimer une rope en supprimer tout ces fils */
    if (rope->left != NULL){
        rope_delete(rope->left);
    } else if (rope->right != NULL){
        rope_delete(rope->right);
    }
    free(rope);
}

void rope_insert_at(Rope* rope, char *base, size_t pos){
    /* Permet d'insérer un élément dans la rope a une position donner (dans la chaine de caractères)*/
    int posInt = (int)pos;
    if (rope->left == NULL) {
        insert_new_string(rope, base, posInt);
    } else {
        if (posInt < rope->weight && rope->left != NULL){
            rope_insert_at(rope->left, base, posInt);
        } else if (rope->right != NULL){
            rope_insert_at(rope->right, base, posInt);
        } else {
            insert_new_string(rope, base, posInt);
        }
    }
    assign_weight(rope);
}
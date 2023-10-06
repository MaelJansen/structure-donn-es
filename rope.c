#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rope.h"
#include "inner_string.h"

size_t rope_len(Rope* rope){
    /* Renvoie la taille  de la chaine de caractère stockée dans la rope*/
    return 100;
}

void rope_insert_at(){
    /* Permet d'insérer un élément dans la rope a une position donner (dans la chaine de caractères)*/
}

char* substring(int pos, int len, int c, char* base){
    /* Renvoie un partie du string*/
    char* substring = malloc(sizeof(base));
    while (c < len) {
        substring += base[pos + c-1];
        c++;
    }
    substring += '\0';
    return substring;
}

inner_string research(Rope* rope, long int i){
    /* Renvoie un rope donner*/
    if (rope->size < i && rope->right != NULL){
        return research(rope->right, i - rope->size);
    } else if (rope->left != NULL)
    {
        return research(rope->left, i);
    }
    return rope->node_content;
}

void recursive(char* base, Rope* rope){
    /* Permet de créer tout les fils d'une rope */
    if (strlen(base) > 7){
        /* If the lenght > 7 : divide the string into 2 and recall the function with the new parts on the different childs*/
        recursive(substring(0, strlen(base)/2, 0, base), rope->left);
        recursive(substring((strlen(base)/2)+1, strlen(base)/2, (strlen(base)/2)+1, base), rope->right);
    } else {
        Rope* rope = malloc(sizeof(Rope));
        rope->node_content = convert(base);
    }
}

Rope* rope_new(char* base){
    /* Permet de créer une rope à partir d'une chaine de caractères */
    Rope* root = malloc(sizeof(Rope));
    recursive(base, root);
    return root;
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

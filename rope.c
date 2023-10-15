#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "rope.h"

char* substring(int pos, int len, int c, char* base){
    /* Renvoie un partie du string*/
    if (strlen(base)>len){
    	char* substring = (char *)malloc((len +1) * sizeof(char));
        /*char* added = malloc(sizeof(char));
    	if (substring != NULL) {
    		for (int i = 0; i <= len; i++){
                *added = base[pos + i];
        		strcat(substring, added);
    		}
    		substring[len] = '\0';
            free(added);
    		return substring;
   	    }*/
        strncpy(substring, base+(pos-1), len);
        strcat(substring, "\0");
        return substring;
   }
   return base;
}

void insert_new_string(Rope* rope, char *base, int pos){
        int insert = pos - rope->node_content->pointeur;
        char* partOne = substring(0, insert, 0, rope->node_content->content);
        char* partTwo = substring(insert +1, strlen(rope->node_content->content) - insert, insert +1, rope->node_content->content);
        char* final = (char *)malloc(strlen(partOne) + strlen(base) + strlen(partTwo) + 1);
        strcpy(final, partOne);
        strcat(final, base);
        strcat(final, partTwo);
        rope->node_content->content = final;
        free(final);
}

Rope* recursive(char* base, int pos){
    /* Permet de créer tout les fils d'une rope */
    Rope* rope = (Rope *) malloc(sizeof(Rope));
    rope = &(Rope) {
        .left = NULL,
        .right = NULL,
        .node_content = NULL,
        .weight = 0,
        .size = 0,
        .last = true
        };
    if (strlen(base) > 7){
        rope->last = false;
        rope->left = recursive(substring(0, strlen(base)/2, 0, base), 0 + pos);
        rope->right = recursive(substring((strlen(base)/2)+1, strlen(base)/2, (strlen(base)/2)+1, base), strlen(base)/2+1);
    }
    rope->node_content = convert(base, pos);
    printf("*%s\r", rope.node_content->content);
    rope->weight = 0;
    return rope;
}

int check_left(Rope* rope){
    if (rope->last != true){
        return strlen(rope->left.node_content->content);
    }
    return strlen(rope->node_content.content);
}

int check_right(Rope* rope){
    int res = 0;
    if (rope->right != NULL){
        res += check_right(rope->right);
        return res;
    }
    return strlen(rope->node_content->content);
}

size_t rope_len(Rope* rope){
    /* Renvoie la taille de la chaine de caractère stockée*/
    return (size_t)(check_left(rope) + check_right(rope));
}

void assign_weight(Rope* rope){
    int weight = 0;
    if (rope->last != true) {
        assign_weight(rope->left);
        if (rope->right != NULL){
            assign_weight(rope->right);
        }
        weight += check_left(rope);
        weight += check_right(rope);
        rope->weight = weight;
    }
    if( rope->node_content != NULL){
        rope->weight = strlen(rope->node_content->content);
    } else {
        rope->weight = 0;
    }
}

Rope* rope_new(char* base){
    /* Permet de créer une rope à partir d'une chaine de caractères */
    Rope* root = (Rope *)malloc(sizeof(Rope));
    root = &(Rope) {
        .left = NULL,
        .right = NULL,
        .node_content = NULL,
        .weight = 0,
        .size = 0,
        .last = true
    };
    if(strlen(base) >= 1){
        if (root != NULL && strlen(base) > 7){
            root->left = recursive(substring(0, strlen(base)/2, 0, base), 0);
            root->right = recursive(substring((strlen(base)/2)+1, strlen(base)/2, (strlen(base)/2)+1, base), strlen(base)/2+1);
            
        } else if (root != NULL){
            root->left = recursive(base, 0);
        }
    }
    assign_weight(root);
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "rope.h"

/**
 * La fonction substring qui permet de récupérer un segment de la chaine de caractères passée en paramètres
 * 
 * pos : la position a partir de laquell on veut copier la chaine
 * len : le nombre de caracère que l'on veut copier
 * base : la chaine de caractère qui dont on veut extraire une partie
**/
char* substring(int pos, int len, char* base){
    if (strlen(base)>len){
    	char* substring = (char *)malloc((len +1) * sizeof(char));
        if (substring != NULL){
            strncpy(substring, base+(pos-1), len);
            return substring;
        } else {
            perror("Memory error on substring");
            exit(EXIT_FAILURE);
        }
   }
   return base;
}

/**
 * La fonction insert_new_string qui permet d'insérer une chaine de carctère dans une rope a une position donnée
 * 
 * rope : la rope dans laquelle on veut insérer la chaine de caractères
 * base : la chaine de caractères que l'on veut insérer dans la rope
 * pos : la position à laquelle on veut insérer la chaine de caractères dans la rope
**/
void insert_new_string(Rope* rope, char *base, int pos){
    int insert = pos - rope->node_content->pointeur;
    char* partOne = substring(1, insert, rope->node_content->content);
    char* partTwo = substring(insert, strlen(rope->node_content->content) - insert, rope->node_content->content);
    char* final = (char *)malloc(strlen(partOne) + strlen(base) + strlen(partTwo) + 1);
    if (final != NULL){
        strcpy(final, partOne);
        strcat(final, base);
        strcat(final, partTwo);
        rope->node_content->content = final;
        free(final);
    } else {
        perror("Memory error on insert_new_string"); 
        exit(EXIT_FAILURE); 
    }
}

/**
 * La fonction recursive qui permet de créer des ropes de manière récurcive
 * en créeant des fils de manière à avoir des chaines des caractère d'une certaine longueur dans les feuilles des ropes 
 * 
 * base : la chaine de caractère à mettre dans la rope
 * pos : la position du premier caractère dans la rope par rapport à la chaine de caractères
**/
Rope* recursive(char* base, int pos){
    Rope* rope = (Rope *) malloc(sizeof(Rope));
    if (rope != NULL){
        rope->left = NULL;
        rope->right = NULL;
        rope->node_content = NULL;
        rope->weight = 0;
        rope->last = true;
        if (strlen(base) > 7){
            rope->last = false;
            rope->left = recursive(substring(1, strlen(base)/2, base), pos);
            rope->right = recursive(substring((strlen(base)/2)+1, strlen(base)/2, base), strlen(base)/2+1);
        } else {
            rope->node_content = convert(base, pos);
        }
        rope->weight = 0;
        return rope;
    } else {
        perror("Memory error on recursive");
        exit(EXIT_FAILURE);
    }
}

/**
 * La fonction check_left qui permet d'avoir le poids du noeuds de gauche
 * (égale a la taille de ça chaine de caractères si il est le dernier sur la gauche)
 * 
 * rope : la rope dont on veut la valeur du fils gauche
**/
int check_left(Rope* rope){
    if (rope->last != true){
        return rope->left->weight;
    }
    return strlen(rope->node_content->content);
}

/**
 * La fonction check_right qui permet d'avoir les poids des noeuds des fils de droite
 * (égale à la somme des poids des fils de droite) 
 * 
 * rope : la rope dont on veut la valeur du fils droit
**/
int check_right(Rope* rope){
    int res = 0;
    if (rope->right != NULL){
        res += check_right(rope->right);
        if (rope->right->left != NULL){
           res += check_left(rope->right);
        }
    } else{
        res = strlen(rope->node_content->content);
    }
    return res;
}

/**
 * La fonction rope_len qui permet d'avoir la taille de toute la rope
 * (de la chaine de caractères qui est dedans)
 * 
 * rope : la rope dont on veut savoir la taille
**/
size_t rope_len(Rope* rope){
    if (rope->left->last != true){
        return (size_t)(check_left(rope) + check_right(rope));
    } else {
        return (size_t)check_left(rope);
    }
}

/**
 * La fonction assign_weight qui permet d'assigner les poids de la rope
 * 
 * rope : la rope dont pour laquelle on veut assigner les poids 
**/
void assign_weight(Rope* rope){
    int weight = 0;
    if (rope->last != true) {
        if (rope->left != NULL){
            assign_weight(rope->left);
        }
        if (rope->right != NULL){
            assign_weight(rope->right);
        }
        weight += check_left(rope);
        if (rope->left != NULL){
            weight += check_right(rope->left);
        }
        rope->weight = weight;
    }
    if( rope->node_content != NULL){
        rope->weight = strlen(rope->node_content->content);
    } else {
        rope->weight = 0;
    }
}

/**
 * La fonction rope_new qui permet de créer une nouvelle rope depuis une chaines de caractères
 * 
 * base : la chaine de caractères que l'on veut mettre dans la rope 
**/
Rope* rope_new(char* base){
    Rope* root = (Rope *)malloc(sizeof(Rope));
    if (root != NULL){
        root->left = NULL;
        root->right = NULL;
        root->node_content = NULL;
        root->weight = 0;
        root->last = true;
        if(strlen(base) >= 1){
            root->last = false;
            if (strlen(base) > 7){
                root->left = recursive(substring(1, strlen(base)/2, base), 0);
                root->right = recursive(substring((strlen(base)/2)+1, strlen(base)/2, base), strlen(base)/2+1);
                
            } else if (root != NULL){
                root->left = recursive(base, 0);
            }
        }
        assign_weight(root);
        return root;
    } else {
        perror("Memory error on rope_new"); 
        exit(EXIT_FAILURE); 
    }
}

/**
 * La fonction rope_delete qui permet de supprimer tout une rope
 * (en supprimant ces fils un à un)
 * 
 * rope : la rope à supprimer 
**/
void rope_delete(Rope* rope){
    if (rope->left != NULL){
        rope_delete(rope->left);
    } else if (rope->right != NULL){
        rope_delete(rope->right);
    }
    free(rope);
}

/**
 * La fonction rope_insert_at qui permet d'insérer une chaine de caractère dans la rope en donnant ça position
 * 
 * rope : la rope dans laquelle on veut insérer la chaine de caractères
 * base : la chaine de caractères à insérer
 * pos : la postion a laquelle on veut l'insérer 
**/
void rope_insert_at(Rope* rope, char *base, size_t pos){
    int posInt = (int)pos;
    if (rope->left == NULL) {
        insert_new_string(rope, base, posInt);
    } else {
        if (posInt < rope->weight && rope->left != NULL){
            rope_insert_at(rope->left, base, pos);
        } else if (rope->right != NULL){
            rope_insert_at(rope->right, base, pos);
        }
    }
    assign_weight(rope);
}

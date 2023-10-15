#include <stdlib.h>
#include <stdio.h>
#include "inner_string.h"

/**
 * La fonction convert qui permet de convertir une chaine de caractères en inner_string
 * (une structure qui prend un chaine de caractères et un "pointeur": la position de son premier élément)
 * 
 * var : la chaine de caractère
 * pos : la position du premier élément de la chaine de caractères 
**/
inner_string* convert(char* var, int pointeur){
    inner_string* res = (inner_string *)malloc(sizeof(inner_string));
    if (res != NULL){
        res->content = var;
        res->pointeur = pointeur;
        return res;
    } else {
        perror("Memory error on convert"); 
        exit(EXIT_FAILURE); 
    }
}
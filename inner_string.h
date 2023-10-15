#include <stdlib.h>
#include <stdio.h>

/**
 * La structure inner_string qui va remplacer les chaine de caractère habituelles dans les rope
 * (permet de stocker la chaine de caractère et la position de son premier élément)
 * 
 * pointeur : la position de son premier élément
 * content : la chaine de caractères stockée dans l'inner_string 
**/
typedef struct inner_string {
    int pointeur;
    char* content;
} inner_string;

/**
 * La fonction convert qui permet de convertir une chaine de caractères en inner_string
 * (une structure qui prend un chaine de caractères et un "pointeur": la position de son premier élément)
 * 
 * var : la chaine de caractère
 * pos : la position du premier élément de la chaine de caractères 
**/
inner_string* convert(char* var, int pointeur);


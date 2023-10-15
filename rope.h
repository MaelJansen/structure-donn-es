#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "inner_string.h"

/**
 * La structure de rope qui permet de stocker différement des chaines de caractères
 * 
 * node_content : la chaine de caractère sous la forme : char* contenu et int position du premier caractère
 * left : le fils gauche de la rope
 * right : le fils droit de la rope
 * weight : le poids de la rope
 * last : un booleen qui permet de savoir si la rope est une feuille
**/
typedef struct Rope{
    inner_string* node_content;
    struct Rope* left;
    struct Rope* right;
    int weight;
    bool last;
    } Rope;

/**
 * La fonction rope_len qui permet d'avoir la taille de toute la rope
 * (de la chaine de caractères qui est dedans)
 * 
 * rope : la rope dont on veut savoir la taille
**/
size_t rope_len(Rope* rope);

/**
 * La fonction insert_new_string qui permet d'insérer une chaine de carctère dans une rope a une position donnée
 * 
 * rope : la rope dans laquelle on veut insérer la chaine de caractères
 * base : la chaine de caractères que l'on veut insérer dans la rope
 * pos : la position à laquelle on veut insérer la chaine de caractères dans la rope
**/
void insert_new_string(Rope* rope, char *base, int pos);

/**
 * La fonction rope_insert_at qui permet d'insérer une chaine de caractère dans la rope en donnant ça position
 * 
 * rope : la rope dans laquelle on veut insérer la chaine de caractères
 * base : la chaine de caractères à insérer
 * pos : la postion a laquelle on veut l'insérer 
**/
void rope_insert_at(Rope* rope, char *base, size_t pos);

/**
 * La fonction substring qui permet de récupérer un segment de la chaine de caractères passée en paramètres
 * 
 * pos : la position a partir de laquell on veut copier la chaine
 * len : le nombre de caracère que l'on veut copier
 * base : la chaine de caractère qui dont on veut extraire une partie
**/
char* substring(int pos, int len, char* base);

/**
 * La fonction recursive qui permet de créer des ropes de manière récurcive
 * en créeant des fils de manière à avoir des chaines des caractère d'une certaine longueur dans les feuilles des ropes 
 * 
 * base : la chaine de caractère à mettre dans la rope
 * pos : la position du premier caractère dans la rope par rapport à la chaine de caractères
**/
Rope* recursive(char* base, int pos);

/**
 * La fonction check_left qui permet d'avoir le poids du noeuds de gauche
 * (égale a la taille de ça chaine de caractères si il est le dernier sur la gauche)
 * 
 * rope : la rope dont on veut la valeur du fils gauche
**/
int check_left(Rope* rope);

/**
 * La fonction check_right qui permet d'avoir les poids des noeuds des fils de droite
 * (égale à la somme des poids des fils de droite) 
 * 
 * rope : la rope dont on veut la valeur du fils droit
**/
int check_right(Rope* rope);

/**
 * La fonction assign_weight qui permet d'assigner les poids de la rope
 * 
 * rope : la rope dont pour laquelle on veut assigner les poids 
**/
void assign_weight(Rope rope);

/**
 * La fonction rope_new qui permet de créer une nouvelle rope depuis une chaines de caractères
 * 
 * base : la chaine de caractères que l'on veut mettre dans la rope 
**/
Rope* rope_new(char* base);

/**
 * La fonction rope_delete qui permet de supprimer tout une rope
 * (en supprimant ces fils un à un)
 * 
 * rope : la rope à supprimer 
**/
void rope_delete(Rope* rope);
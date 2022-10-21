#ifndef BIBLIOH_H
#define BIBLIOH_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>


typedef struct livreh {
	int clef ;
	int num;
	char* titre;
	char* auteur;
	struct livreh* suivant;
} LivreH ;

typedef struct table{
	int nE ; /*nombre d’elements contenus dans la table de hachage */
	int m ; /*taille de la table de hachage */
	LivreH ** T ; /*table de hachage avec resolution des collisions par chainage */
} BiblioH ;


LivreH* creerlivre(int num,char* titre,char* auteur);
void libererlivre(LivreH* l);
BiblioH* creerbiblio(int m);
void libererbiblio(BiblioH* b);
int fonctionHachage(int cle, int m);
void inserer(BiblioH* b,int num,char* titre,char* auteur);

//QUESTION 2.6
void afficher_livre2(LivreH* l);
void afficher_biblio2(BiblioH* b);
LivreH* recherche_num2(int n, BiblioH* b);
LivreH* recherche_titre2(char * t, BiblioH* b);
BiblioH* recherche_auteur2(char *a, BiblioH* b);
void suppression2(BiblioH * b, int n, char * t, char * a);
void fusion2(BiblioH * b1, BiblioH * b2);
BiblioH* plusieursEx2(BiblioH * b);


#endif

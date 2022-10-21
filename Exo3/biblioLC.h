#ifndef BIBLIOLC_H
#define BIBLIOLC_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>


//Exercice1

//Q1.1
typedef struct livre {
	int num ;
	char * titre ;
	char * auteur ;
	struct livre * suiv ;
} Livre ;


typedef struct biblio{ /* Tete fictive */
	Livre * L ; /* Premier element */
} Biblio ;


Livre* creer_livre(int num,char* titre,char* auteur);
void liberer_livre(Livre* l);
Biblio* creer_biblio();
void liberer_biblio(Biblio* b);
void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);

//Q1.6
void afficher_livre(Livre* l);
void afficher_biblio(Biblio* b);
Livre* recherche_num1(int n, Biblio* b);
Livre* recherche_titre1(char * t, Biblio* b);
Biblio* recherche_auteur1(char *a, Biblio* b);
Biblio* suppression1(Biblio * b, int n, char * t, char * a);
Biblio* fusion1(Biblio * b1, Biblio * b2);
Biblio* plusieursEx1(Biblio * b);



#endif

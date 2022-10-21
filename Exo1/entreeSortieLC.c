#include "entreeSortieLC.h"

//EXERCICE 1

//QUESTION 1.3

Biblio* charger_n_entrees(char* nomfic, int n){
	FILE* ficher= fopen(nomfic,"r");
	if(ficher==NULL){
		printf("Erreur d'ouverture du ficher");
		return NULL;
	}
	char buffer[256];
	int num;
	char titre[256];
	char auteur[256];
	Biblio* b=creer_biblio();
	int i=0;
	while(i<n && fgets(buffer,256,ficher)){
		sscanf(buffer,"%d %s %s",&num,titre,auteur);
		inserer_en_tete(b,num,titre,auteur);
		i++;
	}
	fclose(ficher);
	return b;
}

void enregistrer_biblio(Biblio *b, char* nomfic){
	FILE* ficher= fopen(nomfic,"w");
	if(ficher==NULL){
		printf("Erreur d'ouverture du ficher");
		return;
	}
	Livre* temp=b->L;
	while(temp){
		fprintf(ficher,"%d %s %s\n",temp->num,temp->titre,temp->auteur);
		temp=temp->suiv;
	}
	fclose(ficher);
}

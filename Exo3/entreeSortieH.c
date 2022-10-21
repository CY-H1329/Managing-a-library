#include "entreeSortieH.h"

//Exercice1

//Q1.3

BiblioH* charger_n_entreesH(char* nomfic, int n){
	FILE* ficher= fopen(nomfic,"r");
	if(ficher==NULL){
		printf("Erreur d'ouverture du ficher");
		return NULL;
	}
	char buffer[256];
	int num;
	char titre[256];
	char auteur[256];	
	BiblioH* b=creerbiblio(n);
	int i=0;
	while(i<n && fgets(buffer,256,ficher)){	
		sscanf(buffer,"%d %s %s",&num,titre,auteur);
		inserer(b,num,titre,auteur);
		i++;
	}
	fclose(ficher);
	return b;
}

void enregistrer_biblioH(BiblioH *b, char* nomfic){
	FILE* ficher= fopen(nomfic,"w");
	if(ficher==NULL){
		printf("Erreur d'ouverture du ficher");
		return;
	}
	LivreH** temp=b->T;
	for(int i=0; i<b->m;i++){
		while(temp[i]){
			fprintf(ficher,"%d %d %s %s\n",temp[i]->clef,temp[i]->num,temp[i]->titre,temp[i]->auteur);
			temp[i]=temp[i]->suivant;
		}
	}
	fclose(ficher);
}


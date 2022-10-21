#include "biblioLC.h"


//PARTIE 1 - Exercice 1

//QUESTION 1.2
//Création d'un livre Q1.2
Livre* creer_livre(int num,char* titre,char* auteur){
	Livre* newLivre=(Livre*)(malloc(sizeof(Livre)));
	if(newLivre==NULL){
		printf("Livre non alloue\n");
		return NULL;
	}
	newLivre->num=num;
	newLivre->titre=strdup(titre);
	newLivre->auteur=strdup(auteur);
	newLivre->suiv=NULL;
	return newLivre;
}

//Libération d'un livre Q1.2
void liberer_livre(Livre* l){
	if(l==NULL){
		return;
	}
	free(l->titre);
	free(l->auteur);
	free(l);
}

//Création d'une bibliothèque vide Q1.2
Biblio* creer_biblio(){
	Biblio* b=(Biblio*)(malloc(sizeof(Biblio)));
	if(b==NULL){
		printf("Bibliotheque non alloue\n");
		return NULL;
	}
	b->L=NULL;
	return b;
}

//Libère la mémoire occupée par une bibliothèque Q1.2
void liberer_biblio(Biblio* b){
	if(b==NULL){
		printf("Bibliotheque deja liberee\n");
		return;
	}
	Livre* temp=b->L;
	while(temp){
		Livre* next =temp->suiv;
		liberer_livre(temp);
		temp=next;
	}
	liberer_livre(temp);
	free(b);
}

//Ajoute un nouveau livre à la bibliothèque Q1.2
void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){
	if(!b){
		printf("Biobliotheque vide");
		return;
	}
	Livre* new= creer_livre(num,titre,auteur);
	new->suiv=b->L;
	b->L=new;
}


//QUESTION 1.6
//Affichage d'un livre Q1.6
void afficher_livre(Livre* l){
	printf("%d %s %s\n",l->num, l->titre, l->auteur);
}

//Affichage d'une bibliothèque Q1.6
void afficher_biblio(Biblio* b){
	if(!b || !(b->L)){
		printf("Bibliotheque vide");
		return;
	}
	Livre* temp=b->L;
	while(temp){
		afficher_livre(temp);
		temp=temp->suiv;
	}
}

//Recherche d'un ouvrage par son numéro Q1.6
Livre* recherche_num1(int n, Biblio* b){
    if( b == NULL || n<0) return NULL;
    Livre *l = b->L;
    while(l){
      if(l->num == n) return l;
      l=l->suiv;
    }
    printf("Livre de numero %d non trouve.\n",n);
    return NULL;
}

//Recherche d'un ouvrage par son titre Q1.6
Livre *recherche_titre1(char *t, Biblio *b){
    if( b == NULL || t == NULL ){
			printf("Bibliotheque vide");
			return NULL;
		}
    Livre *l = b->L;
    while(l){
      if(strcmp(l->titre,t) == 0 ) return l;
      l=l->suiv;
    }
    printf("Livre de titre '%s' non trouve. \n",t);
    return NULL;
}

//Recherche de tous les livres d'un même auteur
Biblio* recherche_auteur1(char *a, Biblio *b){
    if( b == NULL || a == NULL ){
			printf("Bibliotheque vide");
			return NULL;
		}
    Biblio *bres = creer_biblio();
    Livre *l = b->L;
    while(l){
        if(strcmp(l->auteur,a) == 0 ){
          inserer_en_tete(bres, l->num, l->titre, l->auteur);
    }
      l=l->suiv;
    }
    if( bres->L== NULL ){
      printf("Aucun ouvrage ayant pour auteur %s n'a ete trouve. \n",a);
    }
    return bres;
}

//Suppression d'un ouvrage à partir de son numéro, auteur et titre Q1.6
Biblio *suppression1(Biblio *b, int n, char *t, char *a){
    if(!b){
      printf("La bibliotheque est vide.\n");
      exit(1);
    }

    Biblio *bres=b;
    Livre *ltmp=bres->L;

    Biblio *btmp = recherche_auteur1(a,bres);
    Livre *ls = recherche_num1(n,btmp);
    	if(ls == NULL){
      	printf("Le livre '%s' numero : %d d'auteur : %s n'a pas ete trouve.\n",t,n,a);
      	return b;
    }

    if( strcmp(ltmp->titre,ls->titre) == 0 && strcmp(ltmp->auteur,ls->auteur) == 0 && ltmp->num == ls->num ){
      bres->L=ltmp->suiv;
      liberer_livre(ls);
      //printf("Suppression faite.\n");
      return bres;
    }
    while(ltmp->suiv){
      if( strcmp(ltmp->suiv->titre,ls->titre) == 0 && strcmp(ltmp->suiv->auteur,ls->auteur) == 0 && ltmp->suiv->num == ls->num  ){
        ltmp->suiv = ltmp->suiv->suiv;
        liberer_livre(ls);
        //printf("Suppression faite.\n");
        return bres;
      }
      ltmp=ltmp->suiv;
    }
    return b;
}

//Fusion de la deuxième bibliothèque à la première en supprimant la deuxième Q1.6
Biblio* fusion1(Biblio * b1, Biblio * b2){
	if(b1 == NULL || b1->L == NULL ){
        return b2;
    }
    if(b2 == NULL || b2->L == NULL ){
        return b1;
    }
	while(b1->L){
		b1->L=b1->L->suiv;
	}
	b1->L->suiv=b2->L;
	liberer_biblio(b2);
	return b1;
}

//Fonction de recherche de tous les ouvrages avec plusieurs exemplaires de complexité-temps pire cas O(n²) Q1.6
Biblio* plusieursEx1(Biblio* b){
    if(!b){
        printf("Bibliotheque vide");
        return NULL;
    }

    Biblio* res=creer_biblio();
    Livre* ltab=b->L;
    while(ltab){
        int cpt=0;
        int num=ltab->num;
        char *auteur=ltab->auteur;
        char *titre=ltab->titre;
        Livre *temp=b->L;
        while(temp){
            if(strcmp(titre, temp->titre)==0 && strcmp(auteur,temp->auteur)==0 && num!=temp->num){
                cpt++;
                break;
            }
            temp=temp->suiv;
        }
        if(cpt!=0)
            inserer_en_tete(res, num, titre, auteur);
        ltab=ltab->suiv;
    }
    return res;
}

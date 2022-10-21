#include "biblioH.h"

//PARTIE 2 EXERCICE 2

//QUESTION 2.2
int fonctionClef(char *nom){
	//Fonction qui associe chaque Livre à une clé
	int i=0;
	int res=0;
	while(nom[i]!='\0'){
		res+=(int)(nom[i]);
		i++;
	}
	return res;
}


//QUESTION 2.3
LivreH* creerlivre(int num,char* titre,char* auteur){
	//Fonction qui crée un Livre
	LivreH* l=(LivreH*)malloc(sizeof(LivreH));
	if(!l){
		printf("Erreur d'allocation\n");
		return NULL;
	}
	l->num=num;
	l->titre=strdup(titre);
	l->auteur=strdup(auteur);
	l->clef=fonctionClef(auteur);
	l->suivant=NULL;
	return l;
}


void libererlivre(LivreH* l){
	//Fonction qui libère un Livre, qui réalise une désallocation
	if(l==NULL){
		printf("Livre vide\n");
		return;
	}
	free(l->titre);
	free(l->auteur);
	free(l);
}


BiblioH* creerbiblio(int m){
	//Fonction qui crée une bibliothèque avec une table de hachage de taille m
	BiblioH* b=(BiblioH*)malloc(sizeof(BiblioH));
	if(!b){
		printf("Erreur d'allocation\n");
		return NULL;
	}
	b->m=m;
	b->nE=0;
	b->T= (LivreH**)malloc(sizeof(LivreH*)*m);
	if(!b->T){
		printf("Erreur d'allocation\n");
		return NULL;
	}
  	return b;
}


void libererbiblio(BiblioH* b){
	//Fonction qui libère la mémoire occupé par une bibliothèque
	if(b==NULL){
		printf("bibliotheque vide\n");
		return;
	}
	else{
		for(int i=0;i<b->m;i++){
			LivreH* Liste=b->T[i];
			while(Liste){
				LivreH* temp=Liste->suivant;
				libererlivre(Liste);
				Liste=temp;
			}
		}
		free(b);
	}
}


//QUESTION 2.4
int fonctionHachage(int cle, int m){
	//Fonction qui réalise un hachage
	return (m*(cle*((sqrt(5)-1)/2)-(int)((cle*((sqrt(5)-1)/2)))));
}


//QUESTION 2.5
void inserer(BiblioH* b,int num,char* titre,char* auteur){
	LivreH* nl= creerlivre(num,titre,auteur);
	int ind=fonctionHachage(nl->clef,b->m); //On trouve la case de la table de hachage dans laquelle insérer le Livre
	nl->suivant=b->T[ind]; //On insère le Livre en tête de la liste chainée correspondant à cette case
	b->T[ind]=nl;
	b->nE++;
}


//QUESTION 2.6
void afficher_livre2(LivreH* l){
	//Fonction qui affiche un Livre
	if(!l){
		printf("Pas de livre\n");
		return;
	}
	printf("%d %s %s %d\n",l->num, l->titre, l->auteur, l->clef);
}


void afficher_biblio2(BiblioH* b){
    //Fonction qui affiche une bibliotheque
  if (!b){
    printf("Il n'y a pas de bibliotheque\n");
    return ;
  }
  if (!b->T){
    printf("La bibliotheque est vide.\n");
    return ;
  }
  LivreH* ptr=NULL;
	int i=0;
    while (i < b->m){
        ptr = b->T[i];
        while (ptr){
          	afficher_livre2(ptr);
            ptr = ptr->suivant;
        }
		i++;
    }
}


LivreH* recherche_num2(int num, BiblioH* b){
	//Fonction qui recherche un ouvrage par son numéro
	if (!b|| num<0){
        printf("La bibliothèque est vide.");
    return NULL;
    }
  int i = 0;
    LivreH* tmp;
    while(i < b->m){
    tmp = b->T[i];
        while (tmp){
      if (tmp->num == num){
        return tmp;
      }
      tmp = tmp->suivant;
    }
    i++;
    }
    printf("Le livre de numéro %d n'existe pas.\n", num);
    return NULL;
}


LivreH* recherche_titre2(char *t, BiblioH *b){
	//Fonction qui recherche un ouvrage par son titre
    if( b == NULL || t == NULL ) return NULL;
    LivreH** l = b->T;
	for(int i=0;i<b->m;i++){
	    while(l[i]){
    	    if(strcmp(l[i]->titre,t) == 0 ) return l[i];
    	    l[i]=l[i]->suivant;
    	}
	}
	printf("Livre de titre '%s' non trouve. \n",t);
    return NULL;
}



BiblioH* recherche_auteur2(char *a, BiblioH *b){
	//Fonction qui recherche tous les livres d'un même auteur
    if( b == NULL || a == NULL ) return NULL;
    BiblioH *bres = creerbiblio(b->m);
	int ind=fonctionHachage(fonctionClef(a), b->m);
    LivreH* l = b->T[ind];
	int first=0;
    while(l){
        if(strcmp(l->auteur,a) == 0  && first==0){
			inserer(bres,l->num, l->titre, l->auteur);
			first=1;
		}
		else if(strcmp(l->auteur,a) == 0  && first==1){
			inserer(bres,l->num, l->titre, l->auteur);
        }
        l=l->suivant;
    }
    if(bres->T== NULL ){
        printf("Aucun ouvrage ayant pour auteur %s n'a ete trouve. \n",a);
    }
    return bres;
}





void suppression2(BiblioH *b, int n, char *t, char *a){
	//Fonction qui supprime un Livre selon son numéro, titre et auteur
   if (!b){
        printf("La bibliothèque est vide.\n");
    return;
    }
    LivreH *ptr = b->T[fonctionHachage(fonctionClef(a), b->m)];
    LivreH *tmp=NULL;
  //Dans le cas où les livres à supprimer sont au début de la liste
	if(ptr->num == n && ptr->auteur==a && ptr->titre==t){
    tmp = ptr;
		ptr=ptr->suivant;
    libererlivre(tmp);
		printf("Suppression faite\n");
		b->nE--;
	}

  b->T[fonctionHachage(fonctionClef(a), b->m)] = ptr;
  while(ptr->suivant){
    if (ptr->suivant->num == n && ptr->suivant->auteur==a && ptr->suivant->titre==t){
      tmp = ptr->suivant;
      ptr->suivant= ptr->suivant->suivant;
      libererlivre(tmp);
			printf("Suppression faite\n");
			b->nE--;
    }
    ptr = ptr->suivant;
  }
	//Dans le cas où les livres à supprimer sont à la fin de la liste
  if (ptr->num == n && !strcmp(ptr->auteur,a)&& !strcmp(ptr->titre,t)){
    libererlivre(ptr);
		printf("Suppression faite\n");
		b->nE--;
  }
}


void fusion2(BiblioH * b1, BiblioH * b2){
	//Fonction qui fusionne deux bibliothèques
	 int i = 0;
    while (i < b2->m){
    LivreH* ptrL = b2->T[i];
    while (ptrL){
          inserer(b1, ptrL->num,ptrL->titre, ptrL->auteur);
      ptrL = ptrL->suivant;
    }
      i++;
    }
    libererbiblio(b2);
}


BiblioH* plusieursEx2(BiblioH* b){
	//Fonction qui affiche les ouvrages a plusieurs exemplaires
	if (!b){
    printf("La bibliothèque n'existe pas.\n");
    return NULL;
	}
	BiblioH *nouv= creerbiblio(b->m);
	if(!nouv)
        return NULL;
    if (!b->T){
    	printf("La bibliothèque est vide.\n");
    return NULL;
  	}
    LivreH *tmp=NULL;
  	int i = 0;
  	while(i < b->m){
    	LivreH *ptr = b->T[i];
    	while(ptr){
			int cpt=0;
			tmp = b->T[i];
			while (tmp){
				if(strcmp(ptr->titre,tmp->titre) == 0 && strcmp(ptr->auteur,tmp->auteur) == 0 && tmp->num!=ptr->num){
					cpt++;
					break;
				}
				tmp = tmp->suivant;
			}
			if(cpt!=0){
				inserer(nouv,ptr->num, ptr->titre, ptr->auteur);
			}
			ptr = ptr->suivant;
    	}
    i++;
  }
  return nouv;
}

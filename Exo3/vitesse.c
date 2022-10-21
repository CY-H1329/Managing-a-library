#include "vitesse.h"


//Exercice3

//Q3.1

void vitesse_re_num(int rep){
    /*On cherche ici a determiner les temps de recherche un ouvrage en fonction du numero de l'ouvrage mis en parametre, de la taille de la bibliotheque et de la structure de donnees utilisee (Biblio/BiblioH)*/

    //Declaration des variables
	int num;
	clock_t temps_initial1;
	clock_t temps_final1;
	double temps_cpu1;
	clock_t temps_initial2;
	clock_t temps_final2;
	double temps_cpu2;
	Livre* bex=NULL;
	LivreH* bHex=NULL;
	Biblio* b=NULL;
    BiblioH* bH=NULL;
	FILE* find = fopen("vitesse_num_trouve.txt","w") ;
		if(find==NULL){
			printf("Erreur dans l'ouverture de ficher\n");
            return;
        }
	FILE* notfind = fopen("vitesse_num_nontrouve.txt","w") ;
		if(notfind==NULL){
			printf("Erreur dans l'ouverture de ficher\n");
            return;
        }
    //Appel des fonctions
	int i = 1000;
	while (i < rep+1000){
		num=rand()%7000;//on a fait un random pour avoir aleatoirement des num differents a chaque tour de boucle
	    //Recherche sans table de hachage
    	b = charger_n_entrees("GdeBiblio.txt", i);
    	temps_initial1 = clock () ;
    	bex =  recherche_num1(num,b);
    	temps_final1 = clock () ;
    	temps_cpu1 = ((double)(temps_final1 - temps_initial1))/CLOCKS_PER_SEC;
    	//Recherche avec table de hachage
    	bH = charger_n_entreesH("GdeBiblio.txt", i);
    	temps_initial2 = clock();
   		bHex = recherche_num2(num,bH);
    	temps_final2 = clock();
    	temps_cpu2 = ((double)(temps_final2 - temps_initial2))/CLOCKS_PER_SEC;
    	//Ecriture des temps dans les fichers txt
	
		if(bex && bHex){
			fprintf(find,"%d %f %f\n",i,temps_cpu1,temps_cpu2);
		}
		if(!bex && !bHex){
			fprintf(notfind,"%d %f %f\n",i,temps_cpu1,temps_cpu2);
		}
		i++;
		//Desallocation a chaque boucle
		liberer_livre(bex);
    	libererlivre(bHex);
	}	
	//Desallocation
	liberer_biblio(b);
    libererbiblio(bH);
	liberer_livre(bex);
    libererlivre(bHex);
	
	//fermeture des fichers
	fclose(find);
	fclose(notfind);
}



void vitesse_re_titre(char* titre, int rep){
    /*On cherche ici a determiner les temps de recherche des ouvrages en plusieurs exemplaires en fonction d'un titre et de la taille de la bibliotheque et de la structure de donnees utilisee (Biblio/BiblioH)*/

    //Declaration des variables
	Biblio *b=NULL;
	Livre* bex=NULL;
    BiblioH* bH= NULL;
    LivreH* bHex=NULL;
	clock_t temps_initial1;
	clock_t temps_final1;
	double temps_cpu1;
	clock_t temps_initial2;
	clock_t temps_final2;
	double temps_cpu2;
	FILE* find = fopen("vitesse_titre_trouve.txt","w") ;
		if(find==NULL){
			printf("Erreur dans l'ouverture de ficher\n");
            return;
        }
	FILE* notfind = fopen("vitesse_titre_nontrouve.txt","w") ;
		if(notfind==NULL){
			printf("Erreur dans l'ouverture de ficher\n");
            return;
        }
    //Appel des fonctions
	int i = 1000;
	while (i < rep+1000){
		//Recherche sans table de hachage
		b = charger_n_entrees("GdeBiblio.txt", i);
	    temps_initial1 = clock () ;
	    bex =  recherche_titre1(titre,b);
	    temps_final1 = clock () ;
	    temps_cpu1 = ((double)(temps_final1 - temps_initial1))/CLOCKS_PER_SEC;
    	//Recherche avec table de hachage
    	bH = charger_n_entreesH("GdeBiblio.txt", i);
    	temps_initial2 = clock();
    	bHex = recherche_titre2(titre,bH);
    	temps_final2 = clock();
    	temps_cpu2 = ((double)(temps_final2 - temps_initial2))/CLOCKS_PER_SEC;
    
		//Ecriture des temps dans les fichers txt
		if(bex && bHex){
			fprintf(find,"%d %f %f\n",i,temps_cpu1,temps_cpu2);
		}
		if(!bex && !bHex){
			fprintf(notfind,"%d %f %f\n",i,temps_cpu1,temps_cpu2);
		}
		i++;
		//Desallocation a chaque boucle
  		liberer_livre(bex);
    	libererlivre(bHex);
	}
	//Desallocation
	liberer_biblio(b);
    libererbiblio(bH);
	liberer_livre(bex);
    libererlivre(bHex);
	
	//fermeture des fichers
	fclose(find);
	fclose(notfind);
}


void vitesse_re_auteur(char* auteur, int rep){
    /*On cherche ici a determiner les temps de recherche des ouvrages en plusieurs exemplaires en fonction d'un auteur de la taille de la bibliotheque et de la structure de donnees utilisee (Biblio/BiblioH)*/

    //Declaration des variables
	Biblio* b=NULL;
	Biblio* bex=NULL;
    BiblioH* bH= NULL;
    BiblioH* bHex=NULL;
	clock_t temps_initial1;
	clock_t temps_final1;
	double temps_cpu1;
	clock_t temps_initial2;
	clock_t temps_final2;
	double temps_cpu2;
	FILE* find = fopen("vitesse_auteur_trouve.txt","w") ;
		if(find==NULL){
			printf("Erreur dans l'ouverture de ficher\n");
            return;
        }
	FILE* notfind = fopen("vitesse_auteur_nontrouve.txt","w") ;
		if(notfind==NULL){
			printf("Erreur dans l'ouverture de ficher\n");
            return;
        }
    //Appel des fonctions
	int i = 1000;
	while (i < 1000+rep){
    	//Recherche sans table de hachage
    	b=charger_n_entrees("GdeBiblio.txt", i);
    	temps_initial1=clock();
    	bex=recherche_auteur1(auteur,b);
    	temps_final1=clock ();
    	temps_cpu1=((double)(temps_final1-temps_initial1))/CLOCKS_PER_SEC;
    	//Recherche avec table de hachage
    	bH=charger_n_entreesH("GdeBiblio.txt", i);
    	temps_initial2=clock();
    	bHex=recherche_auteur2(auteur,bH);
    	temps_final2=clock();
    	temps_cpu2=((double)(temps_final2-temps_initial2))/CLOCKS_PER_SEC;
    	
		//Ecriture des temps dans les fichers txt
		if(bex && bHex){
			fprintf(find,"%d %f %f\n",i,temps_cpu1,temps_cpu2);
		}
		if(!(bex->L) && !(bHex->T)){
			fprintf(notfind,"%d %f %f\n",i,temps_cpu1,temps_cpu2);
		}
		i++;
	}
    //Desallocation
    liberer_biblio(b);
    libererbiblio(bH);
    liberer_biblio(bex);
    libererbiblio(bHex);
	
	//fermeture des fichers
	fclose(find);
	fclose(notfind);
}



//Q3.3

void vitesse_re_exemplaire(int n){
    /*On cherche ici a determiner les temps de recherche des ouvrages en plusieurs exemplaires en fonction de la taille de la bibliotheque et de la structure de donnees utilisee (Biblio/BiblioH)*/

    //Declaration des variables
	Biblio *b=NULL;
	Biblio* bex=NULL;
    BiblioH* bH= NULL;
    BiblioH* bHex=NULL;
	clock_t temps_initial1;
	clock_t temps_final1;
	double temps_cpu1;
	clock_t temps_initial2;
	clock_t temps_final2;
	double temps_cpu2;
	FILE* find = fopen("vitesse_plusieursEx_trouve.txt","w") ;
		if(find==NULL){
			printf("Erreur dans l'ouverture de ficher\n");
            return;
        }
    //Appel des fonctions
	int i = 1000;
	while (i<(1000+n) && i < 50000){
   	 //Recherche sans table de hachage
    	b=charger_n_entrees("GdeBiblio.txt", 5000);
    	temps_initial1=clock () ;
    	bex=plusieursEx1(b); 
    	temps_final1=clock() ;
    	temps_cpu1=((double)(temps_final1-temps_initial1))/CLOCKS_PER_SEC;
    	//Recherche avec table de hachage
    	bH=charger_n_entreesH("GdeBiblio.txt", 5000);
    	temps_initial2=clock();
    	bHex=plusieursEx2(bH);
    	temps_final2=clock();
    	temps_cpu2=((double)(temps_final2-temps_initial2))/CLOCKS_PER_SEC;
    	//Ecriture des temps dans les fichers txt
		fprintf(find,"%d %f %f\n",i,temps_cpu1,temps_cpu2);
	
		i+=5;
 	}
    //Desallocation
    liberer_biblio(b);
    libererbiblio(bH);
    liberer_biblio(bex);
    libererbiblio(bHex);
	
	//fermeture des fichers
	fclose(find);
}


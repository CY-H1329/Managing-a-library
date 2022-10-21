#include "entreeSortieH.h"

void menuH(){
	printf("0-Sortie du programme\n");
	printf("1-Affichage d'une bibliotheque\n");
	printf("2-Recherche d'un ouvrage par son numero\n");
	printf("3-Recherche d'un ouvrage par son titre\n");
	printf("4-Recherche de tout les livres d'un auteur\n");
	printf("5-Inserer un ouvrage en tete de la bibliotheque\n");
	printf("6-Suppression d'un ouvrage dans une bibliotheque\n");
	printf("7-Fusionner deux bibliotheques\n");
	printf("8-Liste des ouvrages a plusieurs exemplaires\n");
	printf("9-Liberer la bibliotheque\n");
	return;
}

int main(int argc, char** argv){
	if(argc != 3){
        fprintf(stderr,"3 arguments en parametres !\n");
        exit(1);
    }
    
	
	LivreH* l=	creerlivre(1,"INFOESTNULL","a");
	printf("%d\n",l->clef);
	printf("%d\n",fonctionHachage(l->clef,1));
	int n=atoi(argv[2]);
	BiblioH* b= creerbiblio(n);
	BiblioH* b2=creerbiblio(n);
	b=charger_n_entreesH(argv[1],n);
	b2=charger_n_entreesH(argv[1],n);
	inserer(b,1,"INFOESTNULL","a");
	inserer(b,1,"INFOESTNULL2","a");
	inserer(b,1,"INFOESTNULL3","a");
	//BiblioH* t=recherche_auteur2("a",b);
	//afficher_biblio2(t);
	//enregistrer_biblioH(b, "BiblioH.txt");
	//afficher_biblio2(b);
	//libererbiblio(b);
	//libererbiblio(b2);

	int choix=-1;
	do{
		printf("\n");
    char buffer[200];
  	menuH();
    printf("\n---------------------------------\n");
  	printf("Merci de bien vouloir mentionner votre choix : ");
    fgets(buffer, 200, stdin);
    sscanf(buffer,"%d",&choix);

  	while( choix < 0 || choix > 9 ){
      printf("\nAttention, votre choix n'est pas valide.\n");
      char buffer[200];
      menuH();
      printf("Merci de bien vouloir mentionner un autre chiffre compris entre 0 et 9 : ");
      fgets(buffer, 200, stdin);
      sscanf(buffer, "%d", &choix);
			printf("\n");
      }
		printf("\n");

    switch(choix){

			//Sortie du programme
	case 0:
		printf("---------------------------------\n");
		printf("Sortie du Programme\n");
		printf("Merci, et au revoir.\n");
		exit(1);

			//Affichage de la bibliothèque
	case 1:
      	printf("Affichage de la bibliotheque :\n");
        afficher_biblio2(b);
				printf("\n");
        break;

			//Affichage d'un ouvrage par le numéro
	case 2:
		printf("Afficher l'ouvrage avec le numero: \n");
        int num;
        char buffer2[300];
        fgets(buffer2,300,stdin);
        if (sscanf(buffer2,"%d", &num)==1){
					afficher_livre2(recherche_num2(num, b));
				}
        else{
					printf("Erreur format\n");
				}
				printf("\n");
      	break;

			//Affichage d'un ouvrage avec le titre spécifié
	case 3:
      	printf("Afficher l'ouvrage avec le titre : \n");
        char titre3[300];
        char buffer3[300];
        fgets(buffer3,300,stdin);
        if (sscanf(buffer3,"%s", titre3)==1)
					afficher_livre2(recherche_titre2(titre3, b));
        else{
					printf("Erreur format\n");
				}
				printf("\n");
        break;

			//Affichage d'un ouvrage de l'auteur spécifié
	case 4:
        printf("Afficher les ouvrages de l'auteur: \n");
        char auteur4[300];
        char buffer4[300];
        fgets(buffer4,300,stdin);
        if (sscanf(buffer4,"%s", auteur4)==1){
			afficher_biblio2(recherche_auteur2(auteur4, b));
		}
        else{
			printf("Erreur format\n");
		}
		printf("\n");
        break;

			//Insertion d'un livre dans la bibliothèque
	case 5:
      	printf("Veuillez inscrire le numero, le titre et l'auteur de l'ouvrage a ajouter : \n");
        int num5;
        char titre5[200];
        char auteur5[200];
        char buffer5[200];
        fgets(buffer5,200,stdin);
        //On suppose que le titre et l’auteur ne contiennent pas d’espace
        if (sscanf(buffer5,"%d %s %s",&num5, titre5, auteur5)==3){
          inserer(b, num5, titre5, auteur5);
          printf("Ajout fait.\n");
        }
        else{
          printf("Erreur format\n");
        }
				printf("\n");
				break;

			//Suppression d'un ouvrage de la bibliothèque
	case 6:
        printf("Veuillez inscrire le numero, le titre et l'auteur de l'ouvrage a supprimer : ");
        int num6;
        char titre6[200];
        char auteur6[200];
				char buffer6[200];
        fgets(buffer6,200,stdin);
        // On suppose que le titre et l’auteur ne contiennent pas d’espace
        if (sscanf(buffer6,"%d %s %s",&num6, titre6, auteur6)==3){
        	suppression2(b, num6, titre6, auteur6);
        }
        else{
			printf("Erreur format\n");
		}
		printf("\n");
        break;

			//Affichage de la fusion des bibliothèques
	case 7:
		fusion2(b,b2);
      	afficher_biblio2(b);
        break;

			//Affichage des livres en plusieurs exemplaires
	case 8:
				afficher_biblio2(plusieursEx2(b));
				printf("\n");
				break;

			//Libération de la bibliothèque et sortie du programme
      case 9:
        	printf("Liberation de la bibliotheque.\n");
			printf("\n---------------------------------\n");
			printf("Fin du programme.\n");
		    printf("Merci, et au revoir.\n");
        	libererbiblio(b);
			libererbiblio(b2);
			printf("\n");
			exit(1);
        	break;
        }
    }
	while( choix != 0);
  	printf("\n---------------------------------\n");
    printf("Merci, et au revoir.\n");
		if(b && b2 !=NULL){ // En cas d'oubli de libération des bibliothèques
			libererbiblio(b);
			libererbiblio(b2);
		}
	
	return 0;

}

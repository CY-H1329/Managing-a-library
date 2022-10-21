#include "entreeSortieLC.h"

void menu(){
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
	

	int n=atoi(argv[2]);
	Biblio* b=creer_biblio();
	Biblio* b2=creer_biblio();
	b=charger_n_entrees(argv[1],n);
	enregistrer_biblio(b, "Biblio.txt");
	int choix=-1;
	do{
        char buffer[200];
        menu();
        printf("---------------------------------\n");
        printf("Merci de bien vouloir mentionner votre choix : ");
        fgets(buffer, 200, stdin);
        sscanf(buffer,"%d",&choix);
        
        while( choix < 0 || choix > 9 ){
            printf("\nAttention, votre choix n'est pas valide.\n");
            char buffer[200];
            menu();
            printf("Merci de bien vouloir mentionner un autre chiffre compris entre 0 et 9 : ");
            fgets(buffer, 200, stdin);
            sscanf(buffer, "%d", &choix);
			printf("\n");
        }
		printf("\n");
        switch(choix){
			case 0:
				printf("Sortie du Programme\n");
				exit(1);


            case 1: 
                printf("Affichage de la bibliothèque :\n");
                afficher_biblio(b);
                break;
			

			case 2: 
				printf("Afficher l'ouvrage avec le num: \n");
                int num;
                char buffer2[300];
                fgets(buffer2,300,stdin);
                if (sscanf(buffer2,"%d", &num)==1) 
					afficher_livre(recherche_num1(num, b)); 
                else printf("Erreur format\n");
				printf("\n");
                break;

			  
			case 3:
                printf("Afficher l'ouvrage avec le titre : \n");
                char titre3[300];
                char buffer3[300];
                fgets(buffer3,300,stdin);
                if (sscanf(buffer3,"%s", titre3)==1) 
					afficher_livre(recherche_titre1(titre3, b)); 
                else printf("Erreur format\n");
                break;         

            
            case 4:
                printf("Afficher les ouvrages de l'auteur: \n");
                char auteur4[300];
                char buffer4[300];
                fgets(buffer4,300,stdin);
                if (sscanf(buffer4,"%s", auteur4)==1) 
					afficher_biblio(recherche_auteur1(auteur4, b)); 
                else printf("Erreur format\n");
                break;


			case 5:
                printf("Veuillez inscrire le numero, le titre et l’auteur de l’ouvrage à ajouter : \n");
                int num5;
                char titre5[200];
                char auteur5[200];
                char buffer5[200];
                fgets(buffer5,200,stdin);
                /* On suppose que le titre et l’auteur ne contiennent pas d’espace*/
                if (sscanf(buffer5,"%d %s %s",&num5, titre5, auteur5)==3){
                    inserer_en_tete(b, num5, titre5, auteur5);
                    printf("Ajout fait.\n");
                    }
                else{
                    printf("Erreur format\n");
                }
				break; 


			case 6:
                printf("Veuillez inscrire le numero, le titre et l’auteur de l’ouvrage à supprimer : ");
                int num6;
                char titre6[200];
                char auteur6[200];
                char buffer6[200];
                fgets(buffer6,200,stdin);
                /* On suppose que le titre et l’auteur ne contiennent pas d’espace*/
                if (sscanf(buffer6,"%d %s %s",&num6, titre6, auteur6)==3){
                    suppression1(b, num6, titre6, auteur6);
                    }
                else printf("Erreur format\n");
                break; 


			case 7:
             	afficher_biblio(fusion1(b,b2));
                break; 


			case 8:
				afficher_biblio(plusieursEx1(b));
				break;


            case 9: 
                printf("Liberer la bibliothèque.\n");
                liberer_biblio(b);
				liberer_biblio(b2);
                break;

        }

    }
	while( choix != 0); 
  	printf("---------------------------------\n");
    printf("Merci, et au revoir.\n");

	

	return 0;
}

		
	
		 
	

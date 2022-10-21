#include"vitesse.h"

int main(){
	srand(time(NULL));
	char auteur[256];
	char titre[256];
	int rep;
	printf("Saisissez un auteur pour chercher un livre\n");
	scanf("%s",auteur);
	printf("choississez un titre pour chercher un livre\n");
	scanf("%s",titre);
	printf("Saisissez le nombre de fois que vous vous voulez repeter\n");
	scanf("%d",&rep);
	
	
	//vitesse_re_titre(titre,rep);
	//vitesse_re_auteur(auteur,rep);
	//vitesse_re_exemplaire(rep);
	vitesse_re_num(rep);
	

	return 0;
}

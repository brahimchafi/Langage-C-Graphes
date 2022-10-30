#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>

int main(){
    GrapheLP g = graphe_vide();

	g = ajouter_sommet(1,g);

	g = ajouter_sommet(2,g);

	g = ajouter_sommet(3,g);

	g = ajouter_sommet(4,g);

	g = ajouter_sommet(5,g);

	g = ajouter_sommet(6,g);

	printf("%d sommets sont ajoute\n",g->n);

	g = ajouter_arc(1,2,g);
	g = ajouter_arc(1,3,g);
	g = ajouter_arc(1,4,g);
	g = ajouter_arc(2,5,g);
	g = ajouter_arc(2,6,g);
	g = ajouter_arc(3,6,g);
	g = ajouter_arc(3,7,g);
	g = ajouter_arc(6,8,g);


	printf("les sommets de 1 sont %d\n",g->a[1]->sommet);
	printf("les sommets de 1 sont %d\n",g->a[1]->suivant->sommet);
	printf("les sommets de 1 sont %d\n",g->a[1]->suivant->suivant->sommet);
	printf("les sommets de 1 sont %d\n\n",g->a[1]->suivant->suivant->suivant->sommet);


	printf("les sommets de 2 sont %d\n",g->a[2]->sommet);
	printf("les sommets de 2 sont %d\n",g->a[2]->suivant->sommet);
	printf("les sommets de 2 sont %d\n\n",g->a[2]->suivant->suivant->sommet);


	printf("les sommets de 3 sont %d\n",g->a[3]->sommet);
	printf("les sommets de 3 sont %d\n",g->a[3]->suivant->sommet);
	printf("les sommets de 3 sont %d\n\n",g->a[3]->suivant->suivant->sommet);


	printf("les sommets de 6 sont %d\n",g->a[6]->sommet);
	printf("les sommets de 6 sont %d\n",g->a[6]->suivant->sommet);


//	parcoursEnProfendeur(g,1);

	printf("-----------------------\n\n\n");
	reinitialiser();
	parcoursEnProfendeur(g,1);

	reinitialiser();

	int x =0;
	for(x = 1; x < g->n ;x++){
	     Tab_atteints[x] = 0;
	 }
	for(x = 1; x < g->n; x ++){
		if(!Tab_atteints[x]){
			pracoursEnLargeur(g,x);
		}
	}





}

#include<stdio.h>
#define N_MAX 100 
#include <stdlib.h>

typedef struct cellule {
	int sommet;
	struct cellule* suivant;
}Cellule;

typedef Cellule* Liste;

typedef struct {
	Liste a[N_MAX];
	int n ; 
}GrapheL;

typedef GrapheL *GrapheLP;

int Tab_atteints[N_MAX];


typedef struct{
	int tab[N_MAX];
	int tete;
	int queue;
}File;







/*--------------------les fonctions concernant les listes------------------------------*/
Liste liste_vide()
{
  return NULL;
}

int est_vide(Liste liste)
{
  return liste == NULL;
}

int longueur(Liste liste)
{
  if (est_vide(liste)) return 0;

  int taille = 0;
  Liste ptr = liste;
  while (ptr) {
    taille++;
    ptr = ptr->suivant;
  }

  return taille;
}


Liste acces(Liste liste, int k)
{
  if (k < 1 || k > longueur(liste)) {
    printf("Erreur: Rang invalide!\n");
    exit(-1);
  }

  if (k == 1) return liste;

  Liste ptr = liste;
  int  i;
  for (i = 1; i < k; i++) {
    ptr = ptr->suivant;
  }

  return ptr;
}

Liste inserer(Liste liste, int indice, int element)
{
  if (indice < 1 || indice > longueur(liste) + 1) {
    printf("Erreur: Rang non valide!\n");
    exit(-1);
  }

  Liste cellule = (Liste)malloc(sizeof(Cellule));
  cellule->sommet = element;
  cellule->suivant = NULL;

  if (indice == 1) {
    cellule->suivant = liste;
    liste = cellule;
  } else {
    Liste ptr = acces(liste, indice - 1);

    cellule->suivant = ptr->suivant;
    ptr->suivant = cellule;
  }

  return liste;
}











/*--------------------les fonctions concernant les files------------------------------*/



File file_vide(){
	File f;
	f.queue = f.tete = -1;
	return f;
}


File enfiler(File f, int e) {
	if (f.queue == N_MAX-1) {
		printf("Erreur: on ne peut ajouter !\n");
			exit(-1);
	}
		(f.queue)++;
		(f.tab)[f.queue] = e;
			return f;
}

	int est_vide_file(File f) {
		if (f.tete == f.queue) return 1;
			return 0;
}

	int defiler(File f) {
	
		if (est_vide_file(f)==1) {
			printf("Erreur: file vide !\n");
			exit(-1);
			}
			f.tete++;
			return (f.tab)[f.tete+1];
}




/*--------------------les fonctions concernant les graphes------------------------------*/
GrapheLP graphe_vide(){
	 
	 GrapheLP g = (GrapheLP)malloc(sizeof(GrapheL));
	 g->n = 0;
	 int i = 0;
	 
	 for(i = 0 ; i < N_MAX ; i++){
	 	g->a[i] = NULL;
	 }
	 
	 return g;
}

GrapheLP ajouter_sommet(int s , GrapheLP g){
	
	if (g != NULL) {
		
		Liste c = (Liste)malloc(sizeof(Cellule));
		c->suivant = NULL;
		c->sommet = s;
		g->a[s] = c;
		g->n++;
	}
	return g;
}



GrapheLP ajouter_arc(int s, int v , GrapheLP g){
	
	if( g != NULL){
		Liste tmp = g->a[s] ;
		g->a[s] = inserer(tmp,longueur(tmp)+1,v);
		g->n++;
	}
 		return g;
}

void reinitialiser(){
	
	 int i;
  		for (i = 0; i < N_MAX; i++) {
    		Tab_atteints[i] = 0;
  }
}

void parcoursEnProfendeur(GrapheLP g , int s){
	//reinitialiser();
	Tab_atteints[s] = 1;
	printf(" (%d) ", s);
	
	Liste tmp = g->a[s];
	while(tmp!=NULL){
		if(Tab_atteints[tmp->sommet] == 0){
			parcoursEnProfendeur(g,tmp->sommet);
			
		}
		tmp = tmp->suivant;
	}
	
}


void afficherGrapheParcoursProfendeur(GrapheLP g){
	
	
  reinitialiser();
  int  i;

  printf("\nLes elements du graphe: ");

  for (i = 0; i < N_MAX; i++) {
    Liste liste = g->a[i];
    if (!est_vide(liste)) {
      parcoursEnProfendeur(g, i);
    }
  }

  printf("\n");
	
}

void pracoursEnLargeur(GrapheLP g , int s){
		
		Liste p;
		File f = file_vide();
		f = enfiler(f,s); 
		Tab_atteints[s] = 1;
		while(est_vide_file(f)==1){
			s = defiler(f);
			p = g->a[s];
			printf(" (%d) ", s);
			while(p!=NULL){
				if(Tab_atteints[p->sommet] == 0){
					Tab_atteints[p->sommet]==1;
					enfiler(f,p->sommet);
				}
				p = p->suivant;
			}
		}

}
	


GrapheLP supprimer_sommet(Cellule c , GrapheL g){
	
}

GrapheLP supprimer_arc(Cellule c1 , Cellule c2 , GrapheL g){
	
}

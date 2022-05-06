#include "case.h"
#include <stdio.h>
#include <stdlib.h> 

Ccase * case_init_vide(int f, int i){
	Ccase * res = malloc(sizeof(Ccase));
	res->p=NULL;
	res->fond =f;
	res->index=i;
	return res;
}
Ccase * case_init(int t, int c, int f, int i){
	Ccase * res = malloc(sizeof(Ccase));
	res->p = piece_init(t,c);
	res->fond=f;
	res->index=i;
	return res;
}

piece * retirer_piece(Ccase * ca){
	piece * res = piece_init(ca->p->type,ca->p->couleur);
	ca->p=NULL;
	return res;
}
void modifier_piece(piece * pi,Ccase *ca){
	if(ca->p==NULL){
		ca->p=pi;
	}
}

void case_destroy(Ccase * ca){
	piece_destroy(ca->p);
	free(ca);
	ca=NULL;
}

#include <stdlib.h>
#include <stdio.h> 
#include <math.h> 
#include <unistd.h> 
#include "damier.h"
int main(){
	int curX,curY,newX,newY;
	damier * d = damier_init();
	int cont=1;
	int joueur=1;
	pprise ppr=malloc(sizeof(struct prises));
	while(d->coups<=100){
		affichage(d);
                while(1){
                	if((ppr=maxPrise(d,joueur))!=NULL){
                		while (ppr!=NULL){
                			eat(ppr->x,ppr->y,ppr->newX,ppr->newY,d,joueur);
                			printf("pièce du joueur %d, a effectué une prise de (%d,%d) à (%d,%d)\n",joueur,ppr->x,ppr->y,ppr->newX, ppr->newY);
                			sleep(2);
                			ppr=ppr->next;
                		}
                		break;
                	}
                	
                	
                	printf("joueur: %d \n",joueur + 1);
		        printf("curX :");
		        scanf("%d",&curX);
		        printf("\ncurY:");
		        scanf("%d",&curY);
		        printf("\nnewX:");
		        scanf("%d",&newX);
		        printf("\nnewY:");
		        scanf("%d",&newY);
		        
		        // si on met que des 0 on passe son tour
		        if((curX == 0) && (curY == 0) && (newX == 0) && (newY == 0)){
		        	break;
		        }
		     	if(moveDame(curX,curY,newX,newY,d,joueur)){
		     		break;
		     	}
		        if(abs(newX - curX) == 2){
		        	if(eat(curX,curY,newX,newY,d,joueur) == 0){
		        		printf("coup non valable\n");
		        		sleep(2);
		        	}
		        	 else{
		        	 	break;
		        	 }
		        }
			else{
		        	if(move(curX,curY,newX,newY,d,joueur) == 0){
		        		printf("coup non valable\n");
		        		sleep(2);
		        	}
		        	else{
		   			break;
		   		}
		   	}
		   	system("clear");
		   	affichage(d);
		       
		}
                joueur=!joueur;
                system("clear");
        }
	damier_destroy(d);
	return 0;
}

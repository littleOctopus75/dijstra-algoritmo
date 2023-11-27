#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (void){
	int l[10], i,cont,comp, band=0, nodo=0,v, suma=0,x,y,z,m,contb=1;
	int t[10];
	int w[10][10];
	
	printf ("Ingrese el numero de nodos de su grafo: ");
	scanf ("%d", &m);
	x=m;
	y=m;
	printf("Ingrese los pesos de su matriz: ");
	for (i=0; i<y; i++){
			for (cont=0; cont<x; cont++){
				printf ("nodo: [%d,%d]", i+1,cont+1);
				scanf("%d", &w[i][cont]);
			}
	}
	
	l[0]=0;
	for(i=1; i<m; i++){
		l[i]=1000;
	}
	for(i=0; i<m; i++){
		t[i]=1;
	}
	/*a[1] -> c[3]*/
	printf("Ingrese el nodo de partida: ");
	scanf("%d", &z);
	
	while(t[z]==1){
		/*Seleccionar */
		comp=100;
		for(i=0; i<m; i++){
			if(t[i]==1){
				if(l[i]<=comp){
					comp=l[i];
					band=1;
					nodo=i;
					v=i;
				}
			}
		}
		/*----------------------------*/
		/*quitarle a t el nodo v*/
		if(band==1){
			t[nodo]=0; 
		}
		/*----------------------------*/
		/*asignar minimos*/
		for(i=0; i<m; i++){
			if (w[v][i]>0 && t[i]==1){
				suma=l[v]+w[v][i];
				l[i]=fmin(l[i],suma);
			}
		}	
		/*-----------------------------*/
	}
	printf("peso = %d\n",l[z]);
	do{
	printf("Desea ejecutarlo otra vez: 1[si], 0 [No]");
	scanf("%d", &contb);
	printf("Ingrese el nodo que quiere ver: ");
	scanf("%d", &z);
	printf("\n\t%d\n",l[z]);
	}while (contb==1);
}

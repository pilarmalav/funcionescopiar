/*
 ============================================================================
 Name        : este.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "malavonsenemariadelpilar1.h"


void menuComponentes (int num){

	char *comp[4] = {"Teclado", "Raton", "Monitores", "Mando"};
	float precio[4] = {9.90, 12.90, 20.00, 29.90};
	printf("%i Añadir %s Precio: %.2f\n", num+1, comp[num], precio[num]);

}

float carrito (int codigo, float total, int unidades)
{
	float precio[4] = {9.90,12.90,20.00,29.90};

	return total + precio[codigo] * unidades;
}
int main(void) {

	char *comp[4] = {"Teclado", "Raton", "Monitores", "Mando"};
	int i;
	int opcion = 5;
	int cantidad, cantCarrito = 0;
	float total = 0;
	do {
		for (i = 0; i < 4; i++)
		{
			menuComponentes(i);
		}

		puts("0. Salir");
		printf("\n¿Qué quieres añadir? (1-4)");
		fflush(stdout);		scanf("%i", &opcion);

		if (opcion < 0 || opcion > 4) printf("\nOpción incorrecta.\n");
		else if (opcion != 0)
		{
			printf("\n¿Cuántas unidades de %s quieres?", comp[opcion-1]);
			fflush(stdout);			scanf("%i", &cantidad);

			total = total + carrito(opcion-1, total, cantidad);
			cantCarrito = cantCarrito + cantidad;

			printf("\nHay %i artículos en el carrito con un importe total de %.2f euros\n", cantCarrito, total);
		}
	} while (opcion != 0);

	printf("\nADIOS (:");
	return EXIT_SUCCESS;
}




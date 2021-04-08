#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout,NULL);
	int x;
	int y;
	int resultado;
	int prueba;
	printf("Escriba un número entero: ");
	fflush(stdin);
	scanf("%d",&x);
	printf("Escriba otro número entero: ");
	fflush(stdin);
	scanf("%d",&y);
	prueba = suma(x,y,&resultado);
	if(prueba)
	{
	printf("Su valor de resultado es: %d\n",resultado);
	}else
	{
		printf("No hay nada que sumar");
	}
	return EXIT_SUCCESS;
}

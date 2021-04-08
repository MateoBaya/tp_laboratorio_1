#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"
#include "menu.h"

int main() {
	setbuf(stdout,NULL);
	int retorno;
	int x;
	int y;
	int resultado;
	int opcionUsuario;
	float resultadoFloat;

	do
	{
	printf("Escriba el numero para 1-Suma, 2-Resta, 3-Multiplicar, 4-Dividir, 5-Factorial: ");
	scanf("%d",&opcionUsuario);
	}while(opcionUsuario > 5 || opcionUsuario < 1);

	printf("Escriba un número entero x: ");
	fflush(stdin);
	scanf("%d",&x);
	if(opcionUsuario != 5)
	{
	printf("Escriba un número entero y: ");
	fflush(stdin);
	scanf("%d",&y);
	}

	retorno = menu(x,y,&resultado,&resultadoFloat,opcionUsuario);

	if(retorno == 1)
	{
		printf("x es igual a: %d\n",x);
		if(opcionUsuario != 5)
		{
		printf("y es igual a: %d\n",y);
		}
		printf("El resultado es: %d\n",resultado);

	}else if(retorno == 2)
	{
		printf("x es igual a: %d\n",x);
		if(opcionUsuario != 5)
		{
		printf("y es igual a: %d\n",y);
		}
		printf("El resultado es: %f\n",resultadoFloat);
	}else
	{
		switch(opcionUsuario){
		case 1:
			printf("No hay nada que sumar, ambos valores eran 0");
			break;
		case 2:
			printf("No hay nada que restar, ambos valores eran 0");
			break;
		case 3:
			printf("La respuesta es 0, alguno de tus valores era 0");
			break;
		case 4:
			printf("La repuesta es 0 o incoherente, alguno de tus valores era 0");
			break;
		case 5:
			printf("ERROR. Tu numero era menor a 0");
			break;
		}
	}

	return EXIT_SUCCESS;
}

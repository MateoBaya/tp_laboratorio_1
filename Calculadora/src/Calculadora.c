#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "menu.h"
#include "utn.h"

int main() {
	setbuf(stdout,NULL);
	int retorno;
	int x;
	int y;
	int resultado;
	int segundoResultado;
	int opcionUsuario;
	float resultadoFloat;

	printf("Escriba un número entero x: ");
	fflush(stdin);
	scanf("%d",&x);
	printf("Escriba un número entero y: ");
	fflush(stdin);
	scanf("%d",&y);

	do
	{
	printf("Escriba el numero para 1-Suma, 2-Resta, 3-Multiplicar, 4-Dividir, 5-Factorial: ");
	scanf("%d",&opcionUsuario);
	}while(opcionUsuario > 5 || opcionUsuario < 1);


	retorno = menu(x,y,&resultado,&segundoResultado,&resultadoFloat,opcionUsuario);

	if(retorno == 1)
	{
		printf("x es igual a: %d\n",x);
		printf("y es igual a: %d\n",y);
		printf("El resultado es: %d\n",resultado);

	}else if(retorno == 2)
	{
		printf("x es igual a: %d\n",x);
		printf("y es igual a: %d\n",y);
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
			switch(retorno)
			{
			case 7:
				printf("Ambos valores son negativos, no hay resultado");
				break;
			case 9:
				printf("x es igual a: %d\n",x);
				printf("ERROR. El segundo valor era negativo.\n");
				printf("El resultado del primer valor es: %d\n",resultado);
				break;
			case 11:
				printf("ERROR. El primer valor era negativo.\n");
				printf("y es igual a: %d\n",y);
				printf("El resultado del segundo valor es: %d\n",segundoResultado);
				break;
			case 13:
				printf("x es igual a: %d\n",x);
				printf("y es igual a: %d\n",y);
				printf("El resultado del primer valor es: %d\n",resultado);
				printf("El resultado del segundo valor es: %d\n",segundoResultado);
				break;
			}
		}
	}

	return EXIT_SUCCESS;
}

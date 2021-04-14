#include <stdio.h>
#include "funciones.h"

int submenu(int valor1, int valor2, int* valResultado,int* val2Resultado, float* valResultadoFloat, int opcionUsuario);

int menuUsuario()
{
	int funcionar;
	int opcionInicialUsuario;
	int opcionUsuario;
	int retorno;
	int x;
	int y;
	int resultado;
	int segundoResultado;
	float resultadoFloat;
	int flagx = 1;
	int flagy = 1;

	do
	{
		if(flagx && flagy)
		{
		printf("1- Ingrese valor entero x\n2- Ingrese valor entero y\n3-Eliga su operacion\n4-Ver resultados\n5-Salir\n");
		printf("Elegir:");
		scanf("%d",&opcionInicialUsuario);
		}else if(flagx == 0 && flagy)
		{
			printf("\n1- Ingrese valor entero x: %d\n2- Ingrese valor entero y\n3-Eliga su operacion\n4-Ver resultados\n5-Salir\n",x);
			printf("Elegir:");
			scanf("%d",&opcionInicialUsuario);
		}else if(flagy == 0 && flagx)
		{
			printf("\n1- Ingrese valor entero x\n2- Ingrese valor entero y: %d\n3-Eliga su operacion\n4-Ver resultados\n5-Salir\n",y);
			printf("Elegir:");
			scanf("%d",&opcionInicialUsuario);
		}else if(flagx == 0 && flagy == 0)
		{
			printf("\n1- Ingrese valor entero x: %d\n2- Ingrese valor entero y: %d\n3-Eliga su operacion\n4-Ver resultados\n5-Salir\n",x,y);
			printf("Elegir:");
			scanf("%d",&opcionInicialUsuario);
		}


		switch(opcionInicialUsuario)
		{
		case 1:
			printf("Escriba x: ");
			fflush(stdin);
			scanf("%d",&x);
			flagx=0;

			break;

		case 2:
			printf("Escriba y: ");
			fflush(stdin);
			scanf("%d",&y);
			flagy=0;

			break;

		case 3:
			do
			{
			printf("Escriba el numero para 1-Suma, 2-Resta, 3-Multiplicar, 4-Dividir, 5-Factorial: ");
			scanf("%d",&opcionUsuario);
			}while(opcionUsuario > 5 || opcionUsuario < 1);

			break;

		case 4:
			retorno = submenu(x,y,&resultado,&segundoResultado,&resultadoFloat,opcionUsuario);

			if(retorno == 1)
			{
				printf("\nx es igual a: %d\n",x);
				printf("y es igual a: %d\n",y);
				printf("El resultado es: %d\n",resultado);
				funcionar = 1;

			}else if(retorno == 2)
			{
				printf("\nx es igual a: %d\n",x);
				printf("y es igual a: %d\n",y);
				printf("El resultado es: %f\n",resultadoFloat);
				funcionar =1;
			}else
			{
				switch(opcionUsuario){
				case 1:
					printf("No hay nada que sumar, ambos valores eran 0\n");
					break;
				case 2:
					printf("No hay nada que restar, ambos valores eran 0\n");
					break;
				case 3:
					printf("La respuesta es 0, alguno de tus valores era 0\n");
					break;
				case 4:
					printf("La repuesta es 0 o incoherente, alguno de tus valores era 0\n");
					break;
				case 5:
					switch(retorno)
					{
					case 7:
						printf("\nAmbos valores son negativos, no hay resultado");
						break;
					case 9:
						printf("\nx es igual a: %d\n",x);
						printf("ERROR. El segundo valor era negativo.\n");
						printf("El resultado del primer valor es: %d\n",resultado);
						funcionar =1;
						break;
					case 11:
						printf("\nERROR. El primer valor era negativo.\n");
						printf("y es igual a: %d\n",y);
						printf("El resultado del segundo valor es: %d\n",segundoResultado);
						funcionar =1;
						break;
					case 13:
						printf("\nx es igual a: %d\n",x);
						printf("y es igual a: %d\n",y);
						printf("El resultado del primer valor es: %d\n",resultado);
						printf("El resultado del segundo valor es: %d\n",segundoResultado);
						funcionar =1;
						break;
					}
				}
			}
			break;
		}
	}while(opcionInicialUsuario != 5);



	return funcionar;
}

int submenu(int valor1, int valor2, int* valResultado,int* val2Resultado, float* valResultadoFloat, int opcionUsuario)
{
	int funcionar;
	switch(opcionUsuario)
	{
	case 1:
		if(suma(valor1, valor2, &*valResultado))
		{
			funcionar = suma(valor1, valor2, &*valResultado);
		}else
		{
			funcionar = 0;
		}
		break;
	case 2:
		if(resta(valor1, valor2, &*valResultado))
		{
			funcionar = resta(valor1, valor2, &*valResultado);
		}else
		{
			funcionar = 0;
		}
		break;
	case 3:
		if(multiplicar(valor1, valor2, &*valResultado))
		{
			funcionar = multiplicar(valor1, valor2, &*valResultado);
		}else
		{
			funcionar = 0;
		}
		break;
	case 4:
		if(dividir(valor1, valor2, &*valResultadoFloat))
		{
			funcionar = 2;
		}else
		{
			funcionar = 0;
		}
		break;
	case 5:
		funcionar = factorial(valor1,valor2,&*valResultado,&*val2Resultado);
		break;
	}
	return funcionar;
}



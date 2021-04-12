#include <stdio.h>
#include "funciones.h"

int menu(int valor1, int valor2, int* valResultado,int* val2Resultado, float* valResultadoFloat, int opcionUsuario)
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
		switch(funcionar)
		{
		case 7:
			printf("Ambos valores son negativos, no hay resultado");
			break;
		case 9:
			printf("ERROR. El segundo valor era negativo.\n");
			break;
		case 11:
			printf("ERROR. El primer valor era negativo.\n");
			break;
		case 12:
			printf("Ambos valores positivos");
			break;
		}
		break;
	}
	return funcionar;
}


#include <stdio.h>
#include "funciones.h"

int menu(int valor1, int valor2, int* valResultado, float* valResultadoFloat, int opcionUsuario)
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
		if(factorial(valor1, &*valResultado))
		{
			funcionar = factorial(valor1, &*valResultado);
		}else
		{
			funcionar = 0;
		}
		break;
	}
	return funcionar;
}


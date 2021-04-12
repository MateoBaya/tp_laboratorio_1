#include "validaciones.h"
#include <stdio.h>

int suma(int valor1, int valor2, int* valResultado)
{
	int funcionar;

	if (unoIgual0 (valor1, valor2))
	{
		*valResultado = valor1 + valor2;
		funcionar = 1;
	}else
	{
		funcionar = 0;
	}

	return funcionar;
}

int resta(int valor1, int valor2, int* valResultado)
{
	int funcionar;

	if (unoIgual0 (valor1, valor2))
		{
			*valResultado = valor1 - valor2;
			funcionar = 1;
		}else
		{
			funcionar = 0;
		}

	return funcionar;
}

int multiplicar(int valor1, int valor2, int* valResultado)
{
	int funcionar;

	if (nadaIgual0(valor1, valor2))
	{
		*valResultado = valor1 * valor2;
		funcionar = 1;
	}else
	{
		funcionar = 0;
	}

	return funcionar;
}

int dividir(int valor1, int valor2, float* valResultado)
{
	int funcionar;

	if (nadaIgual0(valor1, valor2))
	{
		*valResultado = (float) valor1 /  valor2;
		funcionar = 1;
	}else
	{
		funcionar = 0;
	}

	return funcionar;
}

int factorial(int valor1,int valor2, int* valResultado, int* val2Resultado)
{
	int funcionar;
	int funcionarAnalisis = 10;
	int acumResultado = 1;
	int acumResultadoVal2 = 1;
	int contador = 1;
	int contadorVal2 = 1;


	if (numeroPos(valor1))
	{
		do
		{
			acumResultado = contador * acumResultado;
			contador++;
		}while(contador <= valor1);

		funcionarAnalisis++;
	}else
	{
		funcionarAnalisis--;
	}

	if (numeroPos(valor2))
	{
		do
		{
			acumResultadoVal2 = contadorVal2 * acumResultadoVal2;
			contadorVal2++;
		}while(contadorVal2 <= valor2);

		funcionarAnalisis=funcionarAnalisis +2;
	}else
	{
		funcionarAnalisis=funcionarAnalisis -2;
	}

	*valResultado = acumResultado;
	*val2Resultado = acumResultadoVal2;

	funcionar = funcionarAnalisis;

	return funcionar;
}

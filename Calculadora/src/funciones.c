#include "validaciones.h"

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

int factorial(int valor1, int* valResultado)
{
	int funcionar;
	int acumResultado = 1;
	int contador = 1;

	if (numeroPos(valor1))
	{
		do
		{
			acumResultado = contador * acumResultado;
			contador++;
		}while(contador <= valor1);
		funcionar = 1;
	}else
	{
		funcionar = 0;
	}
	*valResultado = acumResultado;

	return funcionar;
}

#include <stdio.h>

int nadaIgual0(int valor1, int valor2)
{
	int funcionar;
	if (valor1 != 0 && valor2 != 0)
	{
		funcionar = 1;
	}else
	{
		funcionar = 0;
	}
	return funcionar;
}

int unoIgual0(int valor1, int valor2)
{
	int funcionar;
	if (valor1 != 0 || valor2 != 0)
	{
		funcionar = 1;
	}else
	{
		funcionar = 0;
	}
	return funcionar;
}

int validarSoN(int* respuestaUsuario)
{
	int funcionar;
	char respuesta;
	scanf("%c",&respuesta);
	if (respuesta == 's')
	{
		*respuestaUsuario = respuesta;
		funcionar = 1;
	}else if (respuesta == 'n')
	{
		*respuestaUsuario = respuesta;
		funcionar = 1;
	}else{
		funcionar = 0;
	}
	return funcionar;
}

int numeroPos(int val1)
{
	int funcionar;
	if (val1 >=0)
	{
		funcionar = 1;
	}else
	{
		funcionar = 0;
	}
	return funcionar;
}

int numeroNeg(int val1)
{
	int funcionar;
	if (val1 < 0)
	{
		funcionar = 1;
	}else
	{
		funcionar = 0;
	}
	return funcionar;
}

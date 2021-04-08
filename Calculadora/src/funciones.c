#include <stdio.h>

void menu(int opcionUsuario, int* devolucion)
{

}

int suma(int valor1, int valor2, int* valresultado)
{
	int funcionar;
	if (valor1 != 0 || valor2 != 0)
	{
		*valresultado = valor1 + valor2;
		funcionar = 1;
	}else{
		funcionar = 0;
	}
	return funcionar;
}


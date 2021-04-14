#include <stdio.h>
#include "menu.h"

int main() {
	setbuf(stdout,NULL);

	int retorno;

	retorno = menuUsuario();

	if(retorno)
	{
		printf("Saliendo de la calculadora");
	}else
	{
		printf("Por algun motivo no hizo ningun calculo o no obtuvo resultados");
	}


	return 0;
}

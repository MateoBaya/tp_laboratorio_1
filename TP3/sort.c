#include <stdlib.h>
#include <string.h>
#include "Employee.h"
int compararSalario(void* persona1,void* persona2)
{
	int funcionar=0;
	if(persona1 != NULL && persona2 != NULL)
	{
		if(((Employee*)persona1)->sueldo>((Employee*)persona2)->sueldo)
		{
			funcionar=1;
		}
		if(((Employee*)persona1)->sueldo<((Employee*)persona2)->sueldo)
		{
			funcionar=-1;
		}
	}

	return funcionar;
}

int compararId(void* persona1,void* persona2)
{
	int funcionar=0;
	if(persona1 != NULL && persona2 != NULL)
	{
		if(((Employee*)persona1)->id>((Employee*)persona2)->id)
		{
			funcionar=1;
		}
		if(((Employee*)persona1)->id<((Employee*)persona2)->id)
		{
			funcionar=-1;
		}
	}

	return funcionar;
}

int compararHorasTrabajadas(void* persona1,void* persona2)
{
	int funcionar=0;
	if(persona1 != NULL && persona2 != NULL)
	{
		if(((Employee*)persona1)->horasTrabajadas>((Employee*)persona2)->horasTrabajadas)
		{
			funcionar=1;
		}
		if(((Employee*)persona1)->horasTrabajadas<((Employee*)persona2)->horasTrabajadas)
		{
			funcionar=-1;
		}
	}

	return funcionar;
}

int compararNombres(void* persona1,void* persona2)
{
	int funcionar=0;
	char * nombre1=(char*)malloc(sizeof(char)*128);
	char * nombre2=(char*)malloc(sizeof(char)*128);
	if(persona1 != NULL && persona2 != NULL && nombre1 != NULL && nombre2 != NULL)
	{
		employee_getNombre(((Employee*)persona1), nombre1);
		employee_getNombre(((Employee*)persona2), nombre2);
		if(strcmp(nombre1,nombre2)>0)
		{
			funcionar=1;
		}
		if(strcmp(nombre1,nombre2)<0)
		{
			funcionar=-1;
		}
		free(nombre1);
		free(nombre2);
	}

	return funcionar;
}

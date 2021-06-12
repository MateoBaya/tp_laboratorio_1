#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
Employee* employee_new()
{
	Employee* nuevoEmpleado=NULL;
	nuevoEmpleado=(Employee*)malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id=0;
        strcpy(nuevoEmpleado->nombre," ");
        nuevoEmpleado->horasTrabajadas=0;
        nuevoEmpleado->sueldo=0;
    }

	return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* nuevoEmpleado=employee_new();
	if(nuevoEmpleado!=NULL)
	{
		if(!(
				employee_setId(nuevoEmpleado,atoi(idStr))
				&& employee_setNombre(nuevoEmpleado,nombreStr)
				&& employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr))
				&& employee_setSueldo(nuevoEmpleado,atoi(sueldoStr))
		))
		{
			free(nuevoEmpleado);
			nuevoEmpleado=NULL;
		}
	}
	return nuevoEmpleado;
}

int employee_setId(Employee* this,int id)
{
    int funcionar=0;

    if(this != NULL && id > 0)
    {
        this->id = id;
        funcionar=1;
    }

    return funcionar;
}

int employee_getId(Employee* this,int* id)
{
	int funcionar=0;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		funcionar=1;
	}
	return funcionar;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int funcionar=0;

    if(this != NULL && nombre!=NULL)
    {
    	strcpy(this->nombre,nombre);
        funcionar=1;
    }

    return funcionar;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int funcionar=0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		funcionar=1;
	}
	return funcionar;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int funcionar=0;
	if(this!=NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas=horasTrabajadas;
		funcionar=1;
	}
	return funcionar;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int funcionar=0;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		funcionar=1;
	}
	return funcionar;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int funcionar=0;
	if(this!=NULL && sueldo>0)
	{
		this->sueldo=sueldo;
		funcionar=1;
	}
	return funcionar;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int funcionar=0;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		funcionar=1;
	}
	return funcionar;
}

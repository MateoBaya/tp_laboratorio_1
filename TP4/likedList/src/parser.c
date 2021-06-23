#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int funcionar=0;

	char buffer[4][128];
	Employee * nuevoEmpleado;
	int validarCant;

	if(pFile!=NULL&&pArrayListEmployee!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer),*(buffer+1),*(buffer+2),*(buffer+3));
		while(!(feof(pFile)))
		{
			validarCant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",*(buffer),*(buffer+1),*(buffer+2),*(buffer+3));
			if(validarCant<4)
			{
				printf("ERROR. No se pudo realizar una lectura correcta");
				break;
			}
			nuevoEmpleado=employee_newParametros(*(buffer),*(buffer+1),*(buffer+2),*(buffer+3));
			ll_add(pArrayListEmployee, nuevoEmpleado);
			funcionar=1;
		}
		if(funcionar)
		{
			printf("Carga satisfactoria\n");
		}
	}
    return funcionar;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int funcionar=0;
	Employee nuevoEmpleado;
	Employee*punteroEmpleado;
	char*id=(char*)malloc(sizeof(char)*128);
	char*sueldo=(char*)malloc(sizeof(char)*128);
	char*horasTrabajadas=(char*)malloc(sizeof(char)*128);
	char*nombre=(char*)malloc(sizeof(char)*128);
	int validarCant;
	if(pFile!=NULL&&pArrayListEmployee!=NULL&&id!=NULL&&sueldo!=NULL&&horasTrabajadas!=NULL&&nombre!=NULL)
	{
		while(!(feof(pFile)))
		{
			validarCant=fread(&nuevoEmpleado,sizeof(Employee),1,pFile);
			if(validarCant==1)
			{
				punteroEmpleado=employee_new();
				employee_setId(punteroEmpleado, nuevoEmpleado.id);
				employee_setSueldo(punteroEmpleado, nuevoEmpleado.sueldo);
				employee_setHorasTrabajadas(punteroEmpleado, nuevoEmpleado.horasTrabajadas);
				employee_setNombre(punteroEmpleado, nuevoEmpleado.nombre);

				ll_add(pArrayListEmployee, punteroEmpleado);
			}
			funcionar=1;
		}
	}
    return funcionar;
}

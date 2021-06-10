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
	int contador=0;
	int validarCant;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]\n",*(buffer),*(buffer+1),*(buffer+2),*(buffer+3));

	while(!feof(pFile))
	{
		validarCant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]\n",*(buffer),*(buffer+1),*(buffer+2),*(buffer+3));
		if(validarCant!=4)
		{
			break;
		}
		nuevoEmpleado= employee_newParametros(*(buffer),*(buffer+1),*(buffer+2),*(buffer+3));
		ll_add(*(pArrayListEmployee+contador), nuevoEmpleado);
		contador++;

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

    return 1;
}

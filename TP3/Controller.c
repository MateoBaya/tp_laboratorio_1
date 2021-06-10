#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_general.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE * archivo;
	FILE * archivoNuevo;
		if(pArrayListEmployee != NULL && path != NULL)
		{
			archivo=fopen(path,"r");
			if(archivo==NULL)
			{
				printf("No se pudo abrir el archivo");
			}else
			{
				archivoNuevo=fopen("./dataT.csv","w");
				if(archivoNuevo==NULL)
				{
					printf("No se pudo abrir el archivo en modo escritura");
				}else
				{
					parser_EmployeeFromText(archivo, pArrayListEmployee);
				}
			}

			fclose(archivo);
			fclose(archivoNuevo);
	}
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE * archivo;
	FILE * archivoNuevo;
	if(pArrayListEmployee != NULL && path != NULL)
	{
		archivo=fopen(path,"rb");
		if(archivo==NULL)
		{
			printf("No se pudo abrir el archivo");
		}else
		{
			archivoNuevo=fopen("./dataB.bin","wb");
			if(archivoNuevo==NULL)
			{
				printf("No se pudo abrir el archivo en modo escritura");
			}else
			{
				parser_EmployeeFromBinary(archivo, pArrayListEmployee);
			}
		}
	fclose(archivo);
	fclose(archivoNuevo);
	}
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int funcionar=0;
	int auxInt;
	char * auxTexto;
	int acumId=-1;
	int len;
	Employee empleadoAuxiliar;
	Employee * punteroAuxiliar;
	if(pArrayListEmployee != NULL)
	{

		if(ll_isEmpty(pArrayListEmployee))
		{
			acumId=0;
		}else
		{
			len=ll_len(pArrayListEmployee);
			for(int i=0;i<len;i++)
			{
				punteroAuxiliar=(Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(punteroAuxiliar, &auxInt);
				if(auxInt>acumId)
				{
					acumId=auxInt;
				}
			}
		}

		employee_setId(&empleadoAuxiliar, acumId);

		printf("Cargue nombre: ");
		cargarTexto(auxTexto);
		employee_setNombre(&empleadoAuxiliar, auxTexto);

		printf("Cargue horas trabajadas: ");
		cargarNumero(&auxInt);
		employee_setHorasTrabajadas(&empleadoAuxiliar, auxInt);

		printf("Cargue salario: ");
		cargarNumero(&auxInt);
		employee_setSueldo(&empleadoAuxiliar, auxInt);

		ll_add(pArrayListEmployee, &empleadoAuxiliar);
		funcionar=1;

	}
    return funcionar;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int funcionar=0;
	int idACambiar;
	int posicion;
	char* auxTexto;
	int auxInt;
	int error;
	Employee empleadoAuxiliar;

	if(pArrayListEmployee != NULL)
	{
		printf("Ingrese Id de Empleado a cambiar:");
		do
		{
			error = cargarNumero(&idACambiar);
		}while(error);
		posicion=ll_indexOf(pArrayListEmployee, &idACambiar);

		employee_setId(&empleadoAuxiliar, idACambiar);

		printf("Cargue nombre: ");
		cargarTexto(auxTexto);
		employee_setNombre(&empleadoAuxiliar, auxTexto);

		printf("Cargue horas trabajadas: ");
		cargarNumero(&auxInt);
		employee_setHorasTrabajadas(&empleadoAuxiliar, auxInt);

		printf("Cargue salario: ");
		cargarNumero(&auxInt);
		employee_setSueldo(&empleadoAuxiliar, auxInt);

		ll_set(pArrayListEmployee, posicion, &empleadoAuxiliar);

	}
	return funcionar;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee != NULL)
	{

	}
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee != NULL)
	{

	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee != NULL)
	{

	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee != NULL && path != NULL)
	{

	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee != NULL && path != NULL)
	{

	}
    return 1;
}


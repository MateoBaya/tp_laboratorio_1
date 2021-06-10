#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
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
	char auxTexto;
	Employee empleadoAuxiliar;

	printf("Cargue id: ");
	cargarNumero(&auxInt);
	employee_setId(empleadoAuxiliar, auxInt);

	printf("Cargue nombre: ");
	cargarTexto(&auxTexto);
	employee_setNombre(empleadoAuxiliar, auxTexto);

	printf("Cargue horas trabajadas: ");
	cargarNumero(&auxInt);
	employee_setHorasTrabajadas(empleadoAuxiliar, auxInt);

	printf("Cargue salario: ");
	cargarNumero(&auxInt);
	employee_setSueldo(empleadoAuxiliar, auxInt);

	ll_add(pArrayListEmployee, empleadoAuxiliar);

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
    return 1;
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
    return 1;
}


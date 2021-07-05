#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int funcionar=0;
	FILE * archivo;
	if(pArrayListEmployee != NULL && path != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			printf("Ya tenia datos, se copiaron a un archivo auxiliar\n");
			controller_saveAsText("./dataAux.csv", pArrayListEmployee);
			ll_clear(pArrayListEmployee);
		}
		archivo=fopen(path,"r");
		if(archivo==NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}else
		{
			parser_EmployeeFromText(archivo, pArrayListEmployee);
			funcionar=1;
		}

		fclose(archivo);
	}
    return funcionar;
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
	int funcionar=0;
	FILE * archivo;
	if(pArrayListEmployee != NULL && path != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			printf("Ya tenia datos, se copiaron a un archivo auxiliar\n");
			controller_saveAsText("./dataAux.csv", pArrayListEmployee);
			ll_clear(pArrayListEmployee);
		}
		archivo=fopen(path,"rb");
		if(archivo==NULL)
		{
			printf("No se pudo abrir el archivo");
		}else
		{
			parser_EmployeeFromBinary(archivo, pArrayListEmployee);
			funcionar=1;
		}
		if(funcionar)
		{
			printf("Datos cargados correctamente");
		}
		fclose(archivo);
	}
    return funcionar;
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
	char auxTexto[128];
	int acumId;
	int error;
	int len;
	Employee*punteroAuxiliar;
	Employee*nuevoEmleado=employee_new();

	if(pArrayListEmployee!=NULL&&nuevoEmleado!=NULL)
	{
		acumId=-1;

		if(ll_isEmpty(pArrayListEmployee))
		{
			acumId=0;
		}else
		{
			len=ll_len(pArrayListEmployee);
			if(len == -1)
			{
				printf("ERROR. No se pudo averiguar el tamaño");
			}
			else
			{

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
		}

		acumId++;

		employee_setId(nuevoEmleado, acumId);

		do
		{
			printf("Cargue nombre: ");
			error=cargarNombre(auxTexto);
			if(error)
			{
				printf("Ese nombre no esta formado por caracteres correctos\n");
			}
		}while(error);
		employee_setNombre(nuevoEmleado, auxTexto);
		free(auxTexto);

		do
		{
			printf("Cargue horas trabajadas: ");
			cargarNumero(&auxInt);
			error=numeroPos(auxInt);
		}while(!error);

		employee_setHorasTrabajadas(nuevoEmleado, auxInt);

		do
		{
			printf("Cargue salario: ");
			cargarNumero(&auxInt);
			error=numeroPos(auxInt);
		}while(!error);
		employee_setSueldo(nuevoEmleado, auxInt);


		if(ll_add(pArrayListEmployee, nuevoEmleado))
		{
			printf("ERROR. No se puede cargar\n");
		}

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
	int auxId;
	Employee * auxEmpleado;
	int len;
	char auxTexto[128];
	int auxInt;
	int error;
	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee))
		{
			printf("ERROR. No hay empleados cargados\n");
		}
		else
		{
			controller_ListEmployee(pArrayListEmployee);
			printf("Ingrese Id de Empleado a cambiar:");
			do
			{
				error = cargarNumero(&idACambiar);
			}while(error);

			error=1;
			len=ll_len(pArrayListEmployee);
			for (int i=0;i<len;i++)
			{
				auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(auxEmpleado, &auxId);
				if(auxId == idACambiar)
				{
					error=0;
					break;
				}
			}
			if(error)
			{
				printf("ERROR. Id no econtrado");
			}
			else
			{
				do
				{
					printf("Que desea cambiar [1]-Nombre [2]-Horas trabajadas [3]-Salario [4]-Todo: ");
					cargarNumero(&auxInt);
					error=valorConRango(auxInt, 1, 4);
				}while(error==0);

				switch(auxInt)
				{
				case 1:
					do
					{
						printf("Cargue nuevo nombre: ");
						error=cargarTexto(auxTexto);
					}while(!error);
					employee_setNombre(auxEmpleado, auxTexto);
					funcionar=1;
					break;
				case 2:
					do
					{
						printf("Cargue nuevas horas trabajadas: ");
						error=cargarNumero(&auxInt);
					}while(error);
					employee_setHorasTrabajadas(auxEmpleado, auxInt);
					funcionar=1;
					break;
				case 3:
					do
					{
						printf("Cargue nuevo salario: ");
						error=cargarNumero(&auxInt);
					}while(error);
					employee_setSueldo(auxEmpleado, auxInt);
					funcionar=1;
					break;
				case 4:
					do
					{
						printf("Cargue nuevo nombre: ");
						error=cargarTexto(auxTexto);
					}while(!error);
					employee_setNombre(auxEmpleado, auxTexto);
					free(auxTexto);
					do
					{
						printf("Cargue nuevas horas trabajadas: ");
						error=cargarNumero(&auxInt);
					}while(error);
					employee_setHorasTrabajadas(auxEmpleado, auxInt);
					do
					{
						printf("Cargue nuevo salario: ");
						error=cargarNumero(&auxInt);
					}while(error);
					employee_setSueldo(auxEmpleado, auxInt);

					funcionar=1;
					break;
				}

			}
		}
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
	int funcionar=0;
	int i;
	int len;
	int error;
	int idACambiar;
	int auxId;
	int salario;
	int horasTrabajadas;
	char nombre[128];
	Employee*auxEmpleado;
	char decidir;
	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee))
		{
			printf("ERROR. No hay empleados ingesados");
		}
		else
		{
			controller_ListEmployee(pArrayListEmployee);
			printf("Ingrese Id de Empleado a borrar:");
			do
			{
				error = cargarNumero(&idACambiar);
			}while(error);

			error=1;
			len=ll_len(pArrayListEmployee);
			for (i=0;i<len;i++)
			{
				auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(auxEmpleado, &auxId);
				if(auxId == idACambiar)
				{
					error=0;
					break;
				}
			}
			if(error)
			{
				printf("ERROR. No se pudo encontrar al empleado solicitado");
			}
			else
			{
				employee_getHorasTrabajadas(auxEmpleado, &horasTrabajadas);
				employee_getSueldo(auxEmpleado, &salario);
				employee_getNombre(auxEmpleado, nombre);
				printf("Id: %d Nombre: %s Horas trabajadas: %d Salario: %d\n",auxId,nombre,horasTrabajadas,salario);
				do
				{
					printf("¿Seguro que quiere borrar este empleado? s/n ");
					cargarCaracter(&decidir);
					error=validarSoN(decidir);
				}while(!error);
				if(decidir == 's')
				{
					ll_remove(pArrayListEmployee, i);
					funcionar=1;
				}
			}
		}
	}
    return funcionar;
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
	int funcionar=0;
	int len;
	Employee*punteroAuxiliar;
	int id;
	int sueldo;
	int horasTrabajadas;
	char nombre[128];
	if(pArrayListEmployee!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee))
		{
			printf("ERROR. No hay empleados cargado\n");
		}
		else
		{
			printf(" Id   |     Nombre    |   Horas  |   Sueldo  \n");
			len=ll_len(pArrayListEmployee);
			for(int i=0;i<len;i++)
			{
				punteroAuxiliar=(Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(punteroAuxiliar,&id);
				employee_getHorasTrabajadas(punteroAuxiliar,&horasTrabajadas);
				employee_getSueldo(punteroAuxiliar,&sueldo);
				employee_getNombre(punteroAuxiliar,nombre);
				printf("%-5d  %-18s  %-5d      %-10d\n",id,nombre,horasTrabajadas,sueldo);
				funcionar=1;
			}
		}
	}
    return funcionar;
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
	int funcionar=0;
	int auxNum;
	int ordenamiento;
	int error;
	int(*pFunc)(void*,void*)=NULL;
	int num;
	if(pArrayListEmployee != NULL)
	{
		if(ll_isEmpty(pArrayListEmployee))
		{
			printf("ERROR. No hay empleados cargado\n");
		}
		else
		{
			do
			{
				printf("Elija el ordenamiento [1]-Id [2]-Salario [3]-Horas trabajadas [4]-Nombre: ");
				cargarNumero(&ordenamiento);
				error=valorConRango(ordenamiento,1,4);
			}while(error==0);

			do
			{
				printf("Elija la orientacion del ordenamiento [1]-Menor a mayor [0]-Mayor a menor: ");
				cargarNumero(&auxNum);
				error=valorConRango(auxNum, 0, 1);
			}while(error==0);
			switch(ordenamiento)
			{
				case 1:
					pFunc=compararId;
					break;
				case 2:
					pFunc=compararSalario;
					break;
				case 3:
					pFunc=compararHorasTrabajadas;
					break;
				case 4:
					pFunc=compararNombres;
					break;
			}
			num=ll_sort(pArrayListEmployee,pFunc,auxNum);
			if(num==-1)
			{
				printf("ERROR. No se pudo realizar la ordenacion\n");
			}
			funcionar=1;
		}
	}
    return funcionar;
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
	int funcionar=0;
	int id;
	int salario;
	int horasTrabajadas;
	char nombre[128];
	int len;
	Employee*empleado;
	FILE * archivo;
	if(pArrayListEmployee!=NULL&&path!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee))
		{
			printf("ERROR. No hay empleados cargados\n.");
		}
		else
		{
			len=ll_len(pArrayListEmployee);
			if(len<1000)
			{
				archivo=fopen(path,"a");
				if(archivo==NULL)
				{
					printf("ERROR. El archivo no se pudo abrir/crear\n");
				}
				else
				{
					for(int i=0;i<len;i++)
					{
						empleado=(Employee*)ll_get(pArrayListEmployee, i);
						employee_getId(empleado, (&id+1000));
						employee_getSueldo(empleado, &salario);
						employee_getNombre(empleado, nombre);
						employee_getHorasTrabajadas(empleado, &horasTrabajadas);
						fprintf(archivo,"%d, %s, %d, %d\n",id,nombre,horasTrabajadas,salario);
						funcionar=1;
					}
					fclose(archivo);
				}
			}
			else
			{
				archivo=fopen(path,"w");
				if(archivo==NULL)
				{
					printf("ERROR. El archivo no se pudo abrir/crear");
				}
				else
				{
					fprintf(archivo,"id,nombre,horasTrabajadas,sueldo\n");
					for(int i=0;i<len;i++)
					{
						empleado=(Employee*)ll_get(pArrayListEmployee, i);
						employee_getId(empleado, &id);
						employee_getSueldo(empleado, &salario);
						employee_getNombre(empleado, nombre);
						employee_getHorasTrabajadas(empleado, &horasTrabajadas);
						fprintf(archivo,"%d, %s, %d, %d\n",id,nombre,horasTrabajadas,salario);
						funcionar=1;
					}
					fclose(archivo);
				}
			}
			if(funcionar)
			{
				printf("Guardados los datos correctamente\n");
			}
		}
	}
    return funcionar;
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
	int funcionar=0;
	Employee*empleado;
	FILE*archivo;
	if(pArrayListEmployee!=NULL&&path!=NULL)
	{
		if(ll_isEmpty(pArrayListEmployee))
		{
			printf("ERROR. No hay empleados cargados");
		}
		else
		{

			archivo=fopen(path,"wb");
			if(archivo==NULL)
			{
				printf("El archivo no se pudo abrir/crear");
			}
			else
			{
				for(int i=0;i<ll_len(pArrayListEmployee);i++)
				{
					empleado=ll_get(pArrayListEmployee,i);
					fwrite(empleado,sizeof(Employee),1,archivo);
					funcionar=1;
				}
			fclose(archivo);
			}
			if(funcionar)
			{
				printf("Datos guardados los datos correctamente");
			}
		}
	}
    return funcionar;
}


#include "utn_estructura.h"

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAlta(eTrabajadores varGeneral[],int len,int * id)
{
	int funcionar=0;
	int i=0;
	int error;
	int auxEntero;
	float auxFloat;
	char auxTexto[MAXCHAR];

	while(varGeneral[i].isEmpty==0)
	{
		i++;
	}
	if(varGeneral[i].isEmpty==1)
	{
		*id=*id+1;
		varGeneral[i].idTrabajador=*id;

		do
		{
			printf("Cargue Sector: ");
			error = cargarNumero(&auxEntero);
		}while(error);

		varGeneral[i].sector = auxEntero;

		do
		{
			printf("Cargue Nombre: ");
			error=cargarTexto(auxTexto);
		}while(error==0);
		strcpy(varGeneral[i].nombre,auxTexto);

		do
		{
			printf("Cargue apellido: ");
			error=cargarTexto(auxTexto);
		}while(error==0);
		strcpy(varGeneral[i].apellido,auxTexto);

		do
		{
			printf("Cargue salario: ");
			error = cargarFloat(&auxFloat);
		}while(error);
		varGeneral[i].salario = auxFloat;


		varGeneral[i].isEmpty=0;
	}

	return funcionar;
}

int ABMLectura(eTrabajadores varGeneral[],int len)
{
	int funcionar=0;
	int flagTrabajadores=1;


	for(int i=0;i<len;i++)
	{

		if(varGeneral[i].isEmpty==0)
		{

			if (flagTrabajadores)
			{
			printf("\n************************************************************************************************\n");
			printf("   Id   |   Nombre   |   Apellido  |         Salario         |  Sector  \n");
			printf("************************************************************************************************\n");
			flagTrabajadores=0;
			}
			mostrarEstructura(varGeneral,i);
			funcionar=1;
		}

	}

		if(flagTrabajadores==0)
		{
			printf("*************************************************************************************************\n");
		}else
		{
			printf("ERROR. No habia trabajadores que mostrar");
		}
	return funcionar;
}

int ABMBaja(eTrabajadores varGeneral[],int len)
{
	int funcionar=0;
	int posicionACambiar;
	int flagTrabajador=1;

	if(varGeneral != NULL)
		{
		for(int i=0; i<len;i++)
		{
			if(varGeneral[i].isEmpty == 0)
			{
				flagTrabajador=0;
			}
		}

		if(flagTrabajador)
		{
			printf("ERROR. No hay trabajadores cargados que bajar.");
		}else
		{
			posicionACambiar=buscarId(varGeneral,len);
			if(posicionACambiar==-1)
			{
				printf("No se encontro el id, reintente");
			}else{
				printf("   Id   |   Nombre   |   Apellido  |         Salario         |  Sector  \n");
				if(validarIntencionUsuario(varGeneral, posicionACambiar, "trabajador", "dar de baja"))
				{
					varGeneral[posicionACambiar].isEmpty = 1;
				}
			}
		}
	}
	return funcionar;
}

int ABMModificar(eTrabajadores varGeneral[],int len,const char * deseoModificar,const char * mensajeOpcion1,
const char * mensajeOpcion2,const char * mensajeOpcion3,const char * mensajeOpcion4)
{
	int funcionar=0;
	int posicionACambiar;
	int elegir;
	int error;
	char auxTexto[MAXCHAR];
	float auxFloat;
	int auxEntero;
	if(varGeneral != NULL)
	{
		posicionACambiar = buscarId(varGeneral, len);
		if(posicionACambiar==-1)
		{
			printf("No se encontro el legajo, reintente");
		}else{
			printf("   Id   |   Nombre   |   Apellido  |         Salario         |  Sector  \n");
			if(validarIntencionUsuario(varGeneral, posicionACambiar, "ESTRUCTURA", "modificar"))
			{

				do
				{
				printf("Desea modificar %s, [1]-Nombre, [2]-Apellido, [3]-Salario, [4]-Sector, [5]-Salir: ",deseoModificar);
				cargarNumero(&elegir);
					switch(elegir)
					{
						case 1:
							printf("Ingrese un %s nuevo: ",mensajeOpcion1);
							error = cargarTexto(auxTexto);
							if (error==0)
							{
								printf("ERROR. Demasiados caracteres, reintente.");
							}else
							{
								strcpy(varGeneral[posicionACambiar].nombre,auxTexto);
							}
							break;
						case 2:
							printf("Ingrese un %s nuevo: ",mensajeOpcion2);
							error = cargarTexto(auxTexto);
							if (error==0)
							{
								printf("ERROR. Demasiados caracteres, reintente.");
							}else
							{
								strcpy(varGeneral[posicionACambiar].apellido,auxTexto);
							}
							break;
						case 3:
							printf("Ingrese un %s nuevo: ",mensajeOpcion3);
							error = cargarFloat(&auxFloat);
							if(error == 0)
							{
								varGeneral[posicionACambiar].salario = auxFloat;
							}
							break;
						case 4:
							printf("Ingrese un %s nuevo: ",mensajeOpcion4);
							error = cargarNumero(&auxEntero);
							if(error == 0)
							{
								varGeneral[posicionACambiar].sector = auxEntero;
							}
							break;
						case 5:
							break;
						default:
							printf("ERROR, no eligio un valor dentro del rango");
							elegir=0;
							break;
					}
				}while(elegir == 0);
			}
		}
	}

	return funcionar;
}

int ABMinformes(eTrabajadores varGeneral[],int len)
{
	int funcionar=0;
	int decidir;
	int error;
	do
	{
	printf("[1]-Ordenamiento por Apellido y Sector, [2]-Mostrar promedio salario y trabajadores con mayor salario a promedio, [3]-Salir: ");
	cargarNumero(&decidir);
	switch(decidir)
		{
		case 1:
			do
			{
				printf("Tipo de orden [1]-Ascendente [0]-Descendente: ");
				error=cargarNumero(&decidir);
			}while(error);
			ordenarPorApellidoSector(varGeneral,len,decidir);
			ABMLectura(varGeneral, len);
			break;
		case 2:
			promediar(varGeneral, len);
			break;
		case 3:
			break;
		default:
			printf("ERROR. Valor fuera de rango");
			break;
		}
	}while(decidir!=3);

	return funcionar;
}

///////////////////////////////////BUSQUEDA_INFORMACION////////////////////////////////////////////////

int mostrarEstructura(eTrabajadores varGeneral[],int i)
{
	int funcionar=0;
	printf("   %-5d     %-10s   %-10s     %-15f          %-5d\n",varGeneral[i].idTrabajador,
			varGeneral[i].nombre,varGeneral[i].apellido,varGeneral[i].salario,varGeneral[i].sector);
	return funcionar;
}

int buscarId(eTrabajadores varGeneral[],int len)
{
	int posicion=-1;
	int i;
	int id;
	if(varGeneral != NULL)
	{
		printf("Id a buscar: ");
		cargarNumero(&id);
		for(i=0;i<len;i++)
		{
			if(varGeneral[i].isEmpty==0)
			{
				if(varGeneral[i].idTrabajador == id)
				{
					posicion = i;
					break;
				}
			}
		}
	}
	return posicion;
}

int buscarDescripcion(eTrabajadores varGeneral[],int len)
{
	int id=-1;
	int i;
	char auxString[MAXCHAR];
	printf("Escriba descripcion: ");
	scanf("%s",auxString);
	for(i=0;i<len;i++)
	{
		if(varGeneral[i].isEmpty==0)
		{
			if(strcmp(auxString,varGeneral[i].apellido)==0)
			{
				id = varGeneral[i].idTrabajador;
				break;
			}
		}
	}

	return id;
}

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarId(eTrabajadores varGeneral[],int len,int numero)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if (varGeneral[i].idTrabajador==numero)
			{
				funcionar=1;
			}
		}
	}
	return funcionar;
}

int validarIntencionUsuario(eTrabajadores varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar)
{
	int funcionar=0;
	char decidir;
	int sinError;
	if(varGeneral != NULL)
	{
		do
		{
			mostrarEstructura(varGeneral, posicionACambiar);
			printf("\nSeguro que quiere %s este %s s/n: ",textoAValidar,mensaje);
			cargarCaracter(&decidir);
			sinError=validarSoN(decidir);
			if(sinError && decidir == 's')
			{
				funcionar = 1;
			}
		}while(sinError==0);
	}
	return funcionar;
}

//////////////////////////////////////////FUNCIONES_ESTRUCTURAS////////////////////////////////////////

int inicializarisEmpty(eTrabajadores varGeneral[],int len)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		for(int i=0;i<len;i++)
		{
			varGeneral[i].isEmpty=1;
		}
		funcionar =1;
	}

	return funcionar;
}


int promediar(eTrabajadores varGeneral[],int len)
{
	int funcionar=0;
	int i;
	float salarioTotal=0;
	int cantidadEmpeleados=0;
	float resultadoPromedio;
	int contadorSalarioMayorAPromedio=0;
	int flagNoVacios=1;
	if(varGeneral != NULL)
	{
		for(i=0;i<len;i++)
		{
			if(varGeneral[i].isEmpty==0)
			{
				flagNoVacios=0;
				cantidadEmpeleados++;
				salarioTotal = varGeneral[i].salario + salarioTotal;
			}
		}

		if(flagNoVacios)
		{
			printf("ERROR. No hubo salarios que calcular\n");
		}else
		{
			printf("El total de los salarios suma: %f\n",salarioTotal);
			resultadoPromedio=salarioTotal/cantidadEmpeleados;
			printf("El promedio es: %f\n",resultadoPromedio);

			for(i=0;i<len;i++)
			{
				if(varGeneral[i].isEmpty == 0)
				{
					if(varGeneral[i].salario > resultadoPromedio)
					{
						contadorSalarioMayorAPromedio++;
					}
				}
			}
			printf("Hay %d trabajadores que tienen mas salario que el promedio\n",contadorSalarioMayorAPromedio);
		}
		funcionar=1;
	}

	return funcionar;
}


///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////


int ordenarPorApellidoSector(eTrabajadores varGeneral[],int len,int orden)
{
	int funcionar=0;
	int aux;
	float auxFloat;
	char auxArrayTexto[MAXCHAR];
	if(varGeneral != NULL)
	{
		if(orden)
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(!varGeneral[i].isEmpty&&!varGeneral[j].isEmpty&&varGeneral[i].sector>varGeneral[j].sector)
					{
						aux=varGeneral[i].idTrabajador;
						varGeneral[i].idTrabajador=varGeneral[j].idTrabajador;
						varGeneral[j].idTrabajador=aux;

						aux=varGeneral[i].sector;
						varGeneral[i].sector=varGeneral[j].sector;
						varGeneral[j].sector=aux;

						auxFloat=varGeneral[i].salario;
						varGeneral[i].salario=varGeneral[j].salario;
						varGeneral[j].salario=auxFloat;

						strcpy(auxArrayTexto,varGeneral[i].nombre);
						strcpy(varGeneral[i].nombre,varGeneral[j].nombre);
						strcpy(varGeneral[j].nombre,auxArrayTexto);

						strcpy(auxArrayTexto,varGeneral[i].apellido);
						strcpy(varGeneral[i].apellido,varGeneral[j].apellido);
						strcpy(varGeneral[j].apellido,auxArrayTexto);
						funcionar=1;
					}
					else if(!varGeneral[i].isEmpty&&!varGeneral[j].isEmpty&&varGeneral[i].sector==varGeneral[j].sector&&strcmp(varGeneral[i].apellido,varGeneral[j].apellido)>0)
					{
						aux=varGeneral[i].idTrabajador;
						varGeneral[i].idTrabajador=varGeneral[j].idTrabajador;
						varGeneral[j].idTrabajador=aux;

						aux=varGeneral[i].sector;
						varGeneral[i].sector=varGeneral[j].sector;
						varGeneral[j].sector=aux;

						auxFloat=varGeneral[i].salario;
						varGeneral[i].salario=varGeneral[j].salario;
						varGeneral[j].salario=auxFloat;

						strcpy(auxArrayTexto,varGeneral[i].nombre);
						strcpy(varGeneral[i].nombre,varGeneral[j].nombre);
						strcpy(varGeneral[j].nombre,auxArrayTexto);

						strcpy(auxArrayTexto,varGeneral[i].apellido);
						strcpy(varGeneral[i].apellido,varGeneral[j].apellido);
						strcpy(varGeneral[j].apellido,auxArrayTexto);
						funcionar=1;
					}
				}
			}
		}
		else
		{
			for(int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(!varGeneral[i].isEmpty&&!varGeneral[j].isEmpty&&varGeneral[i].sector<varGeneral[j].sector)
					{
						aux=varGeneral[i].idTrabajador;
						varGeneral[i].idTrabajador=varGeneral[j].idTrabajador;
						varGeneral[j].idTrabajador=aux;

						aux=varGeneral[i].sector;
						varGeneral[i].sector=varGeneral[j].sector;
						varGeneral[j].sector=aux;

						auxFloat=varGeneral[i].salario;
						varGeneral[i].salario=varGeneral[j].salario;
						varGeneral[j].salario=auxFloat;

						strcpy(auxArrayTexto,varGeneral[i].nombre);
						strcpy(varGeneral[i].nombre,varGeneral[j].nombre);
						strcpy(varGeneral[j].nombre,auxArrayTexto);

						strcpy(auxArrayTexto,varGeneral[i].apellido);
						strcpy(varGeneral[i].apellido,varGeneral[j].apellido);
						strcpy(varGeneral[j].apellido,auxArrayTexto);
						funcionar=1;
					}
					else if(!varGeneral[i].isEmpty&&!varGeneral[j].isEmpty&&varGeneral[i].sector==varGeneral[j].sector&&strcmp(varGeneral[i].apellido,varGeneral[j].apellido)<0)
					{
						aux=varGeneral[i].idTrabajador;
						varGeneral[i].idTrabajador=varGeneral[j].idTrabajador;
						varGeneral[j].idTrabajador=aux;

						aux=varGeneral[i].sector;
						varGeneral[i].sector=varGeneral[j].sector;
						varGeneral[j].sector=aux;

						auxFloat=varGeneral[i].salario;
						varGeneral[i].salario=varGeneral[j].salario;
						varGeneral[j].salario=auxFloat;

						strcpy(auxArrayTexto,varGeneral[i].nombre);
						strcpy(varGeneral[i].nombre,varGeneral[j].nombre);
						strcpy(varGeneral[j].nombre,auxArrayTexto);

						strcpy(auxArrayTexto,varGeneral[i].apellido);
						strcpy(varGeneral[i].apellido,varGeneral[j].apellido);
						strcpy(varGeneral[j].apellido,auxArrayTexto);
						funcionar=1;
					}
				}
			}
		}
	}
	return funcionar;
}


#include <stdio.h>

#include "utn_estructura.h"
#include "utn_general.h"

int menuTrabajadores(eTrabajadores varGeneral[],int len,char texto[])
{
	int eleccionUsuario;
	int funcionar=0;
	int legajo=1000;
	int error;

	if(varGeneral != NULL && texto != NULL)
	{
		do
		{
			printf("\n///////////////////////////////////////////\n");
			printf("///    %-12s                     ///\n",texto);
			printf("///      [1]-ALTA                       ///\n");
			printf("///      [2]-BAJA                       ///\n");
			printf("///      [3]-LECTURA                    ///\n");
			printf("///      [4]-MODIFICAR                  ///\n");
			printf("///      [5]-INFORMAR                   ///\n");
			printf("///      [6]-SALIR                      ///\n");
			printf("///                                     ///\n");
			printf("///////////////////////////////////////////\n");

			fflush(stdin);
			do{
			error = cargarNumero(&eleccionUsuario);
			}while(error!=0);
			switch(eleccionUsuario)
			{
			case 1:
				ABMAlta(varGeneral,len,&legajo);
				funcionar=1;
				break;
			case 2:
				ABMBaja(varGeneral,len);
				funcionar=1;
				break;
			case 3:
				ABMLectura(varGeneral, len);
				funcionar=1;
				break;
			case 4:
				ABMModificar(varGeneral, len, "al trabajador", "nombre", "apellido", "salario", "sector");
				funcionar=1;
				break;
			case 5:
				ABMinformes(varGeneral, len);
				funcionar=1;
				break;
			case 6:
				break;
			default:
				printf("Reingrese, no eligio una opcion valida\n");
				break;
			}
		}while(eleccionUsuario!=6);
	}
	return funcionar;
}


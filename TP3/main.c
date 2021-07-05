#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_general.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int funcionar;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
		printf("\n///////////////////////////////////////////////////////////////////////////////////////////\n");
		printf("///                                                                                     ///\n");
		printf("///    [1]-CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.CSV (MODO TEXTO)     ///\n");
		printf("///    [2]-CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.CSV (MODO BINARIO)   ///\n");
		printf("///    [3]-ALTA DE EMPLEADO                                                             ///\n");
		printf("///    [4]-MODIFICAR DATOS DEL EMPLEADO                                                 ///\n");
		printf("///    [5]-BAJA DE EMPLEADO                                                             ///\n");
		printf("///    [6]-LISTAR EMPLEADOS                                                             ///\n");
		printf("///    [7]-ORDENAR EMPLEADOS                                                            ///\n");
		printf("///    [8]-GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATA.CSV (MODO TEXTO)       ///\n");
		printf("///    [9]-GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATAB.BIN (MODO BINARIO)    ///\n");
		printf("///   [10]-SALIR                                                                        ///\n");
		printf("///                                                                                     ///\n");
		printf("///////////////////////////////////////////////////////////////////////////////////////////\n");
		do
		{
			cargarNumero(&option);
			funcionar=valorConRango(option, 1, 10);
			if(funcionar==0)
			{
				printf("ERROR. Valor fuera de rango");
			}
		}while(funcionar==0);

		fflush(stdin);
        switch(option)
        {
            case 1:
                controller_loadFromText("./data.csv",listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("./dataB.bin", listaEmpleados);
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	controller_saveAsText("./data.csv", listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary("./dataB.bin", listaEmpleados);
            	break;
        }
    }while(option != 10);
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}


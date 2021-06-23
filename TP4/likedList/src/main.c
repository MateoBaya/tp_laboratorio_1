/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_general.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


/*int main(void)
{
	setbuf(stdout,NULL);
	startTesting(1);  //ll_newLinkedList;
	startTesting(2);  //ll_len;
	startTesting(3);  //getNode - test_getNode;
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort

    return 0;
}
*/

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
		printf("///    [8]-GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATAT.CSV (MODO TEXTO)      ///\n");
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

































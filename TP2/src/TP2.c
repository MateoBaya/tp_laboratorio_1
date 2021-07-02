#include <stdio.h>
#include "utn_estructura.h"
#include "utn_menu.h"
#define MAXTRABAJADORES 1000

int main(void)
{
	setbuf(stdout,NULL);
	eTrabajadores varTrabajadores[MAXTRABAJADORES];
	inicializarisEmpty(varTrabajadores, MAXTRABAJADORES);
	menuTrabajadores(varTrabajadores, MAXTRABAJADORES, "Trabajadores");
	return 0;
}

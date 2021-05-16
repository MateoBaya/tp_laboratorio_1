#ifndef UTN_ESTRUCTURA_H_
#define UTN_ESTRUCTURA_H_

#include <stdio.h>
#include <string.h>
#include "utn_general.h"


typedef struct
{
	int idTrabajador;
	char nombre[MAXCHAR];
	char apellido[MAXCHAR];
	float salario;
	int sector;
	int isEmpty;
}eTrabajadores;

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAlta(eTrabajadores varGeneral[],int len,int * id);

int ABMLectura(eTrabajadores varGeneral[],int len);

int ABMBaja(eTrabajadores varAlumno[],int len);

int ABMModificar(eTrabajadores varGeneral[],int len,const char * deseoModificar,const char * mensajeOpcion1,
const char * mensajeOpcion2,const char * mensajeOpcion3,const char * mensajeOpcion4);

int ABMinformes(eTrabajadores varGeneral[],int len);

//////////////////////////////////BUSQUEDA_INFORMACION/////////////////////////////////////////////////

int mostrarEstructura(eTrabajadores varGeneral[],int i);

int buscarId(eTrabajadores varGeneral[],int len);

int buscarDescripcion(eTrabajadores varGeneral[],int len);

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarId(eTrabajadores varGeneral[],int len,int numero);

int validarIntencionUsuario(eTrabajadores varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar);

//////////////////////////////////////////FUNCIONES_ESTRUCTURAS////////////////////////////////////////

int inicializarisEmpty(eTrabajadores varGeneral[],int len);

int promediar(eTrabajadores varGeneral[],int len);


///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////

int ordenarPorApellidoSector(eTrabajadores varGeneral[],int len);

#endif /* UTN_ESTRUCTURA_H_ */

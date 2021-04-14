#ifndef MENU_H_
#define MENU_H_

int menuUsuario();
/* @brief Este Menu pide los valores x, y, pide al usuario que funcion usar y los resultados
 * @return Se utiliza para avisar al usuario si hubo o no funciones bien realizadas
 */

int submenu(int valor1, int valor2, int* valResultado,int* val2Resultado, float* valResultadoFloat, int opcionUsuario);
/* @brief submenu que revisa el valor elegido por el usuario, que significara en un switch de funciones matematicas
 * @param valor1 Toma el primer valor dado por el usuario en main
 * @param valor2 Toma el segundo valor dado por el usuario en main
 * @param valResultado Es un puntero que pasara el resultado de la funcion una variable en main
 * @param valResultadoFloat Es un puntero que pasara el resultado de la funcion una variable en main, se usa para las varibles float
 * @param opcionUsuario Revisa el numero ingresado por el usuario en main para pasarlo por un switch
 * @return Se utiliza para saber si la funcion ocurrio correctamente, o si hubo un problema
 */


#endif /* MENU_H_ */

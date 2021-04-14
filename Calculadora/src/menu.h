#ifndef MENU_H_
#define MENU_H_

int menuUsuario();
/* @brief Este Menu pide los valores x, y, pide al usuario que funcion usar y los resultados
 * El menu va a analizar el return del submenu dentro del case 4
 * Si el return es 1, muestra los valores calculados y el resultado entero
 * Si el return es 2, muestra los valores calculados y el resultado float
 * Si el return es distinto, se pregunta cual funcion realizo el usuario, en caso de ser suma la respuesta es una y si es resta es otra, etc.
 * En el caso de haberse hecho un factorial, hace switch de los resultados
 * Si el switch es 9 significa que no hubo numeros positivos, etc.
 * @return Se utiliza para avisar al usuario si hubo (return=1) o no (return=0) funciones bien realizadas
 */

int submenu(int valor1, int valor2, int* valResultado,int* val2Resultado, float* valResultadoFloat, int opcionUsuario);
/* @brief submenu que revisa el valor elegido por el usuario, que significara en un switch de funciones matematicas
 * @param valor1 Toma el primer valor dado por el usuario en main
 * @param valor2 Toma el segundo valor dado por el usuario en main
 * @param valResultado Es un puntero que pasara el resultado de la funcion una variable en main
 * @param valResultadoFloat Es un puntero que pasara el resultado de la funcion una variable en main, se usa para las varibles float
 * @param opcionUsuario Revisa el numero ingresado por el usuario en main para pasarlo por un switch
 * @return Se utiliza para saber si la funcion ocurrio correctamente, o si hubo un problema
 * return = 0 Significa que no funciono
 * return = 1 Significa que funciono y que es un valor entero
 * return = 2 Significa que funciono y que es un valor entero
 * return puede tener calores como 7, 9, 11 y 13, algo particular del factorial, se analiza en el menuUsuario
 */


#endif /* MENU_H_ */

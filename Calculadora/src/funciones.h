#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int suma(int valor1,int valor2,int* valResultado);
/* @brief Muestra el resultado de una suma de dos valores
 * @param valor1 Primer valor ingresado a sumarse
 * @param valor2 Segundo valor ingresado a sumarse
 * @param valresultado es el puntero que contiene el resultado
 * @return Es utilizado para mostrarle al usuario que no se ha hecho la suma con return = 0, si funciono va return = 1
 */

int resta(int valor1, int valor2, int* valResultado);
/* @brief Muestra el resultado de una resta de dos valores
 * @param valor1 Primer valor ingresado a restarse
 * @param valor2 Segundo valor ingresado a restarse
 * @param valresultado es el puntero que contiene el resultado
 * @return Es utilizado para mostrarle al usuario que no se ha hecho la resta con return = 0, si funciono va return = 1
 */

int multiplicar(int valor1, int valor2, int* valResultado);
/* @brief Muestra el resultado de una multiplicación de dos valores
 * @param valor1 Primer valor ingresado a multiplicarse
 * @param valor2 Segundo valor ingresado a multiplicarse
 * @param valresultado es el puntero que contiene el resultado
 * @return Es utilizado para mostrarle al usuario que no se ha hecho la multiplicación con return = 0, si funciono va return = 1
 */

int dividir(int valor1, int valor2, float* valResultado);
/* @brief Muestra el resultado de una división de dos valores
 * @param valor1 Primer valor ingresado a dividirse
 * @param valor2 Segundo valor ingresado a dividirse
 * @param valresultado es el puntero que contiene el resultado
 * @return Es utilizado para mostrarle al usuario que no se ha hecho la división con return = 0, si funciono va return = 1
 */

int factorial(int valor1,int valor2, int* valResultado, int* val2Resultado);
/* @brief Muestra el resultado del factorial de un valor
 * @param valor1 Primer valor ingresado
 * @param valor2 Segundo valor ingresado
 * @param valresultado es el puntero que contiene el resultado
 * @param val2Resultado es el puntero que contiene el segundo resultado
 * @return Es utilizado para mostrarle al usuario que no se ha hecho el factorial con return = 0, si funciono va return = 1
 */

#endif /* FUNCIONES_H_ */

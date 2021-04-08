#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int nadaIgual0(int valor1, int valor2);
/* @brief Confirma si valor1 y valor 2 son distintos de 0
 * @param valor1 obtenido de main
 * @param valor2 obtenido de main
 * @return El valor de return es 0 si no paso por la funcion
 */
int unoIgual0(int valor1, int valor2);
/* @brief Confirma si valor1 O valor 2 son distintos de 0
 * @param valor1 obtenido de main
 * @param valor2 obtenido de main
 * @return El valor de return es 0 si no paso por la funcion
 */

int validarSoN(int* respuestaUsuario);
/* @brief Realiza un printf que pide al usuario un s O n
 * @param respuestaUsuario es un puntero en caso de necesidad de guardar la respuesta
 * @return El valor de return es 0 si no paso por la funcion, si no es s o n
 */

int numeroPos(int val1);
/* @brief Confirma si valor1 es positivo, igual o mayor a 0
 * @param val1 valor obtenido de main
 * @return El valor de return es 0 si no paso por la funcion
 */

int numeroNeg(int val1);
/* @brief Confirma si valor1 es menor a 0, o sea negativo
 * @param val1 valor obtenido de main
 * @return El valor de return es 0 si no paso por la funcion
 */
#endif /* VALIDACIONES_H_ */

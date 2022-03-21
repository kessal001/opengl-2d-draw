#ifndef LIBMATH_C
#define LIBMATH_C
#include <GL/freeglut_std.h>
#endif
/**
 * @brief Calculate the product between two matrices 3x3;
 *
 * @param first The first matrix
 * @param second The second matrix
 * @param result The result matrix
 */
void multiplyMatrices(float first[3][3], float second[3][3],
                      float result[3][3]);
/**
 * @brief Arrotonda all'intero più vicino
 * 
 * @param n Numero
 * @param factor Valore più vicino a cui arrotondare
 * @return int Numero arrotondato
 */
int RoundVertex(int n, int factor);
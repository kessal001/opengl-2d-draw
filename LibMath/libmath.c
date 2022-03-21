#include <GL/freeglut_std.h>
void multiplyMatrices(float first[3][3], float second[3][3],
                      float result[3][3]) {

  // Initializing elements of matrix mult to 0.
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      result[i][j] = 0;
    }
  }

  // Multiplying first and second matrices and storing it in result
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        result[i][j] += first[i][k] * second[k][j];
      }
    }
  }
}

int RoundVertex(int n,int factor) {
  int rounded = n + abs((n % factor) - factor);
  return rounded;
}
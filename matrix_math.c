#include <stdio.h>

#define  MAXDATA 1024

typedef struct {
  double data[MAXDATA];
  int nrows;
  int ncols;
} Matrix;

void printmat(Matrix M);
Matrix matrixmult(Matrix A, Matrix B);

int main(int argc, char const *argv[]) {
  Matrix A = { { 1.2, 2.3,
                 3.4, 4.5,
                 5.6, 6.7},
               3,
               2};
  Matrix B = { {5.5, 6.6, 7.7,
                1.2, 2.1, 3.3},
               2,
               3};
  printf("Printing Matrix A\n");
  printmat(A);
  printf("Printing Matrix B\n");
  printmat(B);

  Matrix C = matrixmult(A, B);
  printf("Printing Matrix C\n");
  printmat(C);
  return 0;
}

void printmat(Matrix M)
{
  int i;
  int j;
  for (i=0; i < M.nrows; i++) {
    for (j=0; j < M.ncols; j++) {
      printf("%.2f ", M.data[j + (i * M.ncols)]);
    }
    printf("\n");
  }
}

Matrix matrixmult(Matrix A, Matrix B)
{
  int i;
  int j;
  int k=0;

  Matrix C = {{}, A.nrows, B.ncols};
    for (i=0; i < A.nrows; i++) {
        for (j=0; j < B.ncols; j++) {
           printf("Cell C[%d] = A[%d] * B[%d] + A[%d] * B[%d]\n", k, (i * A.ncols), j, (i * A.ncols) + 1, (B.ncols + j));
           C.data[k] = A.data[i * A.ncols] * B.data[j] + A.data[(i * A.ncols)+1] * B.data[B.ncols + j];
           k++;
        }
    }

  return C;
}

/* Output:
➜  c ./go
Printing Matrix A
1.20 2.30
3.40 4.50
5.60 6.70
Printing Matrix B
5.50 6.60 7.70
1.20 2.10 3.30
Cell C[0] = A[0] * B[0] + A[1] * B[3]
Cell C[1] = A[0] * B[1] + A[1] * B[4]
Cell C[2] = A[0] * B[2] + A[1] * B[5]
Cell C[3] = A[2] * B[0] + A[3] * B[3]
Cell C[4] = A[2] * B[1] + A[3] * B[4]
Cell C[5] = A[2] * B[2] + A[3] * B[5]
Cell C[6] = A[4] * B[0] + A[5] * B[3]
Cell C[7] = A[4] * B[1] + A[5] * B[4]
Cell C[8] = A[4] * B[2] + A[5] * B[5]
Printing Matrix C
9.36 12.75 16.83
24.10 31.89 41.03
38.84 51.03 65.23 */
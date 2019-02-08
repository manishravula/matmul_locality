#include <stdlib.h>

// define the matrix dimensions A is MxP, B is PxN, and C is MxN
 #define M 32
 #define N 32
 #define P 32

 // calculate C = AxB
void matmul(float **A, float **B, float **C) 
{

	float sum0, sum1, sum2, sum3;
	int   i;
	int   j;
	int   k;


	for (i=0; i<M; i = i + 2) 
	{	 
		for (j=0; j<N; j = j + 2) 
		{
			sum0 = 0.0f; // temporary value
			sum1 = 0.0f;
			sum2 = 0.0f;
			sum3 = 0.0f;
			for (k=0; k<P; k++) 
			{

				sum0 += A[i][k]*B[k][j];
				sum1 += A[i][k]*B[k][j+1];
				sum2 += A[i+1][k]*B[k][j];
				sum3 += A[i+1][k]*B[k][j+1];
			}	
			C[i][j] = sum0;
			C[i][j+1] = sum1;
			C[i+1][j] = sum2;
			C[i+1][j+1] = sum3;
		}
	}
		
}
// function to allocate a matrix on the heap
// creates an mXn matrix and returns the pointer.
                                                                       
// the matrices are in row-major order.
void create_matrix(float*** A, int m, int n) 
{
	float **T = 0;
	int i;

	T = (float**)malloc( m*sizeof(float*));
	for ( i=0; i<m; i++ ) {
		T[i] = (float*)malloc(n*sizeof(float));
	}
	*A = T;
}

int main() 
{
	float** A;
	float** B;
	float** C;

	create_matrix(&A, M, P);
	create_matrix(&B, P, N);
	create_matrix(&C, M, N);

	// assume some initialization of A and B
	// think of this as a library where A and B are
	// // inputs in row-major format, and C is an output
	// in row-major.


	matmul(A, B, C);
														
	return (0);
}
                                                                                                                







#include <stdlib.h>

// define the matrix dimensions A is MxP, B is PxN, and C is MxN
 #define M 4096
 #define N 4096
 #define P 4096

void create_matrix(float*** A, int m, int n);
 // calculate C = AxB
void matmul(float **A, float **B, float **C) 
{

	float sum;
	int   i;
	int   j;
	int   k;

	float **D;
	create_matrix(&D, M, N);

	for (i = 0; i < N ; i++)
	{
		for (int j = 0; j < M ; j ++)
		{
			D[j][i] = B[i][j];
		}
	}


	for (i=0; i<M; i++)
	{	
		for (i=0; i<M; i++) 
		{	 
			for (j=0; j<N; j++) 
			{
	
				sum = 0.0f; // temporary value
				for (k=0; k<P; k++) 
				{

					sum += A[i][k]*D[j][k];
				}	
				C[i][j] = sum;
			}
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
                                                                                                                







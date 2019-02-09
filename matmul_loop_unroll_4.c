#include <stdlib.h>

// define the matrix dimensions A is MxP, B is PxN, and C is MxN
 #define M 512
 #define N 512
 #define P 512

 // calculate C = AxB
void matmul(float **A, float **B, float **C) 
{

	float sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7,sum8, sum9,sum10,sum11,sum12,sum13,sum14,sum15;
	int   i;
	int   j;
	int   k;


	for (i=0; i<M; i = i + 4) 
	{	 
		for (j=0; j<N; j = j + 4) 
		{
			sum0 = 0.0f; // temporary value
			sum1 = 0.0f;
			sum2 = 0.0f;
			sum3 = 0.0f;
			sum4 = 0.0f;
			sum5 = 0.0f;
			sum6 = 0.0f;
			sum7 = 0.0f;
			sum8 = 0.0f;
			sum9 = 0.0f;
			sum10 = 0.0f;
			sum11 = 0.0f;
			sum12 = 0.0f;
			sum13 = 0.0f;
			sum14 = 0.0f;
			sum15 = 0.0f;
			for (k=0; k<P; k++) 
			{

				sum0 += A[i][k]*B[k][j];
				sum1 += A[i][k]*B[k][j+1];
				sum2 += A[i][k]*B[k][j+2];
				sum3 += A[i][k]*B[k][j+3];

				sum4 += A[i+1][k]*B[k][j];
				sum5 += A[i+1][k]*B[k][j+1];
				sum6 += A[i+1][k]*B[k][j+2];
				sum7 += A[i+1][k]*B[k][j+3];
	
				sum8 += A[i+2][k]*B[k][j];
				sum9 += A[i+2][k]*B[k][j+1];
				sum10 += A[i+2][k]*B[k][j+2];
				sum11 += A[i+2][k]*B[k][j+3];

				sum12 += A[i+3][k]*B[k][j];
				sum13 += A[i+3][k]*B[k][j+1];
				sum14 += A[i+3][k]*B[k][j+2];
				sum15 += A[i+3][k]*B[k][j+3];
			}	
			C[i][j] = sum0;
			C[i][j+1] = sum1;
			C[i][j+2] = sum2;
			C[i][j+3] = sum3;
			C[i+1][j] = sum4;
			C[i+1][j+1] = sum5;
			C[i+1][j+2] = sum6;
			C[i+1][j+3] = sum7;
			C[i+2][j] = sum8;
			C[i+2][j+1] = sum9;
			C[i+2][j+2] = sum10;
			C[i+2][j+3] = sum11;
			C[i+3][j] = sum12;
			C[i+3][j+1] = sum13;
			C[i+3][j+2] = sum14;
			C[i+3][j+3] = sum15;
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
                                                                                                                







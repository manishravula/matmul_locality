#include <stdlib.h>

// define the matrix dimensions A is MxP, B is PxN, and C is MxN
 #define M 32
 #define N 32
 #define P 32

 // calculate C = AxB
void matmul(float **A, float **B, float **C) 
{

	float sum;
	int   i;
	int   j;
	int   k;
	int ii, jj, kk;
	int b1 = 16;
	int b2 = 128;
	int xx, yy;
	

	for(xx =0; xx < M; xx +=b2)
	{
		for(yy =0; yy < N; yy += b2)
		{
			for(ii =xx; ii < xx+b2; ii += b1)
			{
				for (jj = yy; jj <yy+b2; jj += b1) 
				{		 
					for (kk = 0; kk < P; kk += b1) 
					{	 
						for (i = ii; i < ii+b1; i++) 
						{		 
							for (j = jj; j < jj + b1; j++) 
							{	 
								sum = 0;
								for (k = kk; k < kk + b1; k++) 
								{  
									sum += A[i][k]*B[k][j]; 
								}								 
								C[i][j] = sum; 
							}	 
						}	
					}	 
				}
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
                                                                                                                







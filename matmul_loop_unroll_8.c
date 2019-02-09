#include <stdlib.h>

// define the matrix dimensions A is MxP, B is PxN, and C is MxN
 #define M 4096
 #define N 4096
 #define P 4096

 // calculate C = AxB
void matmul(float **A, float **B, float **C) 
{

	float sum0, sum1, sum2, sum3, sum4, sum5, sum6, sum7,sum8, sum9,sum10,sum11,sum12,sum13,sum14,sum15;
	float sum16, sum17, sum18, sum19, sum20, sum21, sum22, sum23, sum24, sum25, sum26, sum27, sum28, sum29, sum30, sum31;
	float sum32, sum33, sum34, sum35, sum36, sum37, sum38, sum39, sum40, sum41, sum42, sum43, sum44, sum45, sum46, sum47;
	float sum48, sum49, sum50, sum51, sum52, sum53, sum54, sum55, sum56, sum57, sum58, sum59,sum60,sum61,sum62,sum63;
	int   i;
	int   j;
	int   k;


	for (i=0; i<M; i = i + 8) 
	{	 
		for (j=0; j<N; j = j + 8) 
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
			sum16 = 0.0f;
			sum17 = 0.0f;
			sum18 = 0.0f;
			sum19 = 0.0f;
			sum20 = 0.0f;
			sum21 = 0.0f;
			sum22 = 0.0f;
			sum23 = 0.0f;
			sum24 = 0.0f;
			sum25 = 0.0f;
			sum26 = 0.0f;
			sum27 = 0.0f;
			sum28 = 0.0f;
			sum29 = 0.0f;
			sum30 = 0.0f;
			sum31 = 0.0f;
			sum32 = 0.0f;
			sum33 = 0.0f;
			sum34 = 0.0f;
			sum35 = 0.0f;
			sum36 = 0.0f;
			sum37 = 0.0f;
			sum38 = 0.0f;
			sum39 = 0.0f;
			sum40 = 0.0f;
			sum41 = 0.0f;
			sum42 = 0.0f;
			sum43 = 0.0f;
			sum44 = 0.0f;
			sum45 = 0.0f;
			sum46 = 0.0f;
			sum47 = 0.0f;
			sum48 = 0.0f;
			sum49 = 0.0f;
			sum50 = 0.0f;
			sum51 = 0.0f;
			sum52 = 0.0f;
			sum53 = 0.0f;
			sum54 = 0.0f;
			sum55 = 0.0f;
			sum56 = 0.0f;
			sum57 = 0.0f;
			sum59 = 0.0f;
			sum60 = 0.0f;
			sum61 = 0.0f;
			sum62 = 0.0f;
			sum63 = 0.0f;

			for (k=0; k<P; k++) 
			{

				sum0 += A[i][k]*B[k][j];
				sum1 += A[i][k]*B[k][j+1];
				sum2 += A[i][k]*B[k][j+2];
				sum3 += A[i][k]*B[k][j+3];
				sum4 += A[i][k]*B[k][j+4];
				sum5 += A[i][k]*B[k][j+5];
				sum6 += A[i][k]*B[k][j+6];
				sum7 += A[i][k]*B[k][j+7];		
	
				sum8 += A[i+1][k]*B[k][j];
				sum9 += A[i+1][k]*B[k][j+1];
				sum10 += A[i+1][k]*B[k][j+2];
				sum11 += A[i+1][k]*B[k][j+3];
				sum12 += A[i+1][k]*B[k][j+4];
				sum13 += A[i+1][k]*B[k][j+5];
				sum14 += A[i+1][k]*B[k][j+6];
				sum15 += A[i+1][k]*B[k][j+7];
	
				sum16 += A[i+2][k]*B[k][j];
				sum17 += A[i+2][k]*B[k][j+1];
				sum18 += A[i+2][k]*B[k][j+2];
				sum19 += A[i+2][k]*B[k][j+3];
				sum20 += A[i+2][k]*B[k][j+4];
				sum21 += A[i+2][k]*B[k][j+5];
				sum22 += A[i+2][k]*B[k][j+6];
				sum23 += A[i+2][k]*B[k][j+7];

				sum24 += A[i+3][k]*B[k][j];
				sum25 += A[i+3][k]*B[k][j+1];
				sum26 += A[i+3][k]*B[k][j+2];
				sum27 += A[i+3][k]*B[k][j+3];
				sum28 += A[i+3][k]*B[k][j+4];
				sum29 += A[i+3][k]*B[k][j+5];
				sum30 += A[i+3][k]*B[k][j+6];
				sum31 += A[i+3][k]*B[k][j+7];


                                sum32 += A[i+4][k]*B[k][j];
                                sum33 += A[i+4][k]*B[k][j+1];
                                sum34 += A[i+4][k]*B[k][j+2];
                                sum35 += A[i+4][k]*B[k][j+3];
                                sum36 += A[i+4][k]*B[k][j+4];
                                sum37 += A[i+4][k]*B[k][j+5];
                                sum38 += A[i+4][k]*B[k][j+6];
                                sum39 += A[i+4][k]*B[k][j+7];


                                sum40 += A[i+5][k]*B[k][j];
                                sum41 += A[i+5][k]*B[k][j+1];
                                sum42 += A[i+5][k]*B[k][j+2];
                                sum43 += A[i+5][k]*B[k][j+3];
                                sum44 += A[i+5][k]*B[k][j+4];
                                sum45 += A[i+5][k]*B[k][j+5];
                                sum46 += A[i+5][k]*B[k][j+6];
                                sum47 += A[i+5][k]*B[k][j+7];

                                sum48 += A[i+6][k]*B[k][j];
                                sum49 += A[i+6][k]*B[k][j+1];
                                sum50 += A[i+6][k]*B[k][j+2];
                                sum51 += A[i+6][k]*B[k][j+3];
                                sum52 += A[i+6][k]*B[k][j+4];
                                sum53 += A[i+6][k]*B[k][j+5];
                                sum54 += A[i+6][k]*B[k][j+6];
                                sum55 += A[i+6][k]*B[k][j+7];

                                sum56 += A[i+7][k]*B[k][j];
                                sum57 += A[i+7][k]*B[k][j+1];
                                sum58 += A[i+7][k]*B[k][j+2];
                                sum59 += A[i+7][k]*B[k][j+3];
                                sum60 += A[i+7][k]*B[k][j+4];
                                sum61 += A[i+7][k]*B[k][j+5];
                                sum62 += A[i+7][k]*B[k][j+6];
                                sum63 += A[i+7][k]*B[k][j+7];




























                            
                             
                              
                               
                                
			}	
			C[i][j] =   sum0;
			C[i][j+1] = sum1;
			C[i][j+2] = sum2;
			C[i][j+3] = sum3;
			C[i][j+4] = sum4;
			C[i][j+5] = sum5;
			C[i][j+6] = sum6;
			C[i][j+7] = sum7;

                        C[i+1][j] =   sum8;
                        C[i+1][j+1] = sum9;
                        C[i+1][j+2] = sum10;
                        C[i+1][j+3] = sum11;
                        C[i+1][j+4] = sum12;
                        C[i+1][j+5] = sum13;
                        C[i+1][j+6] = sum14;
                        C[i+1][j+7] = sum15;

                        C[i+2][j] =   sum16;
                        C[i+2][j+1] = sum17;
                        C[i+2][j+2] = sum18;
                        C[i+2][j+3] = sum19;
                        C[i+2][j+4] = sum20;
                        C[i+2][j+5] = sum21;
                        C[i+2][j+6] = sum22;
                        C[i+2][j+7] = sum23;

                        C[i+3][j] =   sum24;
                        C[i+3][j+1] = sum25;
                        C[i+3][j+2] = sum26;
                        C[i+3][j+3] = sum27;
                        C[i+3][j+4] = sum28;
                        C[i+3][j+5] = sum29;
                        C[i+3][j+6] = sum30;
                        C[i+3][j+7] = sum31;

                        C[i+4][j] =   sum32;
                        C[i+4][j+1] = sum33;
                        C[i+4][j+2] = sum34;
                        C[i+4][j+3] = sum35;
                        C[i+4][j+4] = sum36;
                        C[i+4][j+5] = sum37;
                        C[i+4][j+6] = sum38;
                        C[i+4][j+7] = sum39;

                        C[i+5][j] =   sum40;
                        C[i+5][j+1] = sum41;
                        C[i+5][j+2] = sum42;
                        C[i+5][j+3] = sum43;
                        C[i+5][j+4] = sum44;
                        C[i+5][j+5] = sum45;
                        C[i+5][j+6] = sum46;
                        C[i+5][j+7] = sum47;

                        C[i+6][j] =   sum48;
                        C[i+6][j+1] = sum49;
                        C[i+6][j+2] = sum50;
                        C[i+6][j+3] = sum51;
                        C[i+6][j+4] = sum52;
                        C[i+6][j+5] = sum53;
                        C[i+6][j+6] = sum54;
                        C[i+6][j+7] = sum55;


                        C[i+7][j] =   sum56;
                        C[i+7][j+1] = sum57;
                        C[i+7][j+2] = sum58;
                        C[i+7][j+3] = sum59;
                        C[i+7][j+4] = sum60;
                        C[i+7][j+5] = sum61;
                        C[i+7][j+6] = sum62;
                        C[i+7][j+7] = sum63;





			
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
                                                                                                                







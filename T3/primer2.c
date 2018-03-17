/*
Napisati program koji učitava dve kvadratne
matrice A i B dimenzije n, ispisuje njihovu sumu
A+B i proizvod A*B
*/

#include <stdio.h>
#define MAX 10

int main() {

	int i, j, k, n;
	int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
	
	printf("Unesite velicinu celobrojih kvadratnih matrica: ");
	scanf("%d", &n);
	
	printf("Unos matrice A: \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("A[%d][%d] = ", i+1, j + 1);
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("Unos matrice B: \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("B[%d][%d] = ", i+1, j + 1);
			scanf("%d", &B[i][j]);
		}
	}
	
	// C = A + B
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	
	printf("Ispis matrice C: (C = A + B)\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("C[%d][%d] = %d \t", i+1, j + 1, C[i][j]);
		}
		printf("\n");
	}
	
	// C = A * B
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = 0;
			for (k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	printf("Ispis matrice C: (C = A * B) \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("C[%d][%d] = %d \t", i+1, j + 1, C[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

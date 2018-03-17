/*
Dat je niz od maksimalno 30 celobrojnih
elemenata. Učitati n elemenata i ispisati ih po
učitanom i obrnutom redosledu.
*/

#include <stdio.h>
#define MAX_SIZE 30

int main () {

	int a[MAX_SIZE];
	int i, n;
	
	do {
		printf("Unesite broj elemenata niza: \n");
		scanf("%d", &n);
	} while (n <= 0 && n > MAX_SIZE);
	
	for (i = 0; i< n; i++) {
		a[i] = 0;
	}
	
	for (i = 0; i< n; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	printf("Elementi po ucitanom redosledu: \n");
	
	for (i = 0; i< n; i++) {
		printf("a[%d] = %d \t", i, a[i]);
	}
	
	printf("\nElementi po obrnutom redosledu: \n");
	
	for (i = n - 1; i >= 0; i--) {
		printf("a[%d] = %d \t", i, a[i]);
	}
	
	printf("\n");
	
	return 0;
	
}

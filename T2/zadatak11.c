/*
Sa standardnog ulaza učitati prirodan broj N.
Ispisati sve njegove činioce.
*/

#include <stdio.h>

int main() {

	int n, i;
	printf("Unesite prirodan broj n: \n");
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++) {
		if((n % i) == 0) {
			printf("%d \t", i);
		}
	}
	printf("\n");

	return;
}


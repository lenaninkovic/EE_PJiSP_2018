#include <stdio.h>

float power(float x, int k);

int main() {

	/* Poziv funkcije */
	float s = power(2.0,8);
	printf("%f\n", s);
	
	return 0;
}

/* stepenuje x^k tako sto k puta pomnozi x */
float power(float x, int k) {

	int i;
	float rezultat = 1;
	for (i = 0; i<k; i++)
		rezultat*=x;
	
	return rezultat;
}

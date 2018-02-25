/* 
Učitava se temperatura u celzijusima i 
konvertuje u Kelvine*/

#include <stdio.h>

int main( ) {

	double celzijusi, kelvini;
	printf("Unesite temperaturu u celzijusima: ");
	scanf("%lf", &celzijusi);
	kelvini = celzijusi + 273.15;
	printf("%lf stepeni celzijusa je %lf stepeni kelvina. \n", celzijusi, kelvini);
	
	return 0;

} 

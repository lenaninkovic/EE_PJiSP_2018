/*
Napisati program kojim se vrši prevođenje
količine tečnosti iz galona u litre, ako je 1 galon
4.54 litra. Količina tečnosti u galovnima se unosi
sa tastature.
*/

#include <stdio.h>

int main() {

	double litre, galoni;
	
	printf("Unesite kolicinu tecnosti u galonima: \n");
	scanf("%lf", &galoni);
	
	litre = galoni * 4.54;
	
	printf("Kolicina tecnosti u litrama je: %.2lf. \n", litre);
	
	return 0;
	
}

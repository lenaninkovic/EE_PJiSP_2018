/*
Napisati funkciju void updown(char
*s) koja mala slova u stringu s
pretvara u velika, i obrnuto. Ostale
karaktere u stringu (cifre, znakove
interpunkcije, itd) funkcija ne sme
modifikovati. U glavnom programu od
korisnika učitati string. Nakon toga,
string obraditi implementiranom
funkcijom i ispisati rezultat.
*/
#include <stdio.h>
#define MAX_SIZE 101

void updown(char *);

int main() {
	char string[MAX_SIZE];
	
	puts("Unesite string:");
	__fpurge(stdin);
	gets(string);
	updown(string);
	puts(string);
	
	return 0;
}

void updown(char *niz){
	while(*niz) {
		if (*niz >= 'A' && *niz <= 'Z')
			*niz += 32;
		else if (*niz >= 'a' && *niz <= 'z')
			*niz -= 32;
		niz++;
	}
	
}

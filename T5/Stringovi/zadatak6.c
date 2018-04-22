/*
Napisati funkciju int jednaki(char
*s1, char *s2) koja proverava da li su
stringovi s1 i s2 jednaki. U glavnom
programu od korisnika učitati dva
stringa (maksimalne dužine 20
karaktera) i ispisati da li su jednaki.
*/
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 20

int jednaki(char *, char *);

int main() {
	char string1[MAX_SIZE], string2[MAX_SIZE];

	puts("Unesite prvi string");
	__fpurge(stdin);
	gets(string1);
	puts("Unesite drugi string");
	__fpurge(stdin);
	gets(string2);
	
	if (jednaki(string1, string2))
		puts("Uneti stringovi su jednaki.");
	else 
		puts("Uneti stringovi nisu jednaki.");
	
	
	return 0;
}

int jednaki(char *niz1, char *niz2) {
	if(strlen(niz1) != strlen(niz2)) 
		return 0;
	
	while(*niz1) {
		if (*niz1 != *niz2)
			return 0;
		niz1++;
		niz2++;
	}
	
	return 1;
}

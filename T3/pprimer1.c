#include <stdio.h>

int main() {
	int i;
	int *pi = NULL;

	printf("\t\t\tint i; int *pi = NULL;\n\n");
	
	printf("Adresa pokazivaca: %p, vrednost: %p\n", &pi, pi);
	
	i = 7;
	pi = &i;
	printf("\n\n\t\t\ti=7; pi=&i;\n\n");
	
	printf("Adresa promenljive: %p, vrednost: %d\n", &i, i);
	printf("Adresa pokazivaca : %p, vrednost: %p\n", &pi, pi);
	printf("Vrednost pokazivaca: %p, sadrzaj: %d\n", pi, *pi);
	
	i = 10;
	printf("\n\n\t\t\ti = 10;\n\n");
	
	printf("Vrednost pokazivaca: %p, sadrzaj: %d\n", pi, *pi);
	
	(*pi)++; //zasto zagrade? -> prioritet operatora eksplicitno izrazen
	printf("\n\n\t\t\t(*pi)++\n\n");
	
	printf("Adresa promenljive: %p, vrednost: %d\n", &i, i);

	return 0;
	
}

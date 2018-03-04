#include <stdio.h>

int main() {

	int ocena;
	
	printf("Unesite ocenu: \n");
	scanf("%d", &ocena);
	
	switch (ocena) {
		case 5: printf("Odlican!\n\n");
		break;
		case 4: printf("Vrlo dobar!\n\n");
		break;
		case 3: printf("Dobar!\n\n");
		break;
		case 2: printf("Dovoljan!\n\n");
		break;
		case 1: printf("Nedovoljan!\n\n");
		break;
		default: printf("Ocena mora biti izmedju 1 i 5.");
	}

	return 0;
}

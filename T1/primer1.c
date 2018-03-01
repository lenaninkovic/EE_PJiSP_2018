#include <stdio.h>

int main() {

	printf("Velicina memorije (izrazena u bajtovima) iznosi:");
	printf("\n-za char \t %lu", sizeof(char));
	printf("\n-za int \t %lu", sizeof(int));
	printf("\n-za float \t %lu", sizeof(float));
	printf("\n-za double \t %lu\n", sizeof(double));

	return 0;
 
}

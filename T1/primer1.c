#include <stdio.h>

int main() {

	printf("Velicina memorije (izrazena u bajtovima) iznosi:");
	printf("\n-za char \t %d", sizeof(char));
	printf("\n-za int \t %d", sizeof(int));
	printf("\n-za float \t %d", sizeof(float));
	printf("\n-za double \t %d\n", sizeof(double));

	return 0;
 
}

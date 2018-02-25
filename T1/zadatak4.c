/*
Jedan radnik određeni posao uradi za M dana, a
drugi radnik isti posao uradi za N dana. Napisati
program kojim se određuje za koliko dana bi taj
posao bio završen ako bi radili zajedno. Vrednosti
M i N se unose sa tastature.
*/

#include <stdio.h>

int main() {

	double M, N, x_dana;
	
	printf("Uneti koliko dana je potrebno prvom radniku za posao: \n");
	scanf("%lf", &M);
	
	printf("Uneti koliko dana je potrebno drugom radniku za posao: \n");
	scanf("%lf", &N);
	
	/*
	Za jedan dan prvi radnik uradi 1/M posla, a drugi 1/N
	=> zajedno za dan urade 1/M + 1/N  
	=> jedan_dan : (1/M + 1/N) = x_dana : ceo_posao
	=> 1 : (1/M + 1/N) = x_dana : 1
	*/
	
	x_dana = 1 / (1/M + 1/N);
	
	printf("Dvojici radnika je potrebno %.1lf dana za posao. \n", x_dana);
	return 0;

}

/*
Dat je niz od maksimalno 20 realnih elemenata.
Učitati n elemenata, a zatim sortirati niz u
rastućem redosledu.
• koristiti algoritam po izboru
*/

#include <stdio.h>
#define MAX_SIZE 20


int main() {
    double a[MAX_SIZE], max;
    int i, n, changes;

    do {
        printf("Unesite broj elemenata niza: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_SIZE);

    for(i = 0;i < n;i++) { 
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }
    
    double temp;

    do {
        changes = 0;
        for(i = 1;i < n;i++) {
            if(a[i - 1] > a[i]) {
                temp = a[i - 1];
                a[i - 1] = a[i];
                a[i] = temp;
                changes = 1;
            }
        }
    } while(changes);

    printf("Niz nakon sortiranja: ");
    for(i = 0;i < n;i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%.2lf", a[i]);
    }

    printf("\n");
    
    return 0;

}

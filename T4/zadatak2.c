/*
Dati su prirodni brojevi n,m (n <= m). Napisati program
koji određuje koji od brojeva od n do m predstavljaju
prestupne godine. Godina je prestupna ako je
zadovoljen sledeći skup uslova:
 1. broj godine je deljiv sa četiri, i
 2. važi jedno od sledećih pravila:
 - broj godine nije deljiv sa 100
 - broj godine je deljiv sa 400
*/

#include <stdio.h>

void unos_brojeva(int *, int *);
int prestupna(int);
void ispis_prestupnih(int, int);

int main() {

    int n, m;

    unos_brojeva(&n, &m);
    printf("Prestupne godine su:\n");
    ispis_prestupnih(n, m);

    return 0;
}

void unos_brojeva(int *n, int *m) {

    do {
        printf("Od godine: ");
        scanf("%d", n);
        printf("Do godine: ");
        scanf("%d", m);
    } while(*n > *m || *n < 0);
}

int prestupna(int godina) {

    return (godina % 4 == 0) && (godina % 100 != 0 || godina % 400 == 0);
}

void ispis_prestupnih(int n, int m) {

    int i;
    
    for(i = n; i <= m; i++) {
        if(prestupna(i)) {
            printf("%d\n", i);
        }
    }
}

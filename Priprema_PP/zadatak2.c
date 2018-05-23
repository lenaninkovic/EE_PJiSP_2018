#include <stdio.h>
#include <stdlib.h>

#define MAX_MARKA 21

typedef struct automobil_t
{
    char marka[MAX_MARKA];
    unsigned int kubikaza;
    int godina;
} AUTOMOBIL;

typedef struct node_t
{
    struct node_t *pnext;
    AUTOMOBIL value;
} NODE;

typedef struct list_descriptor_t {
  NODE *phead; 
} LIST_DESCRIPTOR;

void initialize(LIST_DESCRIPTOR *);

void destroy(LIST_DESCRIPTOR *);

void read(FILE *, LIST_DESCRIPTOR *);

NODE *new_node(AUTOMOBIL); 

LIST_DESCRIPTOR *push_back(LIST_DESCRIPTOR *, AUTOMOBIL);

NODE *find(LIST_DESCRIPTOR *, char *);

void print_to_file(FILE *, NODE *);

int delete(LIST_DESCRIPTOR *, char *);

void save(FILE *, LIST_DESCRIPTOR *);

NODE *newest(LIST_DESCRIPTOR *, unsigned);

int main()
{
    int radi = 1;
    LIST_DESCRIPTOR descriptor;

  	initialize(&descriptor);

    while (radi)
    {
        puts("1 - Unos iz datoteke");
        puts("2 - Unos jednog automobila");
        puts("3 - Pronalazenje po marki");
        puts("4 - Brisanje automobila");
        puts("5 - Snimanje u datoteku");
        puts("6 - Pronalazenje najnovijeg");
        puts("7 - Izlaz iz programa");

        int c;
        scanf("%d", &c);

        AUTOMOBIL a;
        FILE *file;
        char naziv[100];

        switch (c)
        {
        case 1:
            printf("Unesite ime datoteke: ");
            scanf("%s", naziv);
            file = fopen(naziv, "r");
            if (file)
            {
                read(file, &descriptor);
                fclose(file);
            }
            else
            {
                puts("Nije moguce otvoriti datoteku");
            }
            break;

        case 2:
            printf("Unesite marku: ");
            scanf("%s", a.marka);
            printf("Unesite kubikazu: ");
            scanf("%u", &a.kubikaza);
            printf("Unesite godinu: ");
            scanf("%d", &a.godina);
            push_back(&descriptor, a);
            break;

        case 3:
            printf("Unesite marku: ");
            scanf("%s", a.marka);
            print_to_file(stdout, find(&descriptor, a.marka));
            break;

        case 4:
            printf("Unesite marku: ");
            scanf("%s", a.marka);

            if (delete(&descriptor, a.marka))
            {
                puts("Uspesno obrisan!");
            }
            else
            {
                puts("Nije uspesno obrisan!");
            }
            break;

        case 5:
            printf("Unesite ime datoteke: ");
            scanf("%s", naziv);
            file = fopen(naziv, "w");
            save(file, &descriptor);
            fclose(file);
            break;

        case 6:
            printf("Unesite kubikazu: ");
            scanf("%u", &a.kubikaza);
            print_to_file(stdout, newest(&descriptor, a.kubikaza));
            break;

        case 7:
            radi = 0;
            break;

        default:
            puts("Nepoznata opcija!");
        }
    }

    destroy(&descriptor);
    return 0;
}

void initialize(LIST_DESCRIPTOR *pdescriptor) {
  pdescriptor->phead = NULL;
}

void destroy(LIST_DESCRIPTOR *pdescriptor) {
  NODE *ptemp = NULL;
  while (pdescriptor->phead) {
    ptemp = pdescriptor->phead;
    pdescriptor->phead = ptemp->pnext;
    free(ptemp);
  }
  initialize(pdescriptor);
}

void read(FILE *file, LIST_DESCRIPTOR *pdescriptor){
	
	AUTOMOBIL a;
    destroy(pdescriptor);

    while (fscanf(file, "%s %u %d", a.marka, &a.kubikaza, &a.godina) != EOF)
    {
        push_back(pdescriptor, a);
    }
}

LIST_DESCRIPTOR *push_back(LIST_DESCRIPTOR *pdescriptor, AUTOMOBIL a) {
	if(find(pdescriptor, a.marka)){
		return;
	}
  NODE *pnew = new_node(a);
  NODE *pcurr = pdescriptor->phead;
  if (pcurr == NULL) {
    pdescriptor->phead = pnew;
  } else {
    while (pcurr->pnext != NULL) {  
      pcurr = pcurr->pnext;
    }
    pcurr->pnext = pnew;
  }
  return pdescriptor;
}

NODE *new_node(AUTOMOBIL a) {
  NODE *pnew = malloc(sizeof(NODE));
  pnew->value = a;
  pnew->pnext = NULL;
  return pnew;
}

NODE *find(LIST_DESCRIPTOR *pdescriptor, char* marka){
	NODE *pcurr = pdescriptor->phead;
  while (pcurr != NULL) {
    if (strcmp(pcurr->value.marka, marka) == 0){ 
    	return pcurr;
    }
    pcurr = pcurr->pnext;
  }
  return NULL;
}

int delete(LIST_DESCRIPTOR *pdescriptor, char* marka){
  NODE *pcurr = pdescriptor->phead;
  if (pcurr == NULL){ // lista je prazna
    return 0;
   }
  if (strcmp(pcurr->value.marka, marka) == 0){ // ako brisemo sa pocetka
        pdescriptor->phead = pcurr->pnext;
        free(pcurr);
        return 1;
    }
  pcurr = pdescriptor->phead;
  while (pcurr->pnext != NULL){ 
	  if (strcmp(pcurr->pnext->value.marka, marka) == 0){ // brisemo iz sredine ili sa kraja
		 NODE *ptemp = pcurr->pnext;
     	pcurr->pnext = pcurr->pnext->pnext;
     	free(ptemp);
     	return 1;
		}
		pcurr = pcurr->pnext;
  }
    return 0;
}

void save(FILE *file, LIST_DESCRIPTOR *pdescriptor){
	NODE *pcurr = pdescriptor->phead;
	while(pcurr != NULL){
		print_to_file(file, pcurr);
		pcurr = pcurr->pnext;
	}
}

void print_to_file(FILE *file, NODE *node){
	
	if(node != NULL){
		fprintf(file, "%s %u %d\n", node->value.marka, node->value.kubikaza, node->value.godina);
		}
    else printf("Trazeni automobil ne postoji\n");
	
}

NODE *newest(LIST_DESCRIPTOR *pdescriptor, unsigned kubikaza){
	NODE *pcurr = pdescriptor->phead;
	
	while (pcurr != NULL) {
    if (pcurr->value.kubikaza == kubikaza){ //pronaci ce tacno unetu kubikazu
    	return pcurr;
    }
    pcurr = pcurr->pnext;
  }
  return NULL;
}


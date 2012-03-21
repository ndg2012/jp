#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// TODO
// nauczyc sie wskaznikow


typedef unsigned long long ull;

const int ile = 200;

int main(void)
{
    ull i, t;

    char *tablica[ile];
    char szablon[10];

    //tablica = (char *)malloc (ile * sizeof (tablica));
    /*
       if (tablica == NULL)
       {
       fprintf (stderr, "Error\n");
       exit (1);
       }
     */
    /*
    for (i = 0; i < ile+1; i++) {
	scanf("%s", &tablica[i]);
    }
    */
    
    printf("Podaj wzór: ");
    scanf("%s",&szablon);
    printf("\n");
    /*
    for (i = 0; i < ile; i++) {
	printf("%d\n", strcmp(szablon, tablica[i]));
    }

    */
    //free (tablica);

    return 0;
}

/*

patshaughnessy.net

sof: 

 */

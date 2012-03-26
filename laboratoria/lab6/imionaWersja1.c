/*
 * Prymitywna wersja 
 * strncmp 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned long long ull;

const int ile = 4960;


int
main (int argc, char *argv[])
{
  ull i, t;

  char wzorzec[] = "mate";
  char tablica[ile][20]; 
 
  for (i = 0; i < ile; i++)
    {
 
      scanf ("%s", &tablica[i]);
    }

 

  for (i = 0; i < ile; i++)
    {   
      if (!strncmp(tablica[i],wzorzec,strlen(wzorzec))){
	printf ("%s\n", tablica[i]);
      }
    }


  return 0;
}

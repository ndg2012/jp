#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef long long ll;

#define ILE 1000000

clock_t startclick, clicks;

#define START startclick=clock()
#define STOP(co) clicks=clock()-startclick; printf("czas wykonania %s = %ld\n",co,clicks)

void wczytaj_liczby (ll t[], ll ile);

int
main (int argc, char *argv[])
{
  
 
  ll min, max;
  ll i, tablica[ILE];

  wczytaj_liczby (tablica, ILE);

  START;

  
  min = tablica[0];
  max = tablica[0];
  for (i = 1; i < ILE; i++)
    {
      if (min > tablica[i])
	min = tablica[i];
      if (max < tablica[i])
	max = tablica[i];
    }

  STOP ("pętli");


  printf ("i = %lld :: min = %lld && max = %lld\n", i, min,max);


  return 0;
}


void
wczytaj_liczby (ll t[], ll ile)
{
  ll i;
  for (i = 0; i < ile; i++)
    scanf ("%lld", &t[i]);
}

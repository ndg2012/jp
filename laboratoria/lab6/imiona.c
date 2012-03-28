#include <stdio.h>
#include <string.h>

int
main (int argc, char *argv[])
{
  unsigned int i;

  char tablica[20];

  while (scanf ("%s", tablica) == 1)
    {
      if (!strncmp (tablica, argv[1], strlen (argv[1])))
	printf ("%s\n", tablica);
    }


  return 0;
}

#include <stdio.h>
#include <string.h>

int
main (int argc, char *argv[])
{
<<<<<<< HEAD
  char tablica[20];

  while (scanf ("%s", &tablica) == 1)
    if (!strncmp (tablica, argv[1], strlen (argv[1])))
      printf ("%s\n", tablica);
=======
  unsigned int i;

  char tablica[20];
>>>>>>> b356fa212809e99c16d2b03a02d7a5ef6391be33

  while (scanf ("%s", tablica) == 1)
    {
      if (!strncmp (tablica, argv[1], strlen (argv[1])))
	printf ("%s\n", tablica);
    }


  return 0;
}

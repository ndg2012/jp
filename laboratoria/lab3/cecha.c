#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int
cecha (double liczba)
{
  return (int) floor (log10 (liczba)) + 1;
}

int
witdh (int cecha, int mantysa)
{
  return cecha + mantysa + 1;	// 1 to kropka
}

void
linia (int dlugosc_formatki, int temp1, int temp2)
{
  int i;
  putchar ('|');
  //for (i = 1; i < dlugosc_formatki - 1; i++)
  //  putchar ('-');
  printf ("%*s|%*s", temp1 + 2, "liczba", temp2, "pierwiastek");
  putchar ('|');
  putchar ('\n');
}


void
linia2 (int dlugosc_formatki)
{
  int i;
  putchar (' ');
  for (i = 1; i < dlugosc_formatki - 1; i++)
    putchar ('-');
  putchar (' ');
  putchar ('\n');
}

int
main (void)
{
  double a, b, c, i;
  double wynik;
  int cecha_int, mantysa = 7;	// cecha i mantysa
  int temp1, temp2;

  int dlugosc_formatki;

  char *formatka = "| %*lf | %*lf |\n";
  char *bufor;

  scanf ("%lf %lf %lf", &a, &b, &c);
  assert (a > 0 || b > 0);

  cecha_int = cecha (c);
  temp1 = witdh (cecha_int, mantysa);
  temp2 = witdh (cecha ((int) sqrt (c)), mantysa);

  dlugosc_formatki = 7 + temp1 + temp2;

  bufor = (char *) malloc ((dlugosc_formatki + 1) * sizeof (char));

  if (bufor == NULL)
    {
      puts ("Błąd. Nie udało się przydzielić pamięci dla bufora.");
      exit (1);
    }
  linia2 (dlugosc_formatki);
  linia (dlugosc_formatki, temp1, temp2);
  linia2 (dlugosc_formatki);

  for (i = a; i <= c; i += b)
    {
      wynik = sqrt (i);
      sprintf (bufor, formatka, temp1, a, temp2, wynik);
      printf (bufor);
      a += b;

    }
  linia2 (dlugosc_formatki);

  free (bufor);



  return 0;
}

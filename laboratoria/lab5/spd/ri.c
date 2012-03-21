#include <stdio.h>
#include <stdlib.h>		/* tutaj jest zdefiniowane RAND_MAX */

typedef long long int ll;

ll RandomInteger (ll low, ll high);

int
main (int argc, char *argv[])
{
  ll i, n, low, high;
  
  if(argc == 1){
    fprintf(stderr,"%s n low high\n",argv[0]);
    exit(1);
  }
  
  n = atoi (argv[1]);
  low = atoi (argv[2]);
  high = atoi (argv[3]);

  for (i = 0; i < n; i++)
    {
      printf ("%lld\n", RandomInteger (low, high));
    }

  return 0;
}

ll
RandomInteger (ll low, ll high)
{
  ll k;
  double d;

  d = (double) rand () / ((double) RAND_MAX + 1);
  k = (int) (d * (high - low + 1));
  return (low + k);
}

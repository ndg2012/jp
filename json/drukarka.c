#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "json.c"


int
main (int argc, char *argv[])
{
  int valid = 1;
  int succeeded = 0;
  int failed = 0;
  json_settings settings;

  memset (&settings, 0, sizeof (settings));

  while (valid >= 0)
    {
      int i;

      for (i = 1;; ++i)
	{
	  json_value *value;
	  char filename[16];
	  FILE *file;
	  char *buf;
	  unsigned int length;
	  char error[256];

	  sprintf (filename, valid ? "valid-%04d.json" : "invalid-%04d.json",
		   i);

	  if (!(file = fopen (filename, "rb")))
	    break;

	  fseek (file, 0, SEEK_END);
	  length = ftell (file);
	  fseek (file, 0, SEEK_SET);
	  buf = malloc (length + 1);
	  fread (buf, 1, length, file);
	  fclose (file);

	  buf[length] = 0;

	  if (value = json_parse_ex (&settings, buf, error))
	    {
	      if (valid)
		{
		  printf(buf);
		  printf ("%s succeeded (type = %d)\n", filename,
			  value->type);
		  ++succeeded;
		}
	      else
		{
		  printf ("%s failed (type = %d, should have been error)\n",
			  filename, value->type);

		  ++failed;
		}

	      json_value_free (value);
	    }
	  else
	    {
	      if (!valid)
		{
		  printf ("%s succeeded : %s\n", filename, error);
		  ++succeeded;
		}
	      else
		{
		  printf ("%s failed : %s\n", filename, error);
		  ++failed;
		}

	      json_value_free (value);
	    }
	}

      --valid;
    }

  printf ("*** %d tests executed, of which %d succeeded and %d failed\n",
	  succeeded + failed, succeeded, failed);
}

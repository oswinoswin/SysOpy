#include <stdio.h>
#include <stdlib.h>
/* program udający bardzo prymitywną wersję programu tee(1) */
 
int main (int argc, char *argv[])
{
   FILE *fp;
   int c;
   if (argc < 2) {
      fprintf (stderr, "Uzycie: %s nazwa_pliku\n", argv[0]);
      exit (-1);
   }
   fp = fopen (argv[1], "w");
   if (!fp) {
      fprintf (stderr, "Nie moge otworzyc pliku %s\n", argv[1]);
      exit (-1);
   }
   printf("Wcisnij Ctrl+D+Enter lub Ctrl+Z+Enter aby zakonczyc\n");
   while ( (c = fgetc(stdin)) != EOF) {
      fputc (c, stdout);
      fputc (c, fp);
   }
   fclose(fp);
   return 0;
}

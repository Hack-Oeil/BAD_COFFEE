#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("Enter your first name\n");
  fgets(firstname,45,stdin);
 
  printf("\nHello %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nOops, looks like you found a problem!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nOh my, you are on my bash, you shouldn't be here!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

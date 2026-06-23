#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("Geben Sie Ihren Vornamen ein\n");
  fgets(firstname,45,stdin);
 
  printf("\nHallo %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nHoppla, es sieht so aus, als hätten Sie ein Problem gefunden!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nOh je, Sie sind auf meiner Bash, Sie sollten nicht hier sein!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

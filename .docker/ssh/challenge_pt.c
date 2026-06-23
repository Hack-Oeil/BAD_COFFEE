#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("Digite seu primeiro nome\n");
  fgets(firstname,45,stdin);
 
  printf("\nOlá %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nOps, parece que você encontrou um problema!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nOh não, você está no meu bash, você não deveria estar aqui!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

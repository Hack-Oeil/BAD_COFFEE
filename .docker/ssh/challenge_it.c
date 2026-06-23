#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("Inserisci il tuo nome\n");
  fgets(firstname,45,stdin);
 
  printf("\nBuongiorno %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nOps, sembra che tu abbia trovato un problema!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nOh cavolo, sei sulla mia bash, non dovresti essere qui!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

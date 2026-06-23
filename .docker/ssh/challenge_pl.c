#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("Wpisz swoje imię\n");
  fgets(firstname,45,stdin);
 
  printf("\nWitaj %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nUps, wygląda na to, że znalazłeś problem!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nO rany, jesteś na moim bashu, nie powinno cię tu być!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

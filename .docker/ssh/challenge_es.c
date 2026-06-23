#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("Introduzca su nombre\n");
  fgets(firstname,45,stdin);
 
  printf("\nHola %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\n¡Vaya, parece que has encontrado un problema!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\n¡Oh vaya, estás en mi bash, no deberías estar aquí!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

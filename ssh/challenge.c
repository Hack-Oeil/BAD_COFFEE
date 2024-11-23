#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("Entrez votre prénom\n");
  fgets(firstname,45,stdin);
 
  printf("\nBonjour %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nOups, on dirait que vous avez trouvé un problème !\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nOh mince, vous êtes sur mon bash, vous ne devriez pas être ici !\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}
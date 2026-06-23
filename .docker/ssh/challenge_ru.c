#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("Введите ваше имя\n");
  fgets(firstname,45,stdin);
 
  printf("\nЗдравствуйте %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nУпс, кажется, вы нашли проблему!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nО боже, вы в моем bash, вас здесь не должно быть!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

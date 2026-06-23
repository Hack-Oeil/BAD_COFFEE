#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("أدخل اسمك الأول\n");
  fgets(firstname,45,stdin);
 
  printf("\nمرحباً %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nعفواً، يبدو أنك وجدت مشكلة!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nيا إلهي، أنت في الغلاف (bash) الخاص بي، لا ينبغي أن تكون هنا!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

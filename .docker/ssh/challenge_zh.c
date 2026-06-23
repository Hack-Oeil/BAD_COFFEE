#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("输入您的名字\n");
  fgets(firstname,45,stdin);
 
  printf("\n你好 %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\n哎呀，看来你发现了一个问题！\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\n天哪，你在我的bash上，你不应该在这里！\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

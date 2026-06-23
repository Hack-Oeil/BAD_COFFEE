#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("名を入力してください\n");
  fgets(firstname,45,stdin);
 
  printf("\nこんにちは %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nおっと、問題が見つかったようです！\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nあらら、私のbashにいますね、あなたはここにいるべきではありません！\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

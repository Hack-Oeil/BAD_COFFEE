#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("이름을 입력하세요\n");
  fgets(firstname,45,stdin);
 
  printf("\n안녕하세요 %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\n앗, 문제를 발견한 것 같네요!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\n오 이런, 제 bash에 있군요, 여기에 있으면 안 됩니다!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

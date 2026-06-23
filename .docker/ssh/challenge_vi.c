#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("Nhập tên của bạn\n");
  fgets(firstname,45,stdin);
 
  printf("\nChào %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nRất tiếc, có vẻ như bạn đã tìm thấy một vấn đề!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nÔi trời, bạn đang ở trên bash của tôi, bạn không nên ở đây!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

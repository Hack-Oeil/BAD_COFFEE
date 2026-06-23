#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
 
int main() {
  int secret = 0x04030201;
  char firstname[40];
 
  printf ("ป้อนชื่อจริงของคุณ\n");
  fgets(firstname,45,stdin);
 
  printf("\nสวัสดี %s", firstname);

  if ((secret != 0x04030201) && (secret != 0xbadc0ffe)) {
      printf("\nDEBUG: \n----------------------------\n");
      printf("[firstname]: %s\n", firstname);
      printf("[secret] %p\n", secret);
      printf ("\nอุ๊ย ดูเหมือนว่าคุณจะพบปัญหา!\n");
  }
  if (secret == 0xbadc0ffe) {
      printf("\n\nโอ้โห คุณอยู่บน bash ของฉัน คุณไม่ควรอยู่ที่นี่!\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
  }
  return 0;
}

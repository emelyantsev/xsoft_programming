#include <stdio.h>

int main()
{
  char *str = "emelyantsev";
  int num = 31337;

  printf("str=%s, adrr_str=%p, num=%d, addr_num=%llx\n", str, &str, num, &num);

  return 0;
}
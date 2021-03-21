#include <stdio.h>
#include <stdlib.h>
#define GREEN "\e[38;5;83m"
#define END "\033[0m"
char flag[64];

void print_flag()
{
  FILE *f = fopen("flag.txt", "r");
  fgets(flag, 64, f);
  printf(" Thanks for running my function, here is my secret : %s%s%s", GREEN, flag, END);
}

void vuln()
{
  char buf[24];
  gets(buf);
}

int main()
{
  printf("I will give you my secret if you can run my function\n");
  vuln();
  printf("This is not my function :\n");
  return 0;
}
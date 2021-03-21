#include <stdio.h>
#include <stdlib.h>

#define GREEN "\e[38;5;83m"
#define END "\033[0m"

char flag[64];
int position = 0;

void print_flag()
{
  FILE *f = fopen("flag.txt", "r");
  if (f == NULL)
  {
    printf("If you see this, then it means you solved the challenge. If you see this on server, then contact admin.\n");
    exit(0);
  }
  fgets(flag, 64, f);
  printf("Cafe Coupon: %s%s%s", GREEN, flag, END);
}

void vuln()
{
    char buf[80];
    printf("Tell me the directions, if I feel like going to a cafe, I will go\n");
    fgets(buf, 80, stdin);
    printf(buf);
    printf("I am currently at %x\n", position);
    if(position == 0xcafe)
    {
        printf("Yaaaay, I am at the cafe, Ah mai pawry karunga\n");
        print_flag();
    }
}

int main()
{
  printf("I want to drink a cappucino, please take me to a cafe\n");
  vuln();
  return 0;
}
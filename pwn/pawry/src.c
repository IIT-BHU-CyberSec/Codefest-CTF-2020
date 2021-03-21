#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define GREEN "\e[38;5;83m"
#define END "\033[0m"

char yeh_hamari_doosri_car_hai[24];

void abhi_ka_time(char *gaadi)
{
    printf("Pawry over at ");
    system(gaadi);
}

void vuln()
{
    char buf[16];
    char yeh_hamari_car_hai[24];
    strcpy(yeh_hamari_car_hai, "/bin/date");
    printf("Pawry mein aana hai toh hamari car ka number batao : ");
    gets(buf);
    abhi_ka_time(yeh_hamari_car_hai);
}

int main(int argc, char **argv)
{
    printf("Yeh ham hai : %s%s%s\n", GREEN, "CodeFestTeam", END);
    printf("Yahan hamara address hai : %s%p%s\n", GREEN, puts, END);
    printf("Aur yeh hamari pawrry ho rhi hai.\n");
    strcpy(yeh_hamari_doosri_car_hai, "/bin/cat flag.txt");
    vuln();
}

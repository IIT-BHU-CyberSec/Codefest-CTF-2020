#include<stdio.h>
#include<string.h>
#include <unistd.h>


int main(int argc,char* argv[])
{
    char final[] = {'b', 'm', 'g', 'a', 'c', 'c', 't', '|', 'r', '~', 'c', 'e', '~', 'Q', 'f', 'c', 'N', 'p', 'r', '!', '|', 'u', 'd', 'e',0};
char arr1[] = {'[','*',']','P', 'l', 'e', 'a', 's', 'e', ' ', 'g', 'i', 'v', 'e', ' ', 'm', 'e', ' ', 'f', 'l', 'a', 'g',0};
char arr2[] = {'[', '*', ']', ' ', 'T', 'h', 'i', 's', ' ', 'a', 'i', 'n', 't', ' ', 'f', 'l', 'a', 'g', ' ', 't', 'r', 'y', ' ', 'a', 'g', 'a', 'i', 'n',0};
char arr3[] = {'[', '*', ']', ' ', 'G', 'r', 'e', 'a', 't', ' ', 'S', 'u', 'c', 'c', 'e', 's', 's',0};

    printf("%s\n",arr1);
    char flag[100];
    scanf("%s",flag);
    sleep(5);
    if(strlen(flag)!=24){
        printf("%s\n",arr2);
        return 1;
    }
    for(int i=1;i<25;i++){
        if(((int)flag[i-1]^i)!=final[i-1]){
            printf("%s\n",arr2);
            return 1;
        }


    }
    printf("%s\n",arr3);
    return 0;

}

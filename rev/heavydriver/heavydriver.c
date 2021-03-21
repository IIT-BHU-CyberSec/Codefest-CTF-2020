#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<sys/ptrace.h>

const static uint16_t KEY[4] = {0x2142,0x3421,0x3511,0x2425};
const static uint16_t flag[] = {0xcd86,0x26db,0x571,0x5346,0x46c7,0x1cbd,0xfb0,0x43db,0xae6e,0x13f7,0xc263,0xc505,0x9639,0x2e22,0xfb3b,0xe870};

void encrypt(uint16_t *v,int k) {
  uint16_t v0=v[k], v1=v[k+1], sum=0, i;           
  uint16_t delta=0x9e37;                         
  for (i=0; i < 32; i++) {                       
    sum += delta;
    v0 += ((v1<<4) + KEY[0]) ^ (v1 + sum) ^ ((v1>>5) + KEY[1]);
    v1 += ((v0<<4) + KEY[2]) ^ (v0 + sum) ^ ((v0>>5) + KEY[3]);  
  }                                              
  v[k]=v0; v[k+1]=v1;
}

int main(int argc,char* argv[])
{
	if(ptrace(PTRACE_TRACEME,0,1,0)==-1){
		printf("[*] Please dont debug me!!\n");
		return 1;
	}

	char arr[100];
	int i,j;
	uint16_t ar2[100];
	printf("[*] Please enter the flag\n");
	scanf("%[^\n]s",arr);

	if(strlen(arr)%2!=0) arr[strlen(arr)]='\0';
	if(strlen(arr)!=29)
	{
		printf("[*] Heavy Driver you Failed\n");
		return 1;
	}
	for(i=0,j=0;i<strlen(arr);i=i+2,j++)
	{
		ar2[j] = *(arr+i+1) << 8 | *(arr+i);

	}
	int ar2len = j;
	uint16_t* v = ar2;
	for(i=0;i<j;i=i+2)
	{
		encrypt(v,i);

	}
	for(int i=0;i<16;i++)
	{
		if((int)*(v+i)!=(int)flag[i])
		{	printf("%d",i);
			printf("[*] Heavy Driver you Failed");
			return 1;
		}
	}
	printf("[*] Great Success\n");

	return 0;
}

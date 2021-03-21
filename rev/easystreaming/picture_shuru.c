#include<stdio.h>
#include<immintrin.h>
#include<sys/ptrace.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>

//flag is codefest{1ts55e}
const static uint8_t shuffle[16] = {
    2, 12, 3, 15, 4, 1, 0, 14, 9, 5, 13, 6, 10, 8, 7, 11,
};

const static uint8_t unpackme[16] = {
	4,14,56,12,45,6,7,8,89,12,45,51,25,56,61,12,
};

const static uint8_t xoling[16] = {
	15,25,62,63,63,72,56,25,61,77,12,56,73,73,23,43
};

const static uint8_t ans[16] = {
62,124,50,51,75,17,67,100,36,96,49,75,124,124,36,19,
};
void hehe(){
	srand(time(0));
	for(int i = 0; i<5; i++)
        printf(" %d ", rand());
    printf("\n");
}

int main(int argc,char *argv[])
{
	if(ptrace(PTRACE_TRACEME,0,1,0)==-1){
		printf("[*] pls dont debug me!! its just sse\n");
		return 1;
	}
	__m128i key,ping;
	printf("[*] Please enter the key\n");
	scanf("%16c",((char*)&key));
	
	hehe();
	ping = key;
	__m128i enc;
	__m128i adme = _mm_lddqu_si128((__m128i*)(unpackme));
	ping = _mm_unpackhi_epi8(ping,adme);
	__m128i shuf = _mm_lddqu_si128((__m128i*)(shuffle));
	ping = _mm_shuffle_epi8(ping,shuf);
	__m128i ixol = _mm_lddqu_si128((__m128i*)(xoling));
	ping = _mm_xor_si128(ping,ixol);
	uint8_t* final = (uint8_t*)malloc(16 * sizeof(uint8_t));
	_mm_storeu_si128(((__m128i*)final), ping);
	
	//for(int i=0;i<16;i++){
	//	printf("%d,",*(cipher+i));
	//}
	for (int i = 0; i < 16; i++) {
		if (final[i] != ans[i]) {
			printf("[*] You made a mistake\n");
			free(final);
			return 0;
		}
	}

	printf("[*] Success\n");
	free(final);
	return 0;



	
}

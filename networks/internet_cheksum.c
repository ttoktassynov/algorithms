#include <stdio.h>
#include <stdlib.h>

typedef unsigned char       byte;
typedef unsigned short int  word16;
typedef unsigned int        word32;

#define BUFFER_LEN 8

word16 checksum(word16 * addr, word16 count);

void main(void) {
    word16 buff[BUFFER_LEN];
    word16 check;
    word32 i;
    for (i = 0; i < BUFFER_LEN; ++i)
        buff[i] = (word16)rand();
        
    check = checksum(buff, BUFFER_LEN);
    printf("checksum = %04X \n");
}

word16 checksum(word16 * addr, word16 count) {
    register word16 sum;
    while (count--){
        sum += *addr++;
        if (sum & 0xFFFF0000) {
            sum &= 0xFFFF;
            sum++;
        }
    }
    return ~(sum & 0xFFFF);
}





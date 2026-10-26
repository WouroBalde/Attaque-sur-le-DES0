#include "permutation.h"
#include <stdint.h>

const int P_t [32]={16,7,20,21,29,12,28,17,\
        1,15,23,26,5,18,31,10,2,\
        8,24,14,32,27,3,9,19,\
        13,30,6,22,11,4,25};

uint32_t Perm(uint32_t S, const int *table)// Permutation de 32bits
{
    uint32_t oum=0;
    for(int i=0; i<32; i++)
    {
        int b=32-table[i];
        uint32_t bits=(S>>b)&1;
        oum=(oum<<1)|bits;
    }
    return oum;
}
#include "key_schedule.h"

#include <stdint.h>

const int pc1[56]={57,49,41,33,25,17,9,1,58,50,\
                42,34,26,18,10,2,59,51,43,\
                35,27,19,11,3,60,52,44,36,\
                63,55,47,39,31,23,15,7,62,\
                54,46,38,30,22,14,6,61,53,\
                45,37,29,21,13,5,28,20,12,\
                4};

const int pc2[48] = {14,17,11,24,1,5,3,28,\
                    15,6,21,10,23,19,12,4,\
                    26,8,16,7,27,20,13,2,\
                    41,52,31,37,47,55,30,40,\
                    51,45,33,48,44,49,39,56,\
                    34,53,46,42,50,36,29,32};

const int v[16]={1,1,2,2,2,2,2,2,\
                1,2,2,2,2,2,2,1};

uint64_t PC1(uint64_t cle, const int *table)// Permutation PC1 
{
    uint64_t oum=0;
    for(int i=0; i<58; i++)
    {
        int b=58-table[i];
        uint64_t bit=(K>>b)&1ULL;
        oum=(oum<<1)|bit;
    }
    return oum;
}

typedef struct { //structure contenant les C_i et D_i
    uint32_t C;
    uint32_t D;
} Ks;

uint32_t rot(uint32_t a, int n) //Rotation circulaire à gauche 
{
    return ((a<<n)|(a>>(28-n))) & 0x0FFFFFFF ;
}

void KeySch(uint32_t C0, uint32_t D0, const int *vl, Ks Tab[16]) //Récuperer les Ci et Di et les stocker dans le tableau T;
{
    uint32_t C=C0;
    uint32_t D=D0;
    for (int i=0; i<16;i++)
    {
        C=rot(C,vl[i]);
        D=rot(D,vl[i]);
        T[i].C=C;
        T[i].D=D;
    }
}

uint64_t PC2(uint32_t x, uint32_t y, const int *table)
{
    uint64_t K=0;
    uint64_t CD=((uint64_t)x<<28)|y;
    for (int i=0; i<48; i++)
    {
        int b=48-pc2[i];
        uint64_t bit=(CD>>b)&1ULL;
        K=(K<<1)|bit;
    }
    return K;
}

void Keys(uint64_t K, const int *table1, const int *table2, const int *val, uint64_t Cle[16])// 
{
    uint64_t oum=PC1(K, table1);
    uint32_t C=(oum>>28)&0x0FFFFFFF;
    uint32_t D=oum&0x0FFFFFFF;
    Ks T[16];
    KeySch(C, D, val, T);
    for(int i=0; i<16; i++)
    {
        Cle[i]=PC2(T[i].C, T[i].D, table2);
    }
}
#include "feistel.h"
#include "permutation.h"
#include "sboxes.h"

#include <stdint.h>

uint64_t Exp(uint32_t y)
{
    int E[48]={};
        int E[48]={32};
    int j=1;
    int e;
    for (int i=1;i<6;i++)
    {
        E[i]=i;
        j=i;
    }
    for (int i=4;i<10;i++)
    {
        E[i+2]=i;
        j=j+1;
    }
    for (int i=8;i<14;i++)
    {
        E[j+1]=i;
        j=j+1;
    }
    for (int i=12;i<18;i++)
    {
        E[j+1]=i;
        j=j+1;
    }
    for (int i=16;i<22;i++)
    {
        E[j+1]=i;
        j=j+1;
    }
    for (int i=20;i<26;i++)
    {
        E[j+1]=i;
        j=j+1;
    }
    for (int i=24;i<30;i++)
    {
        E[j+1]=i;
        j=j+1;
    }
    for (int i=28;i<33;i++)
    {
        E[j+1]=i;
        j=j+1;
    }
    E[47]=1;

    uint64_t oum=0;
    for(int i=0; i<48; i++)
    {
        int64_t bit=(y >> (48-E[i]) ) & 1ULL;
        oum=(oum<<1)|bit;
    }
    return oum;
}

uint32_t Feist_f(uint32_t R, uint64_t K)
{
    uint64_t exp=Exp(R);
    uint64_t X=(exp^K) & 0xFFFFFFFFFFFFULL;// conserver que les 48bits(masque; F=1111)
    uint32_t S=SBOX(X);
    uint32_t perm=Permut(S,P_t);
    return perm;
}
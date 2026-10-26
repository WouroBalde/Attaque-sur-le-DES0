#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H
#include <stdint.h>


/*
    uint32_t S : suite de bits à permuter
    const int *table : table de permutation de 32 elements
*/

extern const int P_t[32];

uint32_t Perm(uint32_t S, const int *table);// Permutation de 32bits

#endif
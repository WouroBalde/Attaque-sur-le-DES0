#ifndef KEY_SCHEDULE_H
#define KEY_SCHEDULE_H

#include <stdint.h>

extern const int pc1[56];

extern const int pc2[48];

extern const int v[16];

uint64_t PC1(uint64_t cle, const int *table); // Permutation PC1 

uint32_t rot(uint32_t a, int n) ;//Rotation circulaire à gauche

typedef struct {
    uint32_t C;
    uint32_t D;
} Ks;

void KeySch(uint32_t C0, uint32_t D0, const int *vl, Ks T[16]); //Récuperer les Ci et Di et les stocker dans le tableau T;

uint64_t PC2(uint32_t x, uint32_t y, const int *table);

void Keys(uint64_t K, const int *table1, const int *table2, const int *val, uint64_t Cle[16]);// 

#endif